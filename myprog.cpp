#include <iostream>
using namespace std;
int main()
{                                                                                                                                           
    int row1, row2, col1, col2;
    double** a, ** b, ** c;
                                                                                                                                            
    row1 = 500;
    col1 = 500;
    row2 = 500;
    col2 = 500;
                                                                                                                                            
    a = new double* [row1];
    for (int i = 0; i < row1; i++)
    {                                                                                                                                       
        a[i] = new double[col1];
        for (int j = 0; j < col1; j++)
        {                                                                                                                                   
            a[i][j] = i + j;                                                                                                                
        }                                                                                                                                   
    }                                                                                                                                       
                                                                                                                                            
    b = new double* [row2];
    for (int i = 0; i < row2; i++)
    {                                                                                                                                       
        b[i] = new double[col2];
        for (int j = 0; j < col2; j++)
        {                                                                                                                                   
            b[i][j] = i + j;                                                                                                                
        }                                                                                                                                   
    }                                                                                                                                       
    for (int k = 0; k < 120000; ++k)
    {                                                                                                                                       
    c = new double* [row1];
    for (int i = 0; i < row1; i++)
    {                                                                                                                                       
        c[i] = new double[col2];
        for (int j = 0; j < col2; j++)
        {                                                                                                                                   
            c[i][j] = 0;
            for (int k = 0; k < col1; k++)
                c[i][j] += a[i][k] * b[k][j];                                                                                               
        }                                                                                                                                   
    }                                                                                                                                       
    cin.get(); cin.get();                                                                                                                   
    }                                                                                                                                       
    return 0;
}