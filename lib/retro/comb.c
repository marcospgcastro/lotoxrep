# include <stdio.h>
# include <stdlib.h>

int main (void) {

  int n = 28;
  int line = 153;
  int ind[n+1];
  int table[153+1][1806+1];
  int soma, aux, cont;
  int par = 300;

  for(int i=1; i<=n; i++)
  {
    ind[i] = i;
  }

  // ======================================

  FILE *db = fopen("data.redox.dat","r");
  for(int i=1; i<=153; i++) {
    for(int j=1; j<=1806; j++) {
      fscanf(db,"%d\t",&table[i][j]);
    }
    fscanf(db,"\n");
  }

  // =======================================

  while( ind[1] < ( line-n ) )
  {
    cont = 0;

    for(int i=7; i<=1806; i++) {          // COMPARAÇÃO DE PARIDADES
       soma = 0;
       for(int j=1; j<=28; j++) {
          aux = ind[j];
          soma = soma + table[aux][i];
       }
       if(soma >= 1) {
         cont++;
       }
    }
    if( cont > par ) {
      for(int i=1; i<=n; i++)             // IMPRESSÃO DE COMBINAÇÕES
      {
        printf("%.f\t",(float)ind[i]);
      }
      printf("%d\n",cont);
    }

    ind[n]++;				// ATUALIZAÇÃO DE POSIÇÃO DAS COMBINAÇÕES
    for(int i=0; i<=n-1; i++)
    {
      if( ind[n-i] > line-i)
      {
        ind[n-i-1]++;
        for(int j=0; j<=i ; j++)
        {
           ind[n-i+j] = ind[n-i+j-1] + 1;
        }
      }
    }
  }

  // ======================================

  cont = 0;

  for(int i=7; i<=1806; i++) {
     soma = 0;
     for(int j=1; j<=28; j++) {
        aux = ind[j];
        soma = soma + table[aux][i];
     }
     if(soma >= 1) {
       cont++;
     }
  }
  if( cont > par ) {
    for(int i=1; i<=n; i++)             // IMPRESSÃO DE COMBINAÇÕES
    {
      printf("%.f\t",(float)ind[i]);
    }
    printf("%d\n",cont);
  }

  return 0;
}
