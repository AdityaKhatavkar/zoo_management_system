#include "zoo.h"

#include <iostream>
#include <fstream>

using namespace std;

zoo::zoo() {}

zoo::zoo(vector<shared_ptr<animal>> animals_,
         vector<enclosure> enclosures_)
{
    m_animals = animals_;
    m_enclosures = enclosures_;
}

// Helper Functions :
int zoo::FindAnimalIndex(int m_animalId)
{
    for (size_t i = 0; i < m_animals.size(); i++)
    {
        if (m_animals[i]->GetId() == m_animalId)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}

int zoo::FindEnclosureIndex(int m_CellId)
{
    for (size_t i = 0; i < m_enclosures.size(); i++)
    {
        if (m_enclosures[i].GetCellId() == m_CellId)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}

// Zoo functionalities

void zoo::AddAnimalToCell(int id,
                           bool IsVeg,
                           int freq,
                           int food_kg,
                           string name,
                           int age)
{
    for (auto &a : m_animals)
    {
        if (a->GetId() == id)
        {
            cout << "Animal ID already exists!\n";
            return;
        }
    }

    m_animals.push_back(
        make_shared<animal>(
            id,
            IsVeg,
            freq,
            food_kg,
            name,
            age));

    cout << "Animal added successfully.\n";
}

void zoo::AddEnclosure(int id)
{
    for (auto &e : m_enclosures)
    {
        if (e.GetCellId() == id)
        {
            cout << "Cell ID already exists!\n";
            return;
        }
    }

    m_enclosures.push_back(enclosure(id));

    cout << "Enclosure added successfully.\n";
}

void zoo::AssignAnimalById(int m_animalId,
                            int m_CellId)
{
    int animal_index =
        FindAnimalIndex(m_animalId);

    int enclosure_index =
        FindEnclosureIndex(m_CellId);

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

    AssignAnimal(
        animal_index,
        enclosure_index);
}

void zoo::AssignAnimal(int animal_index, int enclosure_index)
{
    if (animal_index < 0 || animal_index >= static_cast<int>(m_animals.size()))
    {
        cout << "Invalid animal index\n";
        return;
    }

    if (enclosure_index < 0 || enclosure_index >= static_cast<int>(m_enclosures.size()))
    {
        cout << "Invalid enclosure index\n";
        return;
    }

    if (m_animals[animal_index]->IsAssigned())
    {
        cout << "Animal already assigned to another cell\n";
        return;
    }

    if (!m_enclosures[enclosure_index].IsVaccant())
    {
        cout << "Cell already occupied\n";
        return;
    }

    m_enclosures[enclosure_index].AddAnimal(
        m_animals[animal_index]);

    m_animals[animal_index]->SetAssigned(true);

    cout << "Animal assigned successfully\n";
}

void zoo::VacateCellById(int m_CellId)
{
    int enclosure_index =
        FindEnclosureIndex(m_CellId);

    if (enclosure_index == -1)
    {
        cout << "Cell not found\n";
        return;
    }

    VacateCell(enclosure_index);
}

void zoo::VacateCell(int enclosure_index)
{
    if (enclosure_index < 0 ||
        enclosure_index >= static_cast<int>(m_enclosures.size()))
    {
        cout << "Invalid enclosure index\n";
        return;
    }

    if (m_enclosures[enclosure_index].IsVaccant())
    {
        cout << "Cell already vacant\n";
        return;
    }

    shared_ptr<animal> ptr =
        m_enclosures[enclosure_index].GetAnimalPtr();

    if (ptr)
    {
        ptr->SetAssigned(false);
    }

    m_enclosures[enclosure_index].RemoveAnimal();

    cout << "Cell vacated successfully\n";
}

void zoo::DailyFoodReport()
{
    int total_green_food = 0;
    int total_meat = 0;

    for (auto &a : m_animals)
    {
        if (a->IsVeg())
        {
            total_green_food += a->DailyFoodRequirement();
        }
        else
            total_meat += a->DailyFoodRequirement();
    }

    cout << " <========= Daily Food Report ==========>" << endl;
    cout << " Daily Green Food Requirement (kg): " << total_green_food << endl;
    cout << " Daily Meat Requirement (kg): " << total_meat << endl;
}

void zoo::DisplayZoo()
{
    for (auto &e : m_enclosures)
        e.DisplayCellInfo();
}

void zoo::ShowCellHistoryById(int m_CellId)
{
    int enclosure_index =
        FindEnclosureIndex(m_CellId);

    if (enclosure_index == -1)
    {
        cout << "Cell not found\n";
        return;
    }

    m_enclosures[enclosure_index].PrintHistory();
}

void zoo::SaveHistory()
{
    ofstream file("cell_history.csv");

    if (!file)
    {
        cout << "Unable to create file\n";
        return;
    }

    file << "CellID,AnimalID,AnimalName,EntryDate,ExitDate\n";

    for (auto &e : m_enclosures)
    {
        for (auto &r : e.GetHistory())
        {
            file << r.m_CellId << ","
                 << r.m_animalId << ","
                 << r.m_animalName << ","
                 << r.m_entryDate << ","
                 << r.m_exitDate << "\n";
        }
    }

    file.close();

    cout << "History saved successfully\n";
}

void zoo::SaveAnimals()
{
    ofstream file("animals.csv");

    if (!file)
    {
        cout << "Unable to create file\n";
        return;
    }

    file << "AnimalID,Name,Age,Herbivore,Frequency,MealSize,AssignedCellID\n";

    for (auto &a : m_animals)
    {
        int assignedCell = -1;

        for (auto &e : m_enclosures)
        {
            auto ptr = e.GetAnimalPtr();
            if (ptr && ptr->GetId() == a->GetId())
            {
                assignedCell = e.GetCellId();
                break;
            }
        }

        file
            << a->GetId() << ","
            << a->GetName() << ","
            << a->GetAge() << ","
            << a->IsVeg() << ","
            << a->GetFrequency() << ","
            << a->GetMealSize() << ","
            << assignedCell << "\n";
    }

    file.close();

    cout << "Animals saved successfully\n";
}

void zoo::SaveEnclosures()
{
    ofstream file("enclosures.csv");

    if (!file)
    {
        cout << "Unable to create file\n";
        return;
    }

    file << "CellID\n";

    for (auto &e : m_enclosures)
    {
        file << e.GetCellId() << "\n";
    }

    file.close();

    cout << "Enclosures saved successfully\n";
}

void zoo::RestoreAnimals()
{
    ifstream file("animals.csv");

    if (!file)
        return;

    string line;

    getline(file, line); // header

    while (getline(file, line))
    {
        stringstream ss(line);

        string idStr, name, ageStr, vegStr, freqStr, mealStr, assignedStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, vegStr, ',');
        getline(ss, freqStr, ',');
        getline(ss, mealStr, ',');
        getline(ss, assignedStr, ',');

        auto newAnimal = make_shared<animal>(
            stoi(idStr),
            vegStr == "1",
            stoi(freqStr),
            stoi(mealStr),
            name,
            stoi(ageStr));

        m_animals.push_back(newAnimal);

        // Defer assignment until enclosures are restored too.
        // Stash the cell id by attempting assignment now if the
        // enclosure already exists (e.g. RestoreEnclosures ran first).
        if (!assignedStr.empty())
        {
            int cellId = stoi(assignedStr);
            if (cellId != -1)
            {
                int enclosureIndex = FindEnclosureIndex(cellId);
                if (enclosureIndex != -1 &&
                    m_enclosures[enclosureIndex].IsVaccant())
                {
                    m_enclosures[enclosureIndex].AddAnimal(newAnimal);
                    newAnimal->SetAssigned(true);
                }
            }
        }
    }

    file.close();
}

void zoo::RestoreEnclosures()
{
    ifstream file("enclosures.csv");

    if (!file)
        return;

    string line;

    getline(file, line); // header

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        m_enclosures.push_back(
            enclosure(stoi(line)));
    }

    file.close();
}

void zoo::RestoreHistory()
{
    ifstream file("cell_history.csv");

    if (!file)
        return;

    string line;

    getline(file, line); // header

    while (getline(file, line))
    {
        stringstream ss(line);

        OccupancyRecord rec;

        string temp;

        getline(ss, temp, ',');
        rec.m_CellId = stoi(temp);

        getline(ss, temp, ',');
        rec.m_animalId = stoi(temp);

        getline(ss, rec.m_animalName, ',');

        getline(ss, rec.m_entryDate, ',');

        getline(ss, rec.m_exitDate, ',');

        int enclosureIndex =
            FindEnclosureIndex(rec.m_CellId);

        if (enclosureIndex != -1)
        {
            m_enclosures[enclosureIndex]
                .AddHistoryRecord(rec);
        }
    }

    file.close();
}