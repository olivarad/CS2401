#include <iostream>
#ifndef DNODE_H
#define DNODE_H

template <class T>
class dnode{
    public:
		/**
		 * @brief constructor for a dnode
		 * 
		 * @param d data
		 * @param p previous node
		 * @param n next node
		 */
		dnode(T d = 0, dnode* p = NULL, dnode* n = NULL); // Default constructor which sets data to the passed in data of type T and sets previous and next to NULL

		/**
		 * @brief data accessor function
		 * @return T data_field
		 */
		T data() {return data_field;} // Returns data of type T

		/**
		 * @brief previous accessor function
		 * @return dnode<T>* of the previous node
		 */
		dnode<T>* previous() {return previousptr;} // Returns previous

		/**
		 * @brief next accessor function
		 * @return dnode<T>* of the next node
		 */
		dnode<T>* next() {return nextptr;} // Returns next

		/**
		 * @brief data mutator function
		 * @param T item to be added
		 */
		void set_data(T item) {data_field = item;} // Sets data to a passed value of type T

		/**
		 * @brief previous mutator function
		 * @param dnode* to be set
		 */
		void set_previous(dnode* p) {previousptr = p;} // Sets previous

		/**
		 * @brief next mutator function
		 * @param dnode* to be set
		 */
		void set_next(dnode* n) {nextptr = n;} // Sets next

    private:
		T data_field; // Data field of template type T
		dnode *nextptr;
		dnode *previousptr;
};

#include "dnode.template"

#endif