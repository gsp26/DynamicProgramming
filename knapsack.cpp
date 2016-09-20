#include<iostream>

using namespace std;

int max(int a,int b) { return (a>b)?a:b;}


int knapsack(int W,int wt[],int val[],int n)
{
    //base case
    if(n==0||W==0)
        return 0;

    //if weight of the nth item is more then knapsack capacity w
    // then this item cannot be inluded in the optimal solution
    if(wt[n-1]> W)
        return knapsack(W,wt,val,n-1);
    //return the maximum of two cases
    //(1) nth item included
    //(2) not included
    else
        return max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
}

int knapsackDP(int W,int wt[],int val[],int n)
{
    int i,w;
    int K[n+1][W+1];

    //build table K in bottom up manner 
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=W;w++)
        {
            if(i==0||w==0)
                K[i][w] = 0;
            else if(wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][W];
}



int main()
{
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int w = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout << "knapsack| the value of max subset- " << knapsack(w,wt,val,n) << endl ;
    cout << "knapsack| the value of max subset using DP - " << knapsackDP(w,wt,val,n) << endl ;
    return 0;
}

