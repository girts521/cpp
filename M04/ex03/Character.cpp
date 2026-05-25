#include "Character.hpp"
#include <iostream>

Character::Character() : name("default"), floorCount(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    for (int i = 0; i < 100; i++)
        floor[i] = NULL;
}

Character::Character(std::string const & name) : name(name), floorCount(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    for (int i = 0; i < 100; i++)
        floor[i] = NULL;
}

Character::Character(const Character& other) : name(other.name), floorCount(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    for (int i = 0; i < 100; i++)
        floor[i] = NULL;
    copyInventory(other);
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        clearInventory();
        clearFloor();
        name = other.name;
        floorCount = 0;
        copyInventory(other);
    }
    return *this;
}

Character::~Character()
{
    clearInventory();
    clearFloor();
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
    // Inventory full - Materia is lost (subject says nothing should happen)
    // But to avoid leaks, we save it to floor
    if (floorCount < 100)
        floor[floorCount++] = m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    if (inventory[idx] != NULL)
    {
        // Put on floor to avoid leak (subject says unequip must NOT delete)
        if (floorCount < 100)
            floor[floorCount++] = inventory[idx];
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (inventory[idx] != NULL)
        inventory[idx]->use(target);
}

void Character::clearInventory()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
        inventory[i] = NULL;
    }
}

void Character::clearFloor()
{
    for (int i = 0; i < floorCount; i++)
    {
        delete floor[i];
        floor[i] = NULL;
    }
    floorCount = 0;
}

void Character::copyInventory(const Character& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i] != NULL)
            inventory[i] = other.inventory[i]->clone();
    }
}
