# include <stdio.h>
# include <stdlib.h>

int main (void) {

  int n = 28, line = 153;
  int ind[n+1], table[153+1][153+1];
  int sumpri, sumout, reward;

  int rowl, cols;

  for(int i=1; i<=n; i++) { ind[i] = i+39; }

  FILE *db = fopen("data.table.dat","r");
  for(int i=1; i<=153; i++) {
    for(int j=1; j<=153; j++) {
      fscanf(db,"%d\t",&table[i][j]);
    }
    fscanf(db,"\n");
  }

//while( ind[1] < ( line-n ) ) {
  while( ind[20] < 70 ) {
    sumpri = 0;
    for(int i=1; i<=n; i++) {
      rowl = cols = ind[i];
      sumpri += table[rowl][cols];
    }
    sumout =0;
    for(int i=1; i<=(n-1); i++) {
       for(int j=i+1; j<=n; j++) {
          rowl = ind[i];
          cols = ind[j];
          sumout += table[rowl][cols];
       }
    }
    reward = sumpri - sumout;
    if( reward >= 450 ) {
      for(int i=1; i<=n; i++) {
         printf("%d\t",ind[i]);
      }
      printf("%d\n",reward);
    }
    ind[n]++;
    for(int i=0; i<=n-1; i++) {
      if( ind[n-i] > line-i) {
        ind[n-i-1]++;
        for(int j=0; j<=i ; j++) {
        ind[n-i+j] = ind[n-i+j-1] + 1; }
      }
    }

  }

  sumpri = 0;
  for(int i=1; i<=n; i++) {
    rowl = cols = ind[i];
    sumpri += table[rowl][cols];
  }
  for(int i=1; i<=(n-1); i++) {
     for(int j=i+1; j<=n; j++) {
        rowl = ind[i];
        cols = ind[j];
        sumout += table[rowl][cols];
     }
  }
  reward = sumpri - sumout;
  if( reward >= 450 ) {
    for(int i=1; i<=n; i++) {
       printf("%d\t",ind[i]);
    }
    printf("%d\n",reward);
  }

  return 0;
}
