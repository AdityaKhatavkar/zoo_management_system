#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include <memory>
#include <sstream>
#include <string>

#include "animal.h"
#include "enclosure.h"

class zoo{

private:

    std::vector<std::shared_ptr<animal>> m_animals;

    std::vector<enclosure> m_enclosures;

public:

    zoo();

    zoo(std::vector<std::shared_ptr<animal>> animals,
        std::vector<enclosure> enclosures );

    int FindAnimalIndex(int m_animalId);

    int FindEnclosureIndex(int m_cellId);

    void AssignAnimalById(
        int m_animalId,
        int cell_id
    );

    void AddAnimalToCell(
        int id,
        bool is_veg,
        int freq,
        int food_kg,
        std::string name,
        int age
    );

    void AddEnclosure(int id);

    void AssignAnimal(
        int animal_index,
        int enclosure_index
    );

    void  VacateCellById(int cell_id);

    void VacateCell(
        int enclosure_index
    );

    void DailyFoodReport();

    void DisplayZoo();

    void ShowCellHistoryById(
        int enclosure_index
    );

    void SaveHistory();

    void SaveAnimals();

    void SaveEnclosures();

    void RestoreAnimals();

    void RestoreEnclosures();

    void RestoreHistory();
};

#endif