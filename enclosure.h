#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include <memory>
#include <vector>

#include "animal.h"
#include "occupancy_record.h"
using namespace std;

class enclosure{

private:

    int cell_id;

    std::shared_ptr<animal> animal_ptr;

    std::vector<OccupancyRecord> history;

public:

    enclosure(int id);

    enclosure(int id,
              shared_ptr<animal> animal_ptr,
              vector<OccupancyRecord> history);

    bool is_vaccant();

    void add_animal(
        std::shared_ptr<animal> ptr
    );

    void remove_animal();

    void display_cell_info();

    void print_history();

    int get_cell_id();

    std::shared_ptr<animal> get_animal_ptr();

    const std::vector<OccupancyRecord>&
    get_history() const;
};

#endif