#include "data.h"
#include "gen_utils.h"

Data *create_data(int iMoney, int iItems, int iDebt) {
    Data *nData = smalloc(sizeof(Data));
    nData->money = iMoney;
    nData->items = iItems;
    nData->debt = iDebt;

    return nData;
}

FError free_data(Data *data) {
    if (!data) {return FFAILURE;}
    data->money=0;
    data->items=0;
    data->debt=0;
    free(data);
    return FSUCCESS;
}
