#include <iostream>
#include "dlist.h"

using namespace std;

void initializeDList(DList & dl){
    DList d1 = new DListobj;
    d1 = NULL;
}

void put(DList& dl, int val){
    DList p = new DListobj;
    initializeDList(p);

    dl = head;

    p->info = val;
    p->prev = NULL;
    p->next = head;
    if (head != NULL)
        head->prev = p;
    head = p;
}

bool get(DList& dl, int &val){
    if (isEmpty(dl))
        return false;
    else if (dlistLength(dl) == 1){
        dl = head;
        val = dl->info;
        delete(dl);
    }
    else{
        DList temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        dl = temp->next;
        val = dl->info;
        delete(dl);
        temp->next = NULL;
        return true;
    }
}

bool isEmpty(DList dl){
    return (dlistLength(dl) == 0);
}

int dlistLength(DList& dl){
    int c = 0;
    DList p = head;
    while (p != 0){
        c++;
        p = p->next;
    }
    return c;
}
