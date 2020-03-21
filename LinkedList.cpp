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
    HEAD = NULL;
    TAIL = NULL;
    CURRENT = NULL;
}
/**********************************************************************************************************************/
LinkedList::LinkedList(var_type str)
{
    segWords(str);//Added this in as it would make sense for this class constructor.
}
/**********************************************************************************************************************/
LinkedList::~LinkedList()
{
    //Temporary buff on stack
    Node* buff;

    CURRENT = HEAD;

    //Destroy nodes
    for(;CURRENT != NULL;)
    {
        buff = CURRENT->getN();
        delete(CURRENT);
        CURRENT = buff;
    }
}
/**********************************************************************************************************************/
void LinkedList::add(var_type str)
{
    segWords(str);
}
/**********************************************************************************************************************/
unsigned int LinkedList::count(const var_type& str)
{
    CURRENT = HEAD;
    //Looks through Nodes and increments if match is present
    unsigned int count = 0;

    for(;CURRENT != NULL;)
    {
        if(*(CURRENT->getD()) == str)//A match, Increment
        {
            count++;
        }

        CURRENT = CURRENT->getN();
    }

    return count;
}
/**********************************************************************************************************************/
bool LinkedList::doesExist(Node* N)
{
    Node* buff = HEAD;//create temp pointer as CURRENT is being used in calling process

    for(;buff != NULL;)
    {
        if(buff == N)
        {
            return true;
        }

        buff = buff->getN();
    }
    return false;
}
/**********************************************************************************************************************/
int LinkedList::removeNode(Node* toRem)
{
    //As calling uses CURRENT we must create a buff
    Node* buff = NULL;

    //Need to see if Node is head or tail
    if(toRem == HEAD)
    {
        buff = HEAD;
        HEAD = HEAD->getN();//Change HEAD
        HEAD->setP(NULL);//Change new HEAD previous
        delete (buff);//Destroy Node
        return 1;

    }else if(toRem == TAIL)
    {
        buff = TAIL;
        TAIL = TAIL->getP();//Change tail
        TAIL->setN(NULL);//Change new tail next
        delete(buff);//Destroy Node
        return 2;

    } else if(doesExist(toRem))//Pointer may point to non HEAD/tail node or none at all
    {
        buff = toRem;
        //Change right node properties
        buff->getN()->setP(buff->getP());//Set right prev pointer to CURRENT prev
        //Change left Node properties
        buff->getP()->setN(buff->getN());
        //Delete node
        delete(buff);

        return 3;
    } else
    {
        return 0;
    }
}
/**********************************************************************************************************************/
void LinkedList::removeData(const var_type& str)
{
    CURRENT = HEAD;

    for(;CURRENT != NULL;)
    {

        if(*(CURRENT->getD()) == str)
        {
            Node* buff = CURRENT->getN();
            removeNode(CURRENT);
            CURRENT = buff;
            continue;
        }

        CURRENT = CURRENT->getN();
    }
}
/**********************************************************************************************************************/
void LinkedList::remove(const var_type& str)
{
    //For loop to count strings
    unsigned int count = 1;//Starts at one as to include starting word
    unsigned int currCount = 0;
    unsigned int currIndex = 0;
    unsigned int prevIndex = 0;
    Node* buff;

    for(unsigned int i = 0; i < str.size();)//As long as index remains below max
    {
        i = str.find(' ', i+1);//find whitespace

        if(i > str.size())
        {
            //Do not increment, leave
            break;
        } else if((i+1)<str.size()){//Make sure white space is not last character
            count++;
        }
    }

    CURRENT = HEAD;

    for(;CURRENT != NULL;)
    {
        currIndex = str.find(*(CURRENT->getD)(),0);

        if(currIndex < str.size())//Does word exist?
        {
            if((currCount == 0) || (currIndex > prevIndex))//is it found after last found word, or is it the first word?
            {
                prevIndex = currIndex;
                currCount++;

                if(count == currCount)//Is it the last word to find
                {
                    for(;currCount != 0; currCount--)
                    {
                        buff = CURRENT->getP();
                        removeNode(CURRENT);
                        CURRENT = buff;
                    }
                    continue;
                }

                CURRENT = CURRENT->getN();
            } else//Word not in order as needed
            {
                currCount = 0;
                //Current CURRENT might be the start of a streak, dont get next
            }
        } else//Word not found, streak broken
        {
            currCount = 0;
            CURRENT = CURRENT->getN();
        }
    }
}
/**********************************************************************************************************************/
var_type* LinkedList::getListLine()
{
    //Create string buffer
    var_type* buff = new string();

    //Reset CURRENT
    CURRENT = HEAD;

    //For loop
    for(;CURRENT != NULL;)
    {
        buff->append(*(CURRENT->getD()));
        buff->append(" ");
        CURRENT = CURRENT->getN();
    }

    return buff;
}
/**********************************************************************************************************************/
LinkedList& LinkedList::operator += (LinkedList& L2)
{
    //Take out strings from L2 and use add node to add to l1
    segWords(*(L2.getListLine()));
    return *this;
}
/**********************************************************************************************************************/
void LinkedList::addNode(const var_type& str) {
    //Put on heap with pointer
    var_type *pStr = new string(str);

    //See if HEAD node is null
    if (HEAD == NULL) {
        //it is, therefore a list has not been created yet
        HEAD = new Node(NULL, NULL, pStr);
        //TAIL now becomes HEAD
        TAIL = HEAD;
        //CURRENT is referenced with recently modified/viewed Node
        CURRENT = HEAD;
        //std::cout << "NODE: " << *(HEAD->getD()) << std::endl;
        return;
    }

    //std::cout << "NODE: " << *(CURRENT->getD()) << std::endl;

    //If not see if next nodes are null.. ie free.
    CURRENT = TAIL;//Ensure we are at end of list
    CURRENT = new Node(CURRENT, NULL, pStr);//new node data updated
    TAIL = CURRENT;//Change to new TAIL
    CURRENT->getP()->setN(CURRENT);//set next node to this node on previous node

    //std::cout << "NODE: " << *(CURRENT->getD()) << std::endl;
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

        end = str.find(' ',start+1);//Find where CURRENT word ends

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

    }

    //Will probably come across memory issues WELL before this happens
}
/**********************************************************************************************************************/
ostream& operator << (ostream& out, LinkedList& list)
{
    //Required operation is to print out the components of each node in order
    out << *(list.getListLine());
    return out;
}