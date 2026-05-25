#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define ANIMAL_COUNT 6

int main()
{
    std::cout << "=== Test 1: Creating array of Animals (half Dogs, half Cats) ===" << std::endl;
    const Animal* animals[ANIMAL_COUNT];
    for (int i = 0; i < ANIMAL_COUNT; i++)
    {
        if (i < ANIMAL_COUNT / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << animals[i]->getType() << " created" << std::endl;
    }

    std::cout << std::endl << "=== Making sounds ===" << std::endl;
    for (int i = 0; i < ANIMAL_COUNT; i++)
        animals[i]->makeSound();

    std::cout << std::endl << "=== Deleting animals ===" << std::endl;
    for (int i = 0; i < ANIMAL_COUNT; i++)
        delete animals[i];

    std::cout << std::endl << "=== Test 2: Deep copy of Dog ===" << std::endl;
    Dog* dog1 = new Dog();
    dog1->setIdea(0, "Chase the cat!");
    dog1->setIdea(1, "Eat the treat!");

    Dog* dog2 = new Dog(*dog1); // deep copy
    Dog dog3;
    dog3 = *dog1; // deep copy assignment

    std::cout << "Original dog idea[0]: " << dog1->getIdea(0) << std::endl;
    std::cout << "Copied dog idea[0]: " << dog2->getIdea(0) << std::endl;
    std::cout << "Assigned dog idea[0]: " << dog3.getIdea(0) << std::endl;

    delete dog1;
    delete dog2;
    // dog3 destroyed automatically

    std::cout << std::endl << "=== Test 3: Deep copy of Cat ===" << std::endl;
    Cat* cat1 = new Cat();
    cat1->setIdea(0, "Sleep on the sofa!");
    cat1->setIdea(1, "Knock things off the table!");

    Cat* cat2 = new Cat(*cat1);
    std::cout << "Original cat idea[1]: " << cat1->getIdea(1) << std::endl;
    std::cout << "Copied cat idea[1]: " << cat2->getIdea(1) << std::endl;

    delete cat1;
    delete cat2;

    return 0;
}
