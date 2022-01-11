#include <iostream>

namespace TelCoColorCoder
{
    enum MajorColor
    {
        WHITE,
        RED,
        BLACK,
        YELLOW,
        VIOLET
    };
    enum MinorColor
    {
        BLUE,
        ORANGE,
        GREEN,
        BROWN,
        SLATE
    };

    class ColorPair
    {
    private:
        MajorColor majorColor;
        MinorColor minorColor;

    public:
        ColorPair(MajorColor major, MinorColor minor);
        ~ColorPair();
        MajorColor getMajorColor()
        {
            return majorColor;
        }
        MinorColor getMinorColor()
        {
            return minorColor;
        }
        std::string ToString();
    };
    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor majorColor, MinorColor minorColor);
    void DisplayColorCodingPairManual();
}
