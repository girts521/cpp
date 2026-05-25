#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    // Uncommenting the line below would cause a compilation error:
    // const AAnimal* animal = new AAnimal(); // ERROR: abstract class

    std::cout << "=== Test 1: Create Dogs and Cats (not AAnimal) ===" << std::endl;
    const Dog* dog = new Dog();
    const Cat* cat = new Cat();

    std::cout << dog->getType() << " says: ";
    dog->makeSound();
    std::cout << cat->getType() << " says: ";
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << std::endl << "=== Test 2: Polymorphism via AAnimal pointers ===" << std::endl;
    const AAnimal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++)
    {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << std::endl << "=== Test 3: Deep copy ===" << std::endl;
    Dog originalDog;
    originalDog.setIdea(0, "Catch the ball!");
    Dog copyDog(originalDog);
    std::cout << "Original idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copy idea: " << copyDog.getIdea(0) << std::endl;

    std::cout << std::endl << "=== Test 4: Cats with ideas ===" << std::endl;
    Cat cleverCat;
    cleverCat.setIdea(0, "Knock glass off table!");
    cleverCat.setIdea(1, "Blame the dog!");
    std::cout << "Cat idea[0]: " << cleverCat.getIdea(0) << std::endl;
    std::cout << "Cat idea[1]: " << cleverCat.getIdea(1) << std::endl;

    return 0;
}
