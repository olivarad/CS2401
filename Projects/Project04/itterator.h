// forward declaration of the dlist class so that the compiler will continue reading through the node_iterator code
template<class T> class dlist;

template<class T>
class node_iterator{
    public:
        // make this class a friend of the dlist so that dlist functions can access the current pointer in a node_iterator object
        friend class dlist<T>;

		/**
		 * @brief Itterator constructor
		 * @param c Current to be set
		 */
        node_iterator(dnode<T>* c = NULL) {current = c;}

		/**
		 * @brief comparisson
		 * @param other node_iterator to be compared to
		 */
        bool operator != (node_iterator other)const {return current != other.current;}

		/**
		 * @brief operator * overload
		 * @return T data at current
		 */
        T operator * ()const;

        // prefix ++
        node_iterator operator ++ ();
        // postfix ++
        node_iterator operator ++ (int);

        // prefix --
        node_iterator operator -- ();
        //postfix --
        node_iterator operator-- (int);

        dnode<T>* currentPointer() const {return current;}
    private:
        dnode<T>* current;
};

#include "itterator.template"