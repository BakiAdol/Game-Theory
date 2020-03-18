/**
 * 	There are three piles of stone 5,7,9. Each player can remove any non zero stones upto 3 from these piles.
 * 	Find winner of this game. This problem can be solve by Sprague-Grundy Theorem. First find the grundy value
 * 	for all piles and then xor of grundy of 5, 7 9. If xor is non zero first player win otherwise second player.
 * 
 * **/
#include <bits/stdc++.h>
 
using namespace std;

int piles[]={5,7,9};
int n=3;

int memo[100];

int mex(set<int> s)
{
	int res=0;
	
	while(s.find(res)!=s.end()) res++;
	
	return res;
}

int calculateGrundy(int stones)
{
	if(stones<4) return stones;
	
	set<int> s;
	
	if(memo[stones]) return memo[stones];
	
	for(int i=1;i<4;i++) s.insert(calculateGrundy(stones-i));
	
	return memo[stones]=mex(s);
}

int main()
{
	calculateGrundy(10); // calculate grundy atmost 10, we need grundy of 5,7,9 
	
	if((memo[5]^memo[7]^memo[9])==0) printf("Second Player win!\n");
	else printf("First Player win!\n");
	
	return 0;
}
