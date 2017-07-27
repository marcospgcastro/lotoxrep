# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>

typedef struct {
  int line;
  int down;
  float *date;
} matrix;

matrix *newMatrix(int line, int down) {
  matrix *pt = (matrix*)malloc(sizeof(matrix));
  pt->line = line;
  pt->down = down;
  pt->date = (float*)malloc(line*down*sizeof(float));
  for(int i=0; i<line*down; i++) {
    pt->date[i] = 0.0;
  }
  return pt;
}

int freeMatrix(matrix *mtx) {
    assert(mtx->date);
    free(mtx->date);
    free(mtx);
    return 0;
}

# define ELEMENT(mtx,line,down) mtx->date[(down - 1)*mtx->line + (line - 1)]

int main (void) {

  matrix *table = newMatrix(2199,1806);
  FILE *archive = fopen("/opt/app/c/lib/data.redox.dat","r");
  for(int line=1; line<=2199; line++) {
     for(int down=1; down<=1806; down++) {
        fscanf(archive,"%f",&ELEMENT(table,line,down));
        fscanf(archive,"\t");
     }
     fscanf(archive,"\n");
  }
  fclose(archive);

  FILE *gamelog = fopen("/opt/app/c/lib/data.25.dat","r");
  int game[2][28];
  for(int i=0; i<=1; i++) {
    for(int j=0; j<=27; j++) {
      fscanf(gamelog,"%d",&game[i][j]);
    }
    fscanf(gamelog,"\n");
  }
  fclose(gamelog);


  int line, down;

  for(int i=0; i<=1; i++) {
     for(int j=0; j<=27; j++) {
        for(int k=1; k<=6; k++) {
           line = game[0][j];
           down = k;
           printf("%.f\t",ELEMENT(table,line,down));
        }
        printf("\n");
     }
     printf("\n");
  }

  freeMatrix(table);

  return 0;
}
