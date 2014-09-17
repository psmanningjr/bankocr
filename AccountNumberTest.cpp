#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <iostream>
#include <sstream>

#include "AccountNumber.h"

using namespace testing;

class AccountNumberTest : public Test
{
    const string DIGIT_ONE_LINES = ("   \n"
                                    "  |\n"
                                    "  |\n"
                                    "\n");
    const string DIGIT_TWO_LINES = (" _ \n"
                                    " _|\n"
                                    "|_ \n"
                                    "\n");
    const string DIGIT_NINE_LINES = (" _ \n"
                                     "|_|\n"
                                     " _| \n"
                                     "\n");
public:
    AccountNumberTest()
     : AccountNumberOne(DIGIT_ONE_LINES)
     , AccountNumberTwo(DIGIT_TWO_LINES)
     , AccountNumberNine(DIGIT_NINE_LINES)
     , TwoAccountNumbers(DIGIT_ONE_LINES+DIGIT_NINE_LINES)
     , EmptyAccountFile("")
    {
    }

    istringstream AccountNumberOne;
    istringstream AccountNumberTwo;
    istringstream AccountNumberNine;
    istringstream TwoAccountNumbers;
    istringstream EmptyAccountFile;
};

TEST_F(AccountNumberTest, DISABLED_GivenAfileWithOneDigitAccountNumberThenItReadsFourLinesCorrectly)
{
    AccountNumber TheAccountNumber(AccountNumberOne);


    EXPECT_THAT(TheAccountNumber.FirstLine,  Eq("   "));
    EXPECT_THAT(TheAccountNumber.SecondLine, Eq("  |"));
    EXPECT_THAT(TheAccountNumber.ThirdLine,  Eq("  |"));
    EXPECT_THAT(TheAccountNumber.FourthLine, Eq(""));

    AccountNumber TheAccountNumber2 = (AccountNumberTwo);


    EXPECT_THAT(TheAccountNumber2.FirstLine,  Eq(" _ "));
    EXPECT_THAT(TheAccountNumber2.SecondLine, Eq(" _|"));
    EXPECT_THAT(TheAccountNumber2.ThirdLine,  Eq("|_ "));
    EXPECT_THAT(TheAccountNumber2.FourthLine, Eq(""));
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

TEST_F(AccountNumberTest, GivenAfileWithTwoOneDigitAccountNumbersOnePerLineThenItReturnsOneAccountNumberPerLine)
{
    AccountNumber TheAccountNumberList(TwoAccountNumbers);
    EXPECT_THAT(TheAccountNumberList.value(), StrEq("1\n9"));
}

TEST_F(AccountNumberTest, GivenAfileWithNoLinesThenAnEmptyLineIsReturned)
{
    AccountNumber TheEmptyAccountList(EmptyAccountFile);
    EXPECT_THAT(TheEmptyAccountList.value(), StrEq(""));
}

