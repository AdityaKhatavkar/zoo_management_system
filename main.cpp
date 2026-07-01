#include <iostream>

#include "zoo.h"

void UI()
{
    Zoo zoo_object; // default constructor: loads saved state from disk if present

    int choice;

    do
    {
        std :: cout << " ---- User Menu ---- " << "\n";
        std :: cout
            << "1. Add Animal\n"
            << "2. Add Enclosure\n"
            << "3. Assign Animal To Cell\n"
            << "4. Vacate Cell\n"
            << "5. Daily Food Report\n"
            << "6. Display Zoo\n"
            << "7. Show Cell History\n"
            << "8. Save History\n"
            << "0. Exit\n";

        while (true)
        {
            std :: cout << "Enter your choice : ";

            if (std :: cin >> choice && choice >= 0 && choice <= 8)
                break;

            std :: cout << "Invalid choice. Please enter a number between 0 and 8.\n";

            std :: cin.clear();
            std :: cin.ignore(10000, '\n');
        }
        std :: cout << "\n";

        switch (choice)
        {
        case 1:
        {
            int id, freq, age;
            float meal;
            bool herb;
            std :: string name;

            std :: cout << "Animal ID : ";
            std :: cin >> id;

            std :: cout << "Animal Name : ";
            std :: cin.ignore();
            std :: getline(std :: cin, name);

            std :: cout << "Age : ";
            std :: cin >> age;

            std :: cout << "Herbivorous? (1/0) : ";
            std :: cin >> herb;

            std :: cout << "Meals per day : ";
            std :: cin >> freq;

            std :: cout << "Meal size (kg) : ";
            std :: cin >> meal;

            zoo_object.AddAnimalToCell(
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

            std :: cout << "Cell ID : ";
            std :: cin >> cell_id;

            zoo_object.AddEnclosure(cell_id);

            break;
        }

        case 3:
        {
            int animal_id;
            int cell_id;

            std :: cout << "Animal ID : ";
            std :: cin >> animal_id;

            std :: cout << "Cell ID : ";
            std :: cin >> cell_id;

            zoo_object.AssignAnimalById(
                animal_id,
                cell_id);

            break;
        }

        case 4:
        {
            int cell_id;

            std :: cout << "Cell ID : ";
            std :: cin >> cell_id;

            zoo_object.VacateCellById(cell_id);

            break;
        }

        case 5:
        {
            zoo_object.DailyFoodReport();
            break;
        }

        case 6:
        {
            zoo_object.DisplayZoo();
            break;
        }

        case 7:
        {
            int cell_id;

            std :: cout << "Cell ID : ";
            std :: cin >> cell_id;

            zoo_object.ShowCellHistoryById(cell_id);

            break;
        }

        case 8:
        {
            zoo_object.SaveHistory();
            break;
        }

        case 0:
        {
            zoo_object.SaveAnimals();
            zoo_object.SaveEnclosures();
            zoo_object.SaveHistory();
            cout << "State saved. Exiting...\n";
            break;
        }

        default:
        {
            cout << "Invalid choice\n";
        }
        }

        cout << "\n";

    } while (choice != 0);
}

int main()
{
    UI();
    return 0;
}