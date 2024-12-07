#include "../../include/NPCs/Privateer.h"

Privateer::Privateer (Point<int> pos, std::string name) : NPC(pos, name, NPCType::PrivateerType, 30, 3, 'H') {}

bool Privateer::fight (const Pirate &other) {
    return false;
}

bool Privateer::fight (const Privateer &other) {
    return false;
}

bool Privateer::fight (const Rakyat &other) {
    fightNotify(other.getName());
    return true;
}

bool Privateer::accept (std::shared_ptr<NPC> other) {
    return other->fight(*this);
}

void Privateer::move (std::size_t mapWidth, std::size_t mapHeight) {
    std::lock_guard<std::shared_mutex> lock(mtx);

    for (std::size_t i = 0; i < getMovePoints(); i++) {
        Point<int> dPos(std::rand() % 3 - 1, std::rand() % 3 - 1);
        position = position + dPos;

        if (position.getX() < 0) position.setX(0); 
        else if (position.getX() >= mapWidth) position.setX(mapWidth - 1); 
        if (position.getY() < 0) position.setY(0); 
        else if (position.getY() >= mapHeight) position.setY(mapHeight - 1); 
    }
}

std::ostream& Privateer::print (std::ostream &os) {
    os << "Privateer {" << std::endl;
    os << "\tname: " << getName() << std::endl;
    os << "\tposition: " << getPos() << std::endl;
    os << "}";

    return os;
}

std::ostream& operator<<(std::ostream &os, Privateer &privateer) {
    return privateer.print(os);
}
