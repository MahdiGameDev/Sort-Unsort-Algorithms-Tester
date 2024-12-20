// Library section -------------------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
/**
 * Feel free to include some helpfull libraries
 */



// Helpful functions -----------------------------------//
/**
 * Feel free to create some helpfull functions
 */



















// Sort Algorithms -------------------------------------//
/**
 * Feel free to create Sort Functions here (the type must be void)
 */
// void sortFunction1(int* arra, int size) {}
// void sortFunction2(int* arra, int size) {}
// void sortFunction3(int* arra, int size) {}
// .
// .
// .



void Sort(int* array, int size) {
    /**
     * Place the Sort Function that you went use here (The programme will automatically check)
     * The programme support one function if you want more just add a switch
     */
    // sortFunctionN(array, size);
}




















// Unsort Algorithms -----------------------------------//
/**
 * Feel free to create Unsort Functions here (the type must be void)
 */



// void unsortFunction1(int* arra, int size) {}
// void unsortFunction2(int* arra, int size) {}
// void unsortFunction3(int* arra, int size) {}
// .
// .
// .



void Unsort(int* array, int size) {
    /**
     * Place the Unsort Function that you went use here (The programme will automatically check)
     * The programme support one function if you want more just add a switch
     */
    // unsortFunctionN(array, size);
}




















// Program Functions -----------------------------------//
void generateArray(int* array, int max, int size) { // Generate Random Array List
    srand(time(0));
    for (int i = 0; i < size; i++) {
        bool add = false;
        while (!add) {
            // Generate A Random Number
            int rand_number = (rand() % max) + 1;

            // Check The Number
            int attempts = 0;
            for (int j = 0; j < size; j++) {
                if (array[j] != rand_number) attempts++;
            }

            // Adding The Number
            if (attempts >= size) {
                array[i] = rand_number;
                add = true;
            }
        }
    }
}

bool checkArray(int* array, int size, bool OptionCheck) { // Check For Sorting/Unsorting Array List
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) return !OptionCheck;
    }
    return OptionCheck;
}

void outputArray(int* array, int size) { // Output An Array
    printf("\n[");
    for (int i = 0; i < size; i++) {
        if (i == 0) printf("%d", array[i]);
        else printf(", %d", array[i]);
    }
    printf("]\n");
}

int main() {
    // Procedural Array Generation Setting
    srand(time(0));
    unsigned int size = (rand() % 25) + 5;
    int max = (rand() % (300 - size)) + size;

    // Check Setting
    unsigned long waitTime = 500;
    unsigned int repetitions = 4;
    bool sorting = false;

    // Generate A Random Array
    int* array = calloc(size, sizeof(int));
    generateArray(array, max, size);

    // Output The Generated Array
    printf("\nThe generated array : ");
    outputArray(array, size);

    // Check The Sorting Algorithm
    Sort(array, size);
    printf("\nSorting the array");
    for (int i = 0; i < repetitions; i++) {
        _sleep(waitTime);
        printf(".");
    }
    if (checkArray(array, size, true)) {
        printf("\n\nAccepted!");
        printf("\nThe sorted array : ");
        sorting = true;
        outputArray(array, size);
    } else printf("\nWrong\n");


    // Check The Unsorting Algorithm
    printf("\nUnsorting the array");
    for (int i = 0; i < repetitions; i++) {
        _sleep(waitTime);
        printf(".");
    }
    if (checkArray(array, size, false) && sorting) {
        printf("\n\nAccepted!");
        printf("\nThe unsorted array : ");
        outputArray(array, size);
    } else printf("\nWrong\n");

    free(array);

    // Exit
    getchar();
    return 0;
}
