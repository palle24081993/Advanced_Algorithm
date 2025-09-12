#include <iostream>
#include <map>

using namespace std;

int main() {
    int row, column, value;
    map<pair<int, int>, int> spm;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> column;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "Enter value for element at (" << i << ", " << j << "): ";
            cin >> value;
            if (value != 0) {
                spm[{i, j}] = value;
            }
        }
    }
    cout << "\nSparse Matrix Representation (Row, Column, Value):\n";
    cout << "| Row |Column| Value |\n";
    cout << "|-----|------|-------|\n";
    for (const auto& element : spm) {
        cout << "|  " << element.first.first << "   |   " << element.first.second 
             << "    |   " << element.second << "   |\n";
    }
    return 0;
}
