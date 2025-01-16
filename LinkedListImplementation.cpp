// Linked List Node definition for Sparse Matrix
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int row, col, value;
    Node* next;

    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

class SparseMatrix {
private:
    Node* head;

public:
    SparseMatrix() : head(nullptr) {}

    void insert(int row, int col, int value) {
        if (value == 0) return; // Ignore zero values
        Node* newNode = new Node(row, col, value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayMatrix(int totalRows, int totalCols) const {
        vector<vector<int>> matrix(totalRows, vector<int>(totalCols, 0));
        Node* temp = head;
        while (temp) {
            matrix[temp->row][temp->col] = temp->value;
            temp = temp->next;
        }

        cout << "\nSparse Matrix Representation:" << endl;
        for (int i = 0; i < totalRows; ++i) {
            for (int j = 0; j < totalCols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~SparseMatrix() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SparseMatrix sm;
    int rows, cols, value;

    cout << "Enter the total number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter the number of non-zero elements: ";
    int n;
    cin >> n;

    cout << "Enter row, column, and value for each non-zero element:" << endl;
    for (int i = 0; i < n; ++i) {
        int row, col;
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << "Value: ";
        cin >> value;
        sm.insert(row, col, value);
    }

    sm.displayMatrix(rows, cols);

    return 0;
}
