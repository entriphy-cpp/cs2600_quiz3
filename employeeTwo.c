#include <string.h>
#include "employee.h"

// Search through employee table using a pointer to a compare function
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, int (*functionPtr)(const void *, PtrToConstEmployee)) {
    PtrToConstEmployee endPtr = ptr + tableSize; // Calculate pointer to end of table
    for (; ptr < endPtr; ptr++) { // Iterate through each employee in the table
        if ((*functionPtr)(targetPtr, ptr) == 0) { // Call comparison function to check if the employee has been found
            return (PtrToEmployee) ptr; // Return pointer to found employee
        }
    }
    return NULL; // Employee could not be found
}

/* Comparison functions */

static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return *(long *) targetPtr != tableValuePtr->number;
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return strcmp((char *) targetPtr, tableValuePtr->name);
}

/* Wrapper functions (uses comparison functions, used in employeeMain) */

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number) {
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char *name) {
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}