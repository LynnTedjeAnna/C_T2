#include <stdio.h>
#include "file_element.h"

/* pre    : n.a.
 * post   : If file contains enough Animals, nrAnimals Animals are read into
 *          animalPtr. If less animals than nrAnimals exist, all animals from
 *          the file are read into animalPtr.
 * returns: Nr of animals written into animalPtr or -1 if an error occurs
 */
int readAnimals(const char* filename, Animal* animalPtr, size_t nrAnimals){

    return -1;
}

//todo: check
int writeAnimals(const char* filename, const Animal* animalPtr, size_t nrAnimals){
    // checking if the memory allocation is successful
    if (!filename || !animalPtr) {
        return -1;
    }
    // Open the file for writing
    FILE* file = fopen(filename, "w");
    if (!file) {
        return -1;
    }
    // Write each animal to the file
    for (size_t i = 0; i < nrAnimals; i++) {
        // Writing each field of the struct explicitly
        fprintf(file, "Id: %d\n", animalPtr[i].Id);
        fprintf(file, "Species: %d\n", animalPtr[i].Species);
        fprintf(file, "Sex: %d\n", animalPtr[i].Sex);
        fprintf(file, "Age: %d\n", animalPtr[i].Age);
        fprintf(file, "Date Found: %d-%d-%d\n",
            animalPtr[i].DateFound.Year,
            animalPtr[i].DateFound.Month,
            animalPtr[i].DateFound.Day);
        fprintf(file, "\n");
    }
    // Close the file
    fclose(file);
    return 0;
}

int getNrAnimalsInFile(const char* filename, size_t* nrAnimals){
    // Open the file in binary mode
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return -1;
    }

    // Seek to the end of the file to get its size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);  // Get the size of the file in bytes
    fseek(file, 0, SEEK_SET);     // Reset the file pointer to the start

    // Calculate the number of Animal structures in the file
    size_t animalSize = sizeof(Animal);
    *nrAnimals = fileSize / animalSize;

    // Close the file
    fclose(file);

    return 0;
}

/* post   : read the animal on filePosition (first animal is filePosition 0,
 *          second animal is filePosition 1, ...) into animalPtr

	2.	Seek to the desired position: Calculate the correct offset (location) in the file using filePosition.
    The size of each Animal entry can be determined using sizeof(Animal).
    Use fseek to move the file pointer to the correct position.
	3.	Read the animal: After positioning the file pointer, read the animal data into the animalPtr.
	4.	Close the file: After reading, close the file to free system resources.
 */
int readAnimalFromFile(
            const char* filename, size_t filePosition, Animal* animalPtr){
    // Open the file in binary mode
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return -1;
    }

    // Calculate the offset: each animal is sizeof(Animal) bytes long
    size_t offset = filePosition * sizeof(Animal);

    //todo: check, fread, if statement
    // Seek to the file position
    if (fseek(file, offset, SEEK_SET) != 0) {
        fclose(file);
        return -1; // Error: could not seek to the position
    }

    // Read the animal from the file
    size_t readCount = fread(animalPtr, sizeof(Animal), 1, file);
    if (readCount != 1) {
        fclose(file);
        return -1; // Error: could not read the animal
    }
    // Close the file
    fclose(file);
    return 0;
}

/* pre    :
 * post   : write the animal in animalPtr to the file at position 'filePosition'
 * returns: On success: 0, on error: -1
 *
 **** note: do not open the file in append mode (a or a+): in append mode you
 ****       ALWAYS write to the end of the file. You cannot open the file in
 ****       write mode either (w or w+), as this will truncate an existing file
 ****       to 0 bytes. You MUST open the file in "r+" mode (means: r+w) and if
 ****       that fails (could mean: file does not exist) retry in "w" mode.
 */
int writeAnimalToFile(
            const char* filename, size_t filePosition, const Animal* animalPtr){
    return -1;
}

/* pre	   :
 * post    : change the animal name on the filePosition in this way:
 *	         The new animal name will start with animalSurname, followed
 *           by a space and followed by the original animal name
 * Example : We have animal called "Max" on filePosition and animalSurname
 *           "Verstappen". The new animal name will be "Verstappen Max".
 *           The renamed animal will be written back to the file.
 * returns : On success: 0, on error: -1
 */
int renameAnimalInFile(
            const char* filename, size_t filePosition, const char* animalSurname){
    return -1;
}
