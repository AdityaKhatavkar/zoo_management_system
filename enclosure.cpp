#include "enclosure.h"
#include "utility.h"

#include <iostream>

using namespace std;

// Constructor 1
enclosure::enclosure(int id)
{
    cell_id = id;
    animal_ptr = nullptr;
}

//Constructor 2
enclosure::enclosure(
    int id,
    shared_ptr<animal> animal_pointer,
    vector<OccupancyRecord> history_)
{
    cell_id = id;
    animal_ptr = animal_pointer;
    history = history_;
}



bool enclosure::is_vaccant()
{
    return animal_ptr == nullptr;
}

void enclosure::add_animal(shared_ptr<animal> ptr)
{
    animal_ptr = ptr;

    OccupancyRecord rec;

    rec.cell_id = cell_id;
    rec.animal_id = animal_ptr->get_id();
    rec.animal_name = animal_ptr->get_name();

    rec.entry_date = current_date();

    history.push_back(rec);
}

void enclosure::remove_animal()
{
    if (!history.empty())
    {
        history.back().exit_date = current_date();
    }

    animal_ptr = nullptr;
}

void enclosure::display_cell_info()
{
    cout << "Cell ID : " << cell_id << endl;

    if (animal_ptr)
    {
        animal_ptr->display_animal_info();
    }
    else
    {
        cout << "Cell is empty" << endl;
    }
}

void enclosure::print_history()
{
    cout << "\nHistory of Cell "
         << cell_id << endl;

    for (auto &r : history)
    {
        cout << r.animal_name
             << " ("
             << r.animal_id
             << ") ";

        cout << " From "
             << r.entry_date
             << " To "
             << r.exit_date
             << endl;
    }
}

int enclosure::get_cell_id()
{
    return cell_id;
}

shared_ptr<animal> enclosure::get_animal_ptr()
{
    return animal_ptr;
}

const vector<OccupancyRecord>& enclosure::get_history() const
{
    return history;
}