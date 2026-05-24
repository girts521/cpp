#include "Harl.hpp"
#include <iostream>
#include <string>

static int getLevelIndex(const std::string &level) {
    std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    for (int i = 0; i < 4; i++) {
        if (level == levels[i])
            return i;
    }
    return -1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
        std::cerr << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }

    Harl harl;
    int level = getLevelIndex(argv[1]);

    switch (level) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
            std::cout << std::endl;
            // fall through
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
            std::cout << std::endl;
            // fall through
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
            std::cout << std::endl;
            // fall through
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
            break;
    }

    return 0;
}
