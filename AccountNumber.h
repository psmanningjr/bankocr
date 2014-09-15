#ifndef ACCOUNTNUMBER_H
#define ACCOUNTNUMBER_H

#include <iostream>
#include <string>

using namespace std;


class AccountNumber
{
public:
    AccountNumber(istream& inputStream)
    {
        std::getline(inputStream,FirstLine);
        std::getline(inputStream,SecondLine);
        std::getline(inputStream,ThirdLine);
        std::getline(inputStream,FourthLine);
    }

    string value() const
    {
        if (SecondLine == "                          |")
        {
            return "1";
        }
        else
        {
            return "2";
        }
    }

    string FirstLine;
    string SecondLine;
    string ThirdLine;
    string FourthLine;
};

#endif // ACCOUNTNUMBER_H
