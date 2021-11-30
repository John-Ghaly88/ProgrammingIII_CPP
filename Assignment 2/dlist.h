#ifndef DLIST_H_INCLUDED
#define DLIST_H_INCLUDED

struct DListobj{
    int info;
    struct DListobj * next;
    struct DListobj * prev;
};

typedef DListobj * DList;

struct DListobj * head = NULL;

void initializeDList(DList & dl);
void put(DList& dl, int val);
bool get(DList& dl, int &val);
bool isEmpty(DList dl);
int dlistLength(DList& dl);

#endif // DLIST_H_INCLUDED
