#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Subject main test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << std::endl << "=== Test 2: Unequip and re-equip ===" << std::endl;
    src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    me = new Character("hero");
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);

    me->unequip(1); // unequip cure
    me->use(1); // should do nothing
    me->equip(src->createMateria("cure"));
    me->use(1, *bob); // should work again

    delete me;
    delete src;

    std::cout << std::endl << "=== Test 3: Unknown materia ===" << std::endl;
    src = new MateriaSource();
    src->learnMateria(new Ice());
    tmp = src->createMateria("fire"); // unknown
    if (tmp == NULL)
        std::cout << "Unknown materia type returns NULL correctly" << std::endl;

    delete src;

    std::cout << std::endl << "=== Test 4: Deep copy of Character ===" << std::endl;
    src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Character original("Girts");
    original.equip(src->createMateria("ice"));
    original.equip(src->createMateria("cure"));

    Character copy(original);
    copy.use(0, original); // should show ice bolt at Girts
    copy.use(1, original);

    Character assigned("temp");
    assigned = original;
    assigned.use(0, original);

    delete src;

    return 0;
}
