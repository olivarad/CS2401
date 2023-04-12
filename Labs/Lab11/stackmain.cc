/*************************************************************************
	Lab Assignment 9 - working with a stack
	It's sometimes tricky to set up the loop that reads the expression 
	from the keyboard, so I am giving that to you. You have to fill in 
	the rest of the main.

	John Dolan	Fall 2016	Ohio University		Home of the Bobcats
*************************************************************************/
#include <stack>
#include <iostream>
#include <cstdlib>
#include "calc_useful.h"
using namespace std;

int main(){
	char c;
	char tmp;
	int onenum, twonum;
	bool continu = true;
	// declare an STL stack called nums right here:
	stack<int> nums;

	do{
		cout << "Please enter your expression:\n";

		c = cin.get(); // priming read for the sentinel loop.
		while(c != '\n'){
			if(isdigit(c)){
				cin.putback(c);
				cin >> onenum;
				// stack operation here.
				nums.push(onenum);
			}
			else if(isop(c)){
				if(!nums.empty()){

					//pop two numbers from the stack
					twonum = nums.top();
					nums.pop();
					onenum = nums.top();
					nums.pop();
                    // evaluate them using the evaluate from stack_useful
					// push result onto the stack
					nums.push(evaluate(onenum, twonum, c));
				}
				else{
					cout << "Error:";
					cout << " Expression doesn't contain enough enough numbers."; // what did this error tell us about the user's expression?
					return -1;
				}
			}

			c = cin.get(); // reading at the bottom of the sentinel loop
		} // bottom of the loop that reads a single expression from the keyboard

		// output the final result from the top of the stack
		// but only after you check to make sure there's something on the stack
		if (nums.empty() != 1){ // nums has data
			cout << "result: " << nums.top() << endl;
			nums.pop();
		}

		cout << "Enter another equation?(y or n)";
		cin >> tmp;
		cin.ignore();
		if(tmp == 'y' || tmp == 'Y')
			continu = true;
		else
			continu = false;

	}while(continu == true);
	return 0;
}