#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
  int answer1 = 0, answer2 = 0;
  int NumOfDest = 0;
  double OnTimePer = 0.0;
  int NumOfAnn = 0;
  string Destinations;
  cout << "Welcome to the Airline Ranking System.\n" << endl;
  do {
    cout << "Please select what you want to view:" << endl;
    cout << "1. Flight Inquiry" << endl;
    cout << "2. Airline ranking" << endl;
    cout << "3. Quit" << endl;
    cout << "Your choose is: ";
    cin >> answer1;
    cout << endl;
    if (answer1 == 1)
    {
      cout << "Please select the flight you want to check:" << endl;
      cout << "1. American Airlines" << endl;
      cout << "2. Apple Air" << endl;
      cout << "3. Big City Air" << endl;
      cout << "4. Cathy Pacific Airlines" << endl;
      cout << "5. China Eastern" << endl;
      cout << "6. China Southern" << endl;
      cout << "7. Github Air" << endl;
      cout << "8. Ivy Air" << endl;
      cout << "9. UC Air" << endl;
      cout << "10. United Airlines" << endl;
      cout << "11. Virgin Airlines" << endl;
      cout << "12. Royal Dutch Airlines" << endl;
      cout << "Your choose is: ";
      cin >> answer2;
      cout << endl;
    }
    if (answer1 == 1)
    {
      if (answer2 == 1)
      {
        cout << "American Airlines" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else if (answer2 == 2)
      {
        cout << "Apple Air" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else if (answer2 == 3)
      {
        cout << "Big City Air" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else if (answer2 == 4)
      {
        cout << "Cathy Pacific Airlines" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else if (answer2 == 5)
      {
        cout << "China Eastern" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else if (answer2 == 6)
      {
        cout << "China Southern" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else if (answer2 == 7)
      {
        cout << "Github Air" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else if (answer2 == 8)
      {
        cout << "Ivy Air" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else if (answer2 == 9)
      {
        cout << "UC Air" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else if (answer2 == 10)
      {
        cout << "United Airlines" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else if (answer2 == 11)
      {
        cout << "Virgin Airlines" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else if (answer2 == 12)
      {
        cout << "Royal Dutch Airlines" << endl;
        cout << NumOfDest << " destinations: " << Destinations << endl;
        cout << "On-Time Performance: " << OnTimePer << "%" << endl;
        cout << "Number of Annual Customer Complaints: " << NumOfAnn << endl;
      }
      else
      {
        cout << "Please choose a valid number" << endl;
        cout << endl;
      }
    }
    if (answer1 == 2)
    {
      cout << "Please select the ranking you want to view: " << endl;
      cout << "1. Number of Destinations" << endl;
      cout << "2. On-Time Performance" << endl;
      cout << "3. Number of Annual Customer Complaints" << endl;
      cout << "Your choose is: ";
      cin >> answer2;
      cout << endl;
    }
    if (answer1 == 2)
    {
      if (answer2 == 1)
    {
      cout << left;
      cout << setw(20) << "# Airline" << "Number of Destinations" << endl;
      cout << "*******************************************************************" << endl;

    }
      else if (answer2 == 2)
    {
      cout << left;
      cout << setw(20) << "# Airline" << "On-Time Performance" << endl;
      cout << "*******************************************************************" << endl;

    }
      else if (answer2 == 3)
    {
      cout << left;
      cout << setw(20) << "# Airline" << "Number of Annual Customer Complaints" << endl;
      cout << "*******************************************************************" << endl;

    }
    else
    {
        cout << "Please choose a valid number" << endl;
        cout << endl;
    }
    }
    else if (answer1 != 1 && answer1 != 2 && answer1 !=3)
    {
      cout << "Please choose a valid number" << endl;
      cout << endl;
    }
  } while (answer1 != 3);
  cout << "Thank you for watching!" << endl;
  return 0;
  system("pause");
}
