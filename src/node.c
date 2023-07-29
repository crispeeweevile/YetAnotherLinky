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

    return FSUCCESS;
}
