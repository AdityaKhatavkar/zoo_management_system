#include <memory>
#include <vector>

#include "animal.h"
#include "occupancy_record.h"

class Enclosure{

private:
    
    // Each cell has a unique ID number;
    int m_uniqueCellId;

    // Shared Pointer of type 'Animal'
    std::shared_ptr<Animal> m_animalPtr;

    // Vector of datatype OccupancyRecord.
    std::vector<OccupancyRecord> m_history;

public:

    //constructor
    Enclosure(int id,
              std::shared_ptr<Animal> animal_ptr,
              std::vector<OccupancyRecord> history);

    //Adds Animal to the cell
    void AddAnimalToCell(
        std::shared_ptr<Animal> ptr
    );

    //Removes animla from cell
    void RemoveAnimalFromCell();


    //Keep track all the enimals that were entered in a jungle.
    void AddHistoryRecord(const OccupancyRecord& rec);


    //Display cell specific information
    void DisplayCellInfo();

    //Print record of animals that were once occupied perticual cell.
    void PrintHistoryOfCell();

    //Returs true if the cell is vaccant or return false.
    bool IsCellVaccantOrNot()const;

    //Returns the unique ID number of a cell.
    int GetCellId()const;

    //Returs animla pointer
    std::shared_ptr<Animal> GetAnimalPtr();

    //Returns the reference to the vector of occupancy records
    //Its a return type constant
    const std::vector<OccupancyRecord>& GetHistory() const; //Its a function constant

    void Enclosure::AddHistoryRecord( const OccupancyRecord& rec) ; // Its a parameter constant
};
