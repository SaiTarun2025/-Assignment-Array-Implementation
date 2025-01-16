#include <iostream>
#include <vector>

using namespace std;

// Struct to represent a non-zero element in a sparse matrix
struct Element {
    int row;
    int col;
    int value;
};

// Class to handle Sparse Matrix operations
class SparseMatrix {
private:
    int rows;
    int cols;
    vector<Element> elements;

public:
    // Constructor to initialize rows and columns
    SparseMatrix(int rows, int cols) : rows(rows), cols(cols) {}

    // Method to add a non-zero element
    void addElement(int row, int col, int value) {
        if (value != 0) {
            elements.push_back({row, col, value});
        }
    }

    // Method to display the sparse matrix in a tabular format
    void display() {
        cout << "\nSparse Matrix Representation:" << endl;
        for (const auto& element : elements) {
            cout << "Row: " << element.row
                 << ", Col: " << element.col
                 << ", Value: " << element.value << endl;
        }
    }

    // Method to display the matrix in full form
    void displayFullMatrix() {
        cout << "\nFull Matrix Representation:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                bool found = false;
                for (const auto& element : elements) {
                    if (element.row == i && element.col == j) {
                        cout << element.value << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int rows, cols, nonZeroCount;

    // User input for dimensions of the matrix
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    // Create a sparse matrix object
    SparseMatrix matrix(rows, cols);

    // User input for the number of non-zero elements
    cout << "Enter the number of non-zero elements: ";
    cin >> nonZeroCount;

    // Collect non-zero elements from the user
    cout << "Enter the row, column, and value of each non-zero element:" << endl;
    for (int i = 0; i < nonZeroCount; ++i) {
        int row, col, value;
        cout << "Element " << i + 1 << ": ";
        cin >> row >> col >> value;

        // Validate input
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            cout << "Invalid position! Row and column must be within matrix bounds." << endl;
            --i; // Retry the current element
        } else {
            matrix.addElement(row, col, value);
        }
    }

    // Display the sparse matrix
    matrix.display();

    // Display the full matrix
    matrix.displayFullMatrix();

    return 0;
}
