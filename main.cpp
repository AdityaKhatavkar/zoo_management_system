#include <iostream>

#include "zoo.h"

using namespace std;

void UI(){
    zoo myZoo;

    int choice;

    do{        
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

        while (true)
        {
            cout << "Enter your choice : ";

            if (cin >> choice && choice >= 0 && choice <= 8)
                break;

            cout << "Invalid choice. Please enter a number between 0 and 8.\n";

            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << endl;

        switch (choice)
        {

        case 1:
        {
            int id, freq, age;
            float meal;
            bool herb;
            string name;

            cout << "Animal ID : ";
            cin >> id;

            cout << "Animal Name : ";
            cin.ignore();
            getline(cin, name);

            cout << "Age : ";
            cin >> age;

            cout << "Herbivorous? (1/0) : ";
            cin >> herb;

            cout << "Meals per day : ";
            cin >> freq;

            cout << "Meal size (kg) : ";
            cin >> meal;

            myZoo.AddAnimalToCell(
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

            myZoo.AddEnclosure(cell_id);

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

            myZoo.AssignAnimalById(
                animal_id,
                cell_id);

            break;
        }

        case 4:
        {
            int cell_id;

            cout << "Cell ID : ";
            cin >> cell_id;

            myZoo.VacateCellById(cell_id);

            break;
        }
        case 5:
        {
            myZoo.DailyFoodReport();
            break;
        }

        case 6:
        {
            myZoo.DisplayZoo();
            break;
        }

        case 7:
        {
            int enclosure_index;

            cout << "Enclosure Index : ";
            cin >> enclosure_index;

            myZoo.ShowCellHistoryById(enclosure_index);

            break;
        }

        case 8:
        {
            myZoo.SaveHistory();
            cout << "History saved successfully.\n";
            break;
        }

        case 0:
        {   myZoo.SaveHistory();
            cout << "History saved.\n";

            cout << "Exiting...\n";
            break;
        }

        default:
        {
            cout << "Invalid choice\n";
        }
        }

    }while(choice != 0);

}

int main()
{
    UI();
    return 0;
}