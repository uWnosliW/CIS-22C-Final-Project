#ifndef Airline_hpp
#define Airline_hpp

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Airline
{
private:
    string name;
    int score;
    string* destinations;
    int numDestinations;
    double onTimePercentage;
    int numAnnualComplaints;
    
public:
    //Ctor
    Airline();
    Airline(string nme, int scre, string* dest = nullptr, int numDest = 0, double onTime = 0.0, int numAnnComp = 0);
    
    //Dtor
    ~Airline() { }
    
    //Member functions
    void printStats();
    int calculateScore();
    
    //Overloaded Operators
    bool operator> (const Airline& obj);
    bool operator< (const Airline& obj);
    bool operator== (const Airline& obj);
    const Airline operator= (const Airline& obj);

};

#endif /* Airline_hpp */
