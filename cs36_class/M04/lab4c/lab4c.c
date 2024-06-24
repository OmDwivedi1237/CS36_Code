#include <stdio.h>
#include <string.h>

int main() {
  char source[] = "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness...";
  char input[80];
  char *searchPtr;

  printf("Original text:\n%s\n\n", source);

  printf("Enter a search string: ");
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';

  printf("\nSearching for \"%s\" in the text:\n", input);

  searchPtr = strstr(source, input);
  int count = 0;

  while (searchPtr != NULL) {
    count++;
    printf("Occurrence %d: %s\n", count, searchPtr);
    searchPtr = strstr(searchPtr + 1, input);
  }

  if (count == 0) {
    printf("The search string was not found in the text.\n");
  } else {
    printf("\n\nTotal occurrences found: %d\n", count);
  }

  return 0;
}
