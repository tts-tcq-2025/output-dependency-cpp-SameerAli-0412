#include "misaligned.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char capturedBuffer[2048];

void mockOutputFunc(const char* lineContent) {
    strncpy(capturedBuffer, lineContent, sizeof(capturedBuffer) - 1);
    capturedBuffer[sizeof(capturedBuffer) - 1] = '\0';
}

void test_strict_color_pairs() {
    memset(capturedBuffer, 0, sizeof(capturedBuffer));
    int count = printColorMap(mockOutputFunc);

    assert(count == MAJOR_COLORS * MINOR_COLORS);

    // Parse each line and check the color pairs
    char* line = strtok(capturedBuffer, "\n");
    int idx = 0;
    while (line && idx < MAJOR_COLORS * MINOR_COLORS) {
        int parsedIndex;
        char parsedMajor[16], parsedMinor[16];
        int n = sscanf(line, "%d | %15s | %15s", &parsedIndex, parsedMajor, parsedMinor);
        assert(n == 3);

        // Expected values
        int expectedIndex = idx + 1;
        const char* expectedMajor = majorColor[idx / MINOR_COLORS];
        const char* expectedMinor = minorColor[idx % MINOR_COLORS];

        assert(parsedIndex == expectedIndex);
        assert(strcmp(parsedMajor, expectedMajor) == 0);
        assert(strcmp(parsedMinor, expectedMinor) == 0);

        line = strtok(NULL, "\n");
        idx++;
    }
    assert(idx == MAJOR_COLORS * MINOR_COLORS);

    printf("Strict color pair test passed!\n");
}

int main() {
    test_strict_color_pairs();
    return 0;
}
