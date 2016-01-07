#include <stdio.h>
#include "adhf.h"
#include "city.h"

/* #define ADHF_DEBUG  */
/**
   hash function.
   bit_replace is a optional choice of bit alinement order  double array 
   to char array.
   1: array:normal bits:reverse
   2: array:reverse bits:reverse
   3: array:reverse bits:normal
   4: array:normal bits:normal

   @param[in] ddata array of double.
   @param[in] ndata size of array.
   @param[in] hash_size size of hash.
   @param[in] bit_replace choice of bit aline. 

   @return hash value.

 */


unsigned long adhf(double* ddata,
		   unsigned int ndata,
		   unsigned int hash_size,
		   int bit_replace){

  unsigned long ret;
  
  switch(bit_replace){
    
  case 1:
    ret=adhf_1(ddata,ndata,hash_size);
    break;
  case 2:
    ret=adhf_2(ddata,ndata,hash_size);
    break;
  case 3:
    ret=adhf_3(ddata,ndata,hash_size);
    break;
  case 4:
    ret=adhf_4(ddata,ndata,hash_size);
    break;
  defalult:
    ret=adhf_1(ddata,ndata,hash_size);
    break;
  }
  return ret;
}

/**
   hash function.
   bit_replace ment array:normal bits:reverse

   @param[in] ddata array of double.
   @param[in] ndata size of array.
   @param[in] hash_size size of hash.
   @return hash value.

 */


unsigned long adhf_1(double* ddata,
		   unsigned int ndata,
		   unsigned int hash_size){
  char* char_data;
  uint64 city_result;
  unsigned long result;
  
  char_data=(char* )malloc(sizeof(double)*ndata+1);
  
  da2char_1(char_data,ddata,ndata);
  city_result = CityHash64(char_data,sizeof(double)*ndata);
#ifdef ADHF_DEBUG
  printf("%s city_result %u %x\n",__func__,city_result,city_result);
#endif // ADHF_DEBUG
  result=city_result%hash_size;

  return result;
}

/**
   hash function.
   bit_replace ment array:reverse bits:reverse


   @param[in] ddata array of double.
   @param[in] ndata size of array.
   @param[in] hash_size size of hash.
   @return hash value.

 */


unsigned long adhf_2(double* ddata,
		   unsigned int ndata,
		   unsigned int hash_size){
  char* char_data;
  uint64 city_result;
  unsigned long result;
  
  char_data=(char* )malloc(sizeof(double)*ndata+1);
  
  da2char_2(char_data,ddata,ndata);
  city_result = CityHash64(char_data,sizeof(double)*ndata);
#ifdef ADHF_DEBUG
  printf("%s city_result %u %x\n",__func__,city_result,city_result);
#endif // ADHF_DEBUG
  result=city_result%hash_size;

   return result;
}
/**
   hash function.
   bit_replace ment array:reverse bits:normal

   @param[in] ddata array of double.
   @param[in] ndata size of array.
   @param[in] hash_size size of hash.
   @return hash value.

 */


unsigned long adhf_3(double* ddata,
		   unsigned int ndata,
		   unsigned int hash_size){
  char* char_data;
  uint64 city_result;
  unsigned long result;
  
  char_data=(char* )malloc(sizeof(double)*ndata+1);
  
  da2char_3(char_data,ddata,ndata);
  city_result = CityHash64(char_data,sizeof(double)*ndata);
#ifdef ADHF_DEBUG
    printf("%s city_result %u %x\n",__func__,city_result,city_result);
#endif // ADHF_DEBUG
  result=city_result%hash_size;

   return result;
}
/**
   hash function.
   bit_replace ment array:normal bits:normal

   @param[in] ddata array of double.
   @param[in] ndata size of array.
   @param[in] hash_size size of hash.
   @return hash value.

 */


unsigned long adhf_4(double* ddata,
		   unsigned int ndata,
		   unsigned int hash_size){
  char* char_data;
  uint64 city_result;
  unsigned long result;
  
  char_data=(char* )malloc(sizeof(double)*ndata+1);
  
  da2char_4(char_data,ddata,ndata);
  city_result = CityHash64(char_data,sizeof(double)*ndata);
#ifdef ADHF_DEBUG
  printf("%s city_result %u %x\n",__func__,city_result,city_result);
#endif // ADHF_DEBUG
  result=city_result%hash_size;

   return result;
}

