//
// Created by daniel on 18/02/23.
//

#ifndef CRACKING_ANIMAL_SHELTER_H
#define CRACKING_ANIMAL_SHELTER_H


#include <cassert>
#include <list>
#include <string>


class Animal
{
private:
    std::string m_name;
    int m_arrival {-1};  // -1 means arrival is not assigned yet

public:

    explicit Animal(std::string name)
        : m_name {std::move(name)}
    {

    }

    [[nodiscard]] const std::string& getName() const
    {
        return m_name;
    }

    void setArrival(int arrival) {m_arrival = arrival;}
    [[nodiscard]] int getArrival() const {return m_arrival;};

};

class Dog : public Animal
{
public:

    explicit Dog(std::string name)
        : Animal {std::move(name)}
    {

    }
};


class Cat : public Animal
{
public:

    explicit Cat(std::string name)
        : Animal {std::move((name))}
    {

    }
};


class AnimalShelter
{
private:
    std::list<Cat> m_cats;
    std::list<Dog> m_dogs;
    int latestArrival {0};

public:

    AnimalShelter() = default;

    void addNewAnimal(Cat& cat);
    void addNewAnimal(Dog& dog);

    [[nodiscard]] std::size_t getNumAnimals() const
    {
        return m_cats.size() + m_dogs.size();
    }

    [[nodiscard]] std::size_t getNumCats() const
    {
        return m_cats.size();
    }

    [[nodiscard]] std::size_t getNumDogs() const
    {
        return m_dogs.size();
    }

    [[nodiscard]] bool empty() const
    {
        return m_cats.empty() && m_dogs.empty();
    }

    Cat adoptCat();
    Dog adoptDog();
    Animal adoptAny();

};

#endif //CRACKING_ANIMAL_SHELTER_H
