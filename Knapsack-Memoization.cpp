#include<bits/stdc++.h>
using namespace std;

int dp[4][51];
int knapsack(int wt[], int val[], int W, int n)
{
    if (W==0||n==0)
    {
        return 0;
    }
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    if(wt[n-1]<=W)
    {
        return dp[n][W] = max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1) );
    } else if(wt[n-1]>W)
    {
        return dp[n][W] = knapsack(wt, val, W, n-1);
    }
}
 
int main() {
    int n = 3;
    int wt[] = { 10, 20, 30 };
    int val[] = { 60, 100, 120 };
    int W = 50;
    memset(dp, -1, sizeof(dp));
    cout<<knapsack(wt,val,W,n)<<endl;
    // for(int i=0;i<4;i++)
    // {
    //     for(int j=0;j<51;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}


// 220
// -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
// -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 60 -1 -1 -1 -1 -1 -1 -1 -1 -1 60 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 60 
// -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 160 
// -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 220 