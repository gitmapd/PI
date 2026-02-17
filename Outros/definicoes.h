#ifndef DEFINICOES_H
#define DEFINICOES_H

/* Unidades bits*/
#define BIT 1
#define BYTE 8LL

/* Unidades Potencias de 2*/

#define KiB 1024LL         // 1 KiB = 1024 Bytes 2**10 1024
#define MiB (1024LL * KiB) // 1 MiB = 1024 KiB   2**20 1024**2
#define GiB (1024LL * MiB) // 1 GiB = 1024 MiB   2**30 1024**3
#define TiB (1024LL * GiB) // 1 TiB = 1024 GiB   2**40 1024**4
#define PiB (1024LL * TiB) // 1 PiB = 1024 TiB   2**50 1024**5
#define EiB (1024LL * PiB) // 1 EiB = 1024 PiB   2**60 1024**6
#define ZiB (1024LL * EiB) // 1 ZiB = 1024 EiB   2**70 1024**7

/* Unidades Potencias de 10*/
#define kB_SI 1000LL           // 1 kB = 1000 B  10**3
#define MB_SI (1000LL * kB_SI) // 1 MB = 1000 kB 10**6
#define GB_SI (1000LL * MB_SI) // 1 GB = 1000 MB 10**9
#define TB_SI (1000LL * GB_SI) // 1 TB = 1000 GB 10**12
#define PB_SI (1000LL * TB_SI) // 1 PB = 1000 TB 10**15
#define EB_SI (1000LL * PB_SI) // 1 EB = 1000 EB 10**18
#define ZB_SI (1000LL * EB_SI) // 1 ZB = 1000 ZB 10**21

#define CHANNELS 3 // RGB
#define BITS_PER_CHANNEL 8

#define CALC_PIXELS(w, h) ((w) * (h))

#define BYTES_PARA_BITS(n) ((n)*8)

#define TO_BYTES(n) ((n)*KiB)

/* (Bytes * 8) / (pixels * channels) */

#define CALC_BITS_CH(size_kib, pixels, ch)                                     \
  (((float)(size_kib)*KiB * BYTE) / ((pixels) * (ch)))
#endif

typedef struct {
    int width, height, channels, bpp;
    long long size_bytes;
} ImageMeta;

typedef struct {
    float rate_hz;
    int resolution_bits;
    int duration_sec;
} SoundMeta;

typedef struct {
    int *data;
    int total;
} DataList;