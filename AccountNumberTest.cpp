#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <iostream>
#include <sstream>

#include "AccountNumber.h"

using namespace testing;

class AccountNumberTest : public Test
{
//    _  _     _  _  _  _  _
//  | _| _||_||_ |_   ||_||_|
//  ||_  _|  | _||_|  ||_| _|

    const string DIGIT_ONE_LINES = ("                           \n"
                                    "                          |\n"
                                    "                          |\n"
                                    "\n");
    const string DIGIT_TWO_LINES = ("                         _ \n"
                                    "                         _|\n"
                                    "                        |_ \n"
                                    "\n");
    const string DIGIT_NINE_LINES = ("                         _ \n"
                                     "                        |_|\n"
                                     "                          | \n"
                                     "\n");
public:
    AccountNumberTest()
     : AccountNumberOne(DIGIT_ONE_LINES)
     , AccountNumberTwo(DIGIT_TWO_LINES)
     , AccountNumberNine(DIGIT_NINE_LINES)


    {

    }
    istringstream AccountNumberOne;
    istringstream AccountNumberTwo;
    istringstream AccountNumberNine;
};

TEST_F(AccountNumberTest, GivenAfileWithOneDigitAccountNumberThenItReadsFourLinesCorrectly)
{
    AccountNumber TheAccountNumber(AccountNumberOne);


    EXPECT_THAT(TheAccountNumber.FirstLine,  Eq("                           "));
    EXPECT_THAT(TheAccountNumber.SecondLine, Eq("                          |"));
    EXPECT_THAT(TheAccountNumber.ThirdLine,  Eq("                          |"));
    EXPECT_THAT(TheAccountNumber.FourthLine, Eq(""));
//    EXPECT_THAT(TheAccountNumber.ScannedChar, Eq("     |  |"));

    AccountNumber TheAccountNumber2 = (AccountNumberTwo);


    EXPECT_THAT(TheAccountNumber2.FirstLine,  Eq("                         _ "));
    EXPECT_THAT(TheAccountNumber2.SecondLine, Eq("                         _|"));
    EXPECT_THAT(TheAccountNumber2.ThirdLine,  Eq("                        |_ "));
    EXPECT_THAT(TheAccountNumber2.FourthLine, Eq(""));
//    EXPECT_THAT(TheAccountNumber2.ScannedChar, Eq(" _  _||_ "));
}

TEST_F(AccountNumberTest, GivenAfileWithOneDigitAccountNumberThenItInterpretsItIntoCorrectNumber)
{
    AccountNumber TheAccountNumberOne(AccountNumberOne);

    EXPECT_THAT(TheAccountNumberOne.value(), StrEq("1"));

    AccountNumber TheAccountNumberTwo(AccountNumberTwo);
    EXPECT_THAT(TheAccountNumberTwo.value(), StrEq("2"));

    AccountNumber TheAccountNumberNine(AccountNumberNine);
    EXPECT_THAT(TheAccountNumberNine.value(), StrEq("9"));
}
