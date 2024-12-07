#include "../../include/factories/FactoryFile.h"

FactoryFile::FactoryFile (std::string filename) {
    file.open(filename);
    if (!file.is_open()) throw std::ios_base::failure("Failed to open file.");

    file >> countInFile;
    countRead = 0;
}

FactoryFile::~FactoryFile () {
    if (file.is_open()) file.close();
}

bool FactoryFile::fileEnd () {
    return countRead >= countInFile;
}

std::shared_ptr<NPC> FactoryFile::CreateNPCFromFile () {
    if (fileEnd()) throw std::logic_error("End of file reached.");

    int typeNumber, x, y;
    std::string name;

    file >> typeNumber;
    file >> x;
    file >> y;
    file.get();
    std::getline(file, name);
    countRead++;

    NPCType type = NPCType(typeNumber);
    Point<int> pos(x, y);

    switch (type) {
        case NPCType::PirateType:
            return std::make_shared<Pirate>(pos, name);

        case NPCType::PrivateerType:
            return std::make_shared<Privateer>(pos, name);

        case NPCType::RakyatType:
            return std::make_shared<Rakyat>(pos, name);
        
        default:
            throw std::logic_error("Unknown NPC type.");
    }
}

FactoryFile::NPCSaver::NPCSaver (std::string filename, std::size_t writeCount) {
    file.open(filename);
    if (!file.is_open()) throw std::ios_base::failure("Failed to open file.");

    file << writeCount << std::endl;
}

FactoryFile::NPCSaver::~NPCSaver () {
    if (file.is_open()) file.close();
}

void FactoryFile::NPCSaver::saveNPC (const std::shared_ptr<NPC> &npc) {
    file << static_cast<int>(npc->getType()) << std::endl;

    Point pos = npc->getPos();
    file << pos.getX() << std::endl;
    file << pos.getY() << std::endl;

    file << npc->getName() << std::endl;
}