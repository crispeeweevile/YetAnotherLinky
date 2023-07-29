#include <stdio.h>
#include "linkedsys.h"
#include "gen_utils.h"

LList *create_llist(Node *node) {
    if (!node) {return NULL;}
    LList *nList = smalloc(sizeof(LList));

    nList->length = 1;
    nList->curIndex = 0;
    nList->current = node;
    nList->head = node;
    nList->tail = node;

    return nList;
}

FError free_llist(LList *list, bool bFreeData) {
    if (!list) {return FFAILURE;}
    while (list->tail->prev) {
        Node *nRemove = remove_tail(list);
        if (nRemove) {
            if (free_node(nRemove, bFreeData) != FSUCCESS) {return FFAILURE;}
            nRemove = NULL;
        } else {break;}
    }
    
    if ((list->tail == list->head) && (list->head == list->current)) {
        if(free_node(list->current, bFreeData) != FSUCCESS) {return FFAILURE;}
        list->tail = NULL;
        list->current = NULL;
        list->head = NULL;
    } else {return FFAILURE;}

    free(list);

    return FSUCCESS;
}

FError insert_at_tail(LList *list, Node *node) {
    if (!list || !node) {return FFAILURE;}
    if (list->tail->next) {return FFAILURE;}
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;

    list->length++;
    return FSUCCESS;
}

Node *remove_tail(LList *list) {
    if (!list || !list->tail) {return NULL;}
    Node *tail = list->tail;
    if (!tail->prev) {return NULL;}
    Node *tailPrev = tail->prev;

    if (tail == list->current) {
        list->current = tailPrev;
    }

    list->tail = tailPrev;
    tailPrev->next = NULL;
    tail->prev = NULL;
    list->length--;
    return tail;
}


FError goto_next(LList *list) {
    if (!list || !list->current) {return FFAILURE;}
    if (!list->current->next) {return FFAILURE;}
    Node *next = list->current->next;
    list->current = next;
    list->curIndex++;

    return FSUCCESS;
}

FError has_next(LList *list) {
    if (!list || !list->current) {return FFAILURE;}
    if (!list->current->next) {return FFAILURE;}
    return FSUCCESS;
}

FError goto_prev(LList *list) {
    if (!list || !list->current) {return FFAILURE;}
    if (!list->current->prev) {return FFAILURE;}
    Node *prev = list->current->prev;
    list->current = prev;
    list->curIndex--;

    return FSUCCESS;
}

FError has_prev(LList *list) {
    if (!list || !list->current) {return FFAILURE;}
    if (!list->current->prev) {return FFAILURE;}
    return FSUCCESS;
}

FError goto_index(LList *list, int index) {
    if (!list || !list->current) {return FFAILURE;}
    // removed because you could be at head or tail (not cause for failure)
    //if (!list->current->next) {return FFAILURE;}
    //if (!list->current->prev) {return FFAILURE;}
    Node *curNode = list->current;

    if (list->curIndex != index) {
        while (curNode->next && list->curIndex < index) {
            FError err = goto_next(list);
            if (err != FSUCCESS) {return FFAILURE;}
            curNode = list->current;
        }
        while (curNode->prev && list->curIndex > index) {
            FError err = goto_prev(list);
            if (err != FSUCCESS) {return FFAILURE;}
            curNode = list->current;
        }
        
        if (list->curIndex != index) {return FFAILURE;}
    }

    return FSUCCESS;
}
