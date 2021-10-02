#include <string.h>
#include "Employee.h"

static PtrtoEmployee searchEmployeeTable(PtrtoConstEmployee ptr, int tableSize, const void *targetPtr,
                                        int (*functionPtr)(const void *, PtrtoConstEmployee))
{
    PtrtoConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++) 
        if((*functionPtr)(targetPtr, ptr) == 0)
            return (PtrtoEmployee) ptr;
    return NULL;
}

static int compareEmployeeNumber(const void *targetPtr, PtrtoConstEmployee tableValuePtr)
{
    return * (long *) targetPtr != tableValuePtr->number;
}

static int compareEmployeeName(const void *targetPtr, PtrtoConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr->name);
}

static int compareEmployeePhone(const void *targetPtr, PtrtoConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr->phone);
}

static int compareEmployeeSalary(const void *targetPtr, PtrtoConstEmployee tableValuePtr)
{
    return * (double *) targetPtr != tableValuePtr->salary;
}

// wrappers
PtrtoEmployee searchEmployeeByNumber(PtrtoConstEmployee ptr, int size, long number)
{
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

PtrtoEmployee searchEmployeeByName(PtrtoConstEmployee ptr, int size, char* name)
{
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}

PtrtoEmployee searchEmployeeByPhone(PtrtoConstEmployee ptr, int size, char* phone)
{
    return searchEmployeeTable(ptr, size, phone, compareEmployeePhone);
}

PtrtoEmployee searchEmployeeBySalary(PtrtoConstEmployee ptr, int size, double number)
{
    return searchEmployeeTable(ptr, size, &number, compareEmployeeSalary);
}