/**
*    Calculate Grundy value
*    There are one piles contains stones. Any player can take non zero stones from this pile.
*    If Grundy value is 0 the first player lose. First player move first.
**/
#include <bits/stdc++.h>
using namespace std;

int calculateMex(set<int> s)
{
    int mex=0;
    while(s.find(mex)!=s.end()) mex++;
    return mex;
}

int dp[100];
int calculateGrundy(int stones)
{
    if(stones==0) return 0;
    if(dp[stones]!=-1) return dp[stones];
    set<int> s;
    for(int i=0;i<stones;i++)
    {
        s.insert(calculateGrundy(i));
    }
    return dp[stones]=calculateMex(s);
}

/*
    Player can take 1 to 3 stones, then this calculateGrundy() like

    int calculateGrundy(int stones)
    {
        if(stones==0) return 0;
        if(stones==1) return 1;
        if(stones==2) return 2;
        if(stones==3) return 3;
        if(dp[stones]!=-1) return dp[stones];
        set<int> s;
        for(int i=1;i<4;i++)
        {
            s.insert(calculateGrundy(stones-i));
        }
        return dp[stones]=calculateMex(s);
    }
*/


int main()
{
    int stones=10;
    memset(dp,-1,sizeof dp);
    cout << calculateGrundy(stones) << endl;
    for(int i=0;i<=stones;i++) cout << dp[i] << " ";

    return 0;
}

