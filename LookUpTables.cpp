#include "LookUpTables.h"
#include "DesFunc.h"
#include "GlobalV.h"
#include "Types.h"
#include <stdio.h>

u64 PTableLookUp[8][256] = {0};

void genPTableLookUp() {
  u64 x;
  for (int i = 0; i < 8; i++) {
    for (int j = 1; j < 256; j++) {
      x = j;
      x <<= (56 - 8 * i);
      PTableLookUp[i][j] = permutation(x);
    }
  }
}

void printPTableLookUp(int i) {
  for (int j = 0; j < 256; j++) {
    printf("%llx\n", PTableLookUp[i][j]);
  }
}