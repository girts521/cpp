#include "Replacer.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./sed_is_for_losers <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    Replacer replacer(argv[1], argv[2], argv[3]);
    
    if (!replacer.replace()) {
        return 1;
    }

    return 0;
}
