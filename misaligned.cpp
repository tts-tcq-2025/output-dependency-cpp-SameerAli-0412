#include <stdio.h>
#include <string.h>
#include <assert.h>

const char* majorColor[MAJOR_COLORS] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[MINOR_COLORS] = {"Blue", "Orange", "Green", "Brown", "Slate"};

typedef struct {
    int index;
    const char* major;
    const char* minor;
} ColorMapEntry;

void generateColorMap(ColorMapEntry colorMap[]) {
    int idx = 0;
    for (int i = 0; i < MAJOR_COLORS; i++) {
        for (int j = 0; j < MINOR_COLORS; j++) {
            colorMap[idx].index = i * MINOR_COLORS + j;
            colorMap[idx].major = majorColor[i];
            colorMap[idx].minor = minorColor[i];
            idx++;
        }
    }
}

void formatColorMapEntry(char* buffer, int index, const char* major, const char* minor) {
    sprintf(buffer, "%d | %s | %s", index, major, minor);
}

void printOnConsole(const char* lineContent) {
    printf("%s\n", lineContent);
}

int printColorMap(void (*outputFunc)(const char*)) {
    ColorMapEntry colorMap[COLOR_MAP_SIZE];
    char line[MAX_LINE_LEN];
    generateColorMap(colorMap);
    for (int i = 0; i < COLOR_MAP_SIZE; i++) {
        formatColorMapEntry(line, colorMap[i].index, colorMap[i].major, colorMap[i].minor);
        outputFunc(line);
    }
    return COLOR_MAP_SIZE;
}

int main() {
    testPrintColorMap();
    return 0;
}
