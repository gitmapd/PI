#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  int digits[10] = {0};
  int total_counts = 26;
  int max_freq = INT_MIN;
  int min_freq = INT_MAX;
  int least_frequent = -1;
  int most_frequent = -1; // Start at -1 to represent "None"

  printf("Please enter digits: ");
  if (fgets(input, sizeof(input), stdin)) {
    for (int i = 0; input[i] != '\0'; i++) {
      if (isdigit(input[i])) {
        int digit = input[i] - '0';
        digits[digit]++;
      }
    }
    for (int i = 0; i < sizeof(digits) / sizeof(digits[0]); i++) {
      if (digits[i] > max_freq) {
        max_freq = digits[i];
        most_frequent = i;
      }
    }
    for (int i = 0; i < sizeof(digits) / sizeof(digits[0]); i++) {
      if (digits[i] > 0 && digits[i] < min_freq) {
        min_freq = digits[i];
        least_frequent = i;
      }
    }

    if (most_frequent != -1) {
      // FIX 2: Convert index back to letter using + 'a'
      printf("Most frequent digit: '%d' (appeared %d times)\n", most_frequent,
             max_freq);

      printf("Least frequent digit: '%d' (appeared %d times)\n", least_frequent,
             min_freq);
    } else {
      printf("No digits found in the input.\n");
    }
  }
  return 0;
}