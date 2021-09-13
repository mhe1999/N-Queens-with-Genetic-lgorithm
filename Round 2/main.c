#include <math.h>
#include <stdio.h>

#include "type.h"

int erfunc(char *s, int val);
void initialize(char *argv[], POPULATION *p);
void generation(POPULATION *p, int gen);
void report(int gen, POPULATION *p, IPTR  pop);
void statistics(POPULATION *p, IPTR pop);

int main(int argc, char *argv[])
{
  IPTR tmp, op, np;
  POPULATION population;
  POPULATION *p = &population;

  p->gen = 0;
  if(argc != 2) erfunc("Usage: ga <inputfile name> ", argc);
  initialize(argv, p);
  // for(int i=0;i<9;i++){
  //     printf("\n\n test1:%d",p->op->chrom[i]);
  //     printf("\n\n test2:%d",p->op[1].chrom[i]);
  // }
  // printf("\n\n test:%d",p->op->chrom[1]);
  // printf("\n\n test:%d",p->np->chrom[2]);

  // return 0;
  int arr[p->lchrom];
  int max = p->max;
  int n = p->lchrom;
  int ideal_fitness = (n * (n-1)) / 2;
  while(p->gen < p->maxGen){

    p->gen++;
    generation(p, p->gen);
    // return 0;
    statistics(p, p->np);
    report(p->gen, p, p->np);
    tmp = p->op;
    p->op = p->np;
    p->np = tmp;
    if(p->max >= max){
        for(int i=0 ; i<p->lchrom;i++){
             arr[i] = p->op[p->maxi].chrom[i];}
        // printf("Progress\n");
        // printf("p->max:%f\n",p->max);
        // printf("max:%d\n", max);
        max = p->max;
    }
    if ((p->highestEverFitness >= ideal_fitness) && (p->gen > 2)){
        break;
    }
  }
  // printf("\n ");
  // for(int i=0 ; i<p->lchrom;i++){
  //      printf("%d ", p->op[p->maxi].chrom[i]);
  // }
  printf("\n ");
  for(int i=0 ; i<p->lchrom;i++){
       printf("%d ", arr[i]);
  }
  // printf("\n ");
  // for(int i=0 ; i<p->lchrom;i++){
  //      printf("%d ", p->op[1].chrom[i]);
  // }
  // printf("\n\n%d", p->op->chrom[0]);

  //
  // for (i = 0; i < p->popSize; i++){
  //   pi = &(p->op[i]);
  //
  // }
  // for (int j = 0; j < p->lchrom; j++){
  //     //  fprintf(stdout, "%1i\n", pj->chrom[j]);}
  //     // printf("%d%d%d%d\n ENNNNND", arr[0],arr[1],arr[2],arr[3]);
  // }
}
