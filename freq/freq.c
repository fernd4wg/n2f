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

int main(int argc, char *argv[])
{
  char inputStr[STR_LEN];
  fgets(inputStr, STR_LEN, stdin);
  int len = strlen(inputStr) - 1;
  int stepDiff = 0;
  float ratio = 1.0/12.0;
  float distance;

  char noteLetter = inputStr[LETTER];
  int noteNum = inputStr[len - 1] - '0';

  float octDiff = pow(2, -(4 - noteNum)) * BASE_FREQ;

  printf("Note: %c\n", noteLetter);
  printf("Octave: %d\n", noteNum);

  if (noteLetter) {
    if (len == 3) { 
      distance = noteLetter - 'A';
      octDiff = octDiff * pow(2, ratio * distance);
      printf("%.3f Hz", octDiff);
      return 0;
      }

    // distance error = For C & D & E: 13 ??? For F & G: 14
      distance = noteLetter - 'A';
      distance = distance + distance;
      octDiff = octDiff * pow(2, (ratio * distance );
      printf("%.3f Hz", octDiff);
  }

  return 0;
}
