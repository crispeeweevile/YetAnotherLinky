#include <stdio.h>
#include "linkedsys.h"

int main(int arc, char *arv[]) {
    {
        LList *tList = create_llist(create_node(create_data(1, 2, 3)));
        print_node(tList->current, true);
    }

    return 0;
}
