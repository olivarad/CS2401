#ifndef SPACE_H
#define SPACE_H

#include <string>


class Space{
    public:
        // Default constructor (Sets space to empty)
        Space();

        //Space mutator function (Move format is substring of full move with only piece information)
        void Space_mutator(std::string& move);

        //Space Accessor
        int Access_State() const;

    private:
        // State variable 0 is empty 1 is k1, 2 is k2, 3 is c1, 4 is c2
        int state;
};

#endif