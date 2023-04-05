#ifndef BOOP_H
#define BOOP_H

#include "space.h"
#include "game.h"

namespace main_savitch_14
{
    class Boop:private game{
	public:
		// *******************************************************************
		// VIRTUAL FUNCTIONS THAT MUST BE OVERRIDDEN:
		// The overriding function should call the original when it finishes.
		// *******************************************************************
		// Have the next player make a specified move:
		// Have the next player make a specified move:
		virtual void make_move(const std::string& move);
		// Restart the game from the beginning:
		virtual void restart();

		// *******************************************************************
		// PURE VIRTUAL FUNCTIONS
		// *******************************************************************
		// (these must be provided for each derived class)
		// Return a pointer to a copy of myself:
		virtual game* clone() const = 0;
		// Compute all the moves that the next player can make:
		virtual void compute_moves(std::queue<std::string>& moves) const = 0;
		// Display the status of the current game:
		virtual void display_status( ) const = 0;
		// Evaluate a board position:
		// NOTE: positive values are good for the computer.
		virtual int evaluate( ) const = 0;
		// Return true if the current game is finished:
		virtual bool is_game_over( ) const = 0;
		// Return true if the given move is legal for the next player:
		virtual bool is_legal(const std::string& move) const = 0;

	protected:
	Space board [6][6]; // Board is 6X6 array (row, col)
	private:
	int move_count;
	int player1_kittens;
	int player2_kittens;
	
	int player1_cats;
	int player2_cats;
	};
}
#endif