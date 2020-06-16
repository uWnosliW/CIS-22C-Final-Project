#ifndef Airline_h
#define Airline_h

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Airline
{
private:
    string name;
    double score;
    string* destinations;
    int numDestinations;
    double onTimePercentage;
    int numAnnualComplaints;
    
public:
    //Ctor
    Airline();
    Airline(const Airline& obj);
    Airline(string nme, string* dest = nullptr, int numDest = 0, double onTime = 0.0, int numAnnComp = 0);
    
    //Dtor
    ~Airline() { }
    
    //Member functions
    void printStats();
    double calculateScore();
    string getKey() {return name; }
    //Overloaded Operators
    bool operator> (const Airline& obj);
    bool operator< (const Airline& obj);
    bool operator== (const Airline& obj);
    bool operator!= (const Airline& obj);
    Airline& operator= (const Airline& obj);
    //const Airline operator= (const Airline& obj);
    friend std::ostream& operator<<(std::ostream& out, Airline& obj);
    
    //Conversion Operator
    operator unsigned() const;

};

#endif /* Airline_h */
