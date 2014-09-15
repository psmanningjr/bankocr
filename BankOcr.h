#ifndef BANKOCR_H
#define BANKOCR_H

#include <iostream>
#include <string>

#include "AccountNumber.h"

using namespace std;

class BankOcr
{
public:
    string read(istream& inputStream) const
    {
        AccountNumber TheAccountNumber(inputStream);
        return TheAccountNumber.value();
    }
};

#endif // BANKOCR_H
