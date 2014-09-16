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
                                          "  |\n"
                                          "\n");


    EXPECT_THAT(TheBankOcr.read(fileWithAccountNineOnly), Eq("9"));
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
    istringstream fileWithOneAccount("                           \n"
                                     "  |  |  |  |  |  |  |  |  |\n"
                                     "  |  |  |  |  |  |  |  |  |\n"
                                     "\n");
    EXPECT_THAT(TheBankOcr.read(fileWithOneAccount), Eq("111111111"));
}
