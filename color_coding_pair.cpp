#include <iostream>
#include <iomanip>
#include "color_coding_pair.h"

namespace TelCoColorCoder
{
    const char *MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const char *MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
    int numberOfColorCodingPairs = numberOfMajorColors * numberOfMinorColors;

    ColorPair::ColorPair(MajorColor major, MinorColor minor) : majorColor(major), minorColor(minor) {}
    ColorPair::~ColorPair() {}

    std::string ColorPair::ToString()
    {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }

    ColorPair GetColorFromPairNumber(int pairNumber)
    {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor =
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }
    int GetPairNumberFromColor(MajorColor majorColor, MinorColor minorColor)
    {
        return majorColor * numberOfMinorColors + minorColor + 1;
    }
    void DisplayColorCodingPairManual()
    {
        std::cout << "\t \t *******Color Coding Pair Manual*******" << std::endl;
        std::cout << std::endl;
        std::cout << std::setw(10) << "|" << std::setw(10) << "    Pair Number" << std::setw(5) << "|" << std::setw(10) << std::setw(10) << "     Major Color" << std::setw(4) << "|" << std::setw(10) << std::setw(10) << "    Minor Color" << std::setw(5) << "|" << std::setw(10) << std::endl;
        std::cout << std::endl;
        for (auto iterate = 1; iterate <= numberOfColorCodingPairs; iterate++)
        {
            TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(iterate);
            std::string MajorPairStr = MajorColorNames[colorPair.getMajorColor()];
            std::string MinorPairStr = MinorColorNames[colorPair.getMinorColor()];
            std::cout << "|" << std::setw(10) << iterate << std::setw(10) << "|" << std::setw(10) << std::setw(10) << MajorPairStr << std::setw(10) << "|" << std::setw(10) << std::setw(10) << MinorPairStr << std::setw(10) << "|" << std::setw(10) << std::endl;
            std::cout << std::endl;
        }
    }
}
