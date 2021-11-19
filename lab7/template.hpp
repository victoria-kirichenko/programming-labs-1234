#ifndef TEMPLATE_HPP_INCLUDED
#define TEMPLATE_HPP_INCLUDED
#include "../lab4/class_Event.hpp"
#include "../lab4/class_TimeString.hpp"

template<typename T> class ListT {

public:
    ListT() {
        size = 0;
        head = nullptr;
    }
    void Push(T date);
    void Pop();
    int Search(T date);
    char* Show();
    int GetSize() { return size; }
    int SizeOfDate();
	char *GetStr();

    ~ListT() 
    {  
        while (size) {
            Pop();
        }
    }

private:

        class Node {

    private:
        Node *next;
        T *data;

    public:
        friend class ListT;
        Node() {}
        Node(T date) {
            this->data = new T(date);
            this->next = nullptr;
        }
        ~Node() {
            delete this->data;
        }
    };
    int size;
    Node *head;
};

#endif // TEMPLATE_HPP_INCLUDED