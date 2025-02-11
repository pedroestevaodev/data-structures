#include "list.h"
#include <iostream>
using namespace std;

List::List() {
    count = 0;
    head = NULL;
}

List::~List() {
    ListPointer q;
    while (head != NULL) {
        q = head;
        head = head->NextNode;
        delete q;
    }

    count = 0;
}

bool List::Empty() {
    return count == 0;
}

bool List::Full() {
    return false;
}

void List::SetPosition(int p, ListPointer &current) {
    
}