#include <queue>
#include "chore.h"

using namespace std;

int main(){
    chore temp;
    priority_queue<chore> chores;
    for (int i = 0; i < 5; i++){
        temp.input();
        chores.push(temp);
    }
    for (int i = 0; i < 5; i++){
        chores.top().output();
        chores.pop();
    }
    return 0;
}