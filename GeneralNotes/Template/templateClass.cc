#include <iostream>
#include <string>

template<typename T, int N>
class Array{
    public:
        int getSize() const {return N;}

    private:
        T m_Array[N];
};

int main(){
    Array<int, 500> array;
    std::cout << array.getSize() << std::endl;

    return 0;
}