#include "boop.h"

using namespace main_savitch_14;

// Default Constructor (Calls restart())
Boop::Boop(){
    restart();
    // Resets board
}

// Have the next player make a specified move:
void Boop::make_move(const std::string& move){
    ++move_number;
}

// Restart the game from the beginning:
void Boop::restart( ){
    move_number = 0; 
    player1_kittens = player2_kittens = 8;
    player1_cats = player2_cats = 0;
}