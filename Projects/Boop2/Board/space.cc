#include <string>
#include <iostream>
#include "space.h"

using namespace std;
using namespace main_savitch_14;

//Default constructor (Sets space to empty or 0)
Space::Space(){
    state = 3;
}

void Space::Space_mutator(std::string& move){
    if (move == "k1"){ // Little Lesbian
        state = 1;
    }
    else if (move == "k2"){ // Little Trans
        state = 2;
    }
    else if (move == "c1"){ // Big Lesbian
        state = 3;
    }
    else if (move == "c2"){ // Big Trans
        state = 4;
    }
    else{ // Piece was booped
        state = 0;
    }
}

int Space::Access_State() const{
    return state;
}