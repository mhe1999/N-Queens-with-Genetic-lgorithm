#include <stdio.h>

#include "type.h"

int Tourn_sel(IPTR pop, double sumFitness, int popsize, int n);
void crossover(POPULATION *p, IPTR p1, IPTR p2, IPTR c1, IPTR c2);
double eval(POPULATION *p, IPTR pj);

int generation(POPULATION *p, int t)
{

  int i, p1, p2, c;

  IPTR pi, piPlus1, om1, om2;

  for(i = 0; i < p->popSize; i += 2){

    p1 = Tourn_sel(p->op, p->sumFitness, p->popSize, 2);
    // return 0;
    p2 = Tourn_sel(p->op, p->sumFitness, p->popSize, 2);
    // printf("________________________");
    // printf("\nTEST %d\n", p1);
    // printf("\nTEST %d\n\n\nom1:", p2);

    pi = &(p->np[i]);
    piPlus1 = &(p->np[i+1]);
    om1 = &(p->op[p1]);
    om2 = &(p->op[p2]);
    // for (int j = 0; j < p->lchrom; j++)
    //   fprintf(stdout, "%1i ", om1->chrom[j]);
    // printf(": %f\nom2:", om1->fitness);
    //
    // for (int j = 0; j < p->lchrom; j++)
    //   fprintf(stdout, "%1i ", om2->chrom[j]);
    // printf(": %f\n\npi1:", om2->fitness);

    crossover(p, om1, om2, pi, piPlus1);

    pi->fitness = eval(p, pi);
    pi->parent1 = p1;
    pi->parent2 = p2;


    piPlus1->fitness = eval(p, piPlus1);
    piPlus1->parent1 = p2;
    piPlus1->parent2 = p1;
  //
  //   for (int j = 0; j < p->lchrom; j++)
  //     fprintf(stdout, "%1i ", pi->chrom[j]);
  //   printf(": %f\n\npi2:", pi->fitness);
  //
  //   for (int j = 0; j < p->lchrom; j++)
  //     fprintf(stdout, "%1i ", piPlus1->chrom[j]);
  //   printf(": %f\n\n", piPlus1->fitness);
  //
  }

}
