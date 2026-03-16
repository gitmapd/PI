#include <math.h>
#include <stdio.h>

float F1_logic(unsigned char bits) {
 // --- F1 Logic (1s, 4e, 3f) ---

 /* F1 System (1-4-3):
   Sign:     (bits & 0x80) >> 7  --> Bit 7
   Exponent: (bits & 0x78) >> 3  --> Bits 6,5,4,3 (Mask 0111 1000)
   Fraction: (bits & 0x07)       --> Bits 2,1,0   (Mask 0000 0111)
*/
  int s = (bits & 0x80) >> 7;
  int e = (bits & 0x78) >> 3; // Exponent ends at bit 3
  int f = (bits & 0x07);      // Fraction is only 3 bits

  int bias = 7;
  // double modulus = 1.0;
  double modulus;
  int actual_exp;

  if (e == 0) {
    modulus = 0.0;
    actual_exp = -bias + 1;
  } else if (e == 15) {
    if (f == 0) {
      printf("It's %s Infinity\n", s ? "Negative" : "Positive");
    } else {
      printf("It's NaN (Not a Number)\n");
    }
    return 0;
  } else {
    modulus = 1.0;
    actual_exp = e - bias;
  }
  printf("F1 System (1-4-3):\n");
  printf("Sign: %d, Exp: %d, Frac: %d\n", s, e, f);

  // Fractional powers for 3 bits: 2^-1, 2^-2, 2^-3
  for (int i = 1; i <= 3; i++) {
    if ((f >> (3 - i)) & 1) {
      modulus += pow(2, -i);
    }
  }

  double val = pow(-1, s) * modulus * pow(2, actual_exp);
  printf("Value: %f\n", val);
}


float F2_logic(unsigned char bits) {
 // --- F1 Logic (1s, 3e, 4f) ---

 // Mask: 0x80 (Binary: 1000 0000)
 // Goal: Keep only the 7th bit, erase all others.
 // Shift: >> 7 (Move that bit 7 positions to the right so it becomes 0 or 1).
  int s = (bits & 0x80) >> 7; // 

  // Mask: 0x70 (Binary: 0111 0000)
// Goal: Keep only the three bits in the middle.
// Shift: >> 4 (Move those bits 4 positions right so 'Bit 4' lands at 'Bit 0').
// Example: If bits are 0101 0000, masking gives 0101 0000. 
// Shifting >> 4 turns 0101 (binary) into 5 (decimal).
  int e = (bits & 0x70) >> 4; // Exponent ends at bit 4 (Bits 6, 5, 4).

  // Mask: 0x0F (Binary: 0000 1111)
// Goal: Keep the last 4 bits.
// Shift: Not needed (>> 0), because the bits are already at the far right.
// Example: If bits are 0000 1100, f becomes 12 (decimal).
  int f = (bits & 0x0F);      // Fraction is only 4 bits (Bits 3, 2, 1, 0).

  int bias = 3;
  // double modulus = 1.0;
  double modulus;
  int actual_exp;

  if (e == 0) {
    modulus = 0.0;
    actual_exp = -bias + 1;
  } else if (e == 7) {
    if (f == 0) {
      printf("It's %s Infinity\n", s ? "Negative" : "Positive");
    } else {
      printf("It's NaN (Not a Number)\n");
    }
  } else {
    modulus = 1.0;
    actual_exp = e - bias;
  }
  printf("F1 System (1-3-4):\n");
  printf("Sign: %d, Exp: %d, Frac: %d\n", s, e, f);

  // Fractional powers for 4 bits: 2^-1, 2^-2, 2^-3
  // The Scanner: f >> (4 - i)
// When i=1: (f >> 3) & 1  --> Inspects the 1st fraction bit (Most Significant)
// When i=2: (f >> 2) & 1  --> Inspects the 2nd fraction bit
// When i=3: (f >> 1) & 1  --> Inspects the 3rd fraction bit
// When i=4: (f >> 0) & 1  --> Inspects the 4th fraction bit (Least Significant)
  for (int i = 1; i <= 4; i++) {
    if ((f >> (4 - i)) & 1) {
      modulus += pow(2, -i);
    }
  }

  double val = pow(-1, s) * modulus * pow(2, actual_exp);
  printf("Value: %f\n", val);
}
int main() {
  unsigned char bits = 0x0F; // 0000 1111

 float a = F2_logic(bits);

 printf("%f",a);

  return 0;
}