#include <iostream>
#include <string>

    template<typename T>
void print(T value){
    std::cout << value << std::endl;
}

int main(){
    print(5);
    print<std::string>("Hello");
    print(5.5f);

    return 0;
}