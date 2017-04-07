#include <iostream>
 
using namespace std;
 
int main() {
    int v, start, finis;
    cin >> v >> start >> finis;
    --start; --finis;
    int **matrix = new int *[v];
    for (int i = 0; i < v; ++i)  {
        matrix[i] = new int [v];
        for (int j = 0; j < v; ++j)
            cin >> matrix[i][j];
    }
 
    for (int p = 0; p < v; ++p)
        for (int i = 0; i < v; ++i)
            for (int j = 0; j < v; ++j)
                if (matrix[i][p] > 0 && matrix[p][j] > 0 && (matrix[i][p] + matrix[p][j] < matrix[i][j] || matrix[i][j] < 0))
                    matrix[i][j] = matrix[i][p] + matrix[p][j];
    if (matrix[start][finis] < 0)
        cout << -1;
    else
        cout << matrix[start][finis];
 
    for (int i = 0; i < v; ++i)
        delete []matrix[i];
    delete []matrix;
//  system("PAUSE");
    return 0;
}