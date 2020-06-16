//Keith
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
    
    // Description: prints out all important airline information
    // Pre: std::ostream& out - output stream
    // Post: pushes everything into ostream buffer
    // Return:
    void printStats(std::ostream& out = std::cout);
    
    // Description: prints out all important airline information
    // Pre: std::ostream& out - output stream
    // Post: pushes everything into ostream buffer
    // Return:
    void printObject(std::ostream& out = std::cout);
    
    // Description: calculates airline score
    // Pre:
    // Post:
    // Return: score of airline
    double calculateScore();
    
    // Description: returns unique key
    // Pre:
    // Post:
    // Return: name of airline
    string getKey() {return name; }
    //Overloaded Operators
    bool operator> (const Airline& obj);
    bool operator< (const Airline& obj);
    bool operator== (const Airline& obj);
    bool operator!= (const Airline& obj);
    Airline& operator= (const Airline& obj);
    //const Airline operator= (const Airline& obj);
    
    // Description: prints certain attributes of an airline
    // Pre:
    // Post: pushes airline into buffer
    // Return:
    friend std::ostream& operator<<(std::ostream& out, Airline& obj);
    
    //Conversion Operator
    // Description: converts name of airline to an int.
    // Pre:
    // Post:
    // Return: int
    operator unsigned() const;

};

#endif /* Airline_h */
