# include <stdio.h>
# include <stdlib.h>

int reward (int k) {

  int n = 30;
  int ind[31], table[154][154];

  int cont, rowl, cols, rowl_max = 153;

  FILE *db = fopen("data.table.dat","r");
  for(int i=1; i<=153; i++) {
    for(int j=1; j<=153; j++) {
      fscanf(db,"%d\t",&table[i][j]);
    }
    fscanf(db,"\n");
  }

  int i = 1;
  int j = 2;

  ind[i] = k;
  ind[j] = k+1;


  cont = 0;

  while( j <= 28 && ind[j] <= 153 ) {

    cols = ind[i];
    rowl = ind[j];

    if( table[rowl][cols] <= 2 ) {

      i = j;

      cont++;
      // printf("%d\t",cont);
      // printf("table[%d][%d]\n",rowl,cols);

      j++;

      ind[j] = ind[i];

    }

    ind[j]++;
  }

  int parTable[cont+1][cont+1];

//  printf("\n");

  for(int i=1; i<=cont; i++) {
     for(int j=1; j<=cont; j++) {
       rowl = ind[i];
       cols = ind[j];
       parTable[i][j] = table[rowl][cols];
       //printf("%2.f ",(float)parTable[i][j]);
     }
  //   printf("\n");
  }

  int sumpri = 0;
  for(int i=1; i<=cont; i++) {
    sumpri += parTable[i][i];
  }

  int sumout = 0;
  for(int i=1; i<=cont-1; i++) {
     for(int j=i+1; j<=cont; j++) {
       sumout += parTable[i][j];
     }
  }

  int reward = sumpri - sumout;

  printf("%d\t %d\n",cont,reward);

  return 0;
}

int main (void) {

  for(int k=1; k<=153; k++) {
     reward(k);
  }
  return 0;
}
