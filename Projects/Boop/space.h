#ifndef SPACE_H
#define SPACE_H

#include <string>

namespace main_savitch_14
{
	class Space:private Boop{
	public:
		Space(){space_state = "0";} // Default constructor (ALL SPACES INITIALIZED TO EMPTY)
		void state_update(std::string user_move); // State mutator funciton
		std::string get_state(){return space_state;} // State accessor function

	protected:
		std::string space_state;
	};
}

#endif