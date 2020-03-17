//
// Created by Benjamin Young on 15/03/2020.
//
// Email: BenjaminYoung7198@gmail.com
// Student ID: C3330653
// Course: SENG1120
// Task: Assignment 1
// File: Node Class cpp file
//
// This assignment has been developed on the CLion IDE.

#include "Node.h"

Node::Node()
{
    next = NULL;
    prev = NULL;
    data = NULL;
}

Node::Node(Node* P, Node* N, var_type* D)
{
    next = N;
    prev = P;
    data = D;
}

Node::~Node(){}

Node* Node::getP() const
{
    return prev;
}

Node* Node::getN() const
{
    return next;
}

var_type* Node::getD() const
{
    return data;
}

void Node::setP(Node* p)
{
    prev = p;
}

void Node::setN(Node* n)
{
    next = n;
}

void Node::setD(var_type* d)
{
    data = d;
}