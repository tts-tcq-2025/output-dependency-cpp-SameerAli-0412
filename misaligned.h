#ifndef COLOR_MAP_H
#define COLOR_MAP_H

#define MAJOR_COLORS 5
#define MINOR_COLORS 5

extern const char* majorColor[MAJOR_COLORS];
extern const char* minorColor[MINOR_COLORS];

struct ColorPair {
    int index;
    const char* major;
    const char* minor;
};

// Prints the color map using the provided output function.
// Returns the number of color pairs printed.
int printColorMap(void (*outputFunc)(const char*));

#endif // COLOR_MAP_H
