#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class animal{

private:

    int m_animalID;
    bool m_isHerbivorous;
    int m_eatingFrequency;
    float m_mealSizeKg;

    std::string m_animalName;
    int m_animalAge;

    bool m_animalIsAlived;
    bool m_animalRemoved;

    bool m_assigned;

public:

    animal(int m_id,
           bool m_isVeg,
           int m_freq,
           int m_foodKg,
           std::string m_name,
           int m_age);

    bool IsVeg();

    int DailyFoodRequirement();

    void UpdateAnimalInfo(
        bool is_living,
        bool to_remove,
        int age
    );

    void DisplayAnimalInfo();

    int GetId();

    std::string GetName();

    int GetAge();

    int GetFrequency();

    int GetMealSize();

    void SetAssigned(bool value);

    bool IsAssigned() const;

};

#endif