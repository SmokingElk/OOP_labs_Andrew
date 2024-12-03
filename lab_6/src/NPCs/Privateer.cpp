#include "../../include/NPCs/Privateer.h"

Privateer::Privateer (Point<int> pos, std::string name) : NPC(pos, name, NPCType::PrivateerType) {}

bool Privateer::fight (const Pirate &other) {
    fightNotify(other.getName(), false);
    return false;
}

bool Privateer::fight (const Privateer &other) {
    fightNotify(other.getName(), false);
    return false;
}

bool Privateer::fight (const Rakyat &other) {
    fightNotify(other.getName(), true);
    return true;
}

bool Privateer::accept (std::shared_ptr<NPC> other) {
    return other->fight(*this);
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
