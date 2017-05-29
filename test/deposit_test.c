#include "deposit.h"
#include "ctest.h"

CTEST(PenaltyTest, penaltyAppliedTenPercentOK)
{
    const int result = Count(20, 1000);
    const int expected = 1000;
    ASSERT_EQUAL(expected, result);
}

CTEST(LessBlockTests, goodDataPass102)
{
    const int result = Count(60, 1000);
    const int expected = 900;
    ASSERT_EQUAL(expected, result);
}

CTEST(LessBlockTests, goodDataPass106)
{
    const int result = Count(200, 1000);
    const int expected = 918;
    ASSERT_EQUAL(expected, result);
}

CTEST(LessBlockTests, goodDataPass112)
{
    const int result = Count(300, 1000);
    const int expected = 973;
    ASSERT_EQUAL(expected, result);
}

CTEST(MoreBlockTests, goodDataPass103)
{
    const int result = Count(100, 200000);
    const int expected = 180000;
    ASSERT_EQUAL(expected, result);
}

CTEST(MoreBlockTests, goodDataPass108)
{
    const int result = Count(200, 200000);
    const int expected = 183600;
    ASSERT_EQUAL(expected, result);
}

CTEST(MoreBlockTests, goodDataPass115)
{
    const int result = Count(300, 200000);
    const int expected = 194616;
    ASSERT_EQUAL(expected, result);
}
