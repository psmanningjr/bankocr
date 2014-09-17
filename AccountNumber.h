#ifndef ACCOUNTNUMBER_H
#define ACCOUNTNUMBER_H

#include <iostream>
#include <string>
#include <map>

using namespace std;


class AccountNumber
{
    const string DIGIT_ZERO_CODE  = (" _ "
                                     "| |"
                                     "|_|");
    const string DIGIT_ONE_CODE   = ("   "
                                     "  |"
                                     "  |");
    const string DIGIT_TWO_CODE   = (" _ "
                                     " _|"
                                     "|_ ");
    const string DIGIT_THREE_CODE = (" _ "
                                     " _|"
                                     " _|");
    const string DIGIT_FOUR_CODE  = ("   "
                                     "|_|"
                                     "  |");
    const string DIGIT_FIVE_CODE  = (" _ "
                                     "|_ "
                                     " _|");
    const string DIGIT_SIX_CODE   = (" _ "
                                     "|_ "
                                     "|_|");
    const string DIGIT_SEVEN_CODE = (" _ "
                                     "  |"
                                     "  |");
    const string DIGIT_EIGHT_CODE = (" _ "
                                     "|_|"
                                     "|_|");
    const string DIGIT_NINE_CODE  = (" _ "
                                     "|_|"
                                     " _|");
public:
    AccountNumber(istream& inputStream)
        : inpStream(NULL)
        , FirstLine("")
        , SecondLine("")
        , ThirdLine("")
        , FourthLine("")
    {
        inpStream = &inputStream;
        DigitMap[DIGIT_ZERO_CODE]  = "0";
        DigitMap[DIGIT_ONE_CODE]   = "1";
        DigitMap[DIGIT_TWO_CODE]   = "2";
        DigitMap[DIGIT_THREE_CODE] = "3";
        DigitMap[DIGIT_FOUR_CODE]  = "4";
        DigitMap[DIGIT_FIVE_CODE]  = "5";
        DigitMap[DIGIT_SIX_CODE]   = "6";
        DigitMap[DIGIT_SEVEN_CODE] = "7";
        DigitMap[DIGIT_EIGHT_CODE] = "8";
        DigitMap[DIGIT_NINE_CODE]  = "9";
    }

    string value()
    {
        string linesOfScannedDigits;
        bool alreadyReadAnAccountNumber = false;
        while (std::getline(*inpStream,FirstLine))
        {
            if (alreadyReadAnAccountNumber)
            {
                linesOfScannedDigits += '\n';
            }
            std::getline(*inpStream,SecondLine);
            std::getline(*inpStream,ThirdLine);
            std::getline(*inpStream,FourthLine);
            alreadyReadAnAccountNumber = true;
            decodeDigit(FirstLine, SecondLine, ThirdLine, linesOfScannedDigits);
        }
        return linesOfScannedDigits;
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
        if (DigitMap.find(scannedChar) != DigitMap.end())
        {
            scannedDigits += DigitMap.at(scannedChar);
        }
        decodeDigit(firstLine.substr(3,firstLine.length()-3),
                    secondLine.substr(3, secondLine.length()-3),
                    thirdLine.substr(3, thirdLine.length()-3),
                    scannedDigits);
    }
public:
    istream* inpStream;
    string FirstLine;
    string SecondLine;
    string ThirdLine;
    string FourthLine;
    string ScannedChar;
    map<string, string> DigitMap;
};

#endif // ACCOUNTNUMBER_H
