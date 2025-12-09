#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook(void) {
  std::cout << "The default constructor has been called" << std::endl;
  this->_index = 0;
}

PhoneBook::PhoneBook(const PhoneBook &src) : _index(src._index) {
  std::cout << "The copy constructor has been called" << std::endl;

  for (int i = 0; i < 8; i++)
    this->_contact_list[i] = src._contact_list[i];
}

PhoneBook::~PhoneBook(void) {
  std::cout << "The destructor has been called" << std::endl;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &src) {
  std::cout << "The assignment operator has been called" << std::endl;
  if (this == &src)
    return *this;

  this->_index = src._index;

  for (int i = 0; i < 8; i++)
    this->_contact_list[i] = src._contact_list[i];

  return *this;
}

void PhoneBook::addContact(void) {
  std::cout << "Adding a new contact" << std::endl;

  Contact *new_contact = new Contact();

  // i need to ask and get the input for everything in a contact
  std::cout << "Please enter your name: ";
  std::getline(std::cin, new_contact->name);
  std::cout << std::endl;

  std::cout << "Please enter your last name: ";
  std::getline(std::cin, new_contact->last_name);
  std::cout << std::endl;

  std::cout << "Please enter your nickname: ";
  std::getline(std::cin, new_contact->nickname);
  std::cout << std::endl;

  std::cout << "Please enter your phone number: ";
  std::getline(std::cin, new_contact->phone_number);
  std::cout << std::endl;
  // before adding I have to check the index and if its less than 8 then add but
  // if its 8 then rewrite the olderst (index 0) basically i can just restart
  // the index and keep going.
  if (_index == 7)
    _index = 0;
  // then i add that new contact into the array of contacts
  _contact_list[_index] = *new_contact;
}

void searchContact(void) {
  std::cout << "Searching for a contact" << std::endl;
}
