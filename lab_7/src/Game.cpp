#include "../include/Game.h"

using namespace std::chrono_literals;

Game::Game (std::size_t width, std::size_t height) : mapWidth{width}, mapHeight{height} {
    screenOut = std::make_shared<ObserverStdout>();
    screenMurderOut = std::make_shared<ObserverMurderStdout>();
    fileOut = std::make_shared<ObserverFile>("log.txt");
}

void Game::init (std::size_t unitsCount) {
    units.clear();

    FactoryRandom factory(mapWidth, mapHeight);

    for (int i = 0; i < unitsCount; i++) {
        auto npc = factory.CreateRandomNPC();
        npc->subscribe(fileOut);
        units.insert(npc);
    }
}

void Game::saveState (std::string filename) {
    FactoryFile::NPCSaver saver(filename, units.size());

    for (const auto &npc : units) {
        saver.saveNPC(npc);
    }
}

void Game::loadState (std::string filename) {
    units.clear();

    FactoryFile factory(filename);

    while (!factory.fileEnd()) {
        auto npc = factory.CreateNPCFromFile();
        npc->subscribe(fileOut);
        units.insert(npc);
    }
}

void Game::render () {
    Printer printer;

    std::vector<char> cells(mapWidth * mapHeight, ' ');

    for (auto const &npc : units) {
        if (!npc->isAlive()) continue;

        Point pos = npc->getPos();
        cells[pos.getY() * mapWidth + pos.getX()] = npc->getSprite();
    }

    printer << "\n\n\n";

    for (std::size_t y = 0; y < mapHeight; y++) {
        for (std::size_t x = 0; x < mapWidth; x++) {
            printer << "[" << cells[y * mapWidth + x] << "]";
        }

        printer << '\n';
    }
}

void Game::battle (bool printMurderLog) {
    bool gameRunning = true;

    FightManager fightManager;

    if (printMurderLog) {
        fightManager.subscribe(screenMurderOut);
    }

    render();

    std::thread threadFight(std::ref(fightManager), std::ref(gameRunning));

    std::thread threadMove([&fightManager, &gameRunning](std::size_t mapWidth, std::size_t mapHeight, NPCSet &units){
        while (gameRunning) {
            for (auto &npc : units) {
                if (npc->isAlive()) npc->move(mapWidth, mapHeight);
            }

            for (auto &attacker : units) {
                for (auto &defender : units) {
                    if (!attacker->isAlive() || 
                        !defender->isAlive() || 
                        attacker == defender || 
                        !attacker->isClose(defender) || 
                        !defender->accept(attacker)) continue;

                    fightManager.addFightPrompt(FightManager::FightPrompt(attacker, defender));
                }
            }

            std::this_thread::sleep_for(200ms);
        }
    }, mapWidth, mapHeight, std::ref(units));

    std::size_t frames = 0;

    while (frames++ < 30) {
        std::this_thread::sleep_for(1s);
        render();
    }

    gameRunning = false;
    
    threadMove.join();
    threadFight.join();
}

std::ostream& operator<< (std::ostream &os, Game &game) {
    for (const auto &npc : game.units) {
        if (npc->isAlive()) os << *npc << std::endl;
        
    }

    return os;
}