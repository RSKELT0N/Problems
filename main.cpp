#include <iostream>
#include <vector>

using namespace std;


template<class T>
struct LinkedList {

    struct Node {
        T val;
        Node *next;
        Node *prev;

        Node(T val) {
            this->val = val;
            this->next = NULL;
        }
    };

    Node *first;
    Node *last;

    LinkedList() {
        this->first = NULL;
        this->last = NULL;
    }


    LinkedList add(T val) {
        Node *data = new Node(val);
        if (data == NULL)
            return *this;

        if (first == NULL) {
            first = last = data;
        } else {
            last->next = data;
            last->prev = last;
            last = data;
        }
        return *this;
    }

    string toString() {
        string res = "";
        Node *node = first;
        int pos = 0;
        while (node != NULL) {
            res += (node->val) + " ";
            node = node->next;
        }
        return res;
    }

    int size() {
        Node *node = first;
        int size = 0;
        while (node != NULL) {
            size++;
            node = node->next;
        }
        return size;
    }

    T get(int n) {
        Node *data = first;
        int pos = 0;
        while(data != NULL) {
            if(pos == n)
                return data->val;
            pos++;
            data = data->next;
        }
        return T {};
    }
};


int main() {
    LinkedList<string> list;
    list.add("Hey").add("my").add("name").add("is").add("Ryan").add("!");
    cout << "Values within LinkedList: " << list.toString() << "\nLength: " << list.size() << "\nGet pos: " << list.get(4);
    return 0;
}
