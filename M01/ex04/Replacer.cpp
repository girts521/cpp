#include "Replacer.hpp"
#include <fstream>
#include <iostream>

Replacer::Replacer(std::string inFile, std::string s1, std::string s2)
    : _inFile(inFile), _outFile(inFile + ".replace"), _s1(s1), _s2(s2) {}

Replacer::~Replacer(void) {}

bool Replacer::replace(void) {
  if (this->_s1.empty()) {
    std::cerr << "Error: Search string (s1) cannot be empty." << std::endl;
    return false;
  }

  std::ifstream ifs(this->_inFile.c_str());
  if (!ifs.is_open()) {
    std::cerr << "Error: Could not open input file: " << this->_inFile
              << std::endl;
    return false;
  }

  std::ofstream ofs(this->_outFile.c_str());
  if (!ofs.is_open()) {
    std::cerr << "Error: Could not create output file: " << this->_outFile
              << std::endl;
    ifs.close();
    return false;
  }

  std::string line;
  while (std::getline(ifs, line)) {
    size_t pos = 0;
    size_t found;

    while ((found = line.find(this->_s1, pos)) != std::string::npos) {
      ofs << line.substr(pos, found - pos) << this->_s2;
      pos = found + this->_s1.length();
    }
    ofs << line.substr(pos);
    if (!ifs.eof()) {
      ofs << std::endl;
    }
  }

  ifs.close();
  ofs.close();
  return true;
}
