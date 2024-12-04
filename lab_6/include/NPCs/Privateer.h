#pragma once
#include "../NPC.h"
#include "Pirate.h"
#include "Rakyat.h"

class Privateer : public NPC {
    public:
        Privateer (Point<int> pos, std::string name);

        bool fight (const Pirate &other) override;
        bool fight (const Privateer &other) override;
        bool fight (const Rakyat &other) override;

        bool accept (std::shared_ptr<NPC> other) override;

        std::ostream& print (std::ostream &os) override;

        friend std::ostream& operator<<(std::ostream &os, Privateer &privateer); 
};