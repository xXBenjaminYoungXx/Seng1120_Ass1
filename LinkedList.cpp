//
// Created by Benjamin Young on 15/03/2020.
//
// Email: BenjaminYoung7198@gmail.com
// Student ID: C3330653
// Course: SENG1120
// Task: Assignment 1
// File: LinkedList Class cpp file
//
// This assignment has been developed on the CLion IDE.

#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}
/**********************************************************************************************************************/
LinkedList::LinkedList(var_type str)
{
    segWords(str);
}
/**********************************************************************************************************************/
LinkedList::~LinkedList()
{
    //********************************************************************************************
}
/**********************************************************************************************************************/
void LinkedList::add(var_type str)
{
    segWords(str);
}
/**********************************************************************************************************************/
int LinkedList::count(var_type str)
{
    current = head;
    //Looks through Nodes and increments if match is present
    unsigned int count = 0;

    for(;current != NULL;)
    {
        if((current->getD())->compare(str) == 0)//A match, Increment
        {
            count++;
        }

        current = current->getN();
    }

    return count;
}
/**********************************************************************************************************************/
void LinkedList::remove(var_type str)
{
    //Break str into words
    //Delete words
}
/**********************************************************************************************************************/
var_type* LinkedList::getListLine()
{
    //Create string buffer
    var_type* buff = new string();

    //Reset current
    current = head;

    //For loop
    for(;current != NULL;)
    {
        buff->append(*(current->getD()));
        buff->append(" ");
        current = current->getN();
    }

    return buff;
}
/**********************************************************************************************************************/
LinkedList& LinkedList::operator += (LinkedList& L2)
{
    //Take out strings from L2 and use add node to add to l1
    //Reset current

    segWords(*(L2.getListLine()));
}
/**********************************************************************************************************************/
void LinkedList::addNode(var_type str) {
    //Put on heap with pointer
    var_type *pStr = new string(str);

    //See if head node is null
    if (head == NULL) {
        //it is, therefore a list has not been created yet
        head = new Node(NULL, NULL, pStr);
        //Tail now becomes head
        tail = head;
        //Current is referenced with recently modified/viewed Node
        current = head;
        //std::cout << "NODE: " << *(head->getD()) << std::endl;
        return;
    }

    //std::cout << "NODE: " << *(current->getD()) << std::endl;

    //If not see if next nodes are null.. ie free.
    current = tail;//Ensure we are at end of list
    current = new Node(current, NULL, pStr);//new node data updated
    tail = current;//Change to new tail
    current->getP()->setN(current);//set next node to this node on previous node

    //std::cout << "NODE: " << *(current->getD()) << std::endl;
}
/**********************************************************************************************************************/
void LinkedList::segWords(var_type& str)
{
    //Separate str into individual words/tokens
    //Begin By declaring necessary var
    unsigned int start, end;
    start = 0;

    //Get first token as to avoid issues
    end = str.find(' ',start);

    //**Input node**
    addNode(str.substr(start,end));

    //std::cout << str.substr(start,end) << std::endl;

    //catch up
    start = end;

    for(unsigned int i = 0; ; i++)
    {//loop to segregate remaining words

        end = str.find(' ',start+1);//Find where current word ends

        if(end > str.find_last_of(' ',str.size())) //If true 'find' function has hit string limit
        {
            //**Input final node**
            addNode(str.substr(start+1,str.size()));
            //std::cout << str.substr(start+1,str.size()) << std::endl;
            return;
        }

        //**Input Node :
        addNode(str.substr(start+1,end-(start+1)));
        //std::cout << str.substr(start+1,end-(start+1)) << std::endl;
        //catch up
        start = end;

        if(i == 300)
        {
            std::cout << "Warning: Process exceeded 300 loops" << std::endl << "segWords function" << std::endl;
        }
    }

    //Will probably come across memory issues WELL before this happens
}
/**********************************************************************************************************************/
ostream& operator << (ostream& out, LinkedList& list)
{
    //Required operation is to print out the components of each node in order
    cout << *(list.getListLine());
    return cout;
}