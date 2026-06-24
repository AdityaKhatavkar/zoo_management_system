#include "enclosure.h"
#include "utility.h"

#include <iostream>

using namespace std;

// Constructor 1
enclosure::enclosure(int id)
{
    m_cellId = id;
    m_animalPtr = nullptr;
}

// Constructor 2
enclosure::enclosure(
    int id,
    std::shared_ptr<animal> animal_pointer,
    std::vector<OccupancyRecord> history_)
{
    m_cellId = id;
    m_animalPtr = animal_pointer;
    m_history = history_;
}

bool enclosure::IsVaccant()
{
    return m_animalPtr == nullptr;
}

void enclosure::AddAnimal(shared_ptr<animal> ptr)
{
    m_animalPtr = ptr;

    OccupancyRecord rec;

    rec.m_CellId = m_cellId;
    rec.m_animalId = m_animalPtr->GetId();
    rec.m_animalName = m_animalPtr->GetName();

    rec.m_entryDate = CurrentDate();

    m_history.push_back(rec);
}

void enclosure::RemoveAnimal()
{
    if (!m_history.empty())
    {
        m_history.back().m_exitDate = CurrentDate();
    }

    m_animalPtr = nullptr;
}

void enclosure::DisplayCellInfo()
{
    cout << "Cell ID : " << m_cellId << endl;

    if (m_animalPtr)
    {
        m_animalPtr->DisplayAnimalInfo();
    }
    else
    {
        cout << "Cell is empty" << endl;
    }
}

void enclosure::PrintHistory()
{
    cout << "\nHistory of Cell "
         << m_cellId << endl;

    for (auto &r : m_history)
    {
        cout << r.m_animalName
             << " ("
             << r.m_animalId
             << ") ";

        cout << " From "
             << r.m_entryDate
             << " To "
             << r.m_exitDate
             << endl;
    }
}

int enclosure::GetCellId()
{
    return m_cellId;
}

shared_ptr<animal> enclosure::GetAnimalPtr()
{
    return m_animalPtr;
}

const vector<OccupancyRecord>& enclosure::GetHistory() const
{
    return m_history;
}

void enclosure::AddHistoryRecord(
    const OccupancyRecord& rec)
{
    m_history.push_back(rec);
}