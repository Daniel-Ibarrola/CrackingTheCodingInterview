//
// Created by daniel on 18/02/23.
//

#include "animal_shelter.h"


void AnimalShelter::addNewAnimal(Cat &cat)
{
    // Add a new dog to the shelter
    ++latestArrival;
    cat.setArrival(latestArrival);
    m_cats.push_back(cat);
}


void AnimalShelter::addNewAnimal(Dog &dog)
{
    // Add a new cat to the shelter
    ++latestArrival;
    dog.setArrival(latestArrival);
    m_dogs.push_back(dog);
}


Cat AnimalShelter::adoptCat()
{
    // Adopt the oldest cat (arrived first)
    assert(!m_cats.empty());
    Cat cat {m_cats.front()};
    m_cats.pop_front();
    return cat;
}


Dog AnimalShelter::adoptDog() {
    // Adopt the oldest dog (arrived first)
    assert(!m_dogs.empty());
    Dog dog {m_dogs.front()};
    m_dogs.pop_front();
    return dog;
}


Animal AnimalShelter::adoptAny() {
    // Adopt the oldest animal (arrived first)
    assert(!empty());
    if (m_cats.empty() || m_dogs.front().getArrival() < m_cats.front().getArrival())
        return adoptDog();
    else
        return adoptCat();
}




