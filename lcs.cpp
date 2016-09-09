#include<iostream>

using namespace std;

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int LCS(string x,string y, int i,int j)
{
    if(i==0 || j == 0)
        return 0;
    int lcs = 0;
    if(x[i] == y[j])
        lcs = LCS(x,y,i-1,j-1) +1;
    else
        lcs = max(LCS(x,y,i-1,j),LCS(x,y,i,j-1));

    return lcs;
}

int lcsDP(string x, string y,int m,int n)
{
    int L[m+1][n+1];
    int i,j;

    for(i=0; i <= m;i++)
    {
        for(j=0;j <= n;j++)
        {
            if(i==0 || j ==0)
                L[i][j] = 0;
            else if(x[i-1] == y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j],L[i][j-1]);
        }
    }

    return L[m][n];
}


int main()
{
    cout << "Program to calulcate lenght LCS of twon strings" << endl;

    string s1 = "ABCBDAB";
    string s2 = "BDCABA";
    int m = s1.size();
    int n = s2.size();
    cout << "String 1- " << s1 << endl;
    cout << "String 2- " << s2 << endl;

    cout << "length of the longest common subsequence is - " << LCS(s1,s2,m,n) << endl;
    cout << "length of the longest common subsequence using LCS_DP is - " << lcsDP(s1,s2,m,n) << endl;

    return 0;
}

