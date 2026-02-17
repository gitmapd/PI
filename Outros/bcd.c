#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int contar_bits(unsigned int n) {
  if (n == 0)
    return 1;

  int contador = 0;
  while (n > 0) {
    n = n / 2; // Dividir por 2 é o mesmo que n >>= 1
    contador++;
  }
  return contador;
}
/**
 * bin_puro - Verifica se o valor é zero.
 * @n: Número inteiro sem sinal a ser testado.
 * * Exemplo de Funcionamento:
 * - Se n = 0 (0b0000): O ciclo não executa, retorna 1.
 * - Se n = 5 (0b0101): O ciclo corre 3 vezes, retorna 0.
 * * Nota: Apesar de contar bits internamente, o retorno atual
 * funciona como um booleano (1 se for zero, 0 se não for).
 */
int bin_puro(unsigned int n) {
  if (n == 0)
    return 1;
  int count = 0;
  while (n > 0) {
    count++;
    n >>= 1;
  }
  return count;
}

/**
 * find_bits - Identifica a posição do último bloco de 4 bits (nibble) ativo.
 * @bcd: Valor em formato BCD (Binary Coded Decimal).
 * * Exemplos de Entrada/Saída:
 * - Input: 0x0005 (0000 0000 0000 0101) -> Retorna 4  (Cai no else)
 * - Input: 0x00A0 (0000 0000 1010 0000) -> Retorna 8  (Ativa a máscara 0x00F0)
 * - Input: 0x0B00 (0000 1011 0000 0000) -> Retorna 12 (Ativa a máscara 0x0F00)
 * - Input: 0x2000 (0010 0000 0000 0000) -> Retorna 16 (Ativa a máscara 0xF000)
 */
int find_bits(int bcd) {
  if (bcd == 0)
    return 4;
  int bits = 0;
  if (bcd & 0xF0000)
    bits = 20;
  else if (bcd & 0x0F000)
    bits = 16;
  else if (bcd & 0x00F00)
    bits = 12;
  else if (bcd & 0x000F0)
    bits = 8;
  else
    bits = 4;
  return bits;
}
/**
 * find_bits_mag - Determina o tamanho necessário baseado no valor.
 * * Lógica de Magnitude:
 * - Se > 4095 (0x0FFF): Ocupa obrigatoriamente 16 bits.
 * - Se > 255  (0x00FF): Ocupa pelo menos 12 bits.
 * - Se > 15   (0x000F): Ocupa pelo menos 8 bits.
 * - Caso contrário   : Ocupa os 4 bits base.
 */
int find_bits_mag(int bcd) {
  if (bcd == 0)
    return 4;
  if (bcd > 0xF000)
    return 16;
  if (bcd > 0x0F00)
    return 12;
  if (bcd & 0x00F0)
    return 8;
  return 4;
}

/**
 * dec2BCD - Converte um número decimal (0-9999) para formato BCD de 16 bits.
 * @dec: Valor decimal a converter.
 * * Exemplo de Funcionamento (dec = 1234):
 * - m = 1, c = 2, d = 3, u = 4
 * - Shift m (1 << 12): 0001 0000 0000 0000
 * - Shift c (2 << 8) : 0000 0010 0000 0000
 * - Shift d (3 << 4) : 0000 0000 0011 0000
 * - Valor u (4)      : 0000 0000 0000 0100
 * - Resultado final  : 0x1234 (BCD)
 */
uint32_t dec2BCD(int dec) {
  uint32_t sinal = (dec < 0) ? 0x0D : 0x0C;
  int val = (dec < 0) ? -dec : dec;
  uint32_t m = (val / 1000) % 10;
  uint32_t c = (val / 100) % 10;
  uint32_t d = (val / 10) % 10;
  uint32_t u = val % 10;
  return (m << 16) | (c << 12) | (d << 8) | (u << 4) | sinal;
}

