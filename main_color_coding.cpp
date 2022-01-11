#include <iostream>
#include <assert.h>
#include "color_coding_pair.h"

void testNumberToPair(int pairNumber,
                      TelCoColorCoder::MajorColor expectedMajorColor,
                      TelCoColorCoder::MinorColor expectedMinorColor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajorColor() == expectedMajorColor);
    assert(colorPair.getMinorColor() == expectedMinorColor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor majorColor,
    TelCoColorCoder::MinorColor minorColor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(majorColor, minorColor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void testCodingPairManual()
{
    TelCoColorCoder::DisplayColorCodingPairManual();
}

int main()
{
    testNumberToPair(1, TelCoColorCoder::WHITE, TelCoColorCoder::BLUE);
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);
    testNumberToPair(6, TelCoColorCoder::RED, TelCoColorCoder::BLUE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    testCodingPairManual();

    return 0;
}
