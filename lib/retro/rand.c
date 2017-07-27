# include <time.h>
# include <stdio.h>
# include <stdlib.h>

int main (void) {

  srand((unsigned)time(NULL));
  for(int i=1; i<=10; i++) {
    printf("%3.10f\n",(float)rand()/RAND_MAX);
  }
  return 0;
}
