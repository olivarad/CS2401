#include <queue>
#include <string>
#include <iostream>
#include "game.h"
#include "boop.h"

using namespace std;

namespace main_savitch_14
{
	void Boop::make_move(const std::string& move){
		move_count++; // Updates move count
	}

	void Boop::restart(){
		player1_kittens = player2_kittens = 8;
		player1_cats = player2_cats = 0;
	}

    game* Boop::clone() const{ // clone stub

	}

	void Boop::compute_moves(std::queue<std::string>& moves) const{ // compute_moves stub
		move_count = move_number;
	}

	void Boop::display_status( ) const{ // display_status stub
		cout << "\n\n\n--------------------------------------------------------\n|                                                      |\n";
    	for (int x = 0; x < 6; x++){ // Rows
    		cout << "|";
            for (int y = 0; y < 6; y++){ // Colums
                    cout << "    x    ";
                }
            if (x != 5){
                cout << "|\n|                                                      |\n|------------------------------------------------------|\n|                                                      |\n";
            }
            else{
                cout << "|\n|                                                      |\n--------------------------------------------------------\n\n\n";
            }
        }
	}

	int Boop::evaluate( ) const{
        return 0; // temp
	}

	bool Boop::is_game_over( ) const{
            return 0; // temp
	}

	bool Boop::is_legal(const std::string& move) const{
		string piece = move.substr(0, 1); // Create a string to store the piece type
		string location = move.substr(1, 2);
		if (isalpha(piece[0] == 0)){ // Not a valid input
			return 0;
		}
		else{
			tolower(piece[0]);
			if (piece == "c"){ // cat
                return 1; // temp
			}
			else if (piece == "k"){ // kitten
                return 1; // temp
			}
			else{ // invalid input
				return 0;
			}
		}
	}
}