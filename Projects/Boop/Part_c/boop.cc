#include <iostream>
#include <cstring>
#include "space.h"
#include "boop.h"

using namespace std;
using namespace main_savitch_14;

// Default Constructor (Calls restart())
Boop::Boop(){
    restart();
    // Resets board
}

// Have the next player make a specified move:
void Boop::make_move(const std::string& move){ // Example input "k1F" kitten in 1F
    if(move_type == 1){
        char piece = toupper(move.substr(0, 1)[0]); // Sets piece to track the piece type
        int column = (toupper(move.substr(1, 1)[0])) - 49; // Sets column to track the requested column
        int row = (toupper(move.substr(2,1)[0])) - 65; // Sets row to track the requested row
        if (next_mover() == HUMAN){ // Player 1 move
            if (piece == 'K'){ // Player 1 kitten
                string board_move = "k1";
                board[row][column].Space_mutator(board_move);
                player1_kittens--;
            }
            else{ // Player 1 cat
                string board_move = "c1";
                board[row][column].Space_mutator(board_move);
                player1_cats--;
            }
        }
        else{ // Player 2 move
            if (piece == 'K'){ // Player 2 kitten
                string board_move = "k2";
                board[row][column].Space_mutator(board_move);
                player2_kittens--;
            }
            else{ // Player 2 cat
                string board_move = "c2";
                board[row][column].Space_mutator(board_move);
                player2_cats--;
            }
        }
        boopPieces(piece, row, column);

        // check for 3 in a row
        // if(rowOf3()){
        //     move_type = 2;
        //     return;
        // }
        // check for all 8

        // if neither special move, switch to next player
        game::make_move(move);
    }
    else if(move_type == 2){
        // making a remove 3 move
        //promote(move);
    }

    rowOf3(); // Cals rowOf3 function
    all8();
}

