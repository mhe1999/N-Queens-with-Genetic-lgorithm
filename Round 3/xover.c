#include "type.h"
#include <stdio.h>

int rnd(int low, int high);
int flip(double);
int muteX(POPULATION *p, int *pa);

void crossover(POPULATION *p, IPTR p1, IPTR p2, IPTR c1, IPTR c2)
{
/* p1,p2,c1,c2,m1,m2,mc1,mc2 */
  int *pi1,*pi2,*ci1,*ci2;
  int xp, i;

  pi1 = p1->chrom;
  pi2 = p2->chrom;
  ci1 = c1->chrom;
  ci2 = c2->chrom;
  // int arr1[p->lchrom] = {0};
  // int arr2[p->lchrom] = {0};
  int flag=0;
  if(flip(p->pCross)){

    xp = rnd(0, p->lchrom - 1);
    // printf("xp:%d\n",xp);
    for(i = 0; i < xp; i++){
      ci1[i] = pi1[i];
      ci2[i] = pi2[i];
    }
    // printf("pi1:%d%d%d%d%d%d\n\n", pi1[0],pi1[1],pi1[2],pi1[3],pi1[4],pi1[5]);
    // printf("pi2:%d%d%d%d%d%d\n\n", pi2[0],pi2[1],pi2[2],pi2[3],pi2[4],pi2[5]);
    //
    // printf("ci1:%d%d%d%d%d%d\n\n", ci1[0],ci1[1],ci1[2],ci1[3],ci1[4],ci1[5]);
    // printf("ci2:%d%d%d%d%d%d\n\n", ci2[0],ci2[1],ci2[2],ci2[3],ci2[4],ci2[5]);

    for(i = xp; i < p->lchrom; i++){
        for(int j=0; j<p->lchrom ; j++){
            flag = 0;
            for(int k=0; k<i;k++){
                if(pi2[j]==ci1[k])
                    flag=1;
            }
            if (flag==1) continue;
            else ci1[i] = pi2[j];
            break;
        }
    }
    for(i = xp; i < p->lchrom; i++){
        for(int j=0; j<p->lchrom ; j++){
            flag = 0;
            for(int k=0; k<i;k++){
                if(pi1[j]==ci2[k])
                    flag=1;
            }
            if (flag==1) continue;
            else ci2[i] = pi1[j];
            break;
        }
    }
  } else {
    for(i = 0; i < p->lchrom; i++){
      ci1[i] = pi1[i];
      ci2[i] = pi2[i];
    }
  }
  // printf("pi1:%d%d%d%d%d%d\n\n", pi1[0],pi1[1],pi1[2],pi1[3],pi1[4],pi1[5]);
  // printf("pi2:%d%d%d%d%d%d\n\n", pi2[0],pi2[1],pi2[2],pi2[3],pi2[4],pi2[5]);
  // printf("ci1:%d%d%d%d%d%d\n\n", ci1[0],ci1[1],ci1[2],ci1[3],ci1[4],ci1[5]);
  // printf("ci2:%d%d%d%d%d%d\n\n", ci2[0],ci2[1],ci2[2],ci2[3],ci2[4],ci2[5]);
  muteX(p, ci1);
  muteX(p, ci2);
  // printf("ci1:%d%d%d%d%d%d\n\n", ci1[0],ci1[1],ci1[2],ci1[3],ci1[4],ci1[5]);
  // printf("ci2:%d%d%d%d%d%d\n\n", ci2[0],ci2[1],ci2[2],ci2[3],ci2[4],ci2[5]);


}

int muteX(POPULATION *p, int *pa)
{
    int x1, x2 = 0;
    if (flip(p->pMut)){
        x1 = rnd(1,p->lchrom) - 1;
        while(1){
            x2 =rnd(1,p->lchrom) - 1;
            if(x1 != x2)
                break;
        }
        // printf("\nX1:%d\n", x1);
        // printf("\nX2:%d\n", x2);

        int tmp = pa[x1];
        pa[x1] = pa[x2];
        pa[x2] = tmp;
    }
  // return (flip(p->pMut) ? rnd(1,p->lchrom)  : pa);
}
