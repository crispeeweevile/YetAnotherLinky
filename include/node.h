#pragma once
#include <stdbool.h>
#include "data.h"
#include "ferror.h"

typedef struct SNode {
    struct SData *data;
    struct SNode *next;
    struct SNode *prev;
} Node;

Node *create_node(Data *data);
FError free_node(Node *node, bool bFreeData);
