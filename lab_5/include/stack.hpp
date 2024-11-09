#pragma once
#include <memory>
#include <type_traits>
#include <concepts>
#include <type_traits>

template <class T>
struct StackItem {
    T element;
    std::shared_ptr<StackItem<T>> next{nullptr};

    StackItem (T elementValue) : element{elementValue} {}
};

template <class T, bool Const>
class StackIter {
    private:
        std::shared_ptr<StackItem<T>> item{nullptr};

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = typename std::conditional<Const, const T*, T*>::type;
        using reference = typename std::conditional<Const, const T&, T&>::type;

        StackIter (std::shared_ptr<StackItem<T>> itemToWrap) {
            item = itemToWrap;
        }

        StackIter (const StackIter &other) {
            item = other.item;
        }

        StackIter (StackIter &&other) {
            item = std::move(other.item);
        }

        StackIter& operator= (const StackIter &other) {
            if (this == &other) return *this;

            item.reset();
            item = other.item;

            return *this;
        }

        StackIter& operator= (StackIter other) {
            item.reset();
            item = std::move(other.item);
            return *this;
        }

        StackIter& operator++() {
            item = item->next;
            return *this;
        } 

        StackIter operator++(int) {
            StackIter copy{*this};
            item = item->next;
            return copy;
        } 

        reference operator* () const {
            return item->element;
        }

        pointer operator->() const {
            return &item->element;
        }

        bool operator== (const StackIter &other) const {
            return item == other.item;
        }

        bool operator!= (const StackIter &other) const {
            return item != other.item;
        }
};

template <class T>
using StackAllocator = std::pmr::polymorphic_allocator<StackItem<T>>;

template <class T>
class Stack {
    private:
        class DestructionStrategy {
            private:
                StackAllocator<T> allocator;
                
            public:
                DestructionStrategy (StackAllocator<T> allocatorObject) : allocator{allocatorObject} {}

                void operator() (StackItem<T> *ptr) {
                    allocator.deallocate(ptr, 1);
                }
        };

        StackAllocator<T> allocator;
        std::shared_ptr<StackItem<T>> topItem{nullptr};

        void copyStackBody (const Stack &other) {
            std::shared_ptr<StackItem<T>> tail(nullptr, DestructionStrategy(allocator));

            for (auto it = other.begin(); it != other.end(); ++it) {
                auto itemP = allocator.allocate(1);
                allocator.construct(itemP, *it);
                std::shared_ptr<StackItem<T>> item(itemP, allocator);
                if (tail != nullptr) tail->next = item;
                tail = item;
                if (it == other.begin()) topItem = tail;
            }
        }

    public:

        Stack (StackAllocator<T> allocatorObject) : allocator{allocatorObject} {}
        
        Stack (const Stack &other) {
            allocator = other.allocatorObject;
            copyStackBody(other); 
        }

        Stack (Stack &&other) {
            allocator = std::move(other.allocatorObject);
            topItem = std::move(other.topItem);
        }

        Stack& operator= (const Stack &other) {
            if (this == &other) return *this;

            topItem.reset();
            copyStackBody(other);
            return *this;
        }

        Stack& operator= (Stack &&other) {
            allocator = std::move(other.allocatorObject);
            
            topItem.reset();
            topItem = std::move(other.topItem);
            return *this;
        }

        StackIter<T, false> begin () {
            return StackIter<T, false>(topItem);
        }

        StackIter<T, false> end () {
            return StackIter<T, false>(nullptr);
        }

        StackIter<T, true> begin () const {
            return StackIter<T, true>(topItem);
        }

        StackIter<T, true> end () const {
            return StackIter<T, true>(nullptr);
        }

        bool empty () {
            return topItem == nullptr;
        }

        T top () {
            return topItem->element;
        }

        void push (T elem) {
            auto itemP = allocator.allocate(1);
            allocator.construct(itemP, elem);
            std::shared_ptr<StackItem<T>> item(itemP, DestructionStrategy(allocator));
            item->next = topItem;
            topItem = item;
        }

        void pop () {
            if (empty()) return;
            
            topItem = std::move(topItem->next);
        }
};