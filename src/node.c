#include <stdio.h>
#include "node.h"
#include "gen_utils.h"

Node *create_node(Data *data) {
    if (!data) {return NULL;}
    Node *nNode = smalloc(sizeof(Node));

    nNode->data = data;
    nNode->next = NULL;
    nNode->prev = NULL;

    return nNode;
}

FError free_node(Node *node, bool bFreeData) {
    if (!node) {return FFAILURE;}
    if (bFreeData) {
        if(free_data(node->data) != FSUCCESS) {
            printf("Failed to free data from node!\n");
            return FFAILURE;
        }
    }

    node->data = NULL;
    node->next = NULL;
    node->prev = NULL;
    free(node);

    return FSUCCESS;
}

FError print_node(Node *node, bool printData) {
    if (!node) {return FFAILURE;}
    printf("NodePTR: %p; DataPTR: %p; NextPTR: %p; PrevPTR: %p\n", node, node->data, node->next, node->prev);
    if (printData) {
        if (!node->data) {return FFAILURE;}
        Data *data = node->data;
        printf("DMoney: %d; DItems: %d; DDebt: %d\n", data->money, data->items, data->debt);
    }

    return FSUCCESS;
}
