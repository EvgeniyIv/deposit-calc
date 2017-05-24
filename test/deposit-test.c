#include "deposit.h"
#include "ctest.h"

CTEST(PenaltyTest, penaltyAppliedTenPercentOK)
{
    const int result = Count(20, 1000);
    const int expected = 900;
    ASSERT_EQUAL(expected, result);
}

CTEST(LessBlockTests, goodDataPass102)
{
    const int result = Count(60, 1000);
    const int expected = 1020;
    ASSERT_EQUAL(expected, result);
}

CTEST(LessBlockTests, goodDataPass106)
{
    const int result = Count(200, 1000);
    const int expected = 1060;
    ASSERT_EQUAL(expected, result);
}

CTEST(LessBlockTests, goodDataPass112)
{
    const int result = Count(300, 1000);
    const int expected = 1120;
    ASSERT_EQUAL(expected, result);
}

CTEST(MoreBlockTests, goodDataPass103)
{
    const int result = Count(100, 200000);
    const int expected = 206000;
    ASSERT_EQUAL(expected, result);
}

CTEST(MoreBlockTests, goodDataPass108)
{
    const int result = Count(200, 200000);
    const int expected = 216000;
    ASSERT_EQUAL(expected, result);
}

CTEST(MoreBlockTests, goodDataPass115)
{dd
    const int result = Count(300, 200000);
    const int expected = 229999;
    ASSERT_EQUAL(expected, result);
}
