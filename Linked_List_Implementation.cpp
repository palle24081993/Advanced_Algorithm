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

    void insert(int row, int column, int value) {
        Node* newNode = new Node(row, column, value);  
        if (head == nullptr) {
            head = newNode;  
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {  
                temp = temp->next;
            }
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
            temp = temp->next;  // Move to the next node
        }
    }

    ~SparseMatrixLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int rows, column, value;

    SPMLinkedList spm;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> column;

    cout << "Enter the elements of the matrix (0 for empty):\n";
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < column; ++j) {
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
