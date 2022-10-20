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
    
    // Test each function when employee is not found
    PtrToEmployee employeeSearchNumberPtrFail = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 7777);
    PtrToEmployee employeeSearchNamePtrFail = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Matthew Finerty");
    PtrToEmployee employeeSearchPhoneNumberPtrFail = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "123-456-7890");
    PtrToEmployee employeeSearchSalaryPtrFail = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 0.00);

    return EXIT_SUCCESS;
}
