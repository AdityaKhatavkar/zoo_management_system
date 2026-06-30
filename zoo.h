#define ZOO_H

#include <vector>
#include <memory>
#include <sstream>
#include <string>

#include "animal.h"
#include "enclosure.h"

class Zoo{
    
    private:
    std::vector<std::shared_ptr<Animal>> m_animals;
    std::vector<Enclosure> m_enclosures;
    
    public:

    Zoo(std::vector<std::shared_ptr<Animal>>& animals,
        std::vector<Enclosure>& enclosures );

    void AddEnclosure(int ID);
    

    void AssignCellToAnimalById(int& const UniqueAnimalID, int& const UniqueCellID );

    void  VacateCellById(int& const CellID);

    void PrintDailyReportOfTotalFoodRequirement();

    void PrintEveryAnimalInZoo();

    void ShowCellHistoryById( int& const EnclosureID);

    void SaveHistory();

    void SaveAnimals();

    void SaveEnclosures();

    void RestoreAnimals();

    void RestoreEnclosures();

    void RestoreHistory();

    int FindIndexOfAnimal(int& const UniqueAnimalID);

    int FindIndexOfEnclosure(int& const UniqueCellID);
};

