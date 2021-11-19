#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED
#include "../lab4/class_Event.hpp"
#include "../lab4/class_TimeString.hpp"

class List {

public:
    List() {
        size = 0;
        head = nullptr;
    }
    void Push(DateTime date);
    void Push(TimeString date);
    void Push(Event date);
    DateTime* Pop();
    int Search(DateTime date);
    int Search(TimeString date);
    int Search(Event date);
    char* Show();
    int GetSize() { return size; }

    ~List() {
        while (size) {
            Pop();
        }
    }

private:

        class Node {

    private:
        Node *next;
        DateTime *data;

    public:
        friend class List;
        Node() {}
        Node(DateTime date) {
            this->data = new DateTime(date);
            this->next = nullptr;
        }

        Node(TimeString date) {
            this->data = new TimeString(date);
            this->next = nullptr;
        }

        Node(Event date) {
            this->data = new Event(date);
            this->next = nullptr;
        }
        ~Node() {
            delete this->data;
        }
    };
    int size;
    Node *head;
};

#endif // STACK_HPP_INCLUDED