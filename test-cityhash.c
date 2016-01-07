#include <stdio.h>
#include "city.h"
#include "MT.h"

#define FLOAT_CHAR_LENGTH 4
#define DOUBLE_CHAR_LENGTH 8

#define ARRAY_LENGTH 1086
#define HASH_SIZE 2161
#define NSETS 100000

int main(){
  int nset=NSETS;
  int ndata=ARRAY_LENGTH;
  int hash_size=HASH_SIZE;
  /* double* data; */
  double** data2d;
  char *sdata = "hoge";

  /* unsigned long hash,hash2,hash3,hash4; */

  unsigned long* hash;
  unsigned long* hash2;
  unsigned long* hash3;
  unsigned long* hash4;


  
  int i,j;

  data2d=(double**) malloc(sizeof(double*)*nset);
  hash=(unsigned long*) malloc(sizeof(unsigned long)*nset);
  hash2=(unsigned long*) malloc(sizeof(unsigned long)*nset);
  hash3=(unsigned long*) malloc(sizeof(unsigned long)*nset);
  hash4=(unsigned long*) malloc(sizeof(unsigned long)*nset);

  for(i=0;i<nset;i++){
    data2d[i]=(double*) malloc(sizeof(double)*ndata);
  }
  /*data=(double*) malloc(sizeof(double)*ndata);*/


  init_genrand(194743097);

  for(j=0;j<nset;j++){
    for(i=0;i<ndata;i++){
      /* data[i]=genrand_res53(); */
      data2d[j][i]=genrand_res53();
    }
    /* hash=adhf_1(data,ndata,hash_size); */
    /* hash2=adhf_2(data,ndata,hash_size); */
    /* hash3=adhf_3(data,ndata,hash_size); */
    /* hash4=adhf_4(data,ndata,hash_size); */
    /* printf("%d %d %d %d\n",hash,hash2,hash3,hash4); */

  }
/*omp parallel start*/
#pragma omp parallel for
  for(j=0;j<nset;j++){
    hash[j]=adhf_1(data2d[j],ndata,hash_size);
    hash2[j]=adhf_2(data2d[j],ndata,hash_size);
    hash3[j]=adhf_3(data2d[j],ndata,hash_size);
    hash4[j]=adhf_4(data2d[j],ndata,hash_size);
  }

/*omp parallel end*/
  for(j=0;j<nset;j++){
    printf("%d %d %d %d\n",hash[j],hash2[j],hash3[j],hash4[j]);
  }
}
