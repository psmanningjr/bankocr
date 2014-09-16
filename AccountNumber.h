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

    string value()
    {
        string scannedDigits;
        decodeDigit(FirstLine, SecondLine, ThirdLine, scannedDigits);
        return scannedDigits;
    }

private:
    void decodeDigit(const string firstLine,
                     const string secondLine,
                     const string thirdLine,
                     string& scannedDigits) const
    {
        if (firstLine.length() < 3  ||
            secondLine.length() < 3 ||
            thirdLine.length() <3)
        {
            return;
        }
        string scannedChar = firstLine.substr(0,3).
                append(secondLine.substr(0,3).
                append(thirdLine.substr(0,3)));
        if (scannedChar == DIGIT_ONE_CODE)
        {
            scannedDigits += "1";
        }
        else
        {
            if (scannedChar == DIGIT_TWO_CODE)
                scannedDigits += "2";
            else
               scannedDigits += "9";
        }
        decodeDigit(firstLine.substr(3,firstLine.length()-3),
                    secondLine.substr(3, secondLine.length()-3),
                    thirdLine.substr(3, thirdLine.length()-3),
                    scannedDigits);
    }
public:
    string FirstLine;
    string SecondLine;
    string ThirdLine;
    string FourthLine;
    string ScannedChar;
};

#endif // ACCOUNTNUMBER_H