/**
 * dec2BCD_ciclo - Converte decimal para BCD usando um loop.
 * * Exemplo passo a passo (dec = 123):
 * Iteração 0: digito=3, shift=0  -> bcd = 0x0003, dec = 12
 * Iteração 1: digito=2, shift=4  -> bcd = 0x0023, dec = 1
 * Iteração 2: digito=1, shift=8  -> bcd = 0x0123, dec = 0
 * Iteração 3: digito=0, shift=12 -> bcd = 0x0123, dec = 0
 */
uint32_t dec2BCD_ciclo(int dec) {
  uint32_t bcd = 0;

  // 4 dígitos (milhares, centenas, dezenas, unidades)
  for (int i = 0; i < 4; i++) {
    // 1. Isola o dígito atual (começando pela unidade)
    int digito = dec % 10;

    // 2. Calcula quanto tem de "andar" para a esquerda
    // i=0 (unidade) -> shift 0
    // i=1 (dezena)  -> shift 4
    // i=2 (centena) -> shift 8
    // i=3 (milhar)  -> shift 12
    int shift = i * 4;

    bcd |= (digito << shift);

    // 4. Prepara o próximo dígito (ex: 1234 -> 123)
    dec /= 10;
  }

  return bcd;
}
/**
 * bcd2DEC - Converte um valor BCD de 16 bits para um número decimal inteiro.
 * @bcd: Valor BCD (ex: 0x1234).
 * * Exemplo de Funcionamento (bcd = 0x1234):
 * - m = (0x1234 >> 12) & 0xF = 1
 * - c = (0x1234 >> 8)  & 0xF = 2
 * - d = (0x1234 >> 4)  & 0xF = 3
 * - u = (0x1234 & 0xF)       = 4
 * - Retorno: (1*1000) + (2*100) + (3*10) + 4 = 1234 (Decimal)
 */
int bcd2DEC(uint32_t bcd) {

  int m = (bcd >> 16) & 0x000F;
  int c = (bcd >> 12) & 0x000F;
  int d = (bcd >> 8) & 0x000F;
  int u = (bcd >> 4) & 0x000F;
  int s = bcd & 0x000F;
  int res = (m * 1000) + (c * 100) + (d * 10) + u;
  return (s == 0x0D) ? -res : res;
}

/**
 * @brief Converte um valor em formato BCD de 16 bits para binário inteiro.
 * * A função decompõe o valor BCD em 4 dígitos decimais (milhares, centenas,
 * dezenas e unidades), isolando cada nibble (4 bits) através de shifts e
 * máscaras.
 * * @param bcd Valor codificado em BCD (ex: 0x1234).
 * @return uint16_t O valor decimal convertido em binário puro (ex: 1234).
 * * @note Exemplo de processamento para bcd = 0x1234:
 * 1. m = (0x1234 >> 12) & 0xF = 1  -> 1 * 1000 = 1000
 * 2. c = (0x1234 >> 8)  & 0xF = 2  -> 2 * 100  = 200
 * 3. d = (0x1234 >> 4)  & 0xF = 3  -> 3 * 10   = 30
 * 4. u = (0x1234 & 0xF)       = 4  -> 4 * 1    = 4
 * Resultado final: 1234
 */
int bcd2Bin(uint32_t bcd) {
  int ultimo_nibble = bcd & 0x000F;
  if (ultimo_nibble > 0x9) {
    int sinal = ultimo_nibble;
    int val = bcd >> 4;
    int m = (val >> 12) & 0x000F;
    int c = (val >> 8) & 0x000F;
    int d = (val >> 4) & 0x000F;
    int u = val & 0x000F;
    int res = (m * 1000) + (c * 100) + (d * 10) + u;
    return (sinal == 0x0D) ? -res : res;
  } else {
    int m = (bcd >> 12) & 0x000F;
    int c = (bcd >> 8) & 0x000F;
    int d = (bcd >> 4) & 0x000F;
    int u = bcd & 0x000F;
    int res = (m * 1000) + (c * 100) + (d * 10) + u;
    return res;
  }
}

