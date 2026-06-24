#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include <memory>
#include <vector>

#include "animal.h"
#include "occupancy_record.h"

class enclosure{

private:

    int m_cellId;

    std::shared_ptr<animal> m_animalPtr;

    std::vector<OccupancyRecord> m_history;

public:

    enclosure(int id);

    enclosure(int id,
              std::shared_ptr<animal> animal_ptr,
              std::vector<OccupancyRecord> history);

    bool IsVaccant();

    void AddAnimal(
        std::shared_ptr<animal> ptr
    );

    void RemoveAnimal();

    void DisplayCellInfo();

    void PrintHistory();

    int GetCellId();

    std::shared_ptr<animal> GetAnimalPtr();

    const std::vector<OccupancyRecord>&
    GetHistory() const;

    void AddHistoryRecord(
    const OccupancyRecord& rec
);

    
};

#endif