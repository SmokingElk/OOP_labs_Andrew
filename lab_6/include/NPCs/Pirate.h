#pragma once
#include "../NPC.h"
#include "Privateer.h"
#include "Rakyat.h"

class Pirate : public NPC {
    public:
        Pirate (Point<int> pos, std::string name);

        bool fight (const Pirate &other) override;
        bool fight (const Privateer &other) override;
        bool fight (const Rakyat &other) override;

        bool accept (std::shared_ptr<NPC> other) override;

        std::ostream& print (std::ostream &os) override;

        friend std::ostream& operator<<(std::ostream &os, Pirate &pirate); 
};