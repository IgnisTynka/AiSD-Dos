#include "functions.h"
#include <memory>

void sort(std::vector<int> &array) {
    int temp;
    size_t i, j;
    for (i = 1; i < array.size(); i++) {

        temp = array[i]; 
        j = i - 1;      
 
        while (j >= 0 && array[j] > temp) { 
            array[j + 1] = array[j]; 
            j = j - 1; 
        }

        array[j + 1] = temp; 
    }
}