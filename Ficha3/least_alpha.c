#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  int counts[26] = {0}; 
  int total_counts = 26;
  int min_freq = INT_MAX;
  int least_frequent = -1; // Start at -1 to represent "None"

  printf("Enter text: ");
  if (fgets(input, sizeof(input), stdin)) {
    // FIX 1: Initialize i to 0
    for (int i = 0; input[i] != '\0'; i++) {
      if (isalpha(input[i])) {
        char c = tolower(input[i]);
        int alpha = c - 'a';
        counts[alpha]++;
      }
    }

    for (int i = 0; i < total_counts; i++) {
      // Safety Filter: Only check letters that appeared at least once
      if (counts[i] > 0 && counts[i] < min_freq) {
        min_freq = counts[i];
        least_frequent = i;
      }
    }

    if (least_frequent != -1) {
      // FIX 2: Convert index back to letter using + 'a'
      printf("Least frequent letter: '%c' (appeared %d times)\n", 
             least_frequent + 'a', min_freq);
    } else {
      printf("No letters found in the input.\n");
    }
  }
  return 0;
}