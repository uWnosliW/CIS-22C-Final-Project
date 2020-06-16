//
//  main.cpp
//  Final Project
//
//  Created by Wilson Wu on 6/2/20.
//  Copyright © 2020 None. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "HashTable.h"
#include "Airline.h"
#include "BST.h"
#include "LinkedList.h"
using namespace std;
int main(int argc, const char * argv[]) {
    string fileName = "/Users/Wilson/Documents/Final Project/Final Project/smallInput.txt";
    ifstream airInput(fileName);
    SinglyLinkedList<Airline> linkedlist;
    HashTable<Airline, 50> hashtable;
    BST<Airline> bst;
    Airline airlines[50];
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
            
            Airline temp(nameTemp, destListTemp, numDestTemp,
                         onTimePercentage, numAnnualCompTemp);
            
            //cout<<temp<<endl;
            bst.insertNode(temp);
            //bst.printInOrder();
            linkedlist.appendNode(temp);
            hashtable.insert(temp);
            airlines[size - 1] = temp;
            delete []destListTemp;
        }
        catch(...)
        {
            cout << "Something went wrong reading airline data #" << size << endl;
        }
        size++;
    }
    cout<<"Type insert followed by an Airline object on the next line to update the database. Type delete, search, or print stats followed by the name of an Airline on the next line to check the database and display all airline information. Type display hash table, display in order, print indented tree, print efficiency to display Airlines in various formats. Type quit to exit the program."<<endl;
    string input;
    getline(cin,input);
    while(input != "quit")
    {
        if(input == "insert")
        {
            std::string name,space;
            getline(cin,space);
            int numDestTemp,numAnnualCompTemp;
            double onTimePercentage;
            getline(cin,name);
            cout<<name<<endl;
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
            Airline curr(name,destListTemp, numDestTemp, onTimePercentage, numAnnualCompTemp);
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
            Airline temp = hashtable.find(Airline(name));
            if(!(temp == Airline()))
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
            Airline temp = hashtable.find(Airline(name));
            if(!(temp == Airline()))
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
            Airline temp = hashtable.find(Airline(name));
            if(!(temp == Airline()))
            {
                temp.printStats();
            }
            else
            {
                cout<<name<<" is not currently in any data structure."<<endl;
            }
        }
        else if(input == "display hash table")
        {
            
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
            
        }
        getline(cin,input);
    }
    system("pause");
    return 0;
}

