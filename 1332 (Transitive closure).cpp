#include <iostream>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int **matrix = new int * [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int [n];
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
    }
 
    for (int p = 0; p < n; ++p)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][p] == 1 && matrix[p][j] == 1)
                    matrix[i][j] = 1;
 
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << ' ';
        cout << endl;
        delete [] matrix[i];
    }
    delete [] matrix;
    return 0;
}