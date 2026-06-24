#ifndef OCCUPANCY_RECORD_H
#define OCCUPANCY_RECORD_H

#include <string>

class OccupancyRecord{

public:

    int m_CellId;
    int m_animalId;

    std::string m_animalName;

    std::string m_entryDate;
    std::string m_exitDate;
};

#endif