#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
  Contact _contact_list[8];
  int _index;

public:
  PhoneBook(void);
  PhoneBook(const PhoneBook &src);
  ~PhoneBook(void);
  PhoneBook &operator=(const PhoneBook &src);

  void addContact(void);
  void searchContact(void);
};

#endif
