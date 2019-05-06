#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

int
main () {
  char buffer[MAX], *token;
  int max, count = 0;
  FILE *fp;

  printf ("Input filename:");
  fgets (buffer, MAX, stdin);
  sscanf (buffer, "%s", buffer);

  fp = fopen (buffer, "r");

  while (fgets (buffer, MAX, fp)) {
      max = 0;
      token = strtok (buffer, ",\n");
      while (token != NULL) {
          max = strlen (token) > max ? strlen (token) : max;
          printf ("(%2d) %s\n", strlen (token), token);
          count += 1;
          token = strtok (NULL, ",\n");
      }
      printf ("The longest word has %d characters.\n", max);
  }
  printf ("Total %d word.\n", count);

  return 0;
}
