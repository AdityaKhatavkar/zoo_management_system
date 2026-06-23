#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class animal{

private:

    int animal_id;
    bool is_herbivorous;
    int eating_frequency;
    int meal_size_kg;

    std::string animal_name;
    int animal_age;

    bool animal_is_alive;
    bool animal_removed;

    bool assigned;

public:

    animal(int id,
           bool is_veg,
           int freq,
           int food_kg,
           std::string name,
           int age);

    bool is_veg();

    int daily_food_requirement();

    void update_animal_info(
        bool is_living,
        bool to_remove,
        int age
    );

    void display_animal_info();

    int get_id();

    std::string get_name();

    void set_assigned(bool value);

    bool is_assigned() const;
};

#endif