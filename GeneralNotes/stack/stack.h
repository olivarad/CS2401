template <class T>
class Stack{
    public:
        Stack(){topPtr = NULL;} // Constructor

        // Big 3 for singly linked list

        void push(const T item){topPtr = new node<T> item, topPtr;} // Push something onto the stack

        void pop(); // Remove something from the top

        bool empty() const {return topPtr == NULL;} // Checks if the stack is empty

        T top() const {return topPtr -> data();} // See the top item

    private:
        node<T>* topPtr;
};

template <class T>
void Stack::pop(){
    if (topPtr == NULL) return;
    node<T>* temp = topPtr;
    topPtr = topPtr -> next();
    delete temp;
}