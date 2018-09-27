#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("ERROR: You need one argument.\n");
    // this is how you abort a program
    return 1;
  }

  int i = 0;
  for (i = 0; argv[1][i] != '\0'; i++) {
    char letter = argv[1][i];

    if (letter <= 90 && letter >= 32) {
      letter = letter + 32;
    }

    switch (letter) {
      case 'a':
        printf("%d: %c\n", i, letter);
        break;

      case 'e':
        printf("%d: %c\n", i, letter);
        break;

      case 'i':
        printf("%d: %c\n", i, letter);
        break;

      case 'o':
        printf("%d: %c\n", i, letter);
        break;

      case 'u':
        printf("%d: %c\n", i, letter);
        break;

      case 'y':
        if (i > 0) {
          printf("%d: %c\n", i, letter);
          break;
        }

      default:
        printf("%d: %c is not a vowel\n", i, letter);
    }
  }

  return 0;
}
