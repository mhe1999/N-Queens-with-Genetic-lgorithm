#include<stdio.h>
#include "type.h"
#include <stdlib.h>
double f_random();
int rnd(int low, int high);

int Tourn_sel(IPTR pop, double sumFitness, int popsize, int n)
{

    // rand = (int *) calloc (n, sizeof(int));
    // int rand[n];
    int tmp = 0;
    double max = 0;
    int maxi = -1;
    for(int i=0; i<n ; i++){
        // rand[i] = rnd(0, popsize-1);
        tmp = rnd(0, popsize-1);
        // printf("HIII %d\n", tmp);
        // printf("%f\n",pop[tmp].fitness);
        if(pop[tmp].fitness > max) {
            max = pop[tmp].fitness;
            maxi = tmp;
        }
    }
    // printf("\n%d : %f\n", maxi, max);
    return maxi;
    // return 0;

  /* select a single individual by roulette wheel selection */

  // double rand,partsum;
  // int i;
  //
  // partsum = 0.0; i = 0;
  // rand = f_random() * sumFitness;
  //
  // i = -1;
  // do{
  //   i++;
  //   partsum += pop[i].fitness;
  // } while (partsum < rand && i < popsize - 1) ;
  //
  // return i;
}

// int roulette(IPTR pop, double sumFitness, int popsize)
// {
//
//   /* select a single individual by roulette wheel selection */
//
//   double rand,partsum;
//   int i;
//
//   partsum = 0.0; i = 0;
//   rand = f_random() * sumFitness;
//
//   i = -1;
//   do{
//     i++;
//     partsum += pop[i].fitness;
//   } while (partsum < rand && i < popsize - 1) ;
//
//   return i;
// }
