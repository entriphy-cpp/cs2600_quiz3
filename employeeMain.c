#include <stdlib.h>
#include "employee.h"

// External table
extern Employee EmployeeTable[];
extern const int EmployeeTableEntries;

// External functions
PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char *phoneNumberToFind);
PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

int main(void) {
    // Test each function when employee is found
    PtrToEmployee employeeSearchNumberPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1001);
    PtrToEmployee employeeSearchNamePtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tammy Franklin");
    PtrToEmployee employeeSearchPhoneNumberPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    PtrToEmployee employeeSearchSalaryPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34);
    
    // Check that each search was successful
    PtrToEmployee searches[] = { employeeSearchNumberPtr, employeeSearchNamePtr, employeeSearchPhoneNumberPtr, employeeSearchSalaryPtr };
    for (int i = 0; i < 4; i++) {
        PtrToEmployee employee = searches[i]; // Get pointer to employee from array
        if (employee == NULL) {
            // Search function is not working properly; exit program
            printf("Could not find employee %d; exiting...\n", i + 1);
            return EXIT_FAILURE;
        } else {
            // Employee found; search works correctly
            printf("Found employee %d-%d: %s (Phone number: %s, salary: %.2f)\n", i + 1, employee->number, employee->name, employee->phone, employee->salary);
        }
    }

    // Test each function when employee is not found
    PtrToEmployee employeeSearchNumberPtrFail = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 7777);
    PtrToEmployee employeeSearchNamePtrFail = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Matthew Finerty");
    PtrToEmployee employeeSearchPhoneNumberPtrFail = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "123-456-7890");
    PtrToEmployee employeeSearchSalaryPtrFail = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 0.00);

    // Check that each search was unsuccessful
    PtrToEmployee searchesFail[] = { employeeSearchNumberPtrFail, employeeSearchNamePtrFail, employeeSearchPhoneNumberPtrFail, employeeSearchSalaryPtrFail };
    for (int i = 0; i < 4; i++) {
        PtrToEmployee employee = searchesFail[i]; // Get pointer to employee from array
        if (employee != NULL) {
            // Search function is not working properly; exit program
            printf("Found employee %d; exiting...\n", i + 1);
            return EXIT_FAILURE;
        } else {
            // Employee not found; search properly returns null
            printf("Could not find employee %d (success)\n", i + 1);
        }
    }

    return EXIT_SUCCESS;
}
