#pragma once
#define ANIMAL_H

#include <string>

class Animal
{
private:
    // Does animal eat greenfood or not
    bool m_isAnimalHerbivorous;

    // Each animal has a unique ID number
    int m_animalID;

    // ID of the cell this animal currently lives in, or -1 if unassigned.
    // This single field is the one source of truth for assignment status
    // (previously there was also a separate, disconnected bool for this).
    int m_assignedCellIdToAnimal;

    // How many times this animal eats in a day
    int m_eatingFrequencyOfAnimal;

    // How old the animal is
    int m_animalAge;

    // Name of animal (lion, elephant, wolf, fox)
    std::string m_animalName;

    // How much food (kg) the animal eats per meal
    float m_mealQuantityInKg;

public:
    // Parameter order matches how the animal is created from user input
    // and how it is restored from animals.csv: id, veg, freq, meal, name, age
    Animal(int idOfAnimal,
           bool isAnimalVeg,
           int freqOfAnimalToEat,
           float mealQuantityInKg,
           const std::string& nameOfAnimal,
           int ageOfAnimal);

    // Printing Animal Specific Information.
    void DisplayAnimalInfo() const;

    // Sets the cell this animal is assigned to. Pass -1 to clear.
    void AssignedCellToAnimal(int cellId);

    // Returns 'True' if animal is vegetarian, else returns false
    bool IsAnimalHerbivorousOrNot() const;

    // Returns the cell ID the animal is assigned to, or -1 if none.
    int IsCellAssignedToAnimal() const;

    // Returns the unique ID number of animal
    int GetAnimalId() const;

    // Returns the age of animal
    int GetAnimalAge() const;

    // Returns number of times animal eats in a single day.
    int GetFoodEatingFrequencyOfAnimal() const;

    // Returns the name of animal
    std::string GetAnimalName() const;

    // Returns the amount of food the animal needs to eat in a single day.
    float AmountOfFoodAnimalNeedPerDay() const;

    // Returns how much food (kg) the animal eats per single meal.
    float GetMealSizeKg() const;
};
