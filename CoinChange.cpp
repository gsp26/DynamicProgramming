#include<iostream>
#include<vector>
#include<stdio.h>
#include<limits.h>


using namespace std;

int count(int s[],int m,int n)
{
    //if n is 0 then there is only one solution ( do not include any coin)
    if(n==0)
        return 1;

    //if n is less than zero then no solution exists
    if(n<0)
        return 0;

    //if there are no coins and n is greater than 1, then no solutions exists
    if(m<=0 && n >=1)
        return 0;

    return count(s,m-1,n) + count(s,m,n-s[m-1]);
}

int countDP(int s[],int m,int n)
{
    int i,j,x,y;
    //we need n+1 rows as the table is constructed in bottom up manner using the base case 0 value case(n=0)
    int table[n+1][m];

    //fill entries for 0 value case(n=0)
    for(i=0;i<m;i++)
        table[0][i] = 1;

    //fill rest of the table entries in bottom up manner 
    for(i=1;i<n+1;i++)
    {
        for(j=0;j<m;j++)
        {
            //count of solutions including s[j]
            x = (i-s[j] >=0)?table[i-s[j]][j]:0;

            //count of solutions excluding s[j]
            y = (j>=1)?table[i][j-1]:0;

            table[i][j] = x+y;
        }
    }
    return table[n][m-1];
}




int main()
{
    cout << "\nProgram to find the total possible coin changes >>>>>" << endl;
    int i,j;
    int arr[] = {1,2,3};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout << "\n\nTotoal coin change combinations possible--" << count(arr,m,4) << endl;
    cout << "\n\nTotoal coin change combinations using DP possible--" << countDP(arr,m,4) << endl;
    return 0;
}
