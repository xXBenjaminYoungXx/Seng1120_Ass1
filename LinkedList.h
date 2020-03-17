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
#include <string>
#include "Node.h"
using namespace std;

typedef string var_type;

class LinkedList{

//public member functions
public:

    //LinkedList Constructor
    LinkedList();

    //Further defined constructors
    LinkedList(var_type sentence);

    //Destructor
    ~LinkedList();

    //Getter and Setter Functions
    void add(var_type sentence);

    //Member Overloads

//Private member variables
private:
    Node* head;
    Node* tail;
    Node* current;
};

//Non-Member Overloads

#endif //ASSIGNMENT1_LINKEDLIST_H