/**
 * bin2BCD - Converte binário para BCD usando o algoritmo Double Dabble.
 * @a: Valor binário puro (ex: 255).
 * * Lógica:
 * - Percorre cada bit do número original.
 * - Se um nibble (4 bits) do BCD for >= 5, soma 3 (ajuste de carry).
 * - Desloca tudo para a esquerda e insere o próximo bit.
 * * Exemplo (a = 13):
 * 1. Inicializa bcd = 0.
 * 2. Faz shift dos bits de '13' (1101) para dentro do bcd.
 * 3. Faz o ajuste (+3) sempre que um dígito decimal "ameaça" passar de 9.
 * Retorno: 0x0013.
 */
uint32_t bin2BCD(int a) {
  uint32_t sinal = (a < 0) ? 0x0D : 0x0C;
  unsigned int val = (a < 0) ? -a : (unsigned int)a;
  if (val == 0)
    return 0x0000C;
  uint32_t bcd = 0;
  int bits = bin_puro(val);
  for (int i = 0; i < bits; i++) {
    if (((bcd & 0x000F)) >= 0x0005)
      bcd += 0x0003;
    if (((bcd & 0x00F0)) >= 0x0050)
      bcd += 0x0030;
    if (((bcd & 0x0F00)) >= 0x0500)
      bcd += 0x0300;
    if (((bcd & 0xF000)) >= 0x5000)
      bcd += 0x3000;
    int bit = (val >> (bits - 1 - i)) & 1;
    bcd = (bcd << 1) | bit;
  }
  return (bcd << 4) | sinal;
}
uint16_t somarBCD(uint16_t a, uint16_t b) {
  uint16_t res = (uint16_t)a + b;
  if (((a & 0x000F) + (b & 0x000F)) > 0x0009)
    res += 0x0006;
  if (((res & 0x00F0)) > 0x0090)
    res += 0x0060;
  if (((res & 0x0F00)) > 0x0900)
    res += 0x0600;
  if (((res & 0xF000)) > 0x9000)
    res += 0x6000;
  return (uint16_t)res;
}

uint32_t somarBCD_32(uint32_t a, uint32_t b) {
  uint64_t res = (uint64_t)a + b;

  for (int i = 0; i < sizeof(uint32_t) * 2; i++) {
    int desl = i * 4;
    uint32_t mascara = (0xF << desl);
    uint32_t limite = (0x9 << desl);
    uint32_t correcao = (0x6 << desl);
    if (((res >> desl) & 0xF) > 0x9) {
      res += correcao;
    }
  }
  return (uint32_t)res;
}

uint16_t subtrairBCD(uint16_t a, uint16_t b) {
  uint16_t comp9 = 0x9999 - b;
  return somarBCD(a, (somarBCD(comp9, 0x0001)));
}

uint16_t multiplicarBCD(uint16_t a, uint16_t b) {
  uint32_t res = 0;
  uint16_t digitos[4];

  digitos[0] = (b & 0x000F);
  digitos[1] = (b >> 4) & 0x000F;
  digitos[2] = (b >> 8) & 0x000F;
  digitos[3] = (b >> 12) & 0x000F;
  for (int j = 0; j < 4; j++) {
    uint32_t parcela = 0;
    for (int i = 0; i < digitos[j]; i++) {

      parcela = somarBCD_32(parcela, a);
    }
    uint32_t parcela_desc = parcela << (j * 4);
    res = somarBCD_32(res, parcela_desc);
  }
  return (uint16_t)res;
}
void print_bin(uint32_t bcd) {
  for (int i = find_bits(bcd) - 1; i >= 0; i--) {
    uint16_t bit = (bcd >> i) & 1;
    printf("%u", bit);
    if (i % 4 == 0 && i != 0)
      printf(" ");
  }
  // printf("\n");
}

