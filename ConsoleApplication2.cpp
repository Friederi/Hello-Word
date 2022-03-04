#include<iostream>
#include<algorithm>

using namespace std;

void input(double A[][100], int& n, int& m)
{
    cout << "Nhap so hang ma tran:";
    cin >> n;
    cout << "Nhap so cot ma tran:";
    cin >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            cout << "A[" << i << "][" << j << "]:";
            cin >> A[i][j];
        }
        cout << "\n";
    }
}

void MaxCollum(double A[][100], int row, int collum)
{
    for (int i = 0; i < collum; i++)
    {
        double max = A[0][i];
        for (int j = 1; j < row; j++)
            if (A[j][i] > max) max = A[j][i];
        cout << "Gia tri lon nhat tren cot " << i << " la:" << max << endl;
    }
}

void output(double A[][100], int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    double A[100][100];
    int n, m;
    input(A, n, m);
    MaxCollum(A, n, m);
    output(A, n, m);
    return 0;
}