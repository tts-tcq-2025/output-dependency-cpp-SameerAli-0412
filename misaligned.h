#include <stdio.h>

#define MAJOR_COLORS 5
#define MINOR_COLORS 5
#define COLOR_MAP_SIZE (MAJOR_COLORS * MINOR_COLORS)
#define MAX_LINE_LEN 50

extern const char* majorColor[MAJOR_COLORS];
extern const char* minorColor[MINOR_COLORS];

typedef struct {
    int index;
    const char* major;
    const char* minor;
} ColorMapEntry;

void generateColorMap(ColorMapEntry colorMap[]);
void formatColorMapEntry(char* buffer, int index, const char* major, const char* minor);
void printOnConsole(const char* lineContent);
int printColorMap(void (*outputFunc)(const char*));
