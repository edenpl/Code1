#include <iostream>
#include <ctime>
using namespace std;



int main() {

    const int MAX = 10000;
    double A[MAX][MAX], x[MAX], y[MAX], time;

    clock_t start, end;
    int i, j;

    for (i = 0; i < MAX; ++i) {
        for (j = 0; j < MAX; ++j) {
            A[i][j] = 1;
        }
        x[i] = 1;
    }
    
    for (int k = 1000; k <= 10000; k+=1000) {
        
        cout << "N°: " << k << '\n';

        start = clock();
        for (i = 0; i < k; ++i) 
            for (j = 0; j < k; ++j)
                y[i] += A[i][j] * x[j];
        end = clock();

        time = double(end - start)/CLOCKS_PER_SEC;
        cout << "Time of first loop: " << time << '\n';


        start = clock();
        for (j = 0; j < k; ++j) 
            for (i = 0; i < k; ++i)
                y[i] += A[i][j] * x[j];
        end = clock();

        time = double(end - start)/CLOCKS_PER_SEC;
        cout << "Time of second loop : " << time << '\n';

    }
    
    return 0;
}