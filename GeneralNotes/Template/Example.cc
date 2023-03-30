//example using a vector and iterator to demonstrate what we are trying to do with the node_iterator and Template_LL classes

vector<int> nums;
vector<int>::iterator it;

it = nums.begin();
while(it != nums.end()){
    cout << *it << endl;
    ++it;
}

node<T>* c = it.current;

---------------------------------------------------------------------------------------------------
// node.h file for a singly linked template node
template<class T>
class node{
    public:
        node(T d = T(), node* n = NULL);

        node* next() {return nextptr;}
        T data() {return data_field;}

        void set_next(node* n) {nextptr = n;}
        void set_data(T item) {data_field = item;}

    private:
        node* nextptr;
        T data_field;
};

#include "node.template" //if you have one

---------------------------------------------------------------------------------------------------
// template_ll.h file for template linked list

template<class T>
class Template_LL{
    public:
        typedef node_iterator<T> iterator;

        Template_LL();
        ~Template_LL();
        Template_LL(const Template_LL& other);
        Template_LL& operator = (const Template_LL& other);

        iterator begin() {return iterator(head);}
        iterator end() {return iterator(NULL);}

        // add r_begin, r_end 
        // add insert_before, insert_after, remove
    private:
        node<T>* head;
        node<T>* tail;
};

#include "template_ll.template"

---------------------------------------------------------------------------------------------------
// node_iterator.h file for template node_iterator

// forward declaration of the Template_LL class so that the compiler will continue reading through the node_iterator code
template<class T> class Template_LL;

template<class T>
class node_iterator{
    public:
        // make this class a friend of the Template_LL so that Template_LL functions can access the current pointer in a node_iterator object
        friend class Template_LL<T>;

        node_iterator(node<T>* c = NULL) {current = c;}

        bool operator != (node_iterator other)const;
        bool operator == (node_iterator other)const;

        T operator * ()const;

        // prefix ++
        node_iterator operator ++ ();
        // postfix ++
        node_iterator operator ++ (int);

        // add pre and postfix -- operators

    private:
        node<T>* current;
};

#include "node_iterator.template"

---------------------------------------------------------------------------------------------------

// node_iterator.template file

template<class T>
bool node_iterator<T>::operator != (node_iterator<T> other)const{
    return current != other.current;
}

template<class T>
T node_iterator<T>::operator *()const{
    return current -> data();
}

//prefix
template<class T>
node_iterator<T> node_iterator<T>::operator ++(){
    current = current -> next();
    return *this;
}

//postfix
template<class T>
node_iterator<T> node_iterator<T>::operator ++(int){
    node_iterator<T> original(*this);
    current = current -> next();
    return original;
}

---------------------------------------------------------------------------------------------------
// other useful information for project 4

/*
    * You need to turn the singly linked node into a doubly linked node

    * Every function of a template class is a template function so they all need "template<class T> before the implementation"

    * Remember to put <T> after the name of any template class when you are outside the class
      declaration and it is not the name of a constructor or deconstructor.

    * In insert_before, insert_after, and remove:
        * consider all cases
            * first node, last node, middle node, single node list
        * you may find it useful to set a pointer to the iterator's "current"
          //assuming the iterator argument is called "it"
          node<T>* ptr = it.current;

    * You need a .h and a .template for each template class you write (node, dlist, node_iterator)
        * Include the .template file (what you would normally call a .cc) at the end of the .h
        * Still only include .h files in other files
        * When you compile a main, you do not list the .template files in the g++ command, just .cc
*/