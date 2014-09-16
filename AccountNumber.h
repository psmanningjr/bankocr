#ifndef ACCOUNTNUMBER_H
#define ACCOUNTNUMBER_H

#include <iostream>
#include <string>

using namespace std;


class AccountNumber
{
    const string DIGIT_ONE_CODE = ("   "
                                   "  |"
                                   "  |");
    const string DIGIT_TWO_CODE = (" _ "
                                   " _|"
                                   "|_ ");
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
        string scannedChar = FirstLine.substr(24,3).
                append(SecondLine.substr(24,3).
                append(ThirdLine.substr(24,3)));
        if (scannedChar == DIGIT_ONE_CODE)
        {
            return "1";
        }
        else
        {
            if (scannedChar == DIGIT_TWO_CODE)
                return "2";
            else
                return "9";
        }
    }

    string FirstLine;
    string SecondLine;
    string ThirdLine;
    string FourthLine;
    string ScannedChar;
};

#endif // ACCOUNTNUMBER_H
