#include <iostream>
#include "Contact.hpp"

int main(void)
{
  Contact a;
  Contact c;
  Contact b(a);
  c = b;
}
