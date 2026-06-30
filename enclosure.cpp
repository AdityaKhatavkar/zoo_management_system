#include "enclosure.h"
#include "utility.h"
#include <iostream>


// Constructor 
Enclosure::Enclosure(
    int id,
    std::shared_ptr<Animal> animal_pointer,
    std::vector<OccupancyRecord> history_){
    m_uniqueCellId = id;
    m_animalPtr = animal_pointer;
    m_history = history_;
}

bool Enclosure::IsCellVaccantOrNot()const{
    return m_animalPtr == nullptr;
}

void Enclosure::AddAnimalToCell(std :: shared_ptr<Animal> ptr){
    m_animalPtr = ptr;
    OccupancyRecord rec;
    rec.m_CellId = m_uniqueCellId;
    rec.m_animalId = m_animalPtr->GetAnimalId();
    rec.m_animalName = m_animalPtr->GetAnimalName();
    rec.m_entryDate = CurrentDate();
     m_history.push_back(rec);
}

void Enclosure::RemoveAnimalFromCell(){
    if (!m_history.empty()){
        m_history.back().m_exitDate = CurrentDate();
    }
    m_animalPtr = nullptr;
}

void Enclosure::DisplayCellInfo(){
    std :: cout << "Cell ID : " << m_uniqueCellId << "\n";

    if (m_animalPtr){
        m_animalPtr->DisplayAnimalInfo();
    }
    else{
        std :: cout << "Cell is empty" << "\n";
    }
}

void Enclosure::PrintHistoryOfCell(){
    std :: cout << "\nHistory of Cell " << m_uniqueCellId << "n";
    for (auto &r : m_history){
        std :: cout << r.m_animalName << " (" << r.m_animalId << ") ";
        std :: cout << " From " << r.m_entryDate << " To " << r.m_exitDate << "\n";
    }
}

int Enclosure::GetCellId() const{
    return m_uniqueCellId;
}

std :: shared_ptr<Animal> Enclosure::GetAnimalPtr() {
    return m_animalPtr;
}

const std :: vector<OccupancyRecord>& Enclosure::GetHistory() const {
    return m_history;
}

void Enclosure::AddHistoryRecord( const OccupancyRecord& rec) {
    m_history.push_back(rec);
}