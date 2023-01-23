//  Optimal Move in Tic Tac Toe
// Send Feedback
// Given a state of 3*3 Tic Tac Toe Board and two players 'x' and 'o', find the best optimal move possible 
// for player with the next turn, specifying their row and column.
// Consider yourself to be 'x' and computer to be 'o'.
// Note: If there are more than one ways for 'x' to win the game from the given board state, the optimal 
// move is the one where we have to make lesser number of moves to win the game.
// Input Format:

// First line of input contains integer N, representing the number of given states of board.
// Next N lines contain row number, column number and player name('x' or 'o'), space separated.

// Output Format:

// The first line of output contains the ultimate result of the game as follows:
// "Player_name" Wins. If no one wins, print Draw 
// The second line of output contains 
// (Total number of moves left) row: (Row Number) col: (Column Number)

// Sample Input 1:

// 4
// 0 0 x
// 0 1 o
// 0 2 x
// 1 1 o

// Sample Output 1:

// Draw
// 5 row: 2 col: 1

// Sample Input 2:

// 4
// 0 0 o
// 2 0 x
// 2 2 o
// 2 1 x

// Sample Output 2:

// o Wins
// 1 row: 1 col: 1


#include<bits/stdc++.h>
using namespace std;

class Move{
    public:
    	int row, col, score, cr;
};


char player = 'x', opponent = 'o';

bool isMoveLeft(char board[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]=='_'){
                return true;
            }
        }
    }
    return false;
}


int evaluate(char b[3][3]){
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] &&
            b[row][1]==b[row][2])
        {
            if (b[row][0]==player)
                return +10;
            else if (b[row][0]==opponent)
                return -10;
        }
    }
 
    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]==player)
                return +10;
 
            else if (b[0][col]==opponent)
                return -10;
        }
    }
 
    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==player)
            return +10;
        else if (b[0][0]==opponent)
            return -10;
    }
 
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==player)
            return +10;
        else if (b[0][2]==opponent)
            return -10;
    }
 
    // Else if none of them have won then return 0
    return 0;

}

int minimax(char board[3][3], bool isMax, int depth){
    int score = evaluate(board);
    if(score==10){
        return 10-depth;
    }
    if(score==-10){
        return -10+depth;
    }
    if(isMoveLeft(board)==false){
        return 0;
    }
    if(isMax){
        int best = -1000;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]=='_'){
                    board[i][j] = 'x';
                    best = max(best, minimax(board, !isMax,depth+1));
                    board[i][j] = '_';
                    
                }
            }
        }
        return best;
    }
    else{
        int best = 1000;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]=='_'){
                    board[i][j] = 'o';
                    best = min(best, minimax(board,  !isMax, depth+1));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}


Move nextMove(char board[3][3], char turn){
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    bestMove.score = -1000;
    if(turn=='x') bestMove.score = -1000;
    else bestMove.score = 1000;
    bool k = true;
    if(turn=='x') k = false;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]=='_'){
                board[i][j] = turn;
                int val = minimax(board,  k, 0);
                // cout<<i<<" "<<j<<" "<<endl;
                if(k){
                    if(val<bestMove.score){
                        bestMove.row = i;
                        bestMove.col = j;
                        bestMove.score = val;
                    }  
                }
                if(!k){
                    if(val>bestMove.score){
                        bestMove.row = i;
                        bestMove.col = j;
                        bestMove.score = val;
                    } 
                }
                board[i][j] = '_';
                // cout<<i<<" "<<j<<endl;
                // cout<<bestMove.score<<" "<<bestMove.row<<" "<<bestMove.col<<endl;
            }
        }
    }
    return bestMove;
}




int main(){
    // write your code
    char board[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j] = '_';
        }
    }
    
    int n;
    cin>>n;
    int xn = n;
    char nextTurn;
    while(n--){
        int a,b;
        char c;
        cin>>a>>b>>c;
        board[a][b] = c;
        nextTurn = c;
    }
    if(nextTurn=='x')nextTurn = 'o';
    else nextTurn = 'x';
    //cout<<nextTurn<<endl;
    Move bestMove = nextMove(board, nextTurn);
    
    if(bestMove.score==0){
        cout<<"Draw"<<endl;
        int x = 9-xn;
        cout<<x<<" row: "<<bestMove.row<<" col: "<<bestMove.col<<endl;
    }
    else if(bestMove.score>0){
        cout<<"x Wins"<<endl;
        cout<<11-bestMove.score<<" row: "<<bestMove.row<<" col: "<<bestMove.col<<endl;
    }
    else{
        cout<<"o Wins"<<endl;
        cout<<bestMove.score+11<<" row: "<<bestMove.row<<" col: "<<bestMove.col<<endl;
    }
    
    
    
    return 0;
}
