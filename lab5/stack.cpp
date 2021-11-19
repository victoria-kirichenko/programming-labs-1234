#include "stack.hpp"

void List::Push(DateTime date) {
    Node *n = new Node(date);
    n->next = head;
    head = n;
    size++;
}

void List::Push(TimeString date) {
    Node *n = new Node(date);
    n->next = head;
    head = n;
    size++;
}

void List::Push(Event date) {
    Node *n = new Node(date);
    n->next = head;
    head = n;
    size++;
}

DateTime* List::Pop() {
    if (size == 0) {
        return nullptr;
    }
    Node *temp = head;
    head = head->next;
    DateTime *x = temp->data;
    DateTime *y = new DateTime(*x);
    delete temp;
    size--;
    return y;
}

char *List::Show() {
    char *arr;
    Node *ptr = head;
    int sz = GetSize(), s = 0, i = 0;
    while (ptr != NULL) {
        while (i < sz) {
            s += ptr->data->SizeOfDate();
            arr = new char[s];
            sprintf(arr, "");
            i++; 
        }
        strcat(arr, ptr->data->GetStr());
        strcat(arr, "\n");
        ptr = ptr->next;
    }
    return arr;
}

int List::Search(DateTime date) {
    Node* ptr = head;
    int sz = GetSize();
    for (int i = 0; i < sz; i++) {
        if (!(memcmp(ptr->data->GetDateTime(), date.GetDateTime(), 19))) {
           return i;
        }
        ptr = ptr->next;
    }
    return -1;
}

int List::Search(TimeString date) {
    Node* ptr = head;
    int sz = GetSize();
    for (int i = 0; i < sz; i++) {
        if (!(memcmp(ptr->data->GetDateTime(), date.GetDateTime(), 19))) {
           return i;
        }
        ptr = ptr->next;
    }
    return -1;
}

int List::Search(Event date) {
    Node* ptr = head;
    int sz = GetSize();
    for (int i = 0; i < sz; i++) {
        if (!(memcmp(ptr->data->GetDateTime(), date.GetDateTime(), 19))) {
           return i;
        }
        ptr = ptr->next;
    }
    return -1;
}
