#include "administration.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"


int addAnimal(
            const Animal* animalPtr, Animal* animalArray,
            size_t animalArrayLength, size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent){
    // checking if the memory allocation is successful
    if (!animalPtr || !animalArray || !newNumberOfAnimalsPresent) {
        return -1;
    }
    // animalArrayLength must be greater than numberOfAnimalsPresent
    if (animalArrayLength <= numberOfAnimalsPresent){
        return -1;
    }

    //Copy the new Animal structure to the next available position in the animalArray.
    animalArray[numberOfAnimalsPresent] = *animalPtr;
    //Increment the numberOfAnimalsPresent.
    numberOfAnimalsPresent ++;
    //Update the pointer value for the number of animals present.
    *newNumberOfAnimalsPresent = numberOfAnimalsPresent;
    return 0;
}


int removeAnimal(
            int animalId, Animal* animalArray,
            size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent){
    // checking if the memory allocation is successful
    if (!animalArray || !newNumberOfAnimalsPresent){
        return -1;
    }

    int i = 0;
    int animalsRemoved = 0;

    // Loop over the array and shift animals with matching ID to remove them
    while (i < numberOfAnimalsPresent) {
        if (animalArray[i].Id == animalId) {
            // Shift all elements after the current index to the left
            for (int j = i; j < numberOfAnimalsPresent - 1; ++j) {
                animalArray[j] = animalArray[j + 1];
            }
            numberOfAnimalsPresent--;
            animalsRemoved++;
        } else {
            // Only move to the next animal if the current one wasn't removed
            i++;
        }
    }

    *newNumberOfAnimalsPresent = numberOfAnimalsPresent;


    return animalsRemoved;
}

int findAnimalById(
            int animalId, const Animal* animalArray,
            size_t numberOfAnimalsPresent, Animal* animalPtr){
    // checking if the memory allocation is successful
    if (!animalArray || !animalPtr){
        return -1;
    }
    //Iterate through the array of animals to find the animal with the specified ID.
    for(int i = 0; i < numberOfAnimalsPresent; i++) {
        //If the animal is found, copy its data into the provided Animal structure pointer.
        if (animalArray[i].Id == animalId) {
            *animalPtr = animalArray[i];
            return 1;
        }
    }
    //Return a value indicating that the animal was not found
    return 0;
}

/*-------------------------------------------------------------------------------*/
typedef bool (*animal_compare)(Animal* A, Animal* B);

//static because only used if this file and does not need to be exposed to other parts of the program
static void sort_animals(Animal* animalArray, size_t numberOfAnimalsPresent, animal_compare compare){
    if (!animalArray) {
        exit(-1);
    }
    Animal temp;
    // Iterate through each animal in the array
    for(int i = 0; i < numberOfAnimalsPresent; i++) {
        // Compare each animal's ... with the age of subsequent animals
        for(int j = i + 1; j < numberOfAnimalsPresent; j++) {
            // If the ... of the current animal is greater than the ... of the next animal, swap them
            if(compare(&animalArray[i], &animalArray[j])) {
                temp = animalArray[i];
                animalArray[i] = animalArray[j];
                animalArray[j] = temp;
            }
        }
    }
}

// Comparison function to compare animals by age
bool compareAnimalsByAge(Animal* A, Animal* B) {
    return A->Age > B->Age;
}

// Comparison function to compare animals by date found (year)
bool compareAnimalsByDateFound(Animal* A, Animal* B) {
    return A->DateFound.Year > B->DateFound.Year;
}

// Comparison function to compare animals by sex
bool compareAnimalsBySex(Animal* A, Animal* B) {
    return A->Sex < B->Sex;
}

// Function to sort animals in the animalArray by their ages in ascending order
int sortAnimalsByAge(Animal* animalArray, size_t numberOfAnimalsPresent) {
    // checking if the memory allocation is successful
    if (!animalArray){
        return -1;
    }
    sort_animals(animalArray, numberOfAnimalsPresent, compareAnimalsByAge);
    // Print the sorted array of animals (for debugging or verification purposes)
    printf("After Sorting:\n");
    for(int i = 0; i < numberOfAnimalsPresent; i++) {
    }
    return 0;
}

// Function to sort animals in the animalArray by their year found in ascending order
int sortAnimalsByYearFound(Animal* animalArray, size_t numberOfAnimalsPresent) {
    // checking if the memory allocation is successful
    if (!animalArray) {
        return -1;
    }
    sort_animals(animalArray, numberOfAnimalsPresent, compareAnimalsByDateFound);
    // Print the sorted array of animals (for debugging or verification purposes)
    printf("After Sorting:\n");
    for (int i = 0; i < numberOfAnimalsPresent; i++) {
        printf("%d ", animalArray[i].DateFound.Year);
    }
    return 0;
}
//female = 0 male = 1
int sortAnimalsBySex(Animal *animalArray, size_t numberOfAnimalsPresent) {
    // checking if the memory allocation is successful
    if (!animalArray) {
        return -1;
    }
    sort_animals(animalArray, numberOfAnimalsPresent, compareAnimalsBySex);

    // Print the sorted array of animals (for debugging or verification purposes)
    printf("After Sorting:\n");
    for (int i = 0; i < numberOfAnimalsPresent; i++) {
        printf("%d ", animalArray[i].Sex);
    }
    return 0;
}
