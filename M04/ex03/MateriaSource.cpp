#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
        templates[i] = NULL;
    for (int i = 0; i < 4; i++)
    {
        if (other.templates[i] != NULL)
            templates[i] = other.templates[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        clearTemplates();
        for (int i = 0; i < 4; i++)
        {
            if (other.templates[i] != NULL)
                templates[i] = other.templates[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    clearTemplates();
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == NULL)
        {
            templates[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != NULL && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    return 0;
}

void MateriaSource::clearTemplates()
{
    for (int i = 0; i < 4; i++)
    {
        delete templates[i];
        templates[i] = NULL;
    }
}
