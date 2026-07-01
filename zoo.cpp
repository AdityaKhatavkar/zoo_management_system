#include "zoo.h"

#include <iostream>
#include <fstream>
#include <sstream>

Zoo::Zoo()
{
    RestoreEnclosures();
    RestoreAnimals();
    RestoreHistory();
}

Zoo::Zoo(std::vector<std::shared_ptr<Animal>>& animals,
         std::vector<Enclosure>& enclosures)
{
    m_animals = animals;
    m_enclosures = enclosures;
}

void Zoo::AddAnimalToCell(int id,
                           bool isHerbivore,
                           int mealsPerDay,
                           float mealSizeKg,
                           const std::string& name,
                           int age)
{
    for (auto& a : m_animals)
    {
        if (a->GetAnimalId() == id)
        {
            std::cout << "An animal with that ID already exists\n";
            return;
        }
    }

    m_animals.push_back(std::make_shared<Animal>(
        id, isHerbivore, mealsPerDay, mealSizeKg, name, age));

    std::cout << "Animal added successfully\n";
}

void Zoo::AddEnclosure(int cellId)
{
    for (auto& e : m_enclosures)
    {
        if (e.GetCellId() == cellId)
        {
            std::cout << "A cell with that ID already exists\n";
            return;
        }
    }

    m_enclosures.emplace_back(cellId);
    std::cout << "Enclosure added successfully\n";
}

void Zoo::AssignAnimalById(int animalId, int cellId)
{
    std::shared_ptr<Animal> animal = nullptr;

    for (auto& a : m_animals)
    {
        if (a->GetAnimalId() == animalId)
        {
            animal = a;
            break;
        }
    }

    if (animal == nullptr)
    {
        std::cout << "Animal not found\n";
        return;
    }

    // IsCellAssignedToAnimal() now returns the actual cell ID (or -1),
    // so this comparison is meaningful.
    if (animal->IsCellAssignedToAnimal() != -1)
    {
        std::cout << "Animal already assigned to a cell\n";
        return;
    }

    for (auto& e : m_enclosures)
    {
        if (e.GetCellId() == cellId)
        {
            if (!e.IsCellVaccantOrNot())
            {
                std::cout << "Cell already occupied\n";
                return;
            }

            e.AddAnimalToCell(animal);
            animal->AssignedCellToAnimal(cellId);

            std::cout << "Animal assigned successfully\n";
            return;
        }
    }

    std::cout << "Cell not found\n";
}

void Zoo::VacateCellById(int cellId)
{
    for (auto& e : m_enclosures)
    {
        if (e.GetCellId() == cellId)
        {
            auto animal = e.GetAnimalPtr();
            if (animal != nullptr)
            {
                animal->AssignedCellToAnimal(-1);
            }
            e.RemoveAnimalFromCell();
            std::cout << "Cell vacated successfully\n";
            return;
        }
    }
    std::cout << "Cell not found\n";
}

void Zoo::DailyFoodReport()
{
    float greenFood = 0;
    float meatFood = 0;

    for (auto& a : m_animals)
    {
        if (a->IsAnimalHerbivorousOrNot())
            greenFood += a->AmountOfFoodAnimalNeedPerDay();
        else
            meatFood += a->AmountOfFoodAnimalNeedPerDay();
    }

    std::cout << "\n====== Daily Food Report ======\n";
    std::cout << "Green Food : " << greenFood << " kg\n";
    std::cout << "Meat Food  : " << meatFood << " kg\n";
}

void Zoo::DisplayZoo()
{
    if (m_animals.empty())
    {
        std::cout << "No animals in the zoo yet\n";
        return;
    }

    for (auto& a : m_animals)
    {
        a->DisplayAnimalInfo();
        std::cout << "-----\n";
    }
}

void Zoo::ShowCellHistoryById(int cellId)
{
    for (auto& e : m_enclosures)
    {
        if (e.GetCellId() == cellId)
        {
            e.PrintHistoryOfCell();
            return;
        }
    }
    std::cout << "Cell not found\n";
}

void Zoo::SaveHistory()
{
    std::ofstream file("cell_history.csv");

    if (!file)
    {
        std::cout << "Unable to create file\n";
        return;
    }

    file << "CellID,AnimalID,AnimalName,EntryDate,ExitDate\n";

    for (auto& e : m_enclosures)
    {
        for (auto& r : e.GetHistory())
        {
            file << r.m_CellId << ","
                 << r.m_animalId << ","
                 << r.m_animalName << ","
                 << r.m_entryDate << ","
                 << r.m_exitDate << "\n";
        }
    }
    std::cout << "History saved successfully\n";
}

void Zoo::SaveAnimals()
{
    std::ofstream file("animals.csv");
    if (!file)
    {
        std::cout << "Unable to create file\n";
        return;
    }

    // Column order matches the Animal constructor's parameter order:
    // id, veg, freq, meal, name, age -- plus the assigned cell.
    file << "AnimalID,Veg,Frequency,MealSize,Name,Age,AssignedCell\n";

    for (auto& a : m_animals)
    {
        file << a->GetAnimalId() << ","
             << a->IsAnimalHerbivorousOrNot() << ","
             << a->GetFoodEatingFrequencyOfAnimal() << ","
             << a->GetMealSizeKg() << ","
             << a->GetAnimalName() << ","
             << a->GetAnimalAge() << ","
             << a->IsCellAssignedToAnimal() << "\n";
    }
    std::cout << "Animals saved successfully\n";
}

void Zoo::SaveEnclosures()
{
    std::ofstream file("enclosures.csv");
    if (!file)
    {
        std::cout << "Unable to create file\n";
        return;
    }

    file << "CellID\n";

    for (auto& e : m_enclosures)
        file << e.GetCellId() << "\n";

    std::cout << "Enclosures saved successfully\n";
}

void Zoo::RestoreAnimals()
{
    std::ifstream file("animals.csv");

    if (!file)
        return;

    std::string line;
    getline(file, line); // skip header

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);

        std::string id, veg, freq, meal, name, age, assigned;

        getline(ss, id, ',');
        getline(ss, veg, ',');
        getline(ss, freq, ',');
        getline(ss, meal, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');
        getline(ss, assigned, ',');

        auto animal = std::make_shared<Animal>(
            stoi(id),
            veg == "1",
            stoi(freq),
            std::stof(meal),
            name,
            stoi(age));

        animal->AssignedCellToAnimal(stoi(assigned));

        m_animals.push_back(animal);
    }
}

void Zoo::RestoreEnclosures()
{
    std::ifstream file("enclosures.csv");

    if (!file)
        return;

    std::string line;
    getline(file, line); // skip header

    while (getline(file, line))
    {
        if (!line.empty())
            m_enclosures.emplace_back(stoi(line));
    }
}

void Zoo::RestoreHistory()
{
    std::ifstream file("cell_history.csv");

    if (!file)
        return;

    std::string line;
    getline(file, line); // skip header

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);

        OccupancyRecord rec;

        std::string temp;
        getline(ss, temp, ',');
        rec.m_CellId = stoi(temp);

        getline(ss, temp, ',');
        rec.m_animalId = stoi(temp);

        getline(ss, rec.m_animalName, ',');
        getline(ss, rec.m_entryDate, ',');
        getline(ss, rec.m_exitDate, ',');

        for (auto& e : m_enclosures)
        {
            if (e.GetCellId() == rec.m_CellId)
            {
                e.AddHistoryRecord(rec);
                break;
            }
        }
    }
}