#pragma once
#include <set>
#include <iostream>
#include <string>
#include <memory>
#include "Observer.h"
#include "point.h"

enum NPCType {
    Unknown = 0,
    PirateType,
    PrivateerType,
    RakyatType
};

class NPC;
class Pirate;
class Privateer;
class Rakyat;

struct FightEvent {
    std::string attackerName;
    std::string defenderName;
    bool attackerWin;

    FightEvent (std::string attacker, std::string defender, bool win) : 
        attackerName{attacker}, defenderName{defender}, attackerWin{win} {};
};

class NPC : public Observable<FightEvent> {
    private:
        static std::set<std::string> usedNames;
        static std::size_t createdCount;

        std::string name;
        NPCType type;
        Point<int> position;

    protected: 
        void fightNotify (std::string defenderName, bool meWin);

    public:
        static std::size_t getCreatedCount ();

        NPC (Point<int> pos, std::string name, NPCType type);
        virtual ~NPC ();

        std::string getName () const;
        Point<int> getPos () const;
        NPCType getType () const;

        bool isClose (const std::shared_ptr<NPC> &other, double closeDistance);

        virtual bool fight (const Pirate &other) = 0;
        virtual bool fight (const Privateer &other) = 0;
        virtual bool fight (const Rakyat &other) = 0;

        virtual bool accept (std::shared_ptr<NPC> other) = 0;

        virtual std::ostream& print (std::ostream &os) = 0;

        friend std::ostream& operator<<(std::ostream &os, NPC &npc); 
};