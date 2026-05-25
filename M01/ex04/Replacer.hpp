#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>

class Replacer {
private:
  std::string _inFile;
  std::string _outFile;
  std::string _s1;
  std::string _s2;

public:
  Replacer(std::string inFile, std::string s1, std::string s2);
  ~Replacer(void);

  bool replace(void);
};

#endif
