#include<stdio.h>
#include<iostream>
#include<limits.h>


using namespace std;


int matrixChainOrder(int p[],int i,int j)
{
    if(i==j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    //place parenthesis at different places between first and last matrix,
    //recursively calculate count of multiplications for each parenthesis placement and return the minimum count

    for(k=i;k<j;k++)
    {
        count = matrixChainOrder(p,i,k) + matrixChainOrder(p,k+1,j) + p[i-1]*p[k]*p[j];

        if(count < min)
            min = count;
    }

    return min;
}

int matrixChainOrderDP(int p[],int n)
{
    //for simplicity of program one extra row and one extra column are allocated in m[][]. 0th row and 0th column of
    //m[][] are not used
    int m[n][n];

    int i,j,k,L,q;
    //m[i][j] = minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j]
    //where dimensions of A[i] are p[i-1]*p[i]

    //cost is zero when multiplying one matrix
    for(i=0;i<n;i++)
        m[i][i] = 0;

    //L is chain length
    for(L=2;L<n;L++)
    {
        for (i=1;i<n-L+1;i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                //q = cost/scalar multiplications 
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n-1];
}



int main()
{
    cout <<"TO compute matrixChain ordering with minimum operaions >>>>> " << endl;

    int arr[] = { 1,2,3,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "\nMinimum number of multipcations is - " << matrixChainOrder(arr,1,n-1) << endl;
    cout << "\nMinimum number of multipcations using DP is - " << matrixChainOrderDP(arr,n) << endl;

    return 0;
}
