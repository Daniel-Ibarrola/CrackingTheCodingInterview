//
// Created by daniel on 18/02/23.
//

#include "animal_shelter.h"
#include "gtest/gtest.h"


TEST(TestAnimalShelter, TestAdoptDog)
{
    AnimalShelter shelter;
    Dog dog_1 {"Steve"};
    Dog dog_2 {"George"};
    Cat cat_1 {"Marvin"};

    shelter.addNewAnimal(dog_1);
    shelter.addNewAnimal(dog_2);
    shelter.addNewAnimal(cat_1);

    ASSERT_EQ(shelter.getNumAnimals(), 3);
    ASSERT_EQ(shelter.getNumDogs(), 2);
    ASSERT_EQ(shelter.getNumCats(), 1);

    ASSERT_EQ(shelter.adoptDog().getName(), "Steve");
    ASSERT_EQ(shelter.adoptDog().getName(), "George");
    ASSERT_EQ(shelter.getNumDogs(), 0);
}


TEST(TestAnimalShelter, TestAdoptCat)
{
    AnimalShelter shelter;
    Cat cat_1 {"Whiskers"};
    Cat cat_2 {"Lucky"};
    Dog dog_1 {"George"};

    shelter.addNewAnimal(cat_1);
    shelter.addNewAnimal(dog_1);
    shelter.addNewAnimal(cat_2);

    ASSERT_EQ(shelter.getNumAnimals(), 3);
    ASSERT_EQ(shelter.getNumDogs(), 1);
    ASSERT_EQ(shelter.getNumCats(), 2);

    ASSERT_EQ(shelter.adoptCat().getName(), "Whiskers");
    ASSERT_EQ(shelter.adoptCat().getName(), "Lucky");
    ASSERT_EQ(shelter.getNumCats(), 0);
}

TEST(TestAnimalShelter, TestAdoptAny)
{
    AnimalShelter shelter;
    Cat cat_1 {"Gus"};
    Cat cat_2 {"Henry"};
    Dog dog_1 {"Milo"};
    Dog dog_2 {"George"};

    shelter.addNewAnimal(dog_1);
    shelter.addNewAnimal(cat_1);
    shelter.addNewAnimal(cat_2);
    shelter.addNewAnimal(dog_2);

    ASSERT_EQ(shelter.adoptAny().getName(), "Milo");
    ASSERT_EQ(shelter.adoptAny().getName(), "Gus");
    ASSERT_EQ(shelter.adoptAny().getName(), "Henry");
    ASSERT_EQ(shelter.adoptAny().getName(), "George");

    ASSERT_TRUE(shelter.empty());
}