#include "zoo.h"

#include <iostream>
#include <fstream>

using namespace std;

zoo :: zoo (){}

zoo::zoo(vector<shared_ptr<animal>> animals_,
    vector<enclosure> enclosures_){
        animals = animals_;
        enclosures = enclosures_;
    }

    // Helper Functions :
    int zoo :: find_animal_index(int animal_id)
    {

        for (int i = 0; i < animals.size(); i++)
        {

            if (animals[i]->get_id() == animal_id)
            {
                return i;
            }
        }

        return -1;
    }

    int zoo :: find_enclosure_index(int cell_id)
    {

        for (int i = 0; i < enclosures.size(); i++)
        {

            if (enclosures[i].get_cell_id() == cell_id)
            {
                return i;
            }
        }

        return -1;
    }

    // Zoo functionalities

    void zoo :: add_animal_to_cell(int id,
                            bool is_veg,
                            int freq,
                            int food_kg,
                            string name,
                            int age)
    {

        for (auto &a : animals)
        {

            if (a->get_id() == id)
            {

                cout << "Animal ID already exists!\n";
                return;
            }
        }

        animals.push_back(
            make_shared<animal>(
                id,
                is_veg,
                freq,
                food_kg,
                name,
                age));

        cout << "Animal added successfully.\n";
    }

    void zoo :: add_enclosure(int id)
    {

        for (auto &e : enclosures)
        {

            if (e.get_cell_id() == id)
            {

                cout << "Cell ID already exists!\n";
                return;
            }
        }

        enclosures.push_back(enclosure(id));

        cout << "Enclosure added successfully.\n";
    }

    void zoo :: assign_animal_by_id(int animal_id,
                             int cell_id)
    {

        int animal_index =
            find_animal_index(animal_id);

        int enclosure_index =
            find_enclosure_index(cell_id);

        if (animal_index == -1)
        {

            cout << "Animal not found\n";
            return;
        }

        if (enclosure_index == -1)
        {

            cout << "Cell not found\n";
            return;
        }

        assign_animal(
            animal_index,
            enclosure_index);
    }

    void zoo :: assign_animal(int animal_index, int enclosure_index)
    {

        if (animal_index < 0 || animal_index >= animals.size())
        {
            cout << "Invalid animal index\n";
            return;
        }

        if (enclosure_index < 0 || enclosure_index >= enclosures.size())
        {
            cout << "Invalid enclosure index\n";
            return;
        }

        if (animals[animal_index]->is_assigned())
        {
            cout << "Animal already assigned to another cell\n";
            return;
        }

        if (!enclosures[enclosure_index].is_vaccant())
        {
            cout << "Cell already occupied\n";
            return;
        }

        enclosures[enclosure_index].add_animal(
            animals[animal_index]);

        animals[animal_index]->set_assigned(true);

        cout << "Animal assigned successfully\n";
    }
    void zoo :: vacate_cell_by_id(int cell_id)
    {

        int enclosure_index =
            find_enclosure_index(cell_id);

        if (enclosure_index == -1)
        {

            cout << "Cell not found\n";
            return;
        }

        vacate_cell(enclosure_index);
    }

    void zoo :: vacate_cell(int enclosure_index)
    {

        if (enclosure_index < 0 ||
            enclosure_index >= enclosures.size())
        {

            cout << "Invalid enclosure index\n";
            return;
        }

        if (enclosures[enclosure_index].is_vaccant())
        {
            cout << "Cell already vacant\n";
            return;
        }

        shared_ptr<animal> ptr =
            enclosures[enclosure_index].get_animal_ptr();

        if (ptr)
        {
            ptr->set_assigned(false);
        }

        enclosures[enclosure_index].remove_animal();

        cout << "Cell vacated successfully\n";
    }

    void zoo :: daily_food_report()
    {
        int total_green_food = 0;
        int total_meat = 0;

        for (auto &a : animals)
        {
            if (a->is_veg())
            {
                total_green_food += a->daily_food_requirement();
            }
            else
                total_meat += a->daily_food_requirement();
        }

        cout << " <========= Daily Food Report ==========>" << endl;
        cout << " Daily Green Food Requirement (kg): " << total_green_food << endl;
        cout << " Daily Meat Requirement (kg): " << total_meat << endl;
    }

    void zoo :: displayZoo()
    {
        for (auto &e : enclosures)
            e.display_cell_info();
    }

    void zoo :: show_cell_history_by_id(int cell_id)
    {

        int enclosure_index =
            find_enclosure_index(cell_id);

        if (enclosure_index == -1)
        {

            cout << "Cell not found\n";
            return;
        }

        enclosures[enclosure_index].print_history();
    }

    void zoo :: save_history()
    {

        ofstream file("cell_history.csv");

        if (!file)
        {
            cout << "Unable to create file\n";
            return;
        }

        file << "CellID,AnimalID,AnimalName,EntryDate,ExitDate\n";

        for (auto &e : enclosures)
        {

            for (auto &r : e.get_history())
            {

                file << r.cell_id << ","
                     << r.animal_id << ","
                     << r.animal_name << ","
                     << r.entry_date << ","
                     << r.exit_date << "\n";
            }
        }

        file.close();

        cout << "History saved successfully\n";
    }

