#include <vector>
#include <map>

using namespace std;

// Helper function to check if the player has won.
bool checkIfWon(vector<vector<char>>&,int, int);

// Complete the findGameStatus function below.
string findGameStatus(vector<vector<char>> board) {
 
    map <char, bool> Won;
    Won.insert(make_pair('R',false));    
    Won.insert(make_pair('Y',false)); 
    char temp;
    
    // 6 rows
    for (int i = 0; i < 6; i++) {
        // 7 columns
        for (int j = 0; j < 7; j++) {
            if (board[i][j] != '0' && !Won[board[i][j]]) {
                if (checkIfWon(board, i, j)) {
                    Won[board[i][j]] = true;
                }
            }
            
        }
        
    }
    
    if (Won['Y'] && Won['R']) {
        return "B";
    } else if (!Won['Y'] && !Won['R']) {
        return "N";
    } else if (Won['Y']) {
        return "Y";
    } else {
        return "R";
    }
}


bool checkIfWon(vector<vector<char>>& board, int i, int j) {
    
    int k;
    bool won = false;
    bool wayDown, wayRight, wayLeft;
    
    // Vertical
    if (wayDown = i+3 < 6 == true) {
        for (k = i; k < i+4; k++) {
            if (board[k][j] != board[i][j]) {
                goto horrizontal;
            }
        }
        won = true;
        goto end;
    }
    
    // Horrizontal
    horrizontal:
    if (wayRight = j+3 < 7 == true) {
        for (k = j; k < j+4; k++) {
            if (board[i][k] != board[i][j]) {
                goto downright;
            }
        }
		won = true;
		goto end;

    }
    
    // Downright
    downright:
    if (wayDown && wayRight) {
        for (k = 0; k < 4; k++) {
            if (board[i+k][j+k] != board[i][j]) {
                goto downLeft;
            }
        }
		won = true;
		goto end;
    }
    
    // Downleft
    downLeft:
    if (wayDown && (j>=3)) {
        for (k = 0; k < 4; k++) {
            if (board[i+k][j-k] != board[i][j]) {
                goto end;
            }
        }
	    won = true;
	    goto end;
    }
    
    end:    
    return won;
    
}
