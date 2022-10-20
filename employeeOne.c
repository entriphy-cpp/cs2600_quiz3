#include <string.h>
#include "employee.h"

// Search for an employee by number
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber) {
    const PtrToConstEmployee endPtr = ptr + tableSize; // Calculate pointer to the end of the table
    for (; ptr < endPtr; ptr++) { // Iterate through employee table
        if (ptr->number == targetNumber) { // Employee number in current iteration equals target number
            return (PtrToEmployee) ptr; // Return pointer to found employee
        }
    }
    return NULL; // Could not find employee matching number; employee could not be found
}

// Search for an employee by name
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName) {
    const PtrToConstEmployee endPtr = ptr + tableSize; // Calculate pointer to the end of the table
    for (; ptr < endPtr; ptr++) { // Iterate through employee table
        if (strcmp(ptr->name, targetName) == 0) { // Employee name in current iteration equals target name
            return (PtrToEmployee) ptr; // Return pointer to found employee
        }
    }
    return NULL; // Could not find employee matching name; employee could not be found
}