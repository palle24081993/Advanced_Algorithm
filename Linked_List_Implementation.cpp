#include <iostream>
using namespace std;

struct Node {
    int row, column, value;
    Node* next;
    Node(int r, int c, int v) : row(r), column(c), value(v), next(nullptr) {}
};

class SPMLinkedList {
private:
    Node* head;

public:
    SPMLinkedList() : head(nullptr) {}

    void insert(int r, int c, int v) {
        Node* newNode = new Node(r, c, v);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Matrix has no non-zero elements." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << "Row: " << temp->row
                 << ", Column: " << temp->column
                 << ", Value: " << temp->value
                 << ", Next Node Address: " << temp->next << endl;
            temp = temp->next;
        }
    }

    ~SPMLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int rows, cols, value;

    SPMLinkedList spm;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    cout << "Enter the elements of the matrix (0 for empty):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element at Row " << i << ", Column " << j << ": ";
            cin >> value;
            if (value != 0) {
                spm.insert(i, j, value);
            }
        }
    }

    cout << "\nSparse Matrix Linked List Representation:\n";
    spm.display();

    return 0;
}
