#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
  private:
    std::string darkest_secret;
  public:
    std::string name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;

    // 1. Default (No args)
    Contact(void); 

    // 2. Copy (Reference to another Contact)
    Contact(const Contact &src);

    // 3. Assignment Operator (We will cover this next)
    Contact &operator=(const Contact &src);

    // 4. Destructor (Cleanup)
    ~Contact(void);
};
#endif
