#include <stdio.h>
#include "linkedsys.h"

int main(int arc, char *arv[]) {
    while (true){
        LList *tList = create_llist(create_node(create_data(1, 2, 3)));
        print_node(tList->current, true);
        insert_at_tail(tList, create_node(create_data(4, 5, 6)));
        goto_next(tList);
        print_node(tList->current, true);
        if (free_llist(tList, true) != FSUCCESS) {
            printf("cocks\n");
            return 1;
        }
        printf("current: %p; head: %p; tail: %p\n", tList->current, tList->head, tList->tail);
        tList = NULL;
    }

    return 0;
}
