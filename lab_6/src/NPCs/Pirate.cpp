#include "../../include/NPCs/Pirate.h"

Pirate::Pirate (Point<int> pos, std::string name) : NPC(pos, name, NPCType::PirateType) {}

bool Pirate::fight (const Pirate &other) {
    fightNotify(other.getName(), false);
    return false;
}

bool Pirate::fight (const Privateer &other) {
    fightNotify(other.getName(), true);
    return true;
}

bool Pirate::fight (const Rakyat &other) {
    fightNotify(other.getName(), false);
    return false;
}

bool Pirate::accept (std::shared_ptr<NPC> other) {
    return other->fight(*this);
}

std::ostream& Pirate::print (std::ostream &os) {
    os << "Pirate {" << std::endl;
    os << "\tname: " << getName() << std::endl;
    os << "\tposition: " << getPos() << std::endl;
    os << "}";

    return os;
}

std::ostream& operator<<(std::ostream &os, Pirate &pirate) {
    return pirate.print(os);
}