#include <stdlib.h>
#include "utils.h"

__uint64_t createMask(int num) {
  __uint64_t mask = 0;
  for (int i = 0; i < num; ++i) {
    mask <<= 1;
    ++mask;
  }
  return mask;
}

_Bool isNumeric(gene_t gene) {
  return gene < ADD;
}

_Bool isOperator(gene_t gene) {
  return gene != NONE && !isNumeric(gene);
}

gene_t decode(__uint8_t bits) {
  switch (bits) {
    case 0:
      return ZERO;
    case 1:
      return ONE;
    case 2:
      return TWO;
    case 3:
      return THREE;
    case 4:
      return FOUR;
    case 5:
      return FIVE;
    case 6:
      return SIX;
    case 7:
      return SEVEN;
    case 8:
      return EIGHT;
    case 9:
      return NINE;
    case 10:
      return ADD;
    case 11:
      return MINUS;
    case 12:
      return MULTIPLY;
    default:
      return NONE;
  }
}

gene_t getGene(chromosome_t chromosome) {
  __uint8_t geneBits = (__uint8_t) (chromosome & createMask(4));
  return decode(geneBits);
}