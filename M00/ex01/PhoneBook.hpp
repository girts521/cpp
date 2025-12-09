#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook 
{
  private:
    Contact *contact_list;

  public:
    PhoneBook(void);
    PhoneBook(const PhoneBook &src);
    ~PhoneBook(void);
    PhoneBook &operator=(const PhoneBook &src);
    
    void addContact(Contact current);
    void searchContact();
    
}k
