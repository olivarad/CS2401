#include <string>

class chore{
    public:
        void input();
        void output() const;
        friend bool operator < (const chore& c1, const chore& c2);
    private:
        std::string choreName;
        int priorityNumber; // Higher numbers indicate a more urgent chore
};