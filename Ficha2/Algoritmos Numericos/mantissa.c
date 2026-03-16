#include <math.h>
#include <stdio.h>

float F1_logic(unsigned char bits) {
 // --- F1 Logic (1s, 4e, 3f) ---
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
  int s = (bits & 0x80) >> 7;
  int e = (bits & 0x70) >> 4; // Exponent ends at bit 3
  int f = (bits & 0x0F);      // Fraction is only 4 bits

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