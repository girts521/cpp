#include <iostream>
#include <string>

int main(void)
{
    std::string stringVAR = "HI THIS IS BRAIN";

    std::string *stringPTR = &stringVAR;

    std::string &stringREF = stringVAR;

    std::cout << "--- MEMORY ADDRESSES ---" << std::endl;
    std::cout << "Address of string variable: " << &stringVAR << std::endl;
    std::cout << "Address held by stringPTR:  " << stringPTR << std::endl;
    std::cout << "Address held by stringREF:  " << &stringREF << std::endl;

    std::cout << "\n--- VALUES ---" << std::endl;
    std::cout << "Value of string variable:   " << stringVAR << std::endl;
    std::cout << "Value pointed to by PTR:    " << *stringPTR << std::endl;
    std::cout << "Value pointed to by REF:    " << stringREF << std::endl;

    return 0;
}
