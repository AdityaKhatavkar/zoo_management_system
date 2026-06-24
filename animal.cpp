#include "animal.h"

#include <iostream>

using namespace std;

animal::animal(
    int id,
    bool is_veg,
    int freq,
    int food_kg,
    string name,
    int age
)
{
    m_animalID = id;
    m_animalName = name;
    m_animalAge = age;

    m_isHerbivorous = is_veg;
    m_eatingFrequency = freq;
    m_mealSizeKg = food_kg;

    m_animalIsAlived = true;
    m_animalRemoved = false;

    m_assigned = false;
}

bool animal::IsVeg()
{
    return m_isHerbivorous;
}

int animal::DailyFoodRequirement()
{
    return m_eatingFrequency * m_mealSizeKg;
}

void animal::UpdateAnimalInfo(
    bool is_living,
    bool to_remove,
    int age
)
{
    m_animalIsAlived = is_living;
    m_animalRemoved = to_remove;
    m_animalAge = age;
}

void animal::DisplayAnimalInfo()
{
    cout << "Animal ID : "
         << m_animalID << endl;

    cout << "Animal Name : "
         << m_animalName << endl;

    cout << "Animal Age : "
         << m_animalAge << endl;
}

int animal::GetId()
{
    return m_animalID;   // FIX: was returning m_animalAge
}

string animal::GetName()
{
    return m_animalName;
}

int animal::GetAge()
{
    return m_animalAge;
}

int animal::GetFrequency()
{
    return m_eatingFrequency;
}

int animal::GetMealSize()
{
    return m_mealSizeKg;
}

void animal::SetAssigned(bool value)
{
    m_assigned = value;
}

bool animal::IsAssigned() const
{
    return m_assigned;
}