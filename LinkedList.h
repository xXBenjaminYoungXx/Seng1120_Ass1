//
// Created by Benjamin Young on 15/03/2020.
//
// Email: BenjaminYoung7198@gmail.com
// Student ID: C3330653
// Course: SENG1120
// Task: Assignment 1
// File: LinkedList Class header file
//
// This assignment has been developed on the CLion IDE.
//
/**********************************************************************************************************************/
// Assignment Task:
//      -You are required to use a **doubly-linked list**, as discussed in lectures, to create your own
//       implementation of the LinkedList class.
//      -It will use instances of Node to store instances of value_type (in this assignment, each Node will be used to
//       store an instance of string).
//      -Your list will be used to store the individual words of a sentence, broken up on the spaces; so each Node will
//       store a single word. For instance, “The Black Cat” will add three separate words (“The”, “Black”, “Cat”)
//       to the list.
//      -PLEASE NOTE: The main of the program is: "LinkedListDemo", and it will be compiled using the makefile.
//       As I am using the CLion IDE I must:
//          -*****ENSURE THE PROGRAM RUNS USING MAKEFILE AND CYGWIN PROGRAM ALONE*****
//          -*****NAMES OF CLASSES ARE AS SPECIFIED*****
//          -*****INCLUDE HEADERS FOR ALL FILES*****
//          -*****FILES TO SUBMIT INCLUDE:  ******
//              1.LinkedList.cpp
//              2.LinkedList.h
//              3.Node.cpp
//              4.Node.h
//              5.readme.txt
//              6.ASSIGNMENT COVER SHEET
//          -*****ALL HEADER FILES REQUIRE DETAILED COMMENTING*****
//          -*****ALL FILES COMPRESSED INTO A ZIP FOLDER UNDER NAME: "c3330653_remove.zip"*****
//
/**********************************************************************************************************************/
//
/********************************/
//       linkedList Class       //
/********************************/
//Beyond standard class functions we also need to implement the following:
//Remove function Note: This function may need to remove more than one node
// << overload
// += overload

//Macroguard to prevent multiple compilations of LinkedList class
#ifndef ASSIGNMENT1_LINKEDLIST_H
#define ASSIGNMENT1_LINKEDLIST_H

//#include <iostream> //Used for debugging messages only
#include <string>
#include "Node.h"
#define CURRENT current
#define HEAD head
#define TAIL tail
using namespace std;

typedef string var_type;

class LinkedList{

//public member functions
public:

    //LinkedList Constructor
    LinkedList();

    //Further defined constructors
    LinkedList(var_type str);

    //Destructor
    ~LinkedList();

    // Functions that add functionality to the linked list
    void add(var_type str);

    unsigned int count(const var_type& str);
    //Pre-Condition: Takes instance of var_type, named str.
    //
    //Post-Condition: Returns Int with a value based on the number of matching var_type instances as str


    void remove(const var_type& str);
    //Pre-Condition: Takes instance of var_type, named str.

    var_type* getListLine();
    //Post-Condition: Returns pointer to string which contains list data

    //Member Overloads
    //L1 += L2 overload requires concatenation of the two list var_type
    LinkedList& operator += (LinkedList& L2);

//Private member variables
private:
    Node* HEAD;
    Node* TAIL;
    Node* CURRENT;

    //private functions
    void addNode(const var_type& str);
    //Pre-Condition: Takes pointer to var_type and stores it in new node

    bool doesExist(Node* N);
    //Pre-Condition: Pointer to Node under question of existing
    //
    //Post-Condition: True if it exists, False otherwise

    int removeNode(Node* toRem);
    //Pre-Condition: Takes pointer to node that will be removed
    //
    //Post-Condition: Returns 0 if Node does not exist, 1 if it deleted HEAD, 2 tail, 3 other

    void segWords(var_type& str);
    //Pre-Condition: Takes reference of type Var_type
    //
    //Post-Condition: Returns 1 for successful process, 0 otherwise
};

//Non-Member Overloads
//<< Requires that the variable type var_type should be printed to the screen using ostream object
ostream& operator << (ostream& out, LinkedList& list);

#endif //ASSIGNMENT1_LINKEDLIST_H