void Boop::rowOf3(){ // Check for victory then promote 3 kittens in a row
    // Checking for cats
    for (int c = 0; c < 6; c++){ // Itterates through the columns
        int consecutive = 0;
        int previous = board[0][c].Access_State();
        if (previous == 3 || previous == 4){
            consecutive = 1;
        }
        for (int r = 1; r < 6; r++){ // Itterates through the rows
            if (consecutive == 3){
                game_over = 1; // Sets the game to be over
                if (previous == 3){
                    winner = -1;
                }
                else{
                    winner = 1;
                }
                return;
            }
            if (r == 6){
                break;
            }
            if (previous == 3){
                previous = board[r][c].Access_State();
                if (previous == 3){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 4){
                previous = board[r][c].Access_State();
                if (previous == 4){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 3 || previous == 4){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
        }
    }
    // Checking for cats
    for (int r = 0; r < 6; r++){ // Itterates through the columns
        int consecutive = 0;
        int previous = board[r][0].Access_State();
        if (previous == 3 || previous == 4){
            consecutive = 1;
        }
        for (int c = 1; c < 6; c++){ // Itterates through the rows
            if (consecutive == 3){
                game_over = 1; // Sets the game to be over
                if (previous == 3){
                    winner = -1;
                }
                else{
                    winner = 1;
                }
                return;
            }
            if (r == 6){
                break;
            }
            if (previous == 3){
                previous = board[r][c].Access_State();
                if (previous == 3){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 4){
                previous = board[r][c].Access_State();
                if (previous == 4){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 3 || previous == 4){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
        }
    }
    // Checking for cats
    for (int R = 0; R <= 5; R++){
        int consecutive = 0;
        int previous = board[R][0].Access_State();
        if (previous == 3 || previous == 4){
            consecutive = 1;
        }
        int r = R + 1;
        for (int c = 1; c <= (6 - R); c++){
            if (consecutive == 3){
                game_over = 1; // Sets the game to be over
                if (previous == 3){
                    winner = -1;
                }
                else{
                    winner = 1;
                }
                return;
            }
            if (previous == 3){
                previous = board[r][c].Access_State();
                if (previous == 3){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 4){
                previous = board[r][c].Access_State();
                if (previous == 4){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 3 || previous == 4){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
            r++;
        }
    }
    //Checking for cats
    for (int C = 0; C <= 5; C++){
        int consecutive = 0;
        int previous = board[0][C].Access_State();
        if (previous == 3 || previous == 4){
            consecutive = 1;
        }
        int c = C + 1;
        for (int r = 1; r <= (6 - C); r++){
            if (consecutive == 3){
                game_over = 1; // Sets the game to be over
                if (previous == 3){
                    winner = -1;
                }
                else{
                    winner = 1;
                }
                return;
            }
            if (previous == 3){
                previous = board[r][c].Access_State();
                if (previous == 3){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 4){
                previous = board[r][c].Access_State();
                if (previous == 4){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 3 || previous == 4){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
            c++;
        }
    }        
    //Checking for cats
    for (int R = 0; R <= 5; R++){
        int consecutive = 0;
        int previous = board[R][5].Access_State();
        if (previous == 3 || previous == 4){
            consecutive = 1;
        }
        int r = R + 1;
        for (int c = 4; c >= R - 1; c--){
           if (consecutive == 3){
                game_over = 1; // Sets the game to be over
                if (previous == 3){
                    winner = -1;
                }
                else{
                    winner = 1;
                }
                return;
            }
            if (previous == 3){
                previous = board[r][c].Access_State();
                if (previous == 3){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 4){
                previous = board[r][c].Access_State();
                if (previous == 4){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 3 || previous == 4){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
            r++; 
        }
    }
    //Checking for cats
    for (int C = 5; C >= 0; C--){
        int consecutive = 0;
        int previous = board[0][C].Access_State();
        if (previous == 3 || previous == 4){
            consecutive = 1;
        }
        int c = C - 1;
        for (int r = 1; r <= C + 1; r++){
           if (consecutive == 3){
                game_over = 1; // Sets the game to be over
                if (previous == 3){
                    winner = -1;
                }
                else{
                    winner = 1;
                }
                return;
            }
            if (previous == 3){
                previous = board[r][c].Access_State();
                if (previous == 3){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 4){
                previous = board[r][c].Access_State();
                if (previous == 4){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 3 || previous == 4){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
            c--; 
        }
    }


    // Checking for kittens
    for (int c = 0; c < 6; c++){ // Itterates through the columns
        int consecutive = 0;
        int previous = board[0][c].Access_State();
        if (previous == 1 || previous == 2){
            consecutive = 1;
        }
        for (int r = 1; r < 6; r++){ // Itterates through the rows
            if (consecutive == 3){
                if (next_mover() == HUMAN){
                    promote();
                    return;
                }
                else{
                    return;
                }
            }
            if (r == 6){
                break;
            }
            if (previous == 1){
                previous = board[r][c].Access_State();
                if (previous == 1){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 2){
                previous = board[r][c].Access_State();
                if (previous == 2){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 1 || previous == 2){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
        }
    }
    // Checking for kittens
    for (int r = 0; r < 6; r++){ // Itterates through the columns
        int consecutive = 0;
        int previous = board[r][0].Access_State();
        if (previous == 1 || previous == 2){
            consecutive = 1;
        }
        for (int c = 1; c < 6; c++){ // Itterates through the rows
            if (consecutive == 3){
                promote();
                return;
            }
            if (r == 6){
                break;
            }
            if (previous == 1){
                previous = board[r][c].Access_State();
                if (previous == 1){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 2){
                previous = board[r][c].Access_State();
                if (previous == 2){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 1 || previous == 2){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
        }
    }
    // Checking for kittens
    for (int R = 0; R <= 5; R++){
        int consecutive = 0;
        int previous = board[R][0].Access_State();
        if (previous == 1 || previous == 2){
            consecutive = 1;
        }
        int r = R + 1;
        for (int c = 1; c <= (6 - R); c++){
            if (consecutive == 3){
                promote();
                return;
            }
            if (previous == 1){
                previous = board[r][c].Access_State();
                if (previous == 1){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 2){
                previous = board[r][c].Access_State();
                if (previous == 2){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 1 || previous == 2){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
            r++;
        }
    }
    //Checking for kittens
    for (int C = 0; C <= 5; C++){
        int consecutive = 0;
        int previous = board[0][C].Access_State();
        if (previous == 1 || previous == 2){
            consecutive = 1;
        }
        int c = C + 1;
        for (int r = 1; r <= (6 - C); r++){
            if (consecutive == 3){
                promote();
                return;
            }
            if (previous == 1){
                previous = board[r][c].Access_State();
                if (previous == 1){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 2){
                previous = board[r][c].Access_State();
                if (previous == 2){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 1 || previous == 2){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
            c++;
        }
    }        
    //Checking for kittens
    for (int R = 0; R <= 5; R++){
        int consecutive = 0;
        int previous = board[R][5].Access_State();
        if (previous == 1 || previous == 2){
            consecutive = 1;
        }
        int r = R + 1;
        for (int c = 4; c >= R - 1; c--){
           if (consecutive == 3){
                promote();
                return;
            }
            if (previous == 1){
                previous = board[r][c].Access_State();
                if (previous == 1){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 2){
                previous = board[r][c].Access_State();
                if (previous == 2){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 1 || previous == 2){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
            r++; 
        }
    }
    //Checking for kittens
    for (int C = 5; C >= 0; C--){
        int consecutive = 0;
        int previous = board[0][C].Access_State();
        if (previous == 1 || previous == 2){
            consecutive = 1;
        }
        int c = C - 1;
        for (int r = 1; r <= C + 1; r++){
           if (consecutive == 3){
                promote();
                return;
            }
            if (previous == 1){
                previous = board[r][c].Access_State();
                if (previous == 1){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else if (previous == 2){
                previous = board[r][c].Access_State();
                if (previous == 2){
                    consecutive++;
                }
                else{
                    consecutive = 0;
                }
            }
            else{
                previous = board[r][c].Access_State();
                if (previous == 1 || previous == 2){
                    consecutive = 1;
                }
                else{
                    consecutive = 0;
                }
            }
            c--; 
        }
    }        
}

void Boop::all8(){ // Check for victory in all 8 cats on board or promoting all pieces on board
    if ((player1_kittens == 0 && player1_cats == 0) || (player2_kittens == 0 && player2_cats == 0)){
        int p1Cats = 0;
        int p2Cats = 0;
        for (int c = 0; c < 6; c++){ // Itterates through the columns
            for (int r = 1; r < 6; r++){ // Itterates through the rows
                if (p1Cats == 8){ // Player 1 has 8 cats on board
                    game_over = 1;
                    winner = -1;
                }
                else if (p2Cats == 8){
                    game_over = 1;
                    winner = 1;
                }
                if (board[r][c].Access_State() == 3){
                    p1Cats++;
                }
                else if (board[r][c].Access_State() == 4){
                    p2Cats++;
                }
            }
        }
    }
}

void Boop::boopPieces(const char piece, int row, int col){
    string empty = "0";
    string LittleLesbian = "k1";
    string LittleTrans = "k2";
    string BigLesbian = "c1";
    string BigTrans = "c2";
    if (row - 1 > -1){ // The space above the placed piece is valid
        if (row - 2 > -1){ // The space 2 spots above the placement is valid
            if (board[row - 1][col].Access_State() != 0 && board[row - 2][col].Access_State() == 0){
                if (piece == 'C'){ // Cat
                    switch (board[row - 1][col].Access_State()){ // Piece above the placement
                        case 1: // Little Lesbian
                            board[row - 1][col].Space_mutator(empty);
                            board[row - 2][col].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row - 1][col].Space_mutator(empty);
                            board[row - 2][col].Space_mutator(LittleTrans);
                            break;
                        case 3: // Big Lesbian
                            board[row - 1][col].Space_mutator(empty);
                            board[row - 2][col].Space_mutator(BigLesbian);
                            break;
                        case 4: // Big Trans
                            board[row - 1][col].Space_mutator(empty);
                            board[row - 2][col].Space_mutator(BigTrans);
                            break;
                    }
                }
                else{ // Kitten
                    switch (board[row - 1][col].Access_State()){
                        case 1: // Little Lesbian
                            board[row - 1][col].Space_mutator(empty);
                            board[row - 2][col].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row - 1][col].Space_mutator(empty);
                            board[row - 2][col].Space_mutator(LittleTrans);
                            break;
                    }
                }
            }
        }
        else{ // The space 1 spot above the placement is the boards edge
            if (board[row - 1][col].Access_State() != 0){ // Spot above placement is not empty
                if (piece == 'C'){ // Cat
                    switch (board[row - 1][col].Access_State()){
                        case 1:
                            player1_kittens++;
                            break;
                        case 2:
                            player2_kittens++;
                            break;
                        case 3:
                            player1_cats++;
                            break;
                        case 4:
                            player2_cats++;
                            break; 
                    }
                    board[row - 1][col].Space_mutator(empty);
                }
                else{ // Kitten
                    if (board[row - 1][col].Access_State() < 3){ // Kitten above placement
                        switch (board[row - 1][col].Access_State()){
                            case 1:
                                player1_kittens++;
                                break;
                            case 2:
                                player2_kittens++;
                                break;
                        }
                        board[row - 1][col].Space_mutator(empty);
                    }
                }
            }
        }
    }

    if (row + 1 < 6){ // The space below the placed piece is valid
        if (row + 2 < 6){ // The space 2 spots below the placement is valid
            if (board[row + 1][col].Access_State() != 0 && board[row + 2][col].Access_State() == 0){
                if (piece == 'C'){ // Cat
                    switch (board[row + 1][col].Access_State()){ // Piece below the placement
                        case 1: // Little Lesbian
                            board[row + 1][col].Space_mutator(empty);
                            board[row + 2][col].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row + 1][col].Space_mutator(empty);
                            board[row + 2][col].Space_mutator(LittleTrans);
                            break;
                        case 3: // Big Lesbian
                            board[row + 1][col].Space_mutator(empty);
                            board[row + 2][col].Space_mutator(BigLesbian);
                            break;
                        case 4: // Big Trans
                            board[row + 1][col].Space_mutator(empty);
                            board[row + 2][col].Space_mutator(BigTrans);
                            break;
                    }
                }
                else{ // Kitten
                    switch (board[row + 1][col].Access_State()){
                        case 1: // Little Lesbian
                            board[row + 1][col].Space_mutator(empty);
                            board[row + 2][col].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row + 1][col].Space_mutator(empty);
                            board[row + 2][col].Space_mutator(LittleTrans);
                            break;
                    }
                }
            }
        }
        else{ // The space 1 spot below the placement is the boards edge
            if (board[row + 1][col].Access_State() != 0){ // Spot below placement is not empty
                if (piece == 'C'){ // Cat
                    switch(board[row + 1][col].Access_State()){
                        case 1:
                            player1_kittens++;
                            break;
                        case 2:
                            player2_kittens++;
                            break;
                        case 3:
                            player1_cats++;
                            break;
                        case 4:
                            player2_cats++;
                            break; 
                    }
                    board[row + 1][col].Space_mutator(empty);
                }
                else{ // Kitten
                    if (board[row + 1][col].Access_State() < 3){ // Kitten below placement
                        switch(board[row + 1][col].Access_State()){
                            case 1:
                                player1_kittens++;
                                break;
                            case 2:
                                player2_kittens++;
                                break;
                        }
                        board[row + 1][col].Space_mutator(empty);
                    }
                }
            }
        }
    }

    if (col - 1 > -1){ // The space left of the placed piece is valid
        if (col - 2 > -1){ // The space 2 spots left of the placement is valid
            if (board[row][col - 1].Access_State() != 0 && board[row][col - 2].Access_State() == 0){
                if (piece == 'C'){ // Cat
                    switch (board[row][col - 1].Access_State()){ // Piece left of the placement
                        case 1: // Little Lesbian
                            board[row][col - 1].Space_mutator(empty);
                            board[row][col - 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row][col - 1].Space_mutator(empty);
                            board[row][col - 2].Space_mutator(LittleTrans);
                            break;
                        case 3: // Big Lesbian
                            board[row][col - 1].Space_mutator(empty);
                            board[row][col - 2].Space_mutator(BigLesbian);
                            break;
                        case 4: // Big Trans
                            board[row][col - 1].Space_mutator(empty);
                            board[row][col - 2].Space_mutator(BigTrans);
                            break;
                    }
                }
                else{ // Kitten
                    switch (board[row][col - 1].Access_State()){
                        case 1: // Little Lesbian
                            board[row][col - 1].Space_mutator(empty);
                            board[row][col - 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row][col - 1].Space_mutator(empty);
                            board[row][col - 2].Space_mutator(LittleTrans);
                            break;
                    }
                }
            }
        }
        else{ // The space 1 spot left of the placement is the boards edge
            if (board[row][col - 1].Access_State() != 0){ // Spot left of placement is not empty
                if (piece == 'C'){ // Cat
                    switch(board[row][col - 1].Access_State()){
                        case 1:
                            player1_kittens++;
                            break;
                        case 2:
                            player2_kittens++;
                            break;
                        case 3:
                            player1_cats++;
                            break;
                        case 4:
                            player2_cats++;
                            break; 
                    }
                    board[row][col - 1].Space_mutator(empty);
                }
                else{ // Kitten
                    if (board[row][col - 1].Access_State() < 3){ // Kitten left of placement
                        switch(board[row][col - 1].Access_State()){
                            case 1:
                                player1_kittens++;
                                break;
                            case 2:
                                player2_kittens++;
                                break;
                        }
                        board[row][col - 1].Space_mutator(empty);
                    }
                }
            }
        }
    }

    if (col + 1 < 6){ // The space right of the placed piece is valid
        if (col + 2 < 6){ // The space 2 spots right of the placement is valid
            if (board[row][col + 1].Access_State() != 0 && board[row][col + 2].Access_State() == 0){
                if (piece == 'C'){ // Cat
                    switch (board[row][col + 1].Access_State()){ // Piece right of the placement
                        case 1: // Little Lesbian
                            board[row][col + 1].Space_mutator(empty);
                            board[row][col + 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row][col + 1].Space_mutator(empty);
                            board[row][col + 2].Space_mutator(LittleTrans);
                            break;
                        case 3: // Big Lesbian
                            board[row][col + 1].Space_mutator(empty);
                            board[row][col + 2].Space_mutator(BigLesbian);
                            break;
                        case 4: // Big Trans
                            board[row][col + 1].Space_mutator(empty);
                            board[row][col + 2].Space_mutator(BigTrans);
                            break;
                    }
                }
                else{ // Kitten
                    switch (board[row][col + 1].Access_State()){
                        case 1: // Little Lesbian
                            board[row][col + 1].Space_mutator(empty);
                            board[row][col + 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row][col + 1].Space_mutator(empty);
                            board[row][col + 2].Space_mutator(LittleTrans);
                            break;
                    }
                }
            }
        }
        else{ // The space 1 spot right of the placement is the boards edge
            if (board[row][col + 1].Access_State() != 0){ // Spot right of placement is not empty
                if (piece == 'C'){ // Cat
                    switch(board[row][col + 1].Access_State()){
                        case 1:
                            player1_kittens++;
                            break;
                        case 2:
                            player2_kittens++;
                            break;
                        case 3:
                            player1_cats++;
                            break;
                        case 4:
                            player2_cats++;
                            break; 
                    }
                    board[row][col + 1].Space_mutator(empty);
                }
                else{ // Kitten
                    if (board[row][col + 1].Access_State() < 3){ // Kitten left of placement
                        switch(board[row][col + 1].Access_State()){
                            case 1:
                                player1_kittens++;
                                break;
                            case 2:
                                player2_kittens++;
                                break;
                        }
                        board[row][col + 1].Space_mutator(empty);
                    }
                }
            }
        }
    }

    if (row - 1 > -1 && col + 1 < 6){ // The space "NE" the placed piece is valid
        if (row - 2 > -1 && col + 2 < 6){ // The space 2 spots "NE" of the placement is valid
            if (board[row - 1][col + 1].Access_State() != 0 && board[row - 2][col + 2].Access_State() == 0){
                if (piece == 'C'){ // Cat
                    switch (board[row - 1][col + 1].Access_State()){ // Piece "NE" of the placement
                        case 1: // Little Lesbian
                            board[row - 1][col + 1].Space_mutator(empty);
                            board[row - 2][col + 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row - 1][col + 1].Space_mutator(empty);
                            board[row - 2][col + 2].Space_mutator(LittleTrans);
                            break;
                        case 3: // Big Lesbian
                            board[row - 1][col + 1].Space_mutator(empty);
                            board[row - 2][col + 2].Space_mutator(BigLesbian);
                            break;
                        case 4: // Big Trans
                            board[row - 1][col + 1].Space_mutator(empty);
                            board[row - 2][col + 2].Space_mutator(BigTrans);
                            break;
                    }
                }
                else{ // Kitten
                    switch (board[row - 1][col + 1].Access_State()){
                        case 1: // Little Lesbian
                            board[row - 1][col + 1].Space_mutator(empty);
                            board[row - 2][col + 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row - 1][col + 1].Space_mutator(empty);
                            board[row - 2][col + 2].Space_mutator(LittleTrans);
                            break;
                    }
                }
            }
        }
        else{ // The space 1 spot "NE" of the placement is the boards edge
            if (board[row - 1][col + 1].Access_State() != 0){ // Spot "NE" of placement is not empty
                if (piece == 'C'){ // Cat
                    switch(board[row - 1][col + 1].Access_State()){
                        case 1:
                            player1_kittens++;
                            break;
                        case 2:
                            player2_kittens++;
                            break;
                        case 3:
                            player1_cats++;
                            break;
                        case 4:
                            player2_cats++;
                            break;
                    }
                    board[row - 1][col + 1].Space_mutator(empty);
                }
                else{ // Kitten
                    if (board[row - 1][col + 1].Access_State() < 3){ // Kitten "NE" of placement
                        switch (board[row - 1][col + 1].Access_State()){
                            case 1:
                                player1_kittens++;
                                break;
                            case 2:
                                player2_kittens++;
                                break;
                        }
                        board[row - 1][col + 1].Space_mutator(empty);
                    }
                }
            }
        }
    }

    if (row + 1 < 6 && col + 1 < 6){ // The space "SE" the placed piece is valid
        if (row + 2 < 6 && col + 2 < 6){ // The space 2 spots "SE" of the placement is valid
            if (board[row + 1][col + 1].Access_State() != 0 && board[row + 2][col + 2].Access_State() == 0){
                if (piece == 'C'){ // Cat
                    switch (board[row + 1][col + 1].Access_State()){ // Piece "SE" of the placement
                        case 1: // Little Lesbian
                            board[row + 1][col + 1].Space_mutator(empty);
                            board[row + 2][col + 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row + 1][col + 1].Space_mutator(empty);
                            board[row + 2][col + 2].Space_mutator(LittleTrans);
                            break;
                        case 3: // Big Lesbian
                            board[row + 1][col + 1].Space_mutator(empty);
                            board[row + 2][col + 2].Space_mutator(BigLesbian);
                            break;
                        case 4: // Big Trans
                            board[row + 1][col + 1].Space_mutator(empty);
                            board[row + 2][col + 2].Space_mutator(BigTrans);
                            break;
                    }
                }
                else{ // Kitten
                    switch (board[row + 1][col + 1].Access_State()){
                        case 1: // Little Lesbian
                            board[row + 1][col + 1].Space_mutator(empty);
                            board[row + 2][col + 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row + 1][col + 1].Space_mutator(empty);
                            board[row + 2][col + 2].Space_mutator(LittleTrans);
                            break;
                    }
                }
            }
        }
        else{ // The space 1 spot "SE" of the placement is the boards edge
            if (board[row + 1][col + 1].Access_State() != 0){ // Spot "SE" of placement is not empty
                if (piece == 'C'){ // Cat
                    switch (board[row + 1][col + 1].Access_State()){
                        case 1:
                            player1_kittens++;
                            break;
                        case 2:
                            player2_kittens++;
                            break;
                        case 3:
                            player1_cats++;
                            break;
                        case 4:
                            player2_cats++;
                            break;
                    }
                    board[row + 1][col + 1].Space_mutator(empty);
                }
                else{ // Kitten
                    if (board[row + 1][col + 1].Access_State() < 3){ // Kitten "SE" of placement
                        switch (board[row + 1][col + 1].Access_State()){
                            case 1:
                                player1_kittens++;
                                break;
                            case 2:
                                player2_kittens++;
                                break;
                        }
                        board[row + 1][col + 1].Space_mutator(empty);
                    }
                }
            }
        }
    }

    if (row + 1 < 6 && col - 1 > -1){ // The space "SW" the placed piece is valid
        if (row + 2 < 6 && col - 2 > -1){ // The space 2 spots "SW" of the placement is valid
            if (board[row + 1][col - 1].Access_State() != 0 && board[row + 2][col - 2].Access_State() == 0){
                if (piece == 'C'){ // Cat
                    switch (board[row + 1][col - 1].Access_State()){ // Piece "SW" of the placement
                        case 1: // Little Lesbian
                            board[row + 1][col - 1].Space_mutator(empty);
                            board[row + 2][col - 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row + 1][col - 1].Space_mutator(empty);
                            board[row + 2][col - 2].Space_mutator(LittleTrans);
                            break;
                        case 3: // Big Lesbian
                            board[row + 1][col - 1].Space_mutator(empty);
                            board[row + 2][col - 2].Space_mutator(BigLesbian);
                            break;
                        case 4: // Big Trans
                            board[row + 1][col - 1].Space_mutator(empty);
                            board[row + 2][col - 2].Space_mutator(BigTrans);
                            break;
                    }
                }
                else{ // Kitten
                    switch (board[row + 1][col - 1].Access_State()){
                        case 1: // Little Lesbian
                            board[row + 1][col - 1].Space_mutator(empty);
                            board[row + 2][col - 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row + 1][col - 1].Space_mutator(empty);
                            board[row + 2][col - 2].Space_mutator(LittleTrans);
                            break;
                    }
                }
            }
        }
        else{ // The space 1 spot "SW" of the placement is the boards edge
            if (board[row + 1][col - 1].Access_State() != 0){ // Spot "SW" of placement is not empty
                if (piece == 'C'){ // Cat
                    switch (board[row + 1][col - 1].Access_State()){
                      case 1:
                            player1_kittens++;
                            break;
                        case 2:
                            player2_kittens++;
                            break;
                        case 3:
                            player1_cats++;
                            break;
                        case 4:
                            player2_cats++;
                            break;  
                    }
                    board[row + 1][col - 1].Space_mutator(empty);
                }
                else{ // Kitten
                    if (board[row + 1][col - 1].Access_State() < 3){ // Kitten "SW" of placement
                        switch (board[row + 1][col - 1].Access_State()){
                           case 1:
                            player1_kittens++;
                            break;
                        case 2:
                            player2_kittens++;
                            break; 
                        }
                        board[row + 1][col - 1].Space_mutator(empty);
                    }
                }
            }
        }
    }

    if (row - 1 > -1 && col - 1 > -1){ // The space "NW" the placed piece is valid
        if (row - 2 > -1 && col - 2 > -1){ // The space 2 spots "NW" of the placement is valid
            if (board[row - 1][col - 1].Access_State() != 0 && board[row - 2][col - 2].Access_State() == 0){
                if (piece == 'C'){ // Cat
                    switch (board[row - 1][col - 1].Access_State()){ // Piece "NW" of the placement
                        case 1: // Little Lesbian
                            board[row - 1][col - 1].Space_mutator(empty);
                            board[row - 2][col - 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row - 1][col - 1].Space_mutator(empty);
                            board[row - 2][col - 2].Space_mutator(LittleTrans);
                            break;
                        case 3: // Big Lesbian
                            board[row - 1][col - 1].Space_mutator(empty);
                            board[row - 2][col - 2].Space_mutator(BigLesbian);
                            break;
                        case 4: // Big Trans
                            board[row - 1][col - 1].Space_mutator(empty);
                            board[row - 2][col - 2].Space_mutator(BigTrans);
                            break;
                    }
                }
                else{ // Kitten
                    switch (board[row - 1][col - 1].Access_State()){
                        case 1: // Little Lesbian
                            board[row - 1][col - 1].Space_mutator(empty);
                            board[row - 2][col - 2].Space_mutator(LittleLesbian);
                            break;
                        case 2: // Little Trans
                            board[row - 1][col - 1].Space_mutator(empty);
                            board[row - 2][col - 2].Space_mutator(LittleTrans);
                            break;
                    }
                }
            }
        }
        else{ // The space 1 spot "NW" of the placement is the boards edge
            if (board[row - 1][col - 1].Access_State() != 0){ // Spot "NW" of placement is not empty
                if (piece == 'C'){ // Cat
                    switch (board[row - 1][col - 1].Access_State()){
                        case 1:
                            player1_kittens++;
                            break;
                        case 2:
                            player2_kittens++;
                            break;
                        case 3:
                            player1_cats++;
                            break;
                        case 4:
                            player2_cats++;
                            break; 
                    }
                    board[row - 1][col - 1].Space_mutator(empty);
                }
                else{ // Kitten
                    if (board[row - 1][col - 1].Access_State() < 3){ // Kitten "NW" of placement
                        switch (board[row - 1][col - 1].Access_State()){
                            case 1:
                            player1_kittens++;
                            break;
                        case 2:
                            player2_kittens++;
                            break;
                        }
                        board[row - 1][col - 1].Space_mutator(empty);
                    }
                }
            }
        }
    }
}

void Boop::promote(){
    display_status();
    int column[3];
    int row[3];
    string empty = "0";
    string move;

    do{
        cout << "\nPlease provide 3 pieces worthy of promotion in a format such as this \"1a-1b-1c\" followed by the enter/return key\n";
        cout << "The spaces should be entered starting with an edge, then the middle, followed by the other edge\n";
        cin >> move;
    }while (is_legal(move) == 0);
    for (int i = 0; i < 3; i++){
        column[i] = (toupper(move.substr(3 * i, 1)[0])) - 49; // Sets column to track the requested column
        row[i] = (toupper(move.substr(3* i + 1,1)[0])) - 65; // Sets row to track the requested row
    }
    if ((board[row[0]][column[0]].Access_State() == 1 || board[row[0]][column[0]].Access_State() == 3) && (board[row[1]][column[1]].Access_State() == 1 || board[row[1]][column[1]].Access_State() == 3) && (board[row[2]][column[2]].Access_State() == 1 || board[row[2]][column[2]].Access_State() == 3)){ // Worthy of Promotion
        for (int i = 0; i < 3; i++){
            board[row[i]][column[i]].Space_mutator(empty);
        }
        player1_cats += 3;
    }
    else if ((board[row[0]][column[0]].Access_State() == 2 || board[row[0]][column[0]].Access_State() == 4) && (board[row[1]][column[1]].Access_State() == 2 || board[row[1]][column[1]].Access_State() == 4) && (board[row[2]][column[2]].Access_State() == 2 || board[row[2]][column[2]].Access_State() == 4)){ // Worthy of Promotion
        for (int i = 0; i < 3; i++){
            board[row[i]][column[i]].Space_mutator(empty);
        }
        player2_cats += 3;
    }
    cin.ignore();
}

// Restart the game from the beginning:
void Boop::restart(){
    game::restart();
    winner = 0;
    move_type = 1;
    game_over = 0;
    player1_kittens = player2_kittens = 8;
    player1_cats = player2_cats = 0;
}

game* Boop::clone( ) const{
    return new Boop(*this);
}

void Boop::compute_moves(std::queue<std::string>& moves) const{
    string computerMove;
    for (int r = 65; r <= 70; r++){
        for (int c = 49; c <=54 ; c++){
            computerMove = "   ";
            //computerMove = "k" + to_string(char(c)) + to_string(char(r));
            computerMove[0] = 'k';
            computerMove[1] = c;
            computerMove[2] = r;
            //cout << computerMove << endl;
            if (is_legal(computerMove) == 1){
                moves.push(computerMove);
            }
            computerMove = "";
        }
    }
    for (int r = 65; r <= 70; r++){
        for (int c = 1; c <= 6; c++){
            computerMove = "c" + c + r;
            if (is_legal(computerMove) == 1){
                moves.push(computerMove);
            }
            computerMove = "";
        }
    }
}

void Boop::display_status( ) const{
    int sub_row = 0;
    cout << "\n\n\n";
    cout << " --------------------------------------------------------\n";
    for (int row = 0; row < 6; row++){
        for (int sub_column = 0; sub_column < 3; sub_column++){
            switch (sub_row){
                case 1:
                    cout << "A|";
                    break;
                case 4:
                    cout << "B|";
                    break;
                case 7:
                    cout << "C|";
                    break;
                case 10:
                    cout << "D|";
                    break;
                case 13:
                    cout << "E|";
                    break;
                case 16:
                    cout << "F|";
                    break;
                default:
                    cout << " |";
                    break;
            }
            sub_row++;
            for (int column = 0; column < 6; column++){
                cout << "  ";
                switch (board[row][column].Access_State()){ 
                    case 0: // Empty
                        cout << "     ";
                        break;
                    case 1: // Little Lesbian
                        switch (sub_column){
                            case 1:
                                cout << "\e[38;5;208m@@\e[0m@\e[38;5;90m@@\e[0m";
                                break;
                            default:
                                cout << "     ";
                                break;
                        }
                        break;
                    case 2: // Little Trans
                        switch (sub_column){
                            case 1:
                                cout << "\e[34m@\e[35m@\e[0m@\e[35m@\e[34m@\e[0m";
                                break;
                            default:
                                cout << "     ";
                                break;
                        }
                        break;
                    case 3: // Big Lesbian
                        switch (sub_column){
                            case 0:
                                cout << "\e[38;5;208m@@@@@\e[0m";
                                break;
                            case 1:
                                cout << "@@@@@";
                                break;
                            case 2:
                                cout << "\e[38;5;90m@@@@@\e[0m";
                                break;
                        }
                        break;
                    case 4: // Big Trans
                        cout << "\e[34m@\e[35m@\e[0m@\e[35m@\e[34m@\e[0m";
                        break;
                }
                cout << "  ";
            }
            cout << "|\n";
        }
        if (row != 5){
            cout << " |------------------------------------------------------|\n";
        }
    }
    cout << " --------------------------------------------------------\n";
    cout << "      1        2        3        4        5        6        \n\n\n";

    cout << "Player 1 kittens: " << player1_kittens << endl;
    cout << "Player 1 cats: " << player1_cats << endl;
    cout << "Player 2 kittens: " << player2_kittens << endl;
    cout << "Player 2 cats: " << player2_cats << endl;
    cout << "To place a kitten in 1a use \"k1a\"\n";
}

int Boop::evaluate( ) const{ // -1 is player 1, 0 is tie, 1 is player 2
    return winner;
}

bool Boop::is_game_over( ) const{
    if (game_over == 0){
        return 0;
    }
    else{
        return 1;
    }
}

bool Boop::is_legal(const std::string& move) const{ // verify that the player has these pieces
    if (move_type == 1){
        if (move.length() != 3){ // Invalid string length
        return 0;
    }
    char piece = toupper(move.substr(0, 1)[0]); // Sets piece to track the piece type
    if (piece != 'K' && piece != 'C'){ // Not a valid piece selection
        return 0;
    }
    if (next_mover() == HUMAN){ // Player 1 move
        if (piece == 'K' && player1_kittens == 0){ // No pieces to place
            return 0;
        }
        else if (piece == 'C' && player1_cats == 0){
            return 0;
        }
    }
    else{ // Player 2 move
        if (piece == 'K' && player2_kittens == 0){ // No pieces to place
            return 0;
        }
        else if (piece == 'C' && player2_cats == 0){
            return 0;
        }
    }
    int column = (toupper(move.substr(1, 1)[0])) - 49; // Sets column to track the requested column
    if (column < 0 || column > 5){
        return 0;
    }
    int row = (toupper(move.substr(2,1)[0])) - 65; // Sets row to track the requested row
    if (row < 0 || row > 5){
        return 0;
    }
    if (board[row][column].Access_State() != 0){ // Not an empty spot
        return 0;
    }
    return 1;
    }

    else if(move_type == 2){ // remove 3
        string empty = "0";
        int column[3];
        int row[3];
        if (move.length() != 8){ // Bad length
            return 0;
        }
        for (int i = 0; i < 3; i++){
            column[i] = (toupper(move.substr(3 * i, 1)[0])) - 49; // Sets column to track the requested column
            row[i] = (toupper(move.substr(3* i + 1,1)[0])) - 65; // Sets row to track the requested row
            if (column[i] < 0 || column[i] > 5){ // Bad column
                return 0;
            }
            if (row[i] < 0 || row[i] > 5){ // Bad column
                return 0;
            }
        }

        if (column[0] == column[1] && column[1] == column[2] && row[0] - 1 == row[1] && row[1] - 1 == row[2]){ // Pieces are above piece 1
        }
        else if (column[0] + 1 == column[1] && column[1] + 1 == column[2] && row[0] - 1 == row[1] && row[1] - 1 == row[2]){ // Pieces are "NE" of piece 1
        }
        else if (column[0] + 1 == column[1] && column[1] + 1 == column[2] && row[0] == row[1] && row[1] == row[2]){ // Pieces are right of piece 1
        }
        else if (column[0] + 1 == column[1] && column[1] + 1 == column[2] && row[0] + 1 == row[1] && row[1] + 1 == row[2]){ // Pieces are "SE" of piece 1
        }
        else if (column[0] == column[1] && column[1] == column[2] && row[0] + 1 == row[1] && row[1] + 1 == row[2]){ // Pieces are below piece 1
        }
        else if (column[0] - 1 == column[1] && column[1] - 1 == column[2] && row[0] + 1 == row[1] && row[1] + 1 == row[2]){ // Pieces are "SW" of piece 1
        }
        else if (column[0] - 1 == column[1] && column[1] - 1 == column[2] &&  row[0] == row[1] && row[1] == row[2]){ // Pieces are left of piece 1
        }
        else if (column[0] - 1 == column[1] && column[1] - 1 == column[2] && row[0] - 1 == row[1] && row[1] - 1 == row[2]){ // Pieces are "NW"of piece 1
        }
        else{ // Invalid piece combos
            return 0;
        }

        if ((board[row[0]][column[0]].Access_State() == 1 || board[row[0]][column[0]].Access_State() == 3) && (board[row[1]][column[1]].Access_State() == 1 || board[row[1]][column[1]].Access_State() == 3) && (board[row[2]][column[2]].Access_State() == 1 || board[row[2]][column[2]].Access_State() == 3)){ // Worthy of Promotion
            return 1;
        }
        else if ((board[row[0]][column[0]].Access_State() == 2 || board[row[0]][column[0]].Access_State() == 4) && (board[row[1]][column[1]].Access_State() == 2 || board[row[1]][column[1]].Access_State() == 4) && (board[row[2]][column[2]].Access_State() == 2 || board[row[2]][column[2]].Access_State() == 4)){ // Worthy of Promotion
            return 1;
        }
        else{
            return 0;
        }

        return 1;
    }

    else if(move_type == 3){ // all 8 on board
        if (move.length() != 2){ // Bad length
            return 0;
        }
        int column = (toupper(move.substr(0, 1)[0])) - 49; // Sets column to track the requested column
        if (column < 0 || column > 5){
            return 0;
        }
        int row = (toupper(move.substr(1,1)[0])) - 65; // Sets row to track the requested row
        if (row < 0 || row > 5){
            return 0;
        }
        if (next_mover() == HUMAN){
            if (board[row][column].Access_State() != 1 || board[row][column].Access_State() != 3){ // Not an valid
                return 0;
            }
        }
        else{
            if (board[row][column].Access_State() != 2 || board[row][column].Access_State() != 4){ // Not an valid
                return 0;
            }
        }
        return 1;
    }
    return 0;
}