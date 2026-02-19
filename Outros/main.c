#include "definicoes.h"
#include <stdio.h>

void print_bin(int n, int num_bits) {
  for (int i = num_bits - 1; i >= 0; i--) {
    int bit = (n >> i) & 1;
    printf("%d", bit);
  }
}
void print_report_line(char *ex, char *desc, double value, char *unit) {
  printf("%-7s | %-35s | %10.2f %-s\n", ex, desc, value, unit);
}
/*Alternativo
  int unicodes[] = {
     0b1010101, // U
     0b0101110, // .
     0b0100000, // espaço
     0b1001101, // M
     0b1101001, // i
     0b1101110, // n
     0b1101000, // h
     0b1101111  // o
 };
   int list_size = sizeof(unicodes) / sizeof(unicodes[0]);
 for (int i = 0; i < list_size; i++) {
   printf("%c", (char)unicodes[i]);
 }
 printf("\n");
 unsigned char msg[] = {0b1010101, 0b0101110, 0b0100000, 0b1001101, 0b1101001,
                        0b1101110, 0b1101000, 0b1101111, '\0'};
 printf("Mensagem: %s\n", msg);
 */
int main() {
  printf("================ REPORT DE EXERCICIOS (CAP. 2) ================\n");
  printf("%-7s | %-35s | %-20s\n", "EX", "DESCRICAO", "RESULTADO");
  printf("---------------------------------------------------------------\n");

  // 2.1 - Romano (DLXII)
  int roman = 500 + 50 + 10 + 1 + 1;
  print_report_line("2.1", "Valor Decimal Romano", (double)roman, "");

  // 2.2 - Unicode (U. Minho)
  int msg_raw[] = {0b1010101, 0b0101110, 0b0100000, 0b1001101,
                   0b1101001, 0b1101110, 0b1101000, 0b1101111};
  DataList unicode_msg = {msg_raw, 8};
  printf("2.2     | Mensagem Descodificada              | ");
  for (int i = 0; i < unicode_msg.total; i++)
    printf("%c", (char)unicode_msg.data[i]);
  printf("\n");

  // 2.3 - Imagem (128x128, RGB, 24 bpp)
  ImageMeta img23 = {128, 128, 3, 24, 0};
  img23.size_bytes =
      (CALC_PIXELS(img23.width, img23.height) * img23.bpp) / BYTE;
  print_report_line("2.3", "Tamanho Imagem 128x128", (double)img23.size_bytes,
                    "B");

  // 2.4 - Resolucao por Canal
  float bpc24 = CALC_BITS_CH(192, CALC_PIXELS(256, 512), 3);
  int max_val24 = (1 << (int)bpc24) - 1;
  // printf("%d",max_val24);print_bin(max_val24,4);
  // print_report_line("Resolucao Maxima Canal", max_val24);
  // print_report_line("2.4", "Bits por Canal (192 KiB)", (double)bpc24,
  // "bits");
  printf("%-7s | %-35s | %d_10 (", "2.4", "Resolucao Maxima Canal", max_val24);

  // 2. Imprime o binário 1111 primeiro
  print_bin(max_val24, (int)bpc24);

  // 3. Imprime o sufixo da base e a contagem de bits no fim
  printf("_2) | %.0f bits\n", bpc24);

  // 2.5 - Sistema CMYK (6 bits, 4 canais, proibidos 0 e 1)
  long long estados_canal = (1LL << 6) - 2; // 64 - 2 = 62
  long long total_cmyk =
      estados_canal * estados_canal * estados_canal * estados_canal;
  // print_report_line("2.5", "Cores CMYK (6-bit)", (double)total_cmyk,
  // "cores");
  printf("%-7s | %-35s | %lld^4 = %.0f = %.1e\n", "2.5", "Cores CMYK (6-bit)",
         estados_canal, (double)total_cmyk, (double)total_cmyk);

  // 2.6 - Imagem 1024x512, 6 bpp
  // long long size26 = (CALC_PIXELS(1024, 512) * 6) / BYTE;
  // print_report_line("2.6", "Tamanho Imagem 1024x512", (double)size26 / KiB,
  //                 "KiB");
  // 2.6 - Sistema Futebol (7 bits, proibidos 0 e 127)

  long long estados_fut = (1LL << 7) - 2; // 128 - 2 = 126
  long long comb27 = estados_fut * estados_fut * estados_fut;
  printf("%-7s | %-35s | %lld^3 = %.0f = %.1e\n", "2.6", "Combinacoes Futebol",
         estados_fut, (double)comb27, (double)comb27);

  // 2.7 - Som Digital (2 min, 50kHz, 8 bits) Cálculo do total de bits: freq *
  // duracao * resolucao
  SoundMeta snd27 = {50000.0f, 8, 120};

  // Cálculo do total de bits: freq * duracao * resolucao
  long long total_bits27 =
      (long long)(snd27.rate_hz * snd27.duration_sec * snd27.resolution_bits);
  double sound_bytes27 = (double)total_bits27 / BYTE;

  printf("%-7s | %-35s | %.f kB\n", "2.7", "Tamanho Som (SI)",sound_bytes27 / MB_SI);
  printf("%-7s | %-35s | %f KiB\n", "2.7", "Tamanho Som (Binary)",sound_bytes27 / MiB);


  // Dados: 4.5 kB (SI), 60s, 50 Hz. Queremos descobrir resolution_bits.
  SoundMeta snd28;
  snd28.rate_hz = 50.0f;
  snd28.duration_sec = 60;
  double file_size_bytes28 = 4.5 * kB_SI; // 4500 Bytes

  // Resolucao = Bits totais / (Freq * Tempo)
  snd28.resolution_bits =
      (int)((file_size_bytes28 * BYTE) / (snd28.rate_hz * snd28.duration_sec));

  printf("%-7s | %-35s | %.f bits\n", "2.8", "Resolucao de Amostragem",(double)snd28.resolution_bits);

  // 2.9a - Biblioteca (Edicao Diaria)
  double texto = 32LL * 3700 * 2; // UTF-16
  double fotos = (long long)50 * 1.2 * MiB;
  double daily_bytes = texto + fotos;
  printf("%-7s | %-35s | %lld B\n", "2.9 (a)", "Volume Diario",
         (long long)daily_bytes);

  // 2.9b - Arquivo Anual
  double anual_bytes = daily_bytes * 365;
  // print_report_line("2.9b", "Arquivo Anual (1 jornal)", (long) anual_bytes /
  // MiB,
  //         "MiB");
  printf("%-7s | %-35s | %.0f %-s\n", "2.9 (b)", "Arquivo Anual (1 jornal)",
         anual_bytes / MiB, "MiB");
  // 2.9c - Total Biblioteca (50 anos, 1250 jornais)
  double total_biblioteca = anual_bytes * 50 * 1250;
  print_report_line("2.9 (c)", "Total Biblioteca", total_biblioteca / PiB, "PiB");

  printf("---------------------------------------------------------------\n");
  return 0;
}