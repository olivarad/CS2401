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

game* Boop::clone( ) const{
    game* temp;
    return temp;
}

void Boop::compute_moves(std::queue<std::string>& moves) const{

}

void Boop::display_status( ) const{

}

int Boop::evaluate( ) const{
    return 0; // Temp
}

bool Boop::is_game_over( ) const{
    return 0; // Temp
}

bool Boop::is_legal(const std::string& move) const{
    return 1; // Temp
}