#include "Shape.h"
#include <iostream>

using namespace std;

int menu();

int main(){
    /*
    Circle c;
    Rectangle r;
    Triangle t;
    //Shape s; // An abstract class will restrict making on object of the parent type (even one abstract function will make the whole class abstract)

    c.cost();
    r.cost();
    t.cost();
    //s.cost();

    shape* s; // Shape pointers allowed in abstract class
    s = new Circle; // Parent pointers can also point to a child, if it works for parent it works for child (sort of)
    s -> cost();

    Shape* box(10);
    box[0] = new Circle;
    box[1] = new Triangle;
    box[2] = new Rectangle;
*/

    Shape* box[15];
    Shape* tmp;
    int used = 0;
    double total_cost = 0;

    int choice = 0;
    choice = menu();

    while(choice != 4 && used < 15){
        switch(choice){
            case 1:
                tmp = new Circle;
                break;
            case 2:
                tmp = new Triangle;
                break;
            case 3:
                tmp = new Rectangle;
                break;
            case 4:
                break;
                break;
            tmp -> input();
            box[used] = tmp;
            used++;
            choice = menu();
        }
    }

    for (int i = 0; i < used; i++){
        total_cost += box[i] -> cost();
    }

    cout << "Total_cost:" << total_cost << endl;

    return 0;
}

int menu(int choice){
    //opt1 add circ
    //2 add triangle
    //3 add rectangle
    //4 quit

    cin >> choice;

    return choice;
}