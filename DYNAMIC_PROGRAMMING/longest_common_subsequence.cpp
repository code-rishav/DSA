#include<iostream>
#include <vector>
using namespace std;

int lcs(string s1,string s2,int m,int n){
    if(m==0||n==0)
    return 0;
    if(s1[m-1]==s2[n-1])
    return 1+lcs(s1,s2,m-1,n-1);
    else
    return max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));  
}

int lcs(string s1,string s2,int m,int n,vector<vector<int>> memo){
    if(memo[m][n]!=-1)
    return memo[m][n];
    if(m==0||n==0)
    memo[m][n] = 0;
    if(s1[m-1]==s2[n-1])
    memo[m][n] = 1 + lcs(s1,s2,m-1,n-1,memo);
    else
    memo[m][n] = max(lcs(s1,s2,m,n-1,memo),lcs(s1,s2,m-1,n,memo));
    return memo[m][n];
}

int lcs(string s1,string s2){
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    dp[i][0] = 0;
    for(int i=0;i<=n;i++)
    dp[0][i] = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i]==s2[j])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

