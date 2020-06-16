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
            cout<<size - 1 << " "<<airlines[size - 1];
            delete []destListTemp;
        }
        catch(...)
        {
            cout << "Something went wrong reading airline data #" << size << endl;
        }
        size++;
    }
    //bst.printInOrder();
    /*cout<<"------------------"<<endl;
    for(int i=0;i<size-1;i++)
    {
        //cout<<airlines[i];
        auto t = linkedlist.find(airlines[i]);
        cout<<t<<endl;
    }*/
    
    cout<<"------------------"<<endl;
    for(int i=0;i<size-1;i++)
    {
        auto t = hashtable.find(airlines[i]);
        t.printStats();
    }
    system("pause");
    return 0;
}
