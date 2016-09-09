#include<iostream>

using namespace std;

int min(int x,int y,int z)
{
    return min(min(x,y),z);
}

int editDist(string s1,string s2,int m, int n)
{
    if(m==0)
        return n;
    if(n==0)
        return m;

    if(s1[m-1] == s2[n-1])
        return editDist(s1,s2,m-1,n-1);

    return 1 + min(editDist(s1,s2,m,n-1),   // insert
                   editDist(s1,s2,m-1,n),   // Remove
                   editDist(s1,s2,m-1,n-1));  //Replace
}

int editDistDP(string s1, string s2, int m,int n)
{
    int dp[m+1][n+1];

    //fill dp in bottom up order 
    for(int i = 0; i<=m ; ++i)
    {
        for(int j=0;j<=n;++j)
        {
            if(i==0)
                dp[i][j] = j;
            else if (j==0)
                dp[i][j] = i;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], //insert
                               dp[i-1][j], //remove
                               dp[i-1][j-1]); //replace
        }
    }

    return dp[m][n];
}
int main()
{
    string s1 = "govind";
    string s2 = "suman";
    
    cout << "edit distance is - " << editDist(s1,s2,s1.size(),s2.size()) << endl;
    cout << "edit distance using DP is - " << editDistDP(s1,s2,s1.size(),s2.size()) << endl;

    return 0;
}

