#include "animal.h"
#include <iostream>

Animal::Animal(int idOfAnimal,
               bool isAnimalVeg,
               int freqOfAnimalToEat,
               float mealQuantityInKg,
               const std::string& nameOfAnimal,
               int ageOfAnimal)
{
    m_animalID = idOfAnimal;
    m_isAnimalHerbivorous = isAnimalVeg;
    m_eatingFrequencyOfAnimal = freqOfAnimalToEat;
    m_mealQuantityInKg = mealQuantityInKg;
    m_animalName = nameOfAnimal;
    m_animalAge = ageOfAnimal;
    m_assignedCellIdToAnimal = -1;
}

void Animal::DisplayAnimalInfo() const
{
    std::cout << "Name of Animal : " << m_animalName << "\n";
    std::cout << "Age of Animal  : " << m_animalAge << "\n";
    std::cout << "Id of Animal   : " << m_animalID << "\n";
    std::cout << "Diet           : " << (m_isAnimalHerbivorous ? "Herbivore" : "Carnivore") << "\n";
    std::cout << "Assigned Cell  : "
               << (m_assignedCellIdToAnimal == -1 ? std::string("None")
                                                   : std::to_string(m_assignedCellIdToAnimal))
               << "\n";
}

void Animal::AssignedCellToAnimal(int cellId)
{
    m_assignedCellIdToAnimal = cellId;
}

bool Animal::IsAnimalHerbivorousOrNot() const
{
    return m_isAnimalHerbivorous;
}

int Animal::IsCellAssignedToAnimal() const
{
    return m_assignedCellIdToAnimal;
}

int Animal::GetAnimalId() const
{
    return m_animalID;
}

int Animal::GetAnimalAge() const
{
    return m_animalAge;
}

int Animal::GetFoodEatingFrequencyOfAnimal() const
{
    return m_eatingFrequencyOfAnimal;
}

std::string Animal::GetAnimalName() const
{
    return m_animalName;
}

float Animal::AmountOfFoodAnimalNeedPerDay() const
{
    return m_eatingFrequencyOfAnimal * m_mealQuantityInKg;
}

float Animal::GetMealSizeKg() const
{
    return m_mealQuantityInKg;
}