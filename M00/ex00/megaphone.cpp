#include <iostream>
#include <cctype>
#include <string>

void toUpperCase(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
      str[i] = std::toupper(str[i]);
}

int main(int ac, char **av)
{
  if (ac > 1 && av[1])
  {
    std::string str = av[1];
    toUpperCase(str);
    std::cout << str << std::endl;
  }
  return (0);
}
