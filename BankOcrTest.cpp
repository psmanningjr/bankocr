#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <iostream>
#include <sstream>

#include "AccountNumber.h"
#include "BankOcr.h"

using namespace testing;

class BankOcrTest : public Test
{

};

class AccountNumberTest : public Test
{
public:
    AccountNumberTest()
     : AccountNumberOne("                           \n"
                        "                          |\n"
                        "                          |\n"
                        "\n")
     , AccountNumberTwo("                        _ \n"
                        "                        _|\n"
                        "                       |_ \n"
                        "\n")


    {

    }
    istringstream AccountNumberOne;
    istringstream AccountNumberTwo;
};

TEST_F(AccountNumberTest, GivenAfileWithOneDigitAccountNumberThenItReadsFourLinesCorrectly)
{
    AccountNumber TheAccountNumber(AccountNumberOne);


    EXPECT_THAT(TheAccountNumber.FirstLine,  Eq("                           "));
    EXPECT_THAT(TheAccountNumber.SecondLine, Eq("                          |"));
    EXPECT_THAT(TheAccountNumber.ThirdLine,  Eq("                          |"));
    EXPECT_THAT(TheAccountNumber.FourthLine, Eq(""));

    AccountNumber TheAccountNumber2(AccountNumberTwo);


    EXPECT_THAT(TheAccountNumber2.FirstLine,  Eq("                        _ "));
    EXPECT_THAT(TheAccountNumber2.SecondLine, Eq("                        _|"));
    EXPECT_THAT(TheAccountNumber2.ThirdLine,  Eq("                       |_ "));
    EXPECT_THAT(TheAccountNumber2.FourthLine, Eq(""));
}

TEST_F(AccountNumberTest, GivenAfileWithOneDigitAccountNumberThenItInterpretsItIntoCorrectNumber)
{
    AccountNumber TheAccountNumberOne(AccountNumberOne);

    EXPECT_THAT(TheAccountNumberOne.value(), StrEq("1"));

    AccountNumber TheAccountNumberTwo(AccountNumberTwo);
    EXPECT_THAT(TheAccountNumberTwo.value(), StrEq("2"));

}

TEST(BankOcrTest, GivenAFileWithOneAccountNumberThenItReturnsAccountNumber)
{
    BankOcr TheBankOcr;
    istringstream memoryFile("                           \n"
                             "                          |\n"
                             "                          |\n"
                             "\n");


    EXPECT_THAT(TheBankOcr.read(memoryFile), Eq("1"));
    istringstream memoryFile2("                        _ \n"
                              "                        _|\n"
                              "                       |_ \n"
                              "\n");


    EXPECT_THAT(TheBankOcr.read(memoryFile2), Eq("2"));
}
