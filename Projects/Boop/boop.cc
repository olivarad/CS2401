#include <iostream>
#include <cstring>
#include "space.h"
#include "boop.h"

using namespace std;
using namespace main_savitch_14;

// Default Constructor (Calls restart())
Boop::Boop(){
    restart();
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
    ++move_number;
}

// Restart the game from the beginning:
void Boop::restart( ){
    string set = "0";
    move_number = 0; 
    player1_kittens = player2_kittens = 8;
    player1_cats = player2_cats = 0;
    for (int row = 0; row < 6; row++){ // Resets board
        for (int column = 0; column < 6; column++){
            board[row][column].Space_mutator(set);
        }
    }
}

game* Boop::clone( ) const{
    game* temp;
    return temp;
}

void Boop::compute_moves(std::queue<std::string>& moves) const{

}

void Boop::display_status( ){
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