/**
*    Nim Game
*    There are some piles and many stones in piles. Any player can move any non zero number of stones from a pile.
*    Who can't remove stones this player is loss this game, First player move first.
**/
#include <bits/stdc++.h>
using namespace std;

struct Move{
    int pileNum,stones;
};

int nimSum(int piles[], int numOfPiles)
{
    int sum=0;
    for(int i=0;i<numOfPiles;i++) sum^=piles[i];
    return sum;
}

void showPiles(int piles[], int numOfPiles)
{
    for(int i=0;i<numOfPiles;i++) cout << piles[i] << " ";
    cout << endl;
}

Move moves(int piles[], int numOfPiles)
{
    Move mv;
    int nim_sum=nimSum(piles,numOfPiles);
    if(nim_sum)
    {
        //nimsum is non zero, so current player make nimsum zero
        for(int i=0;i<numOfPiles;i++)
        {
            if(piles[i]>(piles[i]^nim_sum))
            {
                mv.pileNum=i+1;
                mv.stones=piles[i]-(piles[i]^nim_sum);
                piles[i]-=mv.stones;
                break;
            }
        }
    }
    else
    {
        // if nimsum is zero, this move can be random or anything <=stones in piles
        // here we remove two stones only
        for(int i=0;i<numOfPiles;i++)
        {
            if(piles[i])
            {
                mv.pileNum=i+1;
                mv.stones=min(2,piles[i]);
                piles[i]-=mv.stones;
                break;
            }
        }
    }
    return mv;
}

bool gameOver(int piles[], int numOfPiles)
{
    //if all stones removes from these piles then game is over otherwise it's continue.
    for(int i=0;i<numOfPiles;i++) if(piles[i]) return true;
    return false;
}

void gamePlay(int piles[], int numOfPiles)
{
    bool whoseTurn=0;// 0 for first player, 1 for second player
    Move mv;
    while(gameOver(piles,numOfPiles))
    {
        showPiles(piles,numOfPiles);
        mv=moves(piles,numOfPiles);
        if(whoseTurn)
        {
            cout << "Second player move " << mv.stones << " stones from pile " << mv.pileNum << endl;
            whoseTurn=0;
        }
        else
        {
            cout << "First player move " << mv.stones << " stones from pile " << mv.pileNum << endl;
            whoseTurn=1;
        }
    }
    showPiles(piles,numOfPiles);
    cout << (whoseTurn ? "First Player Win!" : "Second Player Win!") << endl;
}

int main()
{
    int numOfPiles=3;
    int piles[]={3,4,5};

    //Who win the game? First player make first move
    cout << (nimSum(piles,numOfPiles) ? "First Player Win!" : "Second Player Win!") << endl;

    gamePlay(piles,numOfPiles);


    return 0;
}

