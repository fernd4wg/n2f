#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#define STR_LEN 50
#define LETTER 0
#define FLATSHARP 1
#define BASE_FREQ 440.000 // A4
#define BASE_NUM 4

int main(int argc, char *argv[])
{
  if (argc == 2) {
    // char argv[1][STR_LEN];
    // fgets(argv[1], STR_LEN, stdin);
    int len = strlen(argv[1]);
    float ratio = 1.0/12.0;
    float distance;

    char noteLetter = argv[1][LETTER];
    int noteNum = argv[1][len - 1] - '0';

    float octDiff = pow(2, -(4 - noteNum)) * BASE_FREQ;
    float freq;

    printf("Note: %c\n", noteLetter);
    printf("Octave: %d\n", noteNum);

    if (noteLetter) {
      if (len == 3) { 
        distance = noteLetter - 'A';
        freq = octDiff * pow(2, ratio * distance);
        printf("%.3f Hz", freq);
        return 0;
        }
      // distance error = For C & D & E: 13 ??? For F & G: 14
      distance = noteLetter - 'A';
      // printf("Note Difference: %.3f\n", distance);
      if (1 < distance && distance <= 4) {
        distance = distance + distance - 13; // 12 for the overlap in octave and the transition between B to C
        freq = octDiff * pow(2, (ratio * distance));
        printf("%.3f Hz", freq);
      }
      else if (5 <= distance && distance <= 6) {
        distance = distance + distance - 14; // 12 for the overlap in octave and the transition between B to C and E to F
        freq = octDiff * pow(2, (ratio * distance));
        printf("%.3f Hz", freq);
      }
      else {
        distance = distance + distance;
        freq = octDiff * pow(2, (ratio * distance));
        printf("%.3f Hz", freq);
      }
    }

    return 0;
    }
  else { 
      printf("You must only enter one note (for now...)>:DDDD");
    return 1;
  }
}
