#include "animal.h"
#include <iostream>

Animal::Animal(
           bool isAnimalVeg,
           int idOfAnimal,
           int freqOfAnimalToEat,
           int foodQuantityInKg,
           int ageOfAnimal,
           std::string nameOfAnimal){

            m_isAnimalRemovedFromCell = false;
            m_isCellAssignedToAnimal = false;
            m_isAnimalHerbivorous = isAnimalVeg;
            m_animalID = idOfAnimal;
            m_assignedCellIdToAnimal = -1;
            m_animalAge = ageOfAnimal;
            m_animalName = nameOfAnimal;
    }

    //Printing Animal Specific Information.
    void Animal :: DisplayAnimalInfo(){
        std :: cout << "Name of Animal : " << m_animalName << "\n";
        std :: cout << "Age of Animal  : " << m_animalAge << "\n";
        std :: cout << "Id of Animal   : " << m_animalID << "\n";
    }

    //Assignes true if animal is assigned with a cell else assignes flase.
    void Animal :: AssignedCellToAnimal(bool value){
        m_isCellAssignedToAnimal = value;
    }

    //Returns 'True' if animal is vegeterian else return false
    bool Animal :: IsAnimalHerbivorousOrNot()const{
            return  m_isAnimalHerbivorous;
    }

    //Returns true if animal have any cell
    bool Animal :: IsCellAssignedToAnimal()const{
            return m_isCellAssignedToAnimal;
    }

    int Animal :: GetAnimalId()const{
            return m_animalID;
    } 

    int Animal :: GetAnimalAge()const{
            return m_animalAge;
    }

    int Animal :: GetFoodEatingFrequencyOfAnimal()const{
            return m_eatingFrequencyOfAnimal;
    }

    // int Animal ::  GetQuantityOfFoodAnimalNeedPerDay()const{
    //         return m_
    // }

    //Returns the name of animal 
    std::string Animal :: GetAnimalName()const{
            return m_animalName;
    }

    float Animal :: AmountOfFoodAnimalNeedPerDay()const{
        return m_eatingFrequencyOfAnimal * m_mealQuantityInKg ; 
    };