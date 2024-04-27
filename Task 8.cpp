#include <iostream>
#include <pthread.h>

using namespace std;

// the size of the matrix and number of thread
const int matrix_size = 4;
const int number_of_threads = 2;

// the 2 matricies i hard coded
int matrixA[matrix_size][matrix_size] = {
    {1, 5, 9, 13},
    {2, 6, 10, 14},
    {3, 7, 11, 15},
    {4, 8, 12, 16}
};

int matrixB[matrix_size][matrix_size] = {
    {16, 12, 8, 4},
    {15, 11, 7, 3},
    {14, 10, 6, 2},
    {13, 9, 5, 1}
};

// result matrix
int resultMatrix[matrix_size][matrix_size];

// I use this structure to pass the range of rows each thread should work on
struct RowRange {
    int startRow;
    int endRow;
};

// This function prints any given matrix
void printMatrix(const int matrix[matrix_size][matrix_size], const string& name) {
    cout << "Matrix " << name << ":" << endl;
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// This is the function each thread runs it multiplies a subset of rows from matrix A with matrix B
void* multiplyRowSubset(void* arg) {
    RowRange* rowRange = (RowRange*)arg;
    for (int row = rowRange->startRow; row <= rowRange->endRow; row++) {
        for (int col = 0; col < matrix_size; col++) {
            resultMatrix[row][col] = 0; // Start with zero.
            for (int k = 0; k < matrix_size; k++) {
                // Perform the actual multiplication.
                resultMatrix[row][col] += matrixA[row][k] * matrixB[k][col];
            }
        }
    }
    return NULL;
}

// The main function sets up the threads and starts the multiplication process
int main() {
    pthread_t threads[number_of_threads];
    RowRange rowRanges[number_of_threads];
    int rowsPerThread = matrix_size / number_of_threads;
    int additionalRows = matrix_size % number_of_threads;
    int rc, currentStartRow = 0;

    // First, I print the matrices before multiplication
    printMatrix(matrixA, "A");
    printMatrix(matrixB, "B");

    // Here I distribute the work among the threads
    for (int i = 0; i < number_of_threads; i++) {
        rowRanges[i].startRow = currentStartRow;
        rowRanges[i].endRow = currentStartRow + rowsPerThread - 1;
        if (additionalRows > 0) {
            rowRanges[i].endRow++;
            additionalRows--;
        }
        currentStartRow = rowRanges[i].endRow + 1;

        // Creating the threads.
        rc = pthread_create(&threads[i], NULL, multiplyRowSubset, (void*)&rowRanges[i]);
        if (rc) {
            cerr << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
    }

    // Waiting for all threads to complete
    for (int i = 0; i < number_of_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Finally, I print the resulting matrix
    cout << "Resulting Matrix (MatrixA x MatrixB):" << endl;
    for (int row = 0; row < matrix_size; row++) {
        for (int col = 0; col < matrix_size; col++) {
            cout << resultMatrix[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
