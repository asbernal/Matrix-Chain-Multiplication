#include <iostream>

using namespace std;

void fillMatricesData();
void zeroSpread(int arr[][5])
{
    for(int x = 0; x < 5; x++)
    {
        arr[x][x] = 0;
    }
}
void oneSpread(int _k, int _i, int _j, int arr[][5], int pArr[6])  // int arr** to pass 2d pointer
{
    
    
}

int main(){

    /*           {
        M[i,j] =  0: if i = j
                  min or max or avg: { M[i,j] = M[ i, k ] + M[ k+1, j ] + p_i-1 * p_k * p_j }
                 }
    */

    int MATRICES = 5;
    int scalarMatrix[5][5] = {
                                {-1,-1,-1,-1,-1},
                                {-1,-1,-1,-1,-1},
                                {-1,-1,-1,-1,-1},
                                {-1,-1,-1,-1,-1},
                                {-1,-1,-1,-1,-1}
                             };

    int M1[] = {9,3};
    int M2[] = {3,9};
    int M3[] = {9,1};
    int M4[] = {1,8};
    int M5[] = {8,4};

    int p0 = 9;
    int p1 = 3;
    int p2 = 9;
    int p3 = 1;
    int p4 = 8;
    int p5 = 4;

    int p[] = {9, 3, 9, 1, 8, 4};

    // 0 :  i = j therefor we can just assign them all zereos
    zeroSpread(scalarMatrix);

    int spread = 1; //spread

    for(int chainLength = 1; chainLength < MATRICES; chainLength++)    // start from second link of the Matrix chain, Notice that it starts from 1 NOT 2
    {
        for(int i = 1; i < MATRICES - chainLength ; i++)  // traverse through i while i is less than N - current chainLength
        {
            int j = i + chainLength;    // M[i][i + chainLength - 1]
            
            for(int k = i; k < j; k++)
            {
                int temp = scalarMatrix[i][k] + scalarMatrix[k+1][j] + (p[i-1] * p[k] * p[j]);
                cout << temp << endl;
                
            }
            // return -1;
        }
    }
    return 0;
}

void fillMatricesData(){
    cout << "Enter number of Matrices: " << endl;
    //
    cout << "Enter dimensions for: " << endl;
}