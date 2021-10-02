#include <string.h>
#include "Employee.h"

PtrtoEmployee searchEmployeeByNumber(PtrtoConstEmployee ptr, int tableSize, long targetNumber) {
    const PtrtoConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++) {
        if(ptr->number == targetNumber)
        return (PtrtoEmployee) ptr;
    }
    return NULL;
}

PtrtoEmployee searchEmployeeByName(PtrtoConstEmployee ptr, int tableSize, char* targetName) {
    const PtrtoConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++) {
        if(strcmp(ptr->name, targetName) == 0)
            return (PtrtoEmployee) ptr;
    }
    return NULL;
}

PtrtoEmployee searchEmployeeByPhone(PtrtoConstEmployee ptr, int tableSize, char* targetPhone) {
    const PtrtoConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++) {
        if(strcmp(ptr->phone, targetPhone) == 0)
            return (PtrtoEmployee) ptr;
    }
    return NULL;
}

PtrtoEmployee searchEmployeeBySalary(PtrtoConstEmployee ptr, int tableSize, double targetSalary) {
    const PtrtoConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++) {
        if(ptr->salary == targetSalary)
        return (PtrtoEmployee) ptr;
    }
    return NULL;
}
