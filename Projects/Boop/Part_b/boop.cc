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
    char piece = toupper(move.substr(0, 1)[0]); // Sets piece to track the piece type
    int column = (toupper(move.substr(1, 1)[0])) - 49; // Sets column to track the requested column
    int row = (toupper(move.substr(2,1)[0])) - 65; // Sets row to track the requested row
    if (move_number % 2 == 0){ // Player 1 move
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
    promotion();
    ++move_number;
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

void Boop::promotion(){ // Promotes 3 matching kittens in a row or 8 matching kittens on a board to one cat
    if ((player1_kittens == 0 && player1_cats == 0) || (player2_kittens == 0 && player2_cats == 0)){ // PLayer1 may promote 1 kitten to a cat by removing it from the board
    string target_space = "";
    string empty = "0";
    display_status();
        int empty_promotion = 0;
        do {
            cout << "Please provide a space (number, letter) with one of your kittens to be cleared in order to receive a cat: ";
            cin >> target_space;
            cout << endl;
            if (target_space.length() == 2){
                int column = (toupper(target_space.substr(0, 1)[0])) - 49; // Sets column to track the requested column
                int row = (toupper(target_space.substr(1,1)[0])) - 65; // Sets row to track the requested row
                if ((column > -1 && column < 6) && (row > -1 && row < 6)){// coordinates exsist on the board
                    if (player1_kittens == 0){
                        if (board[row][column].Access_State() == 1){
                            board[row][column].Space_mutator(empty);
                            player1_cats++;
                            empty_promotion++;
                        }
                    }
                    else{
                        if (board[row][column].Access_State() == 2){
                            board[row][column].Space_mutator(empty);
                            player2_cats++;
                            empty_promotion++;
                        }
                    }
                }
            }
        } while (empty_promotion == 0);
    }
}

// Restart the game from the beginning:
void Boop::restart( ){
    move_number = 0; 
    player1_kittens = player2_kittens = 1;
    player1_cats = player2_cats = 0;
}

game* Boop::clone( ) const{
    game* temp;
    return temp;
}

void Boop::compute_moves(std::queue<std::string>& moves) const{

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
}

int Boop::evaluate( ) const{
    return 0; // Temp
}

bool Boop::is_game_over( ) const{
    return 0; // Temp
}

bool Boop::is_legal(const std::string& move) const{ // verify that the player has these pieces
    if (move.length() != 3){ // Invalid string length
        return 0;
    }

    char piece = toupper(move.substr(0, 1)[0]); // Sets piece to track the piece type
    if (piece != 'K' && piece != 'C'){ // Not a valid piece selection
        return 0;
    }

    if (move_number % 2 == 0){ // Player 1 move
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