#include <string>

class Animal{

private:

    // Is animal removed from the cell
    bool m_isAnimalRemovedFromCell;

    // Is cell assigned to the animla
    bool m_isCellAssignedToAnimal;

    // Does animal eat greenfood or not
    bool m_isAnimalHerbivorous;

    // Each animal have a unique ID number
    int m_animalID;

    // Each animal have a CellId in which he lives.
    int m_assignedCellIdToAnimal;

    // How many times perticular animal eats in a day
    int m_eatingFrequencyOfAnimal;

    // How old animal is? 
    int m_animalAge;

    // Name of animal (lion, elephant, wolf, fox)
    std::string m_animalName;

    // How much kg food (greenstuff or meat) animal eat a single time.
    float m_mealQuantityInKg;

    

public:
    
    //Constructor of class 'Animal'
    Animal(bool isAnimalVeg,
           int idOfAnimal,
           int freqOfAnimalToEat,
           int foodQuantityInKg,
           int ageOfAnimal,
           std::string nameOfAnimal);

    //Change the animal specific information ( age increases, )
    void UpdateAnimalInfo(
        bool is_living,
        bool to_remove,
        int age
    );

    //Printing Animal Specific Information.
    void DisplayAnimalInfo();

    //Assignes true if animal is assigned with a cell else assignes flase.
    void AssignedCellToAnimal(bool value);

    //Returns 'True' if animal is vegeterian else return false
    bool IsAnimalHerbivorousOrNot()const;

    //Returns true if animal have any cell
    bool IsCellAssignedToAnimal() const;

    //Returns the unique Id number of animal
    int GetAnimalId()const; 

    //Returns the age of animal
    int GetAnimalAge()const;

    //Returns number of times animal eat in a single day.
    int GetFoodEatingFrequencyOfAnimal()const;

    //Returns quantity of food animal eats single time.
    int GetQuantityOfFoodAnimalNeedPerDay()const;

    //Returns the name of animal 
    std::string GetAnimalName()const;    

    //Returns the Amount of Food Animal need to eat in a single day.
    float AmountOfFoodAnimalNeedPerDay()const;

};
