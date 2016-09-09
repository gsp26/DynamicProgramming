#include<iostream>
#include<vector>
#include<stdio.h>
#include<limits.h>

#define R 3
#define C 3

using namespace std;

int min(int x,int y,int z);

int minCost(int cost[R][C],int m,int n)
{
    if( n <0 || m < 0)
        return INT_MAX;
    else if(m==0 && n==0)
        return cost[m][n];
    else
        return cost[m][n] + min(minCost(cost,m-1,n-1),minCost(cost,m-1,n),minCost(cost,m,n-1));
}


int min(int x,int y,int z)
{
    if(x<y)
        return (x<z)?x:z;
    else
        return (y<z)?y:z;
}

int minCostDP(int cost[R][C],int m, int n)
{
    int i,j;
    //instead of following line, we can use int tc[m+1][n+1] or 
    //dynamically allocate memory to save space. 

    int tc[R][C];

    tc[0][0] = cost[0][0];

    //initializing fisrt column os total cost(tc) array
    for(i=1;i<=m;i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];

    //intialize first row of tc array
    for(j=1;j<=n;j++)
        tc[0][j] = tc[0][j-1] + cost[0][j];

    //construct rest of the tc array
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            tc[i][j] = min(tc[i-1][j-1],tc[i-1][j],tc[i][j-1]) + cost[i][j];

    return tc[m][n];
}



int main()
{
    cout << "\nFor computing minimum cost path >>>>>>>" << endl;
    int  cost[R][C] = { {1,2,3}, {4,8,2},{1,5,3} };
    cout << "\n\nminCost path is - " << minCost(cost,2,2) << endl;
    cout << "\n\nminCost path using DP is - " << minCostDP(cost,2,2) << endl;


    return 0;
}

