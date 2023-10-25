#include <iostream>
#include <vector>
using namespace std;

void printMatrix(int arr[][6]);
void fillMatricesData(int _matrices);
int getMinimum(vector<int> vect);
int getMaximum(vector<int> vect);
void zeroSpread(int arr[][6])
{
    for(int x = 1; x < 6; x++)
    {
        arr[x][x] = 0;
    }
}

int main(){

    /*           {
        M[i,j] =  0: if i = j
                  min or max or avg: { M[i,j] = M[ i, k ] + M[ k+1, j ] + p_i-1 * p_k * p_j }
                 }
    */
    int MATRICES;
    cout << "Enter the number of Matrices : " << endl;
    cin >> MATRICES;
    MATRICES++;
    
    // add extra row and column, ignore row 0 and column 0, 
    int scalarMatrix[6][6] = {
                                {-1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1}
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

    for(int chainLength = 2; chainLength < MATRICES; chainLength++)    // start from second link of the Matrix chain
    {
        for(int i = 1; i < 6 - chainLength + 1; i++)  // traverse through i while i is less than N - current chainLength + 1
        {
            int j = i + chainLength - 1;    // M[i][i + chainLength - 1]
            vector<int> scalarWeights;      // holds values in order to find min, max, or avg
            for(int k = i; k < j; k++)
            {
                int temp = scalarMatrix[i][k] + scalarMatrix[k+1][j] + (p[i-1] * p[k] * p[j]);
                scalarWeights.push_back(temp);
                
            }
            scalarMatrix[i][j] = getMaximum(scalarWeights);
        }
    }

    printMatrix(scalarMatrix);

    return 0;
}

void fillMatricesData(int _matrices){
    cout << "Enter number of Matrices: " << endl;
    cin >> _matrices;
    cout << "Enter dimensions for: " << endl;
}
void printMatrix(int arr[][6])
{
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int getMinimum(vector<int> vect)
{
    int min = vect.at(0);
    for(int i = 0; i < vect.size(); i++)
    {
        if(vect.at(i) < min)
        {
            min = vect.at(i);
        }
    }
    return min;
}
int getMaximum(vector<int> vect)
{
    int max = vect.at(0);
    for(int i = 0; i < vect.size(); i++)
    {
        if(vect.at(i) > max)
        {
            max = vect.at(i);
        }
    }
    return max;
}