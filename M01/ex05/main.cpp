#include "Harl.hpp"
#include <iostream>

int main(void) {
    Harl harl;

    std::cout << "=== Testing all valid levels ===" << std::endl
              << std::endl;

    std::cout << "--- complain(\"DEBUG\") ---" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "--- complain(\"INFO\") ---" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "--- complain(\"WARNING\") ---" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "--- complain(\"ERROR\") ---" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "=== Testing invalid level (should print nothing) ==="
              << std::endl;
    harl.complain("INVALID");
    std::cout << "(no output above this line if invalid is handled correctly)"
              << std::endl
              << std::endl;

    std::cout << "=== Testing empty string (should print nothing) ==="
              << std::endl;
    harl.complain("");
    std::cout << "(no output above this line if empty is handled correctly)"
              << std::endl;

    return 0;
}