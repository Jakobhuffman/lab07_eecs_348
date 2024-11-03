/*
Author: Jakob Huffman
KUID: 2975499
Date: 11/01/2024
Lab: lab07
Last modified: 11/03/2024
Purpose: Take a input file with 2 matrix's and use
operation overload and function overloading to perform 
matrix manipulation. 
*/
#include <iostream>
#include <fstream> //file header
using namespace std;

const int SIZE = 4; // Global constant for matrix size

class Matrix {
private:
    int data[SIZE][SIZE]; // 2D array for matrix data

public:
    // 1. Read values from file into a matrix
    void readFromFile(ifstream &file) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                file >> data[i][j];
            }
        }
    }

    // 2. Display a matrix
    void display() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = 0; 
                for (int k = 0; k < SIZE; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const {
        int mainDiagonalSum = 0;
        int secondaryDiagonalSum = 0;
        for (int i = 0; i < SIZE; ++i) {
            mainDiagonalSum += data[i][i];
            secondaryDiagonalSum += data[i][SIZE - i - 1];
        }
        return mainDiagonalSum + secondaryDiagonalSum;
    }

    // 6. Swap matrix rows
    void swapRows(int row1, int row2) {
        if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {
            for (int j = 0; j < SIZE; ++j) {
                swap(data[row1][j], data[row2][j]);
            }
        } else {
            cout << "Invalid row." << endl;
        }
    }
};

int main() {
    Matrix mat1, mat2;

    // Open the file
    ifstream file("matrix-data.txt");
    if (!file) {
        cout << "Error opening file: matrix-data.txt" << endl;
        return 1;
    }

    // Read Matrix 1 from file
    cout << "Reading values for Matrix 1:" << endl;
    mat1.readFromFile(file);
    mat1.display();

    // Read Matrix 2 from file
    cout << "Reading values for Matrix 2:" << endl;
    mat2.readFromFile(file);
    mat2.display();

    
    file.close();

    // addition
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    // multiplication
    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    
    // Swap rows in Matrix 1
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}