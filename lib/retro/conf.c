# include <stdio.h>

int main (void) {

int table[1968][6];


FILE *db = fopen("/opt/app/c/var/data/data.sena.dat","r");

for(int i=0; i<1912; i++) {
  for(int j=0; j<6; j++) {
    fscanf(db,"%d\t",&table[i][j]);
  }
  fscanf(db,"\n");
}
fclose(db);

FILE *gb = fopen("/opt/app/c/lib/gamebull.log","r");

for(int i=1912; i<1940; i++) {
  for(int j=0; j<6; j++) {
    fscanf(gb,"%d\t",&table[i][j]);
  }
  fscanf(gb,"\n");
}

fscanf(gb,"\n");

for(int i=1940; i<1968; i++) {
  for(int j=0; j<6; j++) {
    fscanf(gb,"%d\t",&table[i][j]);
  }
  fscanf(gb,"\n");
}

fclose(gb);

int cont, rep , game;

for(int i=1940; i<1968; i++) {
  for(int j=0; j<6; j++) {
    printf("%d\t",table[i][j]);
  }
  printf("\n");
}

printf("\n");

   rep = 0;
   for(int i=1; i<1800; i++) {

      game = 0;
      for(int j=1912; j<1940; j++) {

         cont = 0;
         for(int k=0; k<6; k++) {

            for(int l=0; l<6; l++) {

               if(table[i][k] == table[j][l]) {
                 cont++;
               }
            }
         }
         if(cont > 3) {
           game++;
         }
      }
      if(game > 0) {
        rep++;
      }
   }
   printf("%d\n",rep);

return 0;
}
