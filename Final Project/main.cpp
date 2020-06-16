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
int main(int argc, const char * argv[]) {
    string fileName = "/Users/Wilson/Documents/De Anza/Final Project/Final Project/smallInput.txt";
    ifstream airInput(fileName);
    SinglyLinkedList<Airline> linkedlist;
    HashTable<Airline, 50> hashtable;
    BST<Airline> bst;
    if (!airInput)
    {
        cerr << "Can't find " << fileName << endl;
        exit(-1);
    }
    
    string nameTemp, destTemp, dummy;
    int numDestTemp = 0, numAnnualCompTemp = 0;
    double onTimePercentage = 0;
    string* destListTemp;
    int counter = 1;
    
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
            delete []destListTemp;
        }
        catch(...)
        {
            cout << "Something went wrong reading airline data #" << counter << endl;
        }
        counter++;
    }
    bst.printInOrder();
    cout<<"------------------"<<endl;
    while(!linkedlist.isEmpty())
    {
        Airline temp = bst.search(linkedlist.getStart()->data)->getData();
        cout<<temp<<endl;
        linkedlist.deleteNode(linkedlist.getStart()->data);
    }
    system("pause");
    return 0;
}
