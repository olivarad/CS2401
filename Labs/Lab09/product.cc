#include <iostream>
#include <list>
#include "product.h"

using namespace std;

void shirt::input(product*& p){
    /*cout << "Provide a size: ";
    cin >> size;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;*/
    size = "large";
    color = "pink";
    //product_list.push_back(p);
}

void shirt::output() const{
    cout << "shirt\n";
    cout << "Size: " << size << endl;
    cout << "Color: " << color << endl;
}

void skirt::input(product*& p){
    cout << "Provide a size: ";
    cin >> size;
    cout << "\n Provide a length: ";
    cin >> length;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;
}

void skirt::output() const{
    cout << "skirt\n";
    cout << "Size: " << size << endl;
    cout << "Length: " << length << endl;
    cout << "Color: " << color << endl;
}

void heel::input(product*& p){
    cout << "Provide a size: ";
    cin >> size;
    cout << "\n Provide a heel height: ";
    cin >> height;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;
}

void heel::output() const{
    cout << "heel\n";
    cout << "Size: " << size << endl;
    cout << "Heel height: " << height << endl;
    cout << "Color: " << color << endl;  
}

void ears::input(product*& p){
    cout << "provide an animal: ";
    cin >> animal;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;
}

void ears::output() const{
    cout << "ears\n";
    cout << "Animal: " << animal << endl;
    cout << "Color: " << color << endl;
}

void knife::input(product*& p){
    cout << "Provide a blade length: ";
    cin >> length;
    cout << "\nProvide a handle material\n";
    cin >> handle;
    cout << endl;
}

void knife::output() const{
    cout << "knife\n";
    cout << "Length: " << length << endl;
    cout << "Handle material: " << handle << endl;
}