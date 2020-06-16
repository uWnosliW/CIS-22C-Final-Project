//Keith
#include "Airline.h"

Airline::Airline() : name(""), score(-1), destinations(nullptr), numDestinations(0), onTimePercentage(0.0),numAnnualComplaints(0)
{ }

Airline::Airline(string nme, string* dest, int numDest, double onTime, int numAnnComp) : name(nme),destinations(dest) ,numDestinations(numDest), onTimePercentage(onTime), numAnnualComplaints(numAnnComp)
{
    score = calculateScore();
}
Airline::Airline(const Airline& obj) : name(obj.name), score(obj.score), numDestinations(obj.numDestinations), onTimePercentage(obj.onTimePercentage),numAnnualComplaints(obj.numAnnualComplaints)
{
    destinations = new string[numDestinations];
    for(int i=0;i<numDestinations;i++)
    {
        destinations[i] = obj.destinations[i];
    }
}
void Airline::printStats(std::ostream& out)
{
    out << "Airline name: " << name << endl;
    out << "Score: " << score << endl;
    out << "Destinations: ";
    for (auto i = 0; i < numDestinations; i++)
        out << destinations[i] << " ";
    out << endl;
    out << "On Time Percentage: " << onTimePercentage*100.0 << "%" << endl;
    out << "Number of Annual Complaints: " << numAnnualComplaints << endl;
}
void Airline::printObject(std::ostream& out)
{
    out << name << endl;
    out << numDestinations<<" ";
    for (auto i = 0; i < numDestinations; i++)
        out << destinations[i] << " ";
    out << endl;
    out << onTimePercentage << endl;
    out << numAnnualComplaints << endl;
}

double Airline::calculateScore()
{
    double score = 1.0;
    
    for(int i=0;i<numDestinations;i++)
    {
        score*=1.1;
    }
    score*=onTimePercentage*onTimePercentage;
    score/=numAnnualComplaints;
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

bool Airline::operator!= (const Airline& obj)
{
    return (score != obj.score);
}

Airline& Airline::operator = (const Airline& obj)
{
    this->name = obj.name;
    this->numAnnualComplaints = obj.numAnnualComplaints;
    this->numDestinations = obj.numDestinations;
    this->onTimePercentage = obj.onTimePercentage;
    this->score = obj.score;
    this->destinations = new string[this->numDestinations];
    for(int i=0;i<this->numDestinations;i++)
    {
        this->destinations[i] = obj.destinations[i];
    }
    return *this;
}

bool Airline::operator== (const Airline& obj)
{
    return (name == obj.name);
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
