#define ZOO_H

#include <vector>
#include <memory>
#include <sstream>
#include <string>

#include "animal.h"
#include "enclosure.h"

class Zoo
{
private:
    std::vector<std::shared_ptr<Animal>> m_animals;
    std::vector<Enclosure> m_enclosures;

public:
    // Default constructor: starts empty and loads any saved state from disk
    // (animals.csv / enclosures.csv / cell_history.csv), if present.
    Zoo();

    // Also allow constructing from existing in-memory data.
    Zoo(std::vector<std::shared_ptr<Animal>>& animals,
        std::vector<Enclosure>& enclosures);

    // Creates a new animal and adds it (unassigned) to the zoo.
    void AddAnimalToCell(int id,
                          bool isHerbivore,
                          int mealsPerDay,
                          float mealSizeKg,
                          const std::string& name,
                          int age);

    // Creates a new, empty enclosure with the given cell ID.
    void AddEnclosure(int cellId);

    // Assigns an existing animal (by ID) to an existing, vacant cell (by ID).
    void AssignAnimalById(int animalId, int cellId);

    // Vacates whichever animal currently occupies the given cell.
    void VacateCellById(int cellId);

    // Prints total daily green-food / meat-food requirements across the zoo.
    void DailyFoodReport();

    // Prints info for every animal in the zoo.
    void DisplayZoo();

    // Prints the occupancy history for the cell with the given ID.
    void ShowCellHistoryById(int cellId);

    void SaveHistory();
    void SaveAnimals();
    void SaveEnclosures();

    void RestoreAnimals();
    void RestoreEnclosures();
    void RestoreHistory();
};
