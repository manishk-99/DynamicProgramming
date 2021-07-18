#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string X, string Y, int n, int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
        }
    }
    int result = 0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(X[i-1] == Y[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
                result = max(result, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return result;
}

int main() {
    string X = "Geeks";
    string Y = "Geeks";
    reverse(Y.begin(), Y.end()); //To reverse string 
    int n = X.size();
    cout<<"Longest palindromic Substring is: "<<LongestCommonSubsequence(X, Y, n, n);
}