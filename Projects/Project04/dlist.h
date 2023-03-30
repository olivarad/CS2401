#include <iostream>
#include "Dnode.h"
#include "itterator.h"

#ifndef DLIST_H
#define DLIST_H

template <class T> 
class dlist{
    public:
    	/**
		 * @brief Construct a dlist object
		 * 
		 * @param h head of the list
		 * @param t tail of the list
		 */
        dlist(dnode<T>* h = NULL, dnode<T>* t = NULL); // Default constructor setting head and tail to NULL

        typedef node_iterator<T> iterator;

		/**
		 * @brief Destruct a list
		 */
        ~dlist(); // Destructor

        /**
		 * @brief Copy constructor for a dlist
		 * 
		 * @param other a seperate dlist
		 */
        dlist(const dlist& other); // Copy constructor

		/**
		 * @brief dlist Assignment operator
		 * 
		 * @param other dlist that is assigned from
		 */
        void operator = (const dlist& other); // Assignment operator

		/**
		 * @brief front_insert
		 * 
		 * @param item T item that gets added at the front
		 */
		void front_insert(const T item); // Inserts an item at the head of the list

        /**
		 * @brief rear_insert
		 * 
		 * @param item T item that gets added to the rear of the list
		 */
		void rear_insert(const T item); // Places an item in the last "index" of the list

		/**
		 * @brief insert before a node in the list
		 * 
		 * @param it an external itterator that can track a node in the list
		 * @param item T item to be added
		 */
        void insert_before(const iterator it, const T item); // Inserts an item before the itterator

        /**
		 * @brief insert after a node in the list
		 * 
		 * @param it an external itterator that can track a node in the list
		 * @param item T item to be added
		 */
        void insert_after(const iterator it, const T item); // Inserts an item after the itterator

		/**
		 * @brief remove front node
		 */
		void front_remove(); // Removes the very first item in the list
        
        /**
		 * @brief remove rear node
		 */
		void rear_remove(); // Removes the very last item in the list

		/**
		 * @brief general node removal function
		 * 
		 * @param it itterator tracking node to be removed
		 */
        void remove(const iterator it); // Removes data in the passed itterator

		/**
		 * @brief begin an externl itterator 
         * @return an itterator to track the list at the head
		 */
        iterator begin() {return iterator(head);}

        /**
		 * @brief state the end of an external itterator
		 * @return the end of the list
		 */
        iterator end() {return iterator(NULL);}

		/**
		 * @brief makes an external itterator
         * @retrun an external itterator tracking the tail as the start
		 */
        iterator r_begin() {return iterator(tail);}

        /**
		 * @brief define the end of the itterator
		 * @return the end of the list
		 */
        iterator r_end() {return iterator(NULL);}

		/**
		 * @brief show list
		 */
        void show() const; // Outputs list

        		/**
		 * @brief show list in reverse
		 */
        void reverse_show() const; // Outputs the list in reverse

        		/**
		 * @brief gives the size of a list
		 * @return int with list size
		 */
        int size() {return list_size;} // Returns the size of the list

    private:
        dnode<T>* head;
        dnode<T>* tail;
        int list_size;
};

#include "dlist.template"

#endif