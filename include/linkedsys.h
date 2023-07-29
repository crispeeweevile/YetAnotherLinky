#pragma once
#include <stdbool.h>
#include "node.h"
#include "ferror.h"

typedef struct SLList {
    Node *current;
    Node *head;
    Node *tail;
} LList;

LList *create_llist(Node *node);
FError free_llist(LList *list, bool bFreeData);
FError insert_at_tail(LList *list, Node *node);
Node *remove_tail(LList *list);

FError goto_next(LList *list);
FError has_next(LList *list);
