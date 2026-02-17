#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definicoes.h"

int main() {
  unsigned long long total_pixels = CALC_PIXELS(IMG23_WIDTH, IMG23_HEIGHT);

  unsigned long long bytes_por_pixel = (BITS_PER_CHANNEL / 8) * CHANNELS;

  unsigned long long tamanho_total_bytes = total_pixels * bytes_por_pixel;

  printf("Tamanho da imagem: %llu Bytes\n", tamanho_total_bytes);
}