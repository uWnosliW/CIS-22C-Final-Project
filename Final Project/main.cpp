//
//  main.cpp
//  Final Project
//
//  Created by Wilson Wu on 6/2/20.
//  Copyright © 2020 None. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "Airline.h"
#include "BST.h"
#include "LinkedList.h"
using namespace std;
void printEfficiency();
int main(int argc, const char * argv[]) {
    string fileName = "/Users/Wilson/Documents/Final Project/Final Project/input.txt";
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
    
    system("pause");
    return 0;
}

