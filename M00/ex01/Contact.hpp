#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
  std::string darkest_secret;

public:
  std::string name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;

  Contact(void);
  Contact(const Contact &src);
  ~Contact(void);
  Contact &operator=(const Contact &src);
};
#endif
