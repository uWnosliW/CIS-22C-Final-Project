#include <iostream>
#include <fstream>
#include <string>
#include "Airline.h"

using namespace std;

int main()
{
    string fileName = "input.txt";
    ifstream airInput(fileName);

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

    /*
    File Input
    */
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

            temp.printStats();

            delete []destListTemp;
        }
        catch(...)
        {
            cout << "Something went wrong reading airline data #" << counter << endl;
        }
        counter++;
    }

    /*
    Sample File Output, when add data in console need in sync with input file
    */
    ofstream airOutput(fileName, ios::app);
    if (!airOutput)
    {
        cerr << "Can't output to " << fileName << endl;
        exit(-2);
    }

    airOutput << "Test Add Airline" << endl;
    airOutput << 2 << " San_Jose" << " Seattle" << endl;
    airOutput << 100.0 << endl;
    airOutput << 15 << endl;


    airInput.close();
    airOutput.close();
    return 0;
}
