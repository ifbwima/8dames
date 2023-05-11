#ifndef __DAMES__
#define __DAMES__

#include <MLV/MLV_all.h>

# define RES_X 1024
# define RES_Y 512

int bit_value_ULI(unsigned long int n, int position);

void print_ULI(unsigned long int n);

void set_positive_bit_ULI(unsigned long int* n, int position);

void set_negative_bit_ULI(unsigned long int* n, int position);


int verif_col(unsigned long int n, int step);

int verif_lig(unsigned long int n, int step);

int verif_dia(unsigned long int n, int step);

int is_valid(unsigned long int n, int step);

int is_over(unsigned long int n);


#endif
