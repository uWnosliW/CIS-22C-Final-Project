#include "Airline.h"

Airline::Airline() : name(""), score(-1), destinations(nullptr), numDestinations(0), onTimePercentage(0.0),numAnnualComplaints(0)
{ }

Airline::Airline(string nme, string* dest, int numDest, double onTime, int numAnnComp) : name(nme),destinations(dest) ,numDestinations(numDest), onTimePercentage(onTime), numAnnualComplaints(numAnnComp)
{
    score = calculateScore();
}

void Airline::printStats()
{
    cout << "Airline name: " << name << endl;
    cout << "Score: " << score << endl;
    cout << "Destinations: ";
    for (auto i = 0; i < numDestinations; i++)
        cout << destinations[i] << " ";
    cout << endl;
    cout << "On Time Percentage: " << onTimePercentage*100.0 << "%" << endl;
    cout << "Number of Annual Complaints: " << numAnnualComplaints << endl;
}

int Airline::calculateScore()
{
    int score = 0;
    
    if (numDestinations < 5)
        score+=5;
    else if (numDestinations < 10)
        score+=10;
    else
        score+=15;
    
    if (onTimePercentage < 0.8)
        score+=5;
    else if (onTimePercentage < 0.9)
        score+=10;
    else
        score+=15;

    if (numAnnualComplaints < 10)
        score+=15;
    else if (numAnnualComplaints < 15)
        score+=10;
    else
        score+=5;
    
    return score;
}

bool Airline::operator> (const Airline& obj)
{
    return (score > obj.score);
}

bool Airline::operator< (const Airline& obj)
{
    return (score < obj.score);
}

bool Airline::operator== (const Airline& obj)
{
    return (score == obj.score);
}

//const Airline Airline::operator=(const Airline& obj)
//{
//    name = obj.name;
//    score = obj.score;
//    numDestinations = obj.numDestinations;
//    for (auto i = 0; i < numDestinations; i++)
//        destinations[i] = obj.destinations[i];
//    onTimePercentage = obj.onTimePercentage;
//    numAnnualComplaints = obj.numAnnualComplaints;
//    
//    return *this;
//}

Airline::operator unsigned() const
{
    static unsigned primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    unsigned product = 1;
    
    for (auto i = 0; i < name.length(); i++)
    {
        product *= primes[tolower(name[i]) - 'a'];
    }
    
    return product;
}

std::ostream& operator<<(std::ostream& out, Airline& obj)
{
    out << "Airline name: " << obj.name << std::endl;
    out << "Score: " << obj.score << std::endl;
//    out << "Destinations: ";
//    for (auto i = 0; i < obj.numDestinations; i++)
//        out << obj.destinations[i] << " ";
//    out << std::endl;
//    out << "On Time Percentage: " << obj.onTimePercentage*100.0 << "%" << std::endl;
//    out << "Number of Annual Complaints: " << obj.numAnnualComplaints << std::endl;
    
    return out;
}
