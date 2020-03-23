//LinkedListDemo - Main Program
/******************************/
//Author: Alex Mendes
//Course: SENG1120
//Program Description: This program demonstrates the basic functionality of a linked list that stores strings. 
//It will demo the functions of a basic linked list.
//The program adds content to a linked list, removes individual nodes, among other functionalities.

#include <iostream>
#include <cstdlib>
#include <string>
#include "LinkedList.h"
using namespace std;

void initialize(LinkedList &l1, LinkedList &l2)
{
    l1.add("The black cat was sitting on the black mat that was on the black floor");
    l2.add("The dog scared the cat and the cat ran away");
}

int main()
{
    LinkedList firstList;
    LinkedList secondList;

    initialize(firstList, secondList);

    cout << "Start lists:" << endl;
    cout << "List 1: " << firstList  <<  endl;
    cout << "List 2: " << secondList <<  endl << endl;

    cout << "Concatenating the two lists onto list '1':" << endl;
    firstList += secondList;
    cout << "List 1: " << firstList  << endl;
    cout << "List 2: " << secondList << endl << endl;

    cout << "Removing the word 'was' from list '1':" << endl;
    firstList.remove("was");
    cout << "List 1: " << firstList  << endl;
    cout << "List 2: " << secondList << endl << endl;

    cout << "Removing the word 'away' from list '2':" << endl;
    secondList.remove("away");
    cout << "List 1: " << firstList  << endl;
    cout << "List 2: " << secondList << endl << endl;

    cout << "Removing the word 'cat' from both lists:" << endl;
    firstList.remove("cat");
    secondList.remove("cat");
    cout << "List 1: " << firstList  << endl;
    cout << "List 2: " << secondList << endl << endl;

    cout << "Number of occurrences of 'black' in list 1: ";
    cout << firstList.count("black") << endl << endl;

//  Uncomment this section if you are implementing the extended version of the method remove()
 	cout << "Removing 'on the black' from both lists:" << endl;
 	firstList.remove("on the black");
 	secondList.remove("on the black");
 	cout << "List 1: " << firstList  << endl;
 	cout << "List 2: " << secondList << endl << endl;

    cout << "The program has finished." << endl;
    return 0;
}