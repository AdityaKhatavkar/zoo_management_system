#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include <memory>

#include "animal.h"
#include "enclosure.h"

using namespace std;

class zoo{

private:

    std::vector<
        std::shared_ptr<animal>
    > animals;

    std::vector<enclosure>
    enclosures;

public:

    zoo();

    zoo(vector<std::shared_ptr<animal>> animals,
        std::vector<enclosure> enclosures );

    int find_animal_index(int animal_id);

    int find_enclosure_index(int cell_id);

    void assign_animal_by_id(
        int animal_id,
        int cell_id
    );

    void add_animal_to_cell(
        int id,
        bool is_veg,
        int freq,
        int food_kg,
        std::string name,
        int age
    );

    void add_enclosure(int id);

    void assign_animal(
        int animal_index,
        int enclosure_index
    );

    void  vacate_cell_by_id(int cell_id);

    void vacate_cell(
        int enclosure_index
    );

    void daily_food_report();

    void displayZoo();

    void show_cell_history_by_id(
        int enclosure_index
    );

    void save_history();
};

#endif