/**
   bit stream of double array convert to char array.
   array: normal order.
   bits: reverse order.

 */


void da2char_1(char* char_data,double* ddata,unsigned int ndata){

  double_byte db;
  int counter;
  int i,j;
  
  for(i=0;i<ndata;i++){
     db.d=ddata[i];
#ifdef ADHF_DEBUG
     printf("%s %.14e ",__func__,db.d);
#endif // ADHF_DEBUG
     counter=0;
     for(j=sizeof(double)-1;j>=0;j--){
       char_data[sizeof(double)*i+counter]=db.c[j];
#ifdef ADHF_DEBUG
       printf("%08x ",db.c[j]);
#endif // ADHF_DEBUG
       counter++;
     }
#ifdef ADHF_DEBUG
     printf("\n");
#endif // ADHF_DEBUG
   }
   char_data[sizeof(double)*ndata]='\0';
}

/**
   bit stream of double array convert to char array.
   array: reverse order.
   bits: reverse order.

 */


void da2char_2(char* char_data,double* ddata,unsigned int ndata){

  double_byte db;
  int counter,counter2;
  int i,j;

  counter2=0;
  for(i=ndata-1;i>=0;i--){
     db.d=ddata[i];
#ifdef ADHF_DEBUG
     printf("%s %.14e ",__func__,db.d);
#endif // ADHF_DEBUG
     counter=0;
     for(j=sizeof(double)-1;j>=0;j--){
       char_data[sizeof(double)*counter2+counter]=db.c[j];
#ifdef ADHF_DEBUG
       printf("%08x ",db.c[j]);
#endif // ADHF_DEBUG
       counter++;
     }
     counter2++;
#ifdef ADHF_DEBUG
     printf("\n");
#endif // ADHF_DEBUG
   }
   char_data[sizeof(double)*ndata]='\0';
}


/**
   bit stream of double array convert to char array.
   array: reverse order.
   bits: normal order.

 */


void da2char_3(char* char_data,double* ddata,unsigned int ndata){

  double_byte db;
  int counter2;
  int i,j;

  counter2=0;
  for(i=ndata;i>=0;i--){
     db.d=ddata[i];
#ifdef ADHF_DEBUG
     printf("%s %.14e ",__func__,db.d);
#endif // ADHF_DEBUG
     for(j=0;j<sizeof(double);j++){
       char_data[sizeof(double)*counter2+j]=db.c[j];
#ifdef ADHF_DEBUG
       printf("%08x ",db.c[j]);
#endif // ADHF_DEBUG
     }
    counter2++;
#ifdef ADHF_DEBUG
     printf("\n");
#endif // ADHF_DEBUG
   }
   char_data[sizeof(double)*ndata]='\0';
}


/**
   bit stream of double array convert to char array.
   array: normal order.
   bits: normal order.

 */


void da2char_4(char* char_data,double* ddata,unsigned int ndata){

  double_byte db;
  int i,j;
  
  for(i=0;i<ndata;i++){
     db.d=ddata[i];
#ifdef ADHF_DEBUG
     printf("%s %.14e ",__func__,db.d);
#endif // ADHF_DEBUG
     for(j=0;j<sizeof(double);j++){
       char_data[sizeof(double)*i+j]=db.c[j];
#ifdef ADHF_DEBUG
       printf("%08x ",db.c[j]);
#endif // ADHF_DEBUG
     }
#ifdef ADHF_DEBUG
     printf("\n");
#endif // ADHF_DEBUG
   }
   char_data[sizeof(double)*ndata]='\0';
}



#if 0
unsigned long adhf_1(double* ddata,
		   unsigned int ndata,
		   unsigned int hash_size){

  double_byte db;
  char* char_data;
  uint64 city_result;
  unsigned long result;
  
  int counter;
  int i,j;
  
  char_data=(char* )malloc(sizeof(double)*ndata+1);
  
   for(i=0;i<ndata;i++){
     db.d=ddata[i];
     printf("%.14e ",db.d);
     counter=0;
     for(j=sizeof(double)-1;j>=0;j--){
       char_data[sizeof(double)*i+counter]=db.c[j];
       printf("%08x ",db.c[j]);
       counter++;
     }
     printf("\n");
   }
   char_data[sizeof(double)*ndata]='\0';

   city_result = CityHash64(char_data,sizeof(double)*ndata);

   printf("city_result %u %x\n",city_result,city_result);
   result=city_result%hash_size;

   return result;
}
#endif
