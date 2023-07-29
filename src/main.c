#include <stdio.h>
#include "linkedsys.h"

int main(int arc, char *arv[]) {
    {
        LList *tList = create_llist(create_node(create_data(1, 2, 3))); // 0
        print_cur_node(tList, true);
        insert_at_tail(tList, create_node(create_data(4, 5, 6)));       // 1
        goto_next(tList);
        printf("went forth\n");
        print_cur_node(tList, true);
        goto_prev(tList);
        printf("went back\n");
        print_cur_node(tList, true);
        printf("insert a 'ton'\n");
        insert_at_tail(tList, create_node(create_data(4, 5, 6)));       // 2
        insert_at_tail(tList, create_node(create_data(7, 8, 9)));       // 3
        insert_at_tail(tList, create_node(create_data(10, 11, 12)));    // 4
        insert_at_tail(tList, create_node(create_data(13, 14, 15)));    // 5
        insert_at_tail(tList, create_node(create_data(16, 17, 18)));    // 6
        insert_at_tail(tList, create_node(create_data(19, 20, 21)));    // 7
        insert_at_tail(tList, create_node(create_data(22, 23, 24)));    // 8
        insert_at_tail(tList, create_node(create_data(25, 26, 27)));    // 9
        insert_at_tail(tList, create_node(create_data(28, 29, 30)));    // 10
        insert_at_tail(tList, create_node(create_data(31, 32, 33)));    // 11
        insert_at_tail(tList, create_node(create_data(34, 35, 36)));    // 12
        FError err = goto_index(tList, 12);
        if (err != FSUCCESS) {
            printf("ooooof\n");
        }
        print_cur_node(tList, true);

        insert_at_head(tList, create_node(create_data(-2, -1, 0)));     // all previous indices +1
        err = goto_index(tList, 0);
        if (err != FSUCCESS) {
            printf("ooooof\n");
        }
        print_cur_node(tList, true);

        printf("freeing\n");
        if (free_llist(tList, true) != FSUCCESS) {
            printf("free list failed!!!!\n");
            return 1;
        } else {tList = NULL;}

        printf("Finished program. . .\n");
    }

    return 0;
}
