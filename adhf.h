#ifndef __ADHF_H__
#define __ADHF_H__

union _double_byte{
  double d;
  char c[sizeof(double)];
};
typedef union _double_byte double_byte;
unsigned long adhf(double* ddata, unsigned int ndata,unsigned int hash_size,
		   int bit_replace);
unsigned long adhf_1(double* ddata, unsigned int ndata,unsigned int hash_size);
unsigned long adhf_2(double* ddata, unsigned int ndata,unsigned int hash_size);
unsigned long adhf_3(double* ddata, unsigned int ndata,unsigned int hash_size);
unsigned long adhf_4(double* ddata, unsigned int ndata,unsigned int hash_size);


void da2char_1(char* char_data,double* ddata,unsigned int ndata);
void da2char_2(char* char_data,double* ddata,unsigned int ndata);
void da2char_3(char* char_data,double* ddata,unsigned int ndata);
void da2char_4(char* char_data,double* ddata,unsigned int ndata);

#endif   /* __ADHF_H__ */
