//gcc main.c EmployeeTable.c

#include <string.h>
#include <stdlib.h>
#include "Employee.h"

int main(void) {
    // defined in EmployeeOne.c
    PtrtoEmployee searchEmployeeByNumber(const Employee table[], int sizetable, long numberTofind);
    PtrtoEmployee searchEmployeeByName(const Employee table[], int sizetable, char* nameTofind);
    PtrtoEmployee searchEmployeeByPhone(const Employee table[], int sizetable, char* phoneTofind);
    PtrtoEmployee searchEmployeeBySalary(const Employee table[], int sizetable, double salaryTofind);

    // defined in Table.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrtoEmployee matchPtr; //Declaration

    //Example not found
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    if(matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if(matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT in the record\n");

    //Example found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if(matchPtr != NULL)
        printf("Employee with number 909-555-2134 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with number 909-555-2134 is NOT in the record\n");

    //Example not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-1111");
    if(matchPtr != NULL)
        printf("Employee with number 909-555-1111 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with number 909-555-1111 is NOT in the record\n");

    //Example found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);
    if(matchPtr != NULL)
        printf("Employee with salary 4.50 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 4.50 is NOT in the record\n");

    //Example not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.51);
    if(matchPtr != NULL)
        printf("Employee with salary 4.50 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 4.50 is NOT in the record\n");

    return EXIT_SUCCESS;
}