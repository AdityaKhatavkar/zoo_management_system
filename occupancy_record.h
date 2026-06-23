#ifndef OCCUPANCY_RECORD_H
#define OCCUPANCY_RECORD_H

#include <string>

class OccupancyRecord{

public:

    int cell_id;
    int animal_id;

    std::string animal_name;

    std::string entry_date;
    std::string exit_date;
};

#endif