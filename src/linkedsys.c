#include "linkedsys.h"
#include "gen_utils.h"

LList *create_llist(Node *node) {
    if (!node) {return NULL;}
    LList *nList = smalloc(sizeof(LList));

    nList->current = node;
    nList->head = node;
    nList->tail = node;

    return nList;
}

FError free_llist(LList *list, bool bFreeData) {
    return FFAILURE;
}

FError insert_at_tail(LList *list, Node *node) {
    if (!list || !node) {return FFAILURE;}
    if (list->tail->next) {return FFAILURE;}
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;

    return FSUCCESS;
}

Node *remove_tail(LList *list) {
    if (!list || !list->tail) {return FFAILURE;}
    Node *tail = list->tail;
    if (!tail->prev) {return FFAILURE;}
    Node *tailPrev = tail->prev;

    if (tail == list->current) {
        list->current = tailPrev;
    }

    list->tail = tailPrev;
    tailPrev->next = NULL;
    tail->prev = NULL;

    return tail;
}


FError goto_next(LList *list) {
    if (!list || !list->current) {return FFAILURE;}
    if (!list->current->next) {return FFAILURE;}
    Node *next = list->current->next;
    list->current = next;

    return FSUCCESS;
}

FError has_next(LList *list) {
    if (!list || !list->current) {return FFAILURE;}
    if (!list->current->next) {return FFAILURE;}
    return FSUCCESS;
}
