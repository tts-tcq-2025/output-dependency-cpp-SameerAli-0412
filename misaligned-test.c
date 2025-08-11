#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <functional>

std::vector<std::tuple<int, std::string, std::string>> generateColorMap();
std::string formatColorMapEntry(int index, const std::string& major, const std::string& minor);
int printColorMap(const std::function<void(const std::string&)>& outputFunc);

class OutputCapture {
public:
    std::vector<std::string> lines;
    void operator()(const std::string& line) {
        lines.push_back(line);
    }
};

TEST(ColorMapTest, GenerateColorMapSize) {
    auto colorMap = generateColorMap();
    EXPECT_EQ(colorMap.size(), 25);
}

TEST(ColorMapTest, FormatColorMapEntry) {
    std::string formatted = formatColorMapEntry(0, "White", "Blue");
    EXPECT_EQ(formatted, "0 | White | Blue");
}

TEST(ColorMapTest, PrintColorMapOutput) {
    OutputCapture capture;
    int count = printColorMap([&capture](const std::string& line) { capture(line); });
    EXPECT_EQ(count, 25);
    EXPECT_EQ(capture.lines.size(), 25);
    EXPECT_EQ(capture.lines[0], "0 | White | Blue");
    EXPECT_EQ(capture.lines[24], "24 | Violet | Slate");
}
