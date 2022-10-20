#include <stdlib.h>
#include "employee.h"

// External table
extern Employee EmployeeTable[];
extern const int EmployeeTableEntries;

// External functions
PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char *phoneNumberToFind);
PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double *salary);

int main(void)
{
    // Test each function when employee is found

    // Test each function when employee is not found

    return EXIT_SUCCESS;
}
