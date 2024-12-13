#include <iostream>
#include <iostream>

using namespace std;

class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "empty" << endl;
            return;
        }
        while (temp->next != nullptr) {
            cout << temp->value << " <-> ";
            temp = temp->next;
        }
        cout << temp->value << endl;
    }

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail;
    }

    int getLength() {
        return length;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void swapFirstLast() {
        if (length < 2) {
            return;
        }

        head->value = head->value ^ tail->value;
        tail->value = head->value ^ tail->value;
        head->value = head->value ^ tail->value;
    }

    void reverse() {
        if (length <= 2) {
            swapFirstLast();
            return;
        }

        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            temp = head;
            head = tail;
            tail = temp;
        }
    }

    bool isPalindrome() {
        if (length < 2) {
            return true;
        }

        Node* headTemp = head;
        Node* tailTemp = tail;

        for (int i = 0; i < length/2; i++) {
            if (headTemp->value != tailTemp->value) {
                return false;
            }
        }

        return true;
    }

    
    void swapPairs() {
        if (length < 2) {
            return;
        }

        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            Node* next = current->next;
            Node* nextNext = next->next;

            current->next = nextNext;
            if (nextNext != nullptr) {
                nextNext->prev = current;
            }

            next->prev = current->prev;
            if (current->prev != nullptr) {
                current->prev->next = next;
            } else {
                head = next;
            }

            next->next = current;
            current->prev = next;

            current = nextNext;
        }

        if (current != nullptr) {
            tail = current;
        }
    }
};

int main() {
    {
        DoublyLinkedList list(1);
        list.printList();
        list.reverse();
        list.printList();
    }

    {
        DoublyLinkedList list(1);
        list.append(2);
        list.printList();
        list.reverse();
        list.printList();
    }

    {
        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.printList();
        list.reverse();
        list.printList();
        cout << list.isPalindrome() << endl;
    }

    {
        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(2);
        list.append(1);
        list.printList();
        cout << list.isPalindrome() << endl;
    }


    {
        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);
        list.printList();
        list.swapPairs();
        list.printList();
    }
}
