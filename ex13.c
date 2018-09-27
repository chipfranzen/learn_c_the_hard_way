#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;
  float a = 0;
  float b = 0;
  float c = 0;

  // go through each string in argv
  // first is skipped as its the execution command
  for (i = 1; i < argc; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }

  char *states[] = {
    "California",
    "Oregon",
    "Washington",
    "Texas"
  };

  int num_states = sizeof(states) / sizeof(states[0]);
  printf("There are %d states.\n", num_states);

  for (i = 0; i < num_states; i++) {
    printf("state %d: %s\n", i, states[i]);
  }

  for (a = 1, b = 1, c = 12; a + b < c; a = a + 1, b = b * 1.2, c = c * 1.1) {
    printf("%.0f, %.2f, %.2f\n", a, b, c);
  }
  return 0;
}
