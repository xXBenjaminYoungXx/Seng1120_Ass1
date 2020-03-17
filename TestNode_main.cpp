//
// Created by User on 16/03/2020.
//
#include <iostream>
#include "Node.h"
//LinkedListDemo.cpp
//Enter above back into compile list
using namespace std;

int main()
{
    cout << "This main Function is to run the node class individually" << endl;

    //Make node
    cout << "Constructing node N1" << endl;

    Node* N1 = new Node();

    cout << "Node successfully created." << endl << "Node contents: " << endl;

    cout << "Data: " << N1->getD() << " Prev ptr: " << N1->getP() << " next ptr: " << N1->getN() << endl;

    cout << "Storing word: Fellow; " << endl;

    string* word = new string("Fellow");

    N1->setD(word);

    cout << "Data ptr: " << N1->getD() << " Prev ptr: " << N1->getP() << " next ptr: " << N1->getN() << " Data: " << *(N1->getD()) << "Current Ptr: " << N1 << endl;

    cout << "Constructing node N2" << endl;

    string* word2 = new string("Stonks");

    Node* N2 = new Node(N1, NULL, word2);

    cout << "Data ptr: " << N2->getD() << " Prev ptr: " << N2->getP() << " next ptr: " << N2->getN() << " Data: " << *(N2->getD()) << "Current Ptr: " << N2 << endl;

    cout << "Deleting nodes" << endl;

    cout << "Constructing node N3" << endl;

    string* word3 = new string("Rise");

    Node* N3 = new Node(NULL, N1, word3);

    cout << "Data ptr: " << N3->getD() << " Prev ptr: " << N3->getP() << " next ptr: " << N3->getN() << " Data: " << *(N3->getD()) << "Current Ptr: " << N3 << endl;

    cout << "Deleting nodes" << endl;

    delete N1;
    delete N2;
    delete N3;
}