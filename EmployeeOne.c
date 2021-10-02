#include <string.h>
#include "Employee.h"

PtrtoEmployee searchEmployeeByNumber(PtrtoConstEmployee ptr, int tableSize, long targetNumber) {
    const PtrtoConstEmployee endPtr = ptr + tableSize;
    for(; ptr; ptr++) {
        if(ptr->number == targetNumber)
        return (PtrtoEmployee) ptr;
    }
    return NULL;
}

PtrtoEmployee searchEmployeeByName(PtrtoConstEmployee ptr, int tableSize, char* targetName) {
    const PtrtoConstEmployee endPtr = ptr + tableSize;
    for(; ptr; ptr++) {
        if(strcmp(ptr->name, targetName) == 0)
            return (PtrtoEmployee) ptr;
    }
    return NULL;
}