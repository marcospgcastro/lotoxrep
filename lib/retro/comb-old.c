# include <stdio.h>
# include <stdlib.h>

int main (void) {

  int n = 28;
  int line = 153;
  int ind[n+1];

  for(int i=0; i<=n; i++)
  {
    ind[i] = i;
  }

  for(int i=1; i<=4; i++)
  {
    printf("%d\t",ind[i]);
  }
  printf("\n");

  while( ind[1] <= line-n+1 )
  {

    for(int i=1; i<=4; i++)
    {
       printf("%d\t",ind[i]);
    }
    printf("\n");


    ind[n]++;
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

  return 0;
}
