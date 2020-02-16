/*
*   You and your friend Playing stones game. There are n stones in a baskets.
*   At a time/in a move you or your friend take 2,3 or 5 stones from the baskets.
*   The winner in this game who is took stones at last from this basket.
*   First move is yours. You both make optimal moves.
*   This program is find out who is the winner for n stones.
*/
#include <bits/stdc++.h>

using namespace std;

bool memo[1000000];

int main()
{
    int n;
    memset(memo,0,sizeof memo);
    for(int i=2;i<1000000;i++)
    {
        if(i-2>-1 and memo[i-2]==0) memo[i]=1;
        else if(i-3>-1 and memo[i-3]==0) memo[i]=1;
        else if(i-5>-1 and memo[i-5]==0) memo[i]=1;
    }
    while(true)
    {
        cout << "Enter number of stones : ";
        cin >> n;
        cout << (memo[n] ? "You win!" : "Your friend win!") << endl;
    }
    return 0;
}

