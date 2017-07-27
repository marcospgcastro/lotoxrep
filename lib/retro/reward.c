# include <stdio.h>

int main (void) {

  int line, n = 25, par = 2;
  int table[154][154];

  FILE *db = fopen("data.table.dat","r");
  for(int i=1; i<=153; i++) {
    for(int j=1; j<=153; j++) {
      fscanf(db,"%d\t",&table[i][j]);
    }
    fscanf(db,"\n");
  }

  int pt1;
  int pt2;

  int sumout, sumpri;
  int rowl, cols;
  int in[31];

  in[0] = 60;
  line = 153;

  for( in[1] = in[0]+1; in[1]<= line - n + 1; in[1]++ ) {
    pt1 = in[1];

  for( in[2] = in[1]+1; in[2]<= line - n + 2; in[2]++ ) {
    pt2 = in[2];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[3] = in[2]+1; in[3]<= line - n + 3; in[3]++ ) {
    pt2=in[3];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[4] = in[3]+1; in[4]<= line - n + 4; in[4]++ ) {
    pt2=in[4];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[5] = in[4]+1; in[5]<= line - n + 5; in[5]++ ) {
    pt2 = in[5];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[6] = in[5]+1; in[6]<= line - n + 6; in[6]++ ) {
    pt2=in[6];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[7] = in[6]+1; in[7]<= line - n + 7; in[7]++ ) {
    pt2=in[7];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[8] = in[7]+1; in[8]<= line - n + 8; in[8]++ ) {
    pt2 = in[8];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[9] = in[8]+1; in[9]<= line - n + 9; in[9]++ ) {
    pt2=in[9];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[10] = in[9]+1; in[10]<= line - n + 10; in[10]++ ) {
    pt2=in[10];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[11] = in[10]+1; in[11]<= line - n + 11; in[11]++ ) {
    pt2 = in[11];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[12] = in[11]+1; in[12]<= line - n + 12; in[12]++ ) {
    pt2=in[12];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[13] = in[12]+1; in[13]<= line - n + 13; in[13]++ ) {
    pt2=in[13];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[14] = in[13]+1; in[14]<= line - n + 14; in[14]++ ) {
    pt2 = in[14];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[15] = in[14]+1; in[15]<= line - n + 15; in[15]++ ) {
    pt2=in[15];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[16] = in[15]+1; in[16]<= line - n + 16; in[16]++ ) {
    pt2=in[16];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[17] = in[16]+1; in[17]<= line - n + 17; in[17]++ ) {
    pt2 = in[17];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[18] = in[17]+1; in[18]<= line - n + 18; in[18]++ ) {
    pt2=in[18];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[19] = in[18]+1; in[19]<= line - n + 19; in[19]++ ) {
    pt2=in[19];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

  for( in[20] = in[19]+1; in[20]<= line - n + 20; in[20]++ ) {
    pt2 = in[20];
    if( table[pt1][pt2] <= par ) {
      pt1 = pt2;

      sumpri = 0;
      for(int i=1; i<=20; i++) {
        rowl = in[i];
        cols = in[i];
        sumpri += table[rowl][cols];
      }
      sumout = 0;
      for(int i=1; i<=19; i++) {
        for(int j=i+1; j<=20; j++) {
          rowl = in[i];
          cols = in[j];
          sumout += table[rowl][cols];
        }
      }
      if( sumpri-sumout >= 360 ) {
        printf("%d\t",(sumpri-sumout));
        for(int i=1; i<=20; i++) {
          printf("%d\t",in[i]);
        }
        printf("\n");
      }

  } } } } } } } } } } } } } } } } } } } }
  } } } } } } } } } } } } } } } } } } }

  return 0;
}
