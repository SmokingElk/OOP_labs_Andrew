#pragma once
#include "../NPC.h"
#include "Pirate.h"
#include "Privateer.h"

class Rakyat : public NPC {
    public:
        Rakyat (Point<int> pos, std::string name);

        bool fight (const Pirate &other) override;
        bool fight (const Privateer &other) override;
        bool fight (const Rakyat &other) override;

        bool accept (std::shared_ptr<NPC> other) override;

        void move (std::size_t mapWidth, std::size_t mapHeight) override;

        std::ostream& print (std::ostream &os) override;

        friend std::ostream& operator<<(std::ostream &os, Rakyat &rakyat); 
};