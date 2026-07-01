#define OCCUPANCY_RECORD_H

#include <string>

// Represents one stay of an animal inside a specific cell.
// m_exitDate is empty while the animal is still in the cell.
struct OccupancyRecord
{
    int m_CellId = 0;
    int m_animalId = 0;
    std::string m_animalName;
    std::string m_entryDate;
    std::string m_exitDate;
};
