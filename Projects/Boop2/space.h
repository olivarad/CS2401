#ifndef SPACE_H
#define SPACE_H

namespace main_savitch_14
{
    #include <string>
    #include "boop.h"

    class Space:public Boop{
    //class Space{
        public:
            //Default constructor (sets all spaces to empty)
            Space();
        private:
            std::string space_state;
    };
}

#endif