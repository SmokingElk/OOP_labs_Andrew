#pragma once
#include <fstream>  
#include "../NPC.h"
#include "../NPCs/Pirate.h"
#include "../NPCs/Privateer.h"
#include "../NPCs/Rakyat.h"

class FactoryFile {
    private:
        std::ifstream file;
        std::size_t countInFile;
        std::size_t countRead;

    public:
        FactoryFile (std::string filename);
        ~FactoryFile ();

        bool fileEnd ();
        std::shared_ptr<NPC> CreateNPCFromFile ();

        class NPCSaver {
            private:
                std::ofstream file;
            
            public:
                NPCSaver (std::string filename, std::size_t writeCount);
                ~NPCSaver ();

                void saveNPC (const std::shared_ptr<NPC> &npc);
        };
};