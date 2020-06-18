//Yi-wei and Hairun
/*
 assumptions and execution:
 1) all Airlines in the input file are properly formatted in the following manner:
    Airline name
    number of destinations followed by all the destinations space separated(spaces in names are replaced with underscores)
    on time percentage
    number of anual complaints
 2) console input is taken in the following format
    command
    airline name or object
 */
/*
 pseudocode:
 get the input file path and open the file
 declare BST, hash table, and linked list with template argument Airlines
 while not end of file
    dynamically allocate a temporary airline object
    read all airline fields and instantiate the airline object
    insert it into all three data structures
    delete temporary Airline object
 get first user input
 while user input is not quit
    if input is insert
        read airline object to insert(assuming correct syntax)
        insert the object into all three data structures
    if input is delete:
        read airline name
        check if the airline is in the hashtable
        if it is
            retreive the airline object from the hashtable
            use that object to delete instances in the BST and linked list
        else
            notify user that the airline is not currently in any data structure
    if input is search:
        read airline name
        check if the airline is in the hashtable
        search BST for the airline(for efficiency calculations)
        if airline was found
            print airline name and its score
        else
            notify user that the airline is not currently in any data structure
     if input is print stats:
         read airline name
         check if the airline is in the hashtable
         search BST for the airline(for efficiency calculations)
         if airline was found
             print airline name, score, number of destitions, list of destinations, percent of time on time, and number of anual complaints
         else
             notify user that the airline is not currently in any data structure
     if input is display hash table
         print hash table
     if input is print in order
         print bst in order
     if input is print indented tree
        print bst indented
     if input is print efficiency
        print hash table load factor, longest linked list, and average linked list size
        print average operations per bst insertion
        if searches have been made
            print average operations per bst search
        else
            print no searches have been made yet
    if input is recomend
        print top three airlines based on score
    get next input
 update input file with elements from linked list
 */
#include <iostream>
#include <string>
#include <fstream>
#include "HashTable.h"
#include "Airline.h"
#include "BST.h"
#include "LinkedList.h"
using namespace std;
int main(int argc, const char * argv[]) {
    string fileName; //= "/Users/Wilson/Documents/Final Project/Final Project/input.txt";
    cout<<"Please enter the absolute file path of the input file:"<<endl;
    getline(cin,fileName);
    ifstream airInput(fileName);
    SinglyLinkedList<Airline*> linkedlist;
    HashTable<Airline*, 20> hashtable;
    BST<Airline*> bst;

    if (!airInput)
    {
        cerr << "Can't find " << fileName << endl;
        exit(-1);
    }

    string nameTemp, destTemp, dummy;
    int numDestTemp = 0, numAnnualCompTemp = 0;
    double onTimePercentage = 0;
    string* destListTemp;
    int size = 1;

    while(!airInput.eof())
    {
        try
        {
            getline(airInput, nameTemp);

            if(airInput.eof())
                break;

            airInput >> numDestTemp;
            destListTemp = new string[numDestTemp];

            int counter = 0;

            while(counter < numDestTemp)
            {
                airInput >> destTemp;
                destListTemp[counter] = destTemp;
                counter++;
            }

            airInput >> onTimePercentage;
            airInput >> numAnnualCompTemp;

            getline(airInput, dummy);

            Airline* temp = new Airline(nameTemp,destListTemp,numDestTemp,onTimePercentage,numAnnualCompTemp);

            //cout<<temp<<endl;
            bst.insertNode(temp);
            //bst.printInOrder();
            linkedlist.appendNode(temp);
            hashtable.insert(temp);
            //delete [] destListTemp;
        }
        catch(...)
        {
            cout << "Something went wrong reading airline data #" << size << endl;
        }
        size++;
    }
    //hashtable.print();
    //bst.printInOrder();

    airInput.close();
    cout<<"Type insert followed by an Airline object on the next line to update the database. Type delete, search, or print stats followed by the name of an Airline on the next line to check the database and display all airline information. Type display hash table, display in order, print indented tree, print efficiency to display Airlines in various formats. Type recommend to recommend top 3 airlines. Type quit to exit the program."<<endl;
    string input;
    getline(cin,input);
    while(input != "quit")
    {
        if(input == "insert")
        {
            std::string name,space;
            int numDestTemp,numAnnualCompTemp;
            double onTimePercentage;
            getline(cin,name);
            cin >> numDestTemp;
            string* destListTemp = new string[numDestTemp];
            int counter = 0;

            while(counter < numDestTemp)
            {
                cin >> destTemp;
                destListTemp[counter] = destTemp;
                counter++;
            }
            cin >> onTimePercentage;
            cin >> numAnnualCompTemp;
            Airline* curr = new Airline(name,destListTemp, numDestTemp, onTimePercentage, numAnnualCompTemp);
            
            bst.insertNode(curr);
            hashtable.insert(curr);
            linkedlist.appendNode(curr);
            cout<<name<<" inserted into database."<<endl;
            delete[] destListTemp;
        }
        else if(input == "delete")
        {
            std::string name;
            getline(cin,name);
            
            Airline* searchPtr = new Airline(name);
            auto temp = hashtable.find(searchPtr);
            
            if(!(temp == nullptr))
            {
                bst.deleteNode(temp);
                hashtable.remove(temp);
                linkedlist.deleteNode(temp);
                cout<<name<<" successfully removed from all data structures."<<endl;
            }
            else
            {
                cout<<name<<" is not currently in any data structure."<<endl;
            }
        }
        else if(input == "search")
        {
            std::string name;
            getline(cin,name);
            Airline* searchPtr = new Airline(name);
            auto temp = hashtable.find(searchPtr);
            bst.search(temp);
            if(!(temp == nullptr))
            {
                cout<<temp<<endl;
            }
            else
            {
                cout<<name<<" is not currently in any data structure."<<endl;
            }

        }
        else if(input == "print stats")
        {
            std::string name;
            getline(cin,name);
            Airline* searchPtr = new Airline(name);
            auto temp = hashtable.find(searchPtr);
            if(!(temp == nullptr))
            {
                temp->printStats();
            }
            else
            {
                cout<<name<<" is not currently in any data structure."<<endl;
            }
        }
        else if(input == "display hash table")
        {
            hashtable.print();
        }
        else if(input == "display in order")
        {
            bst.printInOrder();
        }
        else if(input == "print indented tree")
        {
            bst.printIndentedTree();
        }
        else if(input == "print efficiency")
        {
            cout<<"Hash table"<<endl;
            cout<<"load factor: "<<hashtable.getLoadFactor()<<endl;
            cout<<"longest linked list:"<<hashtable.getLongestList()<<endl;
            cout<<"BST"<<endl;
            cout<<"Average operations per insertion: "<<bst.getInsertionOperations()*1.0/bst.getInsertionQueries()<<endl;
            if(bst.getSearchQueries()>0)
            {
                cout<<"Average operations per search: "<<bst.getSearchOperations()*1.0/bst.getSearchQueries()<<endl;
            }
            else
            {
                cout<<"No searches have been made yet."<<endl;
            }
        }
        else if(input == "recommend")
        {
            cout << "Here's the top 3 airlines in the data structure:" << endl;
            linkedlist.printTop3();
        }
        else
        {
            cout<<"Unrecognized command."<<endl;
        }
        getline(cin,input);
    }
    ofstream airOutput(fileName);
    while(!linkedlist.isEmpty())
    {
        linkedlist.getStart()->data->printObject(airOutput);
        linkedlist.deleteNode(linkedlist.getStart()->data);
    }
    system("pause");
    return 0;
}


