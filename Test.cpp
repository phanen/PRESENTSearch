#include "DesFunc.h"
#include "DiffDistribution.h"
#include "GlobalV.h"
#include "LookUpTables.h"
#include "Search.h"
#include "Tables.h"
#include "Types.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TN 1000000

u64 genRandom64() {
  u64 x;
  srand((unsigned long)time(NULL));
  for (int i = 0; i < 5; i++) {
    x = x << 15 | rand();
  }
  return x;
}

void print64(u64 x) { printf("%llx\n", x); }
void print4t16(u8 *x) {
  for (int i = 0; i < 16; i++) {
    printf("%x\t", *(x + i));
  }
  printf("\n");
}

void printUnP() {
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 64; j++) {
      if (PTable[j] == i) {
        printf("%d,", j);
        break;
      }
    }
  }
}

int main() {
  genDiffTable();
  genPTableLookUp();
  clock_t start, end;

  printDiffTable();
  // printPTableLookUp(7);

  /*u64 x;
  u8 sb[16];
  bool bit[64];
  x=genRandom64();
  print64(x);
  word64_2_word4(sb,x);
  word4_2_word64(&x,sb);
  print64(x);
  print64(x);
  word64_2_bit(bit,x);
  bit_2_word64(&x,bit);
  print64(x);
  x=permutation(x);
  print64(x);
  x=unPermutation(x);
  print64(x);
  x=permutationTL(x);
  print64(x);
  start=clock();
  for(int i=0;i<TN;i++){
          x=permutationTL(x);
  }
  end=clock();
  printf("���time=%f\n",(double)(end-start)/CLK_TCK);
  for(int i=0;i<TN;i++){
          x=permutation(x);
  }
  end=clock();
  printf("��ͨtime=%f\n",(double)(end-start)/CLK_TCK);*/
  // start=clock();
  // search(13);
  // Round_1();
  searchAll();
  // make(4,-14);
  // searchByMaking(4);

  /*rounds=5;
  B_n_bar=-20;
  proba[1]=-4;
  proba[2]=-2;
  proba[3]=-2;
  proba[4]=-5;
  proba[5]=-7;
  searchPattern();*/
  end = clock();
  printf("����time=%f\n", (double)(end - start) / sysconf(_SC_CLK_TCK));
  system("pause");
}
