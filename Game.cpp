#include "Game.h"

#include <iostream>
#include <string>

Game::Game() : hero_(20), enemy_(24), potions_(2) {}

void Game::printState() const {
    std::cout << "STATE "
              << hero_.hp() << ' '
              << enemy_.hp() << ' '
              << potions_ << '\n';
}

void Game::run() {
    std::string command;

    while (std::getline(std::cin, command)) {
        if (command == "ATTACK") {
            enemy_.takeDamage(6);

            if (!enemy_.alive()) {
                std::cout << "WIN\n";
                return;
            }

            hero_.takeDamage(5);

            if (!hero_.alive()) {
                std::cout << "LOSE\n";
                return;
            }

            printState();
        } else if (command == "HEAL") {
            if (potions_ == 0) {
                std::cout << "NO_POTIONS\n";
                continue;
            }

            --potions_;
            hero_.heal(8);
            hero_.takeDamage(5);

            if (!hero_.alive()) {
                std::cout << "LOSE\n";
                return;
            }

            printState();
        } else if (command == "STATUS") {
            printState();
        } else if (command == "QUIT") {
            std::cout << "BYE\n";
            return;
        } else {
            std::cout << "ERROR\n";
        }
    }
}