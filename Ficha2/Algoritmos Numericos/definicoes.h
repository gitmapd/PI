#ifndef DEFINICOES_H
#define DEFINICOES_H

#define BIT  1
#define BYTE 8

#define KiB 1024LL
#define MiB (1024LL * KiB)
#define GiB (1024LL * MiB)
#define TiB (1024LL * GiB)
#define PiB (1024LL * TiB)
#define EiB (1024LL * PiB)
#define ZiB (1024LL * EiB)

#define IMG23_WIDTH  128
#define IMG23_HEIGHT 128

#define IMG24_WIDTH  256
#define IMG24_HEIGHT 512

#define EX24_SIZE_KIB 192

#define CHANNELS   3     // RGB
#define BITS_PER_CHANNEL 8

#define CALC_PIXELS(w, h) ((w) * (h))

#define BYTES_PARA_BITS(n) ((n) * 8)

#define TO_BYTES(n) ((n) * KiB)

#define CALC_BITS_CH(size_kb, pixels, ch) ((( (float)TO_BYTES(size_kb) / (pixels) / ch)) * 8)
#endif