#include <stdio.h>

int main() {

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
  /*Alternativo*/
  int list_size = sizeof(unicodes) / sizeof(unicodes[0]);
  for (int i = 0; i < list_size; i++) {
    printf("%c", (char)unicodes[i]);
  }
  printf("\n");
    unsigned char msg[] = {0b1010101, 0b0101110, 0b0100000,
                           0b1001101, 0b1101001, 0b1101110,
                           0b1101000, 0b1101111, '\0'};
  printf("Mensagem: %s\n", msg);
}

#include <stdio.h>
#include "definicoes.h"

void print_report_line(char* ex, char* desc, double value, char* unit) {
    printf("%-7s | %-35s | %10.2f %-s\n", ex, desc, value, unit);
}

int main() {
    printf("================ REPORT DE EXERCICIOS (CAP. 2) ================\n");
    printf("%-7s | %-35s | %-15s\n", "EX", "DESCRICAO", "RESULTADO");
    printf("---------------------------------------------------------------\n");

    // 2.1 Romano (DLXII)
    int roman = 500 + 50 + 10 + 1 + 1;
    print_report_line("2.1", "Valor Decimal do Padrao Romano", (double)roman, "");

    // 2.2 Unicode/ASCII (U. Minho)
    int msg_raw[] = {0b1010101, 0b0101110, 0b0100000, 0b1001101, 0b1101001, 0b1101110, 0b1101000, 0b1101111};
    DataList unicode_msg = { msg_raw, sizeof(msg_raw)/sizeof(msg_raw[0]) };
    printf("2.2     | Mensagem Descodificada              | ");
    for(int i=0; i<unicode_msg.total; i++) printf("%c", (char)unicode_msg.data[i]);
    printf("\n");

    // 2.3 Tamanho de Imagem (128x128, 256 tons, RGB)
    ImageMeta img23 = {128, 128, 3, 24, 0};
    img23.size_bytes = (CALC_PIXELS(img23.width, img23.height) * img23.bpp) / BYTE;
    print_report_line("2.3", "Tamanho Imagem 128x128 (Bytes)", (double)img23.size_bytes, "B");

    // 2.4 Resolucao por Canal
    float bpc24 = CALC_BITS_CH(192, CALC_PIXELS(256, 512), 3);
    print_report_line("2.4", "Bits por Canal (192 KiB)", (double)bpc24, "bits");

    // 2.6(a) Imagem 1024x512, 6 bpp
    long long size26a = (CALC_PIXELS(1024, 512) * 6) / BYTE;
    print_report_line("2.6a", "Tamanho Imagem 1024x512", (double)size26a / KiB, "KiB");

    // 2.7 Sistema de Futebol
    long long combinacoes = (128 - 2) * (128 - 2) * (128 - 2);
    print_report_line("2.7", "Combinacoes Validas (126^3)", (double)combinacoes, "");

    // 2.8 Ficheiro de Som (2 min, 50kHz, 8 bits)
    SoundMeta snd28 = {50000, 8, 120};
    long long sound_bytes = (long long)(snd28.rate_hz * snd28.duration_sec * snd28.resolution_bits) / BYTE;
    print_report_line("2.8", "Tamanho Som (SI)", (double)sound_bytes / kB_SI, "kB");
    print_report_line("", "Tamanho Som (Binary)", (double)sound_bytes / KiB, "KiB");

    // 2.9 Resolucao de Amostragem
    // 4.5 kB_SI em 1 min a 50Hz
    long long total_bits29 = 4.5 * kB_SI * BYTE;
    long long total_samples29 = 50 * 60;
    print_report_line("2.9", "Resolucao de Amostragem", (double)total_bits29 / total_samples29, "bits");

    // 2.10 Biblioteca de Jornais
    // 3700 char * 32 pag * 2 bytes + 50 fotos * 1.2 MiB
    double daily_bytes = (3700 * 32 * 2) + (50 * 1.2 * MiB);
    double library_total = daily_bytes * 365 * 50 * 1250;
    print_report_line("2.10a", "Edicao Diaria", daily_bytes, "B");
    print_report_line("2.10b", "Arquivo Anual", (daily_bytes * 365) / MiB, "MiB");
    print_report_line("2.10c", "Total Biblioteca (50 anos)", library_total / PiB, "PiB");

    printf("---------------------------------------------------------------\n");
    return 0;
}