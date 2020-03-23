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
/*LinkedList::LinkedList(var_type str)
{
    sepWords(str);//Added this in as it would make sense for this class constructor.
}*/
/**********************************************************************************************************************/
LinkedList::~LinkedList()
{
    //Temporary buff on stack
    Node* buff;

    CURRENT = HEAD;

    //Destroy nodes
    while(CURRENT != NULL)
    {
        buff = CURRENT->getN();
        delete(CURRENT);
        CURRENT = buff;
    }
}
/**********************************************************************************************************************/
void LinkedList::add(var_type str)
{
    sepWords(str);
}
/**********************************************************************************************************************/
unsigned int LinkedList::count(const var_type& str)
{
    CURRENT = HEAD;
    //Looks through Nodes and increments if match is present
    unsigned int count = 0;

    while(CURRENT != NULL)
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

    while(buff != NULL)
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
/*void LinkedList::removeData(const var_type& str)//Function Not used, but kept as comment anyways
{
    CURRENT = HEAD;

    while(CURRENT != NULL)
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
}*/
/**********************************************************************************************************************/
void LinkedList::remove(const var_type& str)
{
    //For loop to count var_types
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

    //The above for loop should be turned into an independent public function, but because this is not used anywhere
    //else I just got lazy and wrote it here

    CURRENT = HEAD;

    while(CURRENT != NULL)
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
    //Create var_type buffer
    var_type* buff = new var_type();

    //Reset CURRENT
    CURRENT = HEAD;

    //For loop
    while(CURRENT != NULL)
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
    //Take out var_types from L2 and use add node to add to l1
    sepWords(*(L2.getListLine()));
    return *this;
}
/**********************************************************************************************************************/
void LinkedList::addNode(const var_type& str) {
    //Put on heap with pointer
    var_type *pStr = new var_type(str);

    //If words dont  exist
    if(str.size() == 0)
    {
        return;
    }

    //See if HEAD node is null
    if (HEAD == NULL) {
        //it is, therefore a list has not been created yet
        HEAD = new Node(NULL, NULL, pStr);
        //TAIL now becomes HEAD
        TAIL = HEAD;
        //CURRENT is referenced with recently modified/viewed Node
        CURRENT = HEAD;
        return;
    }

    //If not see if next nodes are null.. ie free.
    CURRENT = TAIL;//Ensure we are at end of list
    CURRENT = new Node(CURRENT, NULL, pStr);//new node data updated
    TAIL = CURRENT;//Change to new TAIL
    CURRENT->getP()->setN(CURRENT);//set next node to this node on previous node
}
/**********************************************************************************************************************/
void LinkedList::sepWords(var_type& str)
{
    //Separate str into individual words/tokens
    //Begin By declaring necessary var
    unsigned int start, end;
    start = 0;

    //Get first token as to avoid issues
    end = str.find(' ',start);

    if(end > str.size())//Only one word or no word
    {
        addNode(str);
        return;
    }

    //Input node
    addNode(str.substr(start,end));

    //catch up
    start = end;

    for(unsigned int i = 0; ; i++)
    {//loop to separate remaining words

        end = str.find(' ',start+1);//Find where CURRENT word ends

        if(end > str.find_last_of(' ',str.size())) //If true 'find' function has hit var_type limit
        {
            //Input final node
            addNode(str.substr(start+1,str.size()));
            return;
        }

        //Input Node
        addNode(str.substr(start+1,end-(start+1)));

        //catch up
        start = end;
    }

    //I feel like I could improve this function to be more readable and efficient, however it does the task ¯\_(ツ)_/¯
}
/**********************************************************************************************************************/
ostream& operator << (ostream& out, LinkedList& list)
{
    //Required operation is to print out the components of each node in order
    out << *(list.getListLine());
    return out;
}