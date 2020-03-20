//
// Created by Benjamin Young on 15/03/2020.
//
// Email: BenjaminYoung7198@gmail.com
// Student ID: C3330653
// Course: SENG1120
// Task: Assignment 1
// File: Node Class header file
//
// This assignment has been developed on the CLion IDE.

/********************************/
//         Node Class           //
/********************************/
//NODE_VARIABLES:
//    -Node* next
//    -Node* prev
//    -var_type* data

//Macroguard to prevent multiple compilations of Node class
#ifndef ASSIGNMENT1_NODE_H
#define ASSIGNMENT1_NODE_H

#define NEXT next
#define PREV prev
#define DATA data

//Required Library files/classes/namespaces
#include <string>
using namespace std;

typedef string var_type;

class Node {
//public member functions
public:

    //LinkedList Constructor
    Node();

    //Further defined constructors
    Node(Node* P, Node* N, var_type* D);
    //Pre-condition: Requires 3 object pointers; previous node ptr, next node ptr, and var_type ptr

    //Destructor
    ~Node();

    //Getter and Setter Functions
    Node* getP() const;//Declare const as no private variables are manipulated
    //Post-condition: Returns a Node pointer that points to the previous node. May return null

    Node* getN() const;
    //Post-condition: Returns a Node pointer that points to the next node. May return null

    var_type* getD() const;
    //Post-condition: Returns a var_type pointer that points to the var_type. May return null

    void setP(Node* p);
    //Pre-condition: requires node pointer to previous node

    void setN(Node* n);
    //Pre-condition: requires node pointer to next node

    void setD(var_type* d);
    //Pre-condition: requires var_type pointer to var_type

    //Member Overloads

//Private member variables
private:
    Node* NEXT;
    Node* PREV;
    string* DATA;
};

//Non-Member Overloads

#endif //ASSIGNMENT1_NODE_H
