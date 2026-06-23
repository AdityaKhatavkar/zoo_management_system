#include "animal.h"

#include <iostream>

using namespace std;

animal::animal(
    int id,
    bool is_veg,
    int freq,
    int food_kg,
    string name,
    int age
)
{
    animal_id = id;
    animal_name = name;
    animal_age = age;

    is_herbivorous = is_veg;
    eating_frequency = freq;
    meal_size_kg = food_kg;

    animal_is_alive = true;
    animal_removed = false;

    assigned = false;
}

bool animal::is_veg()
{
    return is_herbivorous;
}

int animal::daily_food_requirement()
{
    return eating_frequency * meal_size_kg;
}

void animal::update_animal_info(
    bool is_living,
    bool to_remove,
    int age
)
{
    animal_is_alive = is_living;
    animal_removed = to_remove;
    animal_age = age;
}

void animal::display_animal_info()
{
    cout << "Animal ID : "
         << animal_id << endl;

    cout << "Animal Name : "
         << animal_name << endl;

    cout << "Animal Age : "
         << animal_age << endl;
}

int animal::get_id()
{
    return animal_id;
}

string animal::get_name()
{
    return animal_name;
}

void animal::set_assigned(bool value)
{
    assigned = value;
}

bool animal::is_assigned() const
{
    return assigned;
}   