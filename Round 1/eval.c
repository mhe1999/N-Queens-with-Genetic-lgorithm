#include <stdio.h>
#include <math.h>    /* for pow(x, y) */
#include "type.h"

// double decode(IPTR pj, int index, int size);
// double binToDec(int *chrom, int l);

double eval(POPULATION *p, IPTR pj)
     /* Called from gen.c and init.c */
{
   // printf("HEREEEE\n");
   int arr[p->lchrom];
    for (int j = 0; j < p->lchrom; j++){
   //       // pj->chrom[j] = rnd(1,p->lchrom);
   //       /*      fprintf(stdout, "%1i", pi->chrom[j]); */
        arr[j] = pj->chrom[j];
        //  fprintf(stdout, "%1i\n", pj->chrom[j]);}
        // printf("%d%d%d%d\n ENNNNND", arr[0],arr[1],arr[2],arr[3]);
    }

    int test_val = 0;
    for(int i=0;i<p->lchrom;i++){
        for(int j=i+1;j<p->lchrom;j++){
            if(arr[i] == arr[j])
                continue;
            else if((arr[i]-arr[j] == i-j)||(arr[i]-arr[j] == j-i))
                continue;
            else
                test_val++;
        }
    }
    // printf("%d%d%d%d : %d\n\n", arr[0],arr[1],arr[2],arr[3], test_val);
    return test_val;

  // double val;
  // double square = 0.0;
  //
  // val = decode(pj, 0, p->lchrom);
  // square = val * val;
  //
  // return square;
}
// int eval(POPULATION *p, IPTR pj){
//     for (int j = 0; j < p->lchrom; j++){
//       // pj->chrom[j] = rnd(1,p->lchrom);
//       /*      fprintf(stdout, "%1i", pi->chrom[j]); */
//       fprintf(stdout, "HEERREE %1i", pj->chrom[j]);
//     }
//
// }

// double decode(IPTR pj, int index, int size)
// {
//   return ((double) binToDec(&(pj->chrom[0]), size));
// }
//
// double binToDec(int *chrom, int l)
// {
//   int i;
//   double prod;
//
//   prod = 0.0;
//
//   for(i = 0; i < l; i++){
//     prod += (chrom[i] == 0 ? 0.0 : pow((double)2.0, (double) i));
//   }
//   return prod;
// }
//
// void decToBin(int ad, int *barray, int size)
// {
//   int i, t;
//
//   t = ad;
//   for(i = 0; i < size; i++){
//     barray[i] = t%2;
//     t = t/2;
//   }
// }
