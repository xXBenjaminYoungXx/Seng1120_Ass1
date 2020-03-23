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
    NEXT = NULL;
    PREV = NULL;
    DATA = NULL;
}

Node::Node(Node* P, Node* N, var_type* D)
{
    NEXT = N;
    PREV = P;
    DATA = D;
}

Node::~Node()
{
    delete(DATA);
}

Node* Node::getP() const
{
    return PREV;
}

Node* Node::getN() const
{
    return NEXT;
}

var_type* Node::getD() const
{
    return DATA;
}

void Node::setP(Node* p)
{
    PREV = p;
}

void Node::setN(Node* n)
{
    NEXT = n;
}
/*
void Node::setD(var_type* d)
{
    DATA = d;
}*/