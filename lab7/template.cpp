#include "template.hpp"

template<class T>
void ListT<T>::Push(T date) { 
    Node *n = new Node(date);
    n->next = head;
    head = n;
    size++;
}

template<class T>
void ListT<T>::Pop() {
    Node *temp = head;
    head = head->next;
    delete temp;
    size--;
}

template<class T>
char *ListT<T>::Show() {
    char *arr;
    char *str = new char[10];
    Node *ptr = head;
    int sz = GetSize(), s = 0, i = 0, len = 0;
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

template<>
char* ListT<int>::Show() {
    char *arr;
    char *str = new char[10];
    Node *ptr = head;
    int sz = GetSize(), s = 0, i = 0, len = 0;
        while (ptr != NULL) {
            while (i < sz) {
                    int temp = *ptr->data;
                    while (temp != 0) {
                        temp /= 10;
                        s++;
                    }
                    arr = new char[s];
                    sprintf(arr, "");
                    i++;
            }
            sprintf(str, "%d", *ptr->data);
            strcat(arr, str);
            strcat(arr, "\n");
            ptr = ptr->next;   
        }
        return arr;
}

template<class T>
int ListT<T>::Search(T date) {
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

template<>
int ListT<int>::Search(int date) {
    Node* ptr = head;
    int sz = GetSize();
    for (int i = 0; i < sz; i++) {
        if (*ptr->data == date) {
           return i;
        }
        ptr = ptr->next;
    }
    return -1;
}
