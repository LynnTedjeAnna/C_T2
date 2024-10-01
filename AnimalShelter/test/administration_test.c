#include <string.h>

#include "administration.h"
#include "unity.h"
#include "unity_test_module.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void administration_setUp(void)
{
    // This is run before EACH test
}

void administration_tearDown(void)
{
    // This is run after EACH test
}

void test_EmptyTest(void)
{
    TEST_ASSERT_EQUAL(1, 0);
    TEST_ASSERT_EQUAL(-1, -1);
    TEST_ASSERT_EQUAL(-1, -1);
    TEST_ASSERT_EQUAL(-1, -1);
    TEST_ASSERT_EQUAL(0, 0);
}

//add here your testcases
void test_addAnimal_emptyArray(void) {
    Animal test;                       // Declare an Animal structure 'test'.
    size_t test_nnoap;                 // Declare a variable 'test_nnoap' of type size_t (typically used for array sizes).

    // Call the 'addAnimal' function with the following parameters:
    // - &test: A pointer to the 'test' Animal object.
    // - NULL: This likely represents an empty array, indicating that no existing animals are present.
    // - 10: This might be a limit or size parameter, possibly the maximum capacity of the array.
    // - 0: This could be the current number of animals in the array (0 because it's empty).
    // - &test_nnoap: A pointer to 'test_nnoap', where 'addAnimal' may store the new number of animals after the operation.
    int res = addAnimal(&test, NULL, 10, 0, &test_nnoap);

    // Check if the result of 'addAnimal' is -1, which indicates an error (such as an attempt to add an animal to a NULL array).
    TEST_ASSERT_EQUAL(res, -1);
}
void test_addAnimal_fullArray(void) {
    Animal test;
    size_t test_nnoap;
    Animal animal_array[10];  // Correct type for the animal array
    int res = addAnimal(&test, animal_array, 10, 10, &test_nnoap);
    TEST_ASSERT_EQUAL(res, -1);  // Check for -1, indicating the array is full
}
void test_removeAnimal_emptyArray(void){
    size_t test_nnoap;
    int res = removeAnimal(0, NULL, 0, &test_nnoap);
    TEST_ASSERT_EQUAL(res, -1);
}
void test_removeAnimal(void){
    size_t test_nnoap;
    Animal animal_array[10];  // Correct type for the animal array
    int res = removeAnimal(1, animal_array, 10, &test_nnoap);
    TEST_ASSERT_EQUAL(res, 0);
}

void test_sortAnimalsByAge_one_animal(void) {
    // Initialize the array with one animal
    Animal animal_array[1] = {
        { .Id = 1, .Species = Dog, .Sex = Male, .Age = 5, .DateFound = {1, 1, 2020} }
    };
    int res = sortAnimalsByAge(animal_array, 1);

    TEST_ASSERT_EQUAL(0, res);

    // Since we only have one animal, the age should still be 5 after sorting
    TEST_ASSERT_EQUAL(5, animal_array[0].Age);
}
void test_sortAnimalsByAge(void) {
    // Initialize the array with one animal
    Animal animal_array[2] = {
        { .Id = 1, .Species = Dog, .Sex = Male, .Age = 5, .DateFound = {1, 1, 2020}  },
        { .Id = 2, .Species = Cat, .Sex = Male, .Age = 7, .DateFound = {1, 2, 2020}  }
    };
    int res = sortAnimalsByAge(animal_array, 2);

    TEST_ASSERT_EQUAL(0, res);

    TEST_ASSERT_EQUAL(5, animal_array[0].Age);
    TEST_ASSERT_EQUAL(7, animal_array[1].Age);
}
void run_administration_tests(void)
{
    UnityRegisterSetupTearDown(administration_setUp, administration_tearDown);

    MY_RUN_TEST(test_EmptyTest);
    MY_RUN_TEST(test_addAnimal_emptyArray);
    MY_RUN_TEST(test_addAnimal_fullArray);
    MY_RUN_TEST(test_removeAnimal_emptyArray);
    MY_RUN_TEST(test_removeAnimal);
    MY_RUN_TEST(test_sortAnimalsByAge_one_animal);
    MY_RUN_TEST(test_sortAnimalsByAge);

    UnityUnregisterSetupTearDown();
}

