#pragma once

typedef struct SData {
    int money;
    int items;
    int debt;
} Data;

typedef struct SNode {
    struct SData *data;
    struct SNode *next;
    struct SNode *prev;
} Node;

typedef struct SLList {
    Node *current;
    Node *head;
    Node *tail;
} LList;
