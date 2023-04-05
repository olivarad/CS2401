#include <string>
#include "space.h"

using namespace std;
using namespace main_savitch_14;

//Default constructor (Sets space to empty or 0)
Space::Space(){
    state = 0;
}

void Space::Space_mutator(std::string& move){
    if (move == "k1"){
        state = 1;
    }
    else if (move == "k2"){
        state = 2;
    }
    else if (move == "c1"){
        state = 3;
    }
    else if (move == "c2"){
        state = 4;
    }
    else{ // Piece was booped
        state = 0;
    }
}

int Space::Access_State(){
    return state;
}
