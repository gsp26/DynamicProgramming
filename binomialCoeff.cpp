#include<iostream>

using namespace std;

int binomialCoeff(int n, int k)
{
    if(k==0 || k==n)
        return 1;


    return binomialCoeff(n-1,k-1) + binomialCoeff(n-1,k);
}

int min(int a,int b)
{
    return  (a<b)?a:b;
}


int binomialCoeffDP(int n, int k)
{
    int C[n+1][k+1];
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=min(i,k);j++)
        {
            //base cases
            if(j==0 || j==i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][k];
}

int binomialCoeffSpaceOptimised(int n,int k)
{
    int C[k+1];
    for(int i=0;i<=k;i++)
        C[i] = 0;
    
    C[0] = 1;

    for(int i=0;i<=n;i++)
    {
        //compute next row of pascal triangle using 
        //the previous row
        for(int j=min(i,k);j>0;j--)
            C[j] = C[j] + C[j-1];
    }
    return C[k];
}



int main()
{
    int n=5,k=2;
    cout << "\nValue of binomialCoeff for n=5 and k=2 is - " << binomialCoeff(n,k)<<endl;
    cout << "\nValue of binomialCoeff using DP for n=5 and k=2 is - " << binomialCoeffDP(n,k)<<endl;
    cout << "\nValue of binomialCoeff using DP and space optmization for n=5 and k=2 is - " << binomialCoeffSpaceOptimised(n,k)<<endl;

    return 0;
}

