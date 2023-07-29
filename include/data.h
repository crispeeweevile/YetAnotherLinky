#pragma once
#include "ferror.h"

typedef struct SData {
    int money;
    int items;
    int debt;
} Data;


Data *create_data(int iMoney, int iItems, int iDebt);
FError free_data(Data *data);
