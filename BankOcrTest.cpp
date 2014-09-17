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

TEST(BankOcrTest, GivenAFileWithOneAccountNumberThenItReturnsAccountNumber)
{
    BankOcr TheBankOcr;
    istringstream fileWithAccountOneOnly("   \n"
                                         "  |\n"
                                         "  |\n"
                                         "\n");


    EXPECT_THAT(TheBankOcr.read(fileWithAccountOneOnly), Eq("1"));
    istringstream fileWithAccountTwoOnly(" _ \n"
                                         " _|\n"
                                         "|_ \n"
                                         "\n");


    EXPECT_THAT(TheBankOcr.read(fileWithAccountTwoOnly), Eq("2"));

    istringstream fileWithAccountNineOnly(" _ \n"
                                          "|_|\n"
                                          " _|\n"
                                          "\n");


    EXPECT_THAT(TheBankOcr.read(fileWithAccountNineOnly), Eq("9"));

    istringstream fileWithAccountEightOnly(" _ \n"
                                           "|_|\n"
                                           "|_|\n"
                                           "\n");


    EXPECT_THAT(TheBankOcr.read(fileWithAccountEightOnly), Eq("8"));
}

TEST(BankOcrTest, GivenAFileWithTwoDigitAccountNumberThenItReturnsAccountNumber)
{
    BankOcr TheBankOcr;
    istringstream fileWithAccountOneOnly("      \n"
                                         "  |  |\n"
                                         "  |  |\n"
                                         "\n");


    EXPECT_THAT(TheBankOcr.read(fileWithAccountOneOnly), Eq("11"));
}

TEST(BankOcrTest, GivenAFileWithNineDigitAccountNumberThenItReturnsAccountNumber)
{
    BankOcr TheBankOcr;
    istringstream fileWithAllOnes("                         _ \n"
                                  "  |  |  |  |  |  |  |  || |\n"
                                  "  |  |  |  |  |  |  |  ||_|\n"
                                  "\n");
    EXPECT_THAT(TheBankOcr.read(fileWithAllOnes), Eq("111111110"));

    istringstream fileWithOneAccount("    _  _     _  _  _  _  _ \n"
                                     "  | _| _||_||_ |_   ||_||_|\n"
                                     "  ||_  _|  | _||_|  ||_| _|\n"
                                     "\n");
    EXPECT_THAT(TheBankOcr.read(fileWithOneAccount), Eq("123456789"));
}

TEST(BankOcrTest, GivenAFileWithTwoNineDigitAccountNumbersThenItReturnsBothAccountNumbers)
{
    BankOcr TheBankOcr;
    istringstream fileWithTwoAccountNums("                         _ \n"
                                         "  |  |  |  |  |  |  |  || |\n"
                                         "  |  |  |  |  |  |  |  ||_|\n"
                                         "\n"
                                         "    _  _     _  _  _  _  _ \n"
                                         "  | _| _||_||_ |_   ||_||_|\n"
                                         "  ||_  _|  | _||_|  ||_| _|\n"
                                         "\n");
    EXPECT_THAT(TheBankOcr.read(fileWithTwoAccountNums), Eq("111111110\n123456789"));
    istringstream fileWithFourAccountNums("    _                    _ \n"
                                          "  |  |  |  |  |  |  |  || |\n"
                                          "  |  |  |  |  |  |  |  ||_|\n"
                                          "\n"
                                          "    _  _     _  _  _  _  _ \n"
                                          "  | _| _||_||_ |_|  ||_||_|\n"
                                          "  ||_  _|  | _||_|  ||_| _|\n"
                                          "\n"
                                          "    _  _     _  _  _  _  _ \n"
                                          "  | _| _||_||_ |_   ||_||_|\n"
                                          "  | _| _|  | _||_|  ||_| _|\n"
                                          "\n"
                                          "                         _ \n"
                                          "|_|  |  |  |  |  |  |  || |\n"
                                          "  |  |  |  |  |  |  |  ||_|\n"
                                          "\n");
    EXPECT_THAT(TheBankOcr.read(fileWithFourAccountNums), Eq("171111110\n123458789\n133456789\n411111110"));
}


