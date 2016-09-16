#include<iostream>
#include<limits.h>

using namespace std;

int max(int a,int b) { return (a>b)?a:b;}

int eggDrop(int n,int k)
{
    //if there are no floor ,then no trials needed . OR if there is one floor one trial needed
    if(k==1 || k==0)
        return k;

    //we need k trials for one egg and k floors
    if(n==1)
        return k;

    int min = INT_MAX,x,res;
    //consider all droppings from 1st floor to kth floor and
    //return the minimum of there values plus 1
    for(x=1;x<=k;++x)
    {
        res = max(eggDrop(n-1,x-1),eggDrop(n,k-x));
        if(res < min)
            min = res;
    }

    return min +1;
}
int eggDropDP(int n,int k)
{
    //a 2D table where entry eggFloor[i][j] will represent minimun
    //number of trials needed for i egg and j floors
    int eggFloor[n+1][k+1];
    int res;
    int i,j,x;

    //we need one trial for one floor and 0 trials for 0 floors
    for(i=1;i<=n;i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    //we always need j trials for one egg with j floors 
    for(j=1;j<=k;j++)
        eggFloor[1][j] = j;

    //fill rest of the entries in table using optimal substructure properly
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            eggFloor[i][j] = INT_MAX;
            for(x=1;x<=j;++x)
            {
                res = 1 + max(eggFloor[i-1][x-1],eggFloor[i][j-x]);
                if(res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }

    return eggFloor[n][k];
}


       


int main()
{
    cout << "Egg Dropping puzzle >>>> " << endl;

    int n=2,k=10;
    cout << "\nMinimum number of trials in worst case with " << n << " eggs and " << k << " floors is - " <<
    eggDrop(n,k) << endl;

    cout << "\nMinimum number of trials in worst case with using DP" << n << " eggs and " << k << " floors is - " <<
    eggDropDP(n,k) << endl;
    return 0;
}

