#include<iostream>
using namespace std;
bool canplace(int mat[][100], int N, int x, int y, int value) {
    for (int i = 0; i < N*N;i++) {
        if (mat[x][i] == value || mat[i][y] == value) {
            return false;
        }
    }
    int gsx = (x/N)*N, gsy = (y/N)*N;
    for(int i = gsx; i < gsx+N; i++) {
        for (int j = gsy; j < gsy+N; j++) {
            if (mat[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int mat[][100], int N, int x, int y) {
    if (x == N*N) {
        return true;
    }
    int newx = x, newy = y+1;
    if (y == N*N-1) {
        newx = x+1;
        newy = 0;
    }
    if (mat[x][y] !=0) {
        return solveSudoku(mat, N, newx, newy);
    }
    for (int i =1; i <= N*N; i++) {
        if (canplace(mat, N, x, y, i)) {
            mat[x][y] = i;
            bool ans = solveSudoku(mat, N, newx, newy);
            if (ans == true) {
                return ans;
            } else {
                mat[x][y] = 0;
            }
        }
    }
    return false;
}
int main () {
    int mat[100][100];
    for (int i =0 ;i < 9; i++) {
        for (int j =0; j < 9;j++) {
            cin >> mat[i][j];
        }
    }
    bool ans = solveSudoku(mat, 3, 0,0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}

