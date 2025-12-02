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
  if (ac < 2)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }
  for (int i = 1; av[i]; i++)
  {
    std::string str = av[i];
    toUpperCase(str);
    std::cout << str;
  }
  std::cout << std::endl;
  return (0);
}
