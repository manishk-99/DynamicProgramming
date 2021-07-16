#include <bits/stdc++.h>
using namespace std;

string PrintLongestCommonSubsequence(string X, string Y, int n, int m)
{
    int result = 0;
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
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(X[i-1] == Y[j-1])
            {
                dp[i][j] = 1+ dp[i-1][j-1];
                result = max(result,dp[i][j]);
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    string ans;
    while(i>0 && j>0)
    {
        if(X[i-1] == Y[j-1])
        {
            ans.push_back(X[i-1]);
            i--;
            j--;
        } else {
            if(dp[i-1][j] > dp[i][j-1])
            {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    string X= "acbcf";
    string Y = "abcdaf";
    int n = X.size();
    int m = Y.size();
    cout<<"Longest Common Subsequence is "<<PrintLongestCommonSubsequence(X, Y, n, m)<<endl;
}