#include "../../include/NPCs/Rakyat.h"

Rakyat::Rakyat (Point<int> pos, std::string name) : NPC(pos, name, NPCType::RakyatType) {}

bool Rakyat::fight (const Pirate &other) {
    fightNotify(other.getName(), true);
    return true;
}

bool Rakyat::fight (const Privateer &other) {
    fightNotify(other.getName(), false);
    return false;
}

bool Rakyat::fight (const Rakyat &other) {
    fightNotify(other.getName(), false);
    return false;
}

bool Rakyat::accept (std::shared_ptr<NPC> other) {
    return other->fight(*this);
}

std::ostream& Rakyat::print (std::ostream &os) {
    os << "Rakyat {" << std::endl;
    os << "\tname: " << getName() << std::endl;
    os << "\tposition: " << getPos() << std::endl;
    os << "}";

    return os;
}

std::ostream& operator<<(std::ostream &os, Rakyat &rakyat) {
    return rakyat.print(os);
}