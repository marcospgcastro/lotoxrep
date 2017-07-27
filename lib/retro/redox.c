# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>

// DECLARAÇÃO DE ESTRUTURA PARA MATRIZ COM ALUCAMENTO DINAMICO

typedef struct {
  int line;
  int down;
  float *date;
} matrix;

// DECLARAÇÃO PARA MATRIZ NxM

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

// LIBERAÇÃO DE MEMORIA PARA ALOCAMENTO DINAMICO

int freeMatrix(matrix *mtx) {
    assert(mtx->date);
    free(mtx->date);
    free(mtx);
    return 0;
}

// MACRO PARA MATRIZ

# define ELEMENT(mtx,line,down) mtx->date[(down - 1)*mtx->line + (line - 1)]

// PROGRMA PRINCIPAL

int main (void) {

  matrix *table = newMatrix(2199,1806);

  FILE *archive = fopen("/opt/app/c/out/24.03/data.over.dat","r");

  for(int line=1; line<=2199; line++) {
     for(int down=1; down<=1806; down++) {
        fscanf(archive,"%f",&ELEMENT(table,line,down));
        fscanf(archive,"\t");
     }
     fscanf(archive,"\n");
  }
  fclose(archive);

  // insere linha de processamento

  int cont, one, line, pont = 1;
  int two, down, comp = 2;

  line = pont;
  for(int i=1; i<=1806; i++) {
     down = i;
     printf("%.f\t",ELEMENT(table,line,down));
  }
  printf("\n");

  while( comp <= 1806 ) {
    cont = 0;
    for(int i=7; i<=1806; i++) {
      line = pont;
      down = i;
      one = ELEMENT(table,line,down);
      line = comp;
      two = ELEMENT(table,line,down);
      if( one == two ) {
        cont++;
      }
    }
    if( cont < 1800) {
      pont = comp;
      comp++;
      for(int i=1; i<=1806; i++) {
         line = pont;
         down = i;
         printf("%.f\t",ELEMENT(table,line,down));
      }
      printf("\n");
    }
    else {
      comp++;
    }
  }

  freeMatrix(table);

  return 0;
}
