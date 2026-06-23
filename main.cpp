#include <iostream>

#include "zoo.h"

using namespace std;

int main()
{
    zoo myZoo;

    int choice;

    do{

        // menu

        
        cout << " ---- User Menu ---- " << endl;
        cout
            << "1. Add Animal\n"
            << "2. Add Enclosure\n"
            << "3. Assign Animal To Cell\n"
            << "4. Vacate Cell\n"
            << "5. Daily Food Report\n"
            << "6. Display Zoo\n"
            << "7. Show Cell History\n"
            << "8. Save History\n"
            << "0. Exit\n";

        cout << " Enter your choice : ";
        cin >> choice;
        while (choice < 0 || choice > 9)
        {
            cout << "\nEnter valid choice : ";
            cin >> choice;
        }
        cout << endl;

        switch (choice)
        {

        case 1:
        {
            int id, freq, meal, age;
            bool herb;
            string name;

            cout << "Animal ID : ";
            cin >> id;

            cout << "Animal Name : ";
            cin >> name;

            cout << "Age : ";
            cin >> age;

            cout << "Herbivorous? (1/0) : ";
            cin >> herb;

            cout << "Meals per day : ";
            cin >> freq;

            cout << "Meal size (kg) : ";
            cin >> meal;

            myZoo.add_animal_to_cell(
                id,
                herb,
                freq,
                meal,
                name,
                age);

            break;
        }

        case 2:
        {
            int cell_id;

            cout << "Cell ID : ";
            cin >> cell_id;

            myZoo.add_enclosure(cell_id);

            break;
        }

        case 3:
        {
            int animal_id;
            int cell_id;

            cout << "Animal ID : ";
            cin >> animal_id;

            cout << "Cell ID : ";
            cin >> cell_id;

            myZoo.assign_animal_by_id(
                animal_id,
                cell_id);

            break;
        }

        case 4:
        {
            int cell_id;

            cout << "Cell ID : ";
            cin >> cell_id;

            myZoo.vacate_cell_by_id(cell_id);

            break;
        }
        case 5:
        {
            myZoo.daily_food_report();
            break;
        }

        case 6:
        {
            myZoo.displayZoo();
            break;
        }

        case 7:
        {
            int enclosure_index;

            cout << "Enclosure Index : ";
            cin >> enclosure_index;

            myZoo.show_cell_history_by_id(
                enclosure_index);

            break;
        }

        case 8:
        {
            myZoo.save_history();
            break;
        }

        case 0:
        {
            cout << "Exiting...\n";
            break;
        }

        default:
        {
            cout << "Invalid choice\n";
        }
        }

    }while(choice != 0);

    return 0;
}