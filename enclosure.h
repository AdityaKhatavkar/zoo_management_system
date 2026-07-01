#define ENCLOSURE_H

#include <memory>
#include <vector>

#include "animal.h"
#include "occupancy_record.h"

class Enclosure
{
private:
    // Each cell has a unique ID number
    int m_uniqueCellId;

    // The animal currently occupying this cell (nullptr if vacant)
    std::shared_ptr<Animal> m_animalPtr;

    // All past and present occupancy records for this cell
    std::vector<OccupancyRecord> m_history;

public:
    // animal_ptr and history default so this can be constructed from just
    // a cell ID (e.g. when restoring enclosures from enclosures.csv).
    explicit Enclosure(int id,
                        std::shared_ptr<Animal> animal_ptr = nullptr,
                        std::vector<OccupancyRecord> history = {});

    // Adds an animal to the cell and opens a new history record
    void AddAnimalToCell(std::shared_ptr<Animal> ptr);

    // Removes the animal from the cell and closes the current history record
    void RemoveAnimalFromCell();

    // Appends a pre-built history record (used when restoring from disk)
    void AddHistoryRecord(const OccupancyRecord& rec);

    // Display cell specific information
    void DisplayCellInfo() const;

    // Print record of animals that have occupied this cell
    void PrintHistoryOfCell() const;

    // Returns true if the cell is vacant
    bool IsCellVaccantOrNot() const;

    // Returns the unique ID number of the cell
    int GetCellId() const;

    // Returns the animal pointer (nullptr if vacant)
    std::shared_ptr<Animal> GetAnimalPtr();

    // Returns the history of this cell
    const std::vector<OccupancyRecord>& GetHistory() const;
};