void print_bin_custom(uint32_t bcd, int tam) {
  for (int i = tam - 1; i >= 0; i--) {
    uint32_t bit = (bcd >> i) & 1;
    printf("%u", bit);
    if (i % 4 == 0 && i != 0)
      printf(" ");
  }
  // printf("\n");
}
void tabela_decbcd(uint32_t *numeros, int total) {

  printf(" DEC   |       BIN (BCD)      | HEX (BCD)\n");
  printf("-------|----------------------|----------\n");
  for (int i = 0; i < total; i++) {
    int n = numeros[i];
    uint32_t res = dec2BCD(n);
    printf(" %-5d | ", n);
    int tam = (res > 0x0FFF) ? 16 : (res > 0x00FF ? 12 : 8);
    print_bin_custom(res, tam);
    int espacos = 21 - (tam + (tam / 4 - 1));
    for (int s = 0; s < espacos; s++)
      printf(" ");
    printf("| 0x%04X\n", res);
  }
  printf("---------------------|---------|---------\n");
}
void tabela_bcddec(uint32_t *numeros, int total) {

  printf("      BIN (BCD)      |   DEC   |   HEX   \n");
  // 2. Linha separadora (20 traços + barra + 9 traços + barra + 9 traços)
  printf("---------------------|---------|---------\n");

  for (int i = 0; i < total; i++) {
    int n = numeros[i];
    int res = bcd2Bin(n);
    // int tam = (n > 0xFF) ? 12 : 8;
    int tam = (n > 0x0FFF) ? 16 : (n > 0x00FF ? 12 : 8);
    print_bin_custom(n, tam);
    int espacos = 20 - (tam + (tam / 4 - 1));
    for (int s = 0; s < espacos; s++)
      printf(" ");
    printf(" |   %-5d | 0x%03X\n", res, n);
  }
  printf("---------------------|---------|---------\n");
}
int main() {
  uint32_t numeros_dec[] = {10, 13, 25, 57, 125, 1964};
  uint32_t numeros_bin[] = {0b10010110, 0b1010100, 0b100001010111};
  int total_dec = sizeof(numeros_dec) / sizeof(numeros_dec[0]);
  int total_bin = sizeof(numeros_bin) / sizeof(numeros_bin[0]);
  tabela_decbcd(numeros_dec, total_dec);
  tabela_bcddec(numeros_bin, total_bin);
  uint32_t a = 0x96D;
  uint32_t b = 0x10C;
  int num1 = bcd2Bin(a); // Converte 0x96D para -96
  int num2 = bcd2Bin(b); // Converte 0x10C para 10
  int soma = num1 + num2;
  uint32_t res = bin2BCD(soma);
  printf("Binario BCD: ");
  print_bin(res);
  printf("\nSoma Real (Decimal): %d", soma);  // Imprime -86
  printf("\nSoma em BCD (Hex): 0x%X\n", res); // Imprime 0x86D
  // uint16_t a = 0x0025;
  // uint16_t b = 0x0013;

  // printf("0x%x", multiplicarBCD(a, b));

  //   uint16_t x = 1964;
  //   uint16_t res = dec2BCD(x);
  //   uint16_t bins = bcd2Bin(res);
  // printf("0x%02x\n", res);
  //   print_bin(bins);

  // printf("%u", double_dabble(res));
  //  int bits = find_bits(res);
  //  if (bits == 4)
  //    printf("                | ");
  //  if (bits == 8)
  //    printf("           | ");
  //  if (bits == 12)
  //    printf("      | ");
  //  if (bits == 16)
  //    printf(" | ");
  return 0;

  // uint32_t x = 1964;
  // uint32_t y = 1;
  // uint16_t res = somarBCD(dec2BCD(x), dec2BCD(y));

  // printf("0x%02x\n", res);

  // printf("0x%02x",dec2BCD(x));
  // print_bin(res);
}
