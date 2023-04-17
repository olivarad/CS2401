#include <iostream>

using namespace std;

int counting(int n);
/*
Helping function of see_stars to print stars
should print n stars on the same line
needs to be recursive
*/
void print_stars(int n);
// Calls the print_stars int the body
void see_stars(int count, int stop);

int main(){
    int x;
    for (int j = 0; j < 3; ++j){
        cout << "Enter a number: ";
        cin >> x;
        cout << "The numbers counting up to there:\n";
        counting(x);
        cout << endl;
    }

    int n;
    cout << "Enter a number between 1 and 30 to see the stars\n";
    cin >> n;
    see_stars(1, n);
    return 0;
}

int counting(int n){
    if (n > 1){
        counting(n - 1);
        cout << n << " ";
    }
    else if (n == 1){
        cout << n << " ";
    }
    else{
        return -1;
    }
    return 0;
}

void print_stars(int n){
    if (n == 1){
        cout << "*\n";
    }
    else{
        cout << "*";
        print_stars(n - 1);
    }
}

void see_stars(int count, int stop){
    if (stop > 30 || stop < 1){
        return;
    }

    if (stop == count){
        print_stars(count);
        print_stars(count);
        see_stars (count -1, stop -1);
    }
    else if (stop > count){
        print_stars(count);
        see_stars(count + 1, stop);
    }
}