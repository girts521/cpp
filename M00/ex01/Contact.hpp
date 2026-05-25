#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
  std::string _darkest_secret;
  std::string name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;

public:
  Contact(void);
  Contact(const Contact &src);
  ~Contact(void);
  Contact &operator=(const Contact &src);

  std::string getName(void) const;
  std::string getLastName(void) const;
  std::string getNickname(void) const;
  std::string getPhoneNumber(void) const;
  std::string getDarkestSecret(void) const;

  void setName(void);
  void setLastName(void);
  void setNickname(void);
  void setPhoneNumber(void);
  void setDarkestSecret(void);
};

#endif
