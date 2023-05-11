#include <stdio.h>
#include <stdlib.h>
# include <MLV/MLV_all.h>

# include "../include/display.h"

int bit_value_ULI(unsigned long int n, int position){
    unsigned long int mask = 1;
    mask = mask << position;
    if((n & mask) == mask){
        return 1;
    }
    return 0;
}

void print_ULI(unsigned long int n){
    unsigned long int mask = 1;
    mask = mask << 63;
    for(int i = 0; i < 64; i++){
        if((n & mask) == mask){
            printf("1");
        }else{
            printf("0");
        }
        mask = mask >> 1;
    }
    printf("\n");
}

void set_positive_bit_ULI(unsigned long int* n, int position){
    unsigned long int mask = 1;
    mask = mask << position;
    *n = *n | mask;
}

void set_negative_bit_ULI(unsigned long int* n, int position){
    unsigned long int mask = 1;
    mask = mask << position;
    mask = ~mask;
    *n = *n & mask;
}

int verif_col(unsigned long int n, int step){
    int first = step%8;
    int last = first + 56;

    for (size_t i = first; i < last; i+=8){
        if(bit_value_ULI(n, i) == 1 && i != step){
            return 1;
        }
    }
    return 0;
}

int verif_lig(unsigned long int n, int step){
    int first = (step/8)*8;
    int last = first + 7;

    for (size_t i = first; i < last; i++){
        if(bit_value_ULI(n, i) == 1 && i != step){
            return 1;
        }
    }
    return 0;
}

int verif_dia(unsigned long int n, int step){
    for(int i = step + 9; i < 64; i+=9){
        if(bit_value_ULI(n, i) == 1){
            return 1;
        }
        if(i%8 == 0 || i > 63){
            break;
        }
    }
    for(int i = step - 9; i >= 0; i-=9){
        if(bit_value_ULI(n, i) == 1){
            return 1;
        }
        if(i%8 == 7 || i < 0){
            break;
        }
    }
    for(int i = step + 7; i < 64; i+=7){
        if(bit_value_ULI(n, i) == 1){
            return 1;
        }
        if(i%8 == 7 || i > 63){
            break;
        }
    }
    for(int i = step - 7; i >= 0; i-=7){
        if(bit_value_ULI(n, i) == 1){
            return 1;
        }
        if(i%8 == 0 || i < 0){
            break;
        }
    }
}


int is_valid(unsigned long int n, int step){
    if(bit_value_ULI(n, step) == 1){
        return 0;
    }
    else if(verif_col(n, step) == 1){
        return 0;
    }
    else if(verif_lig(n, step) == 1){
        return 0;
    }
    else if(verif_dia(n, step) == 1){
        return 0;
    }
    return 1;
}

int is_over(unsigned long int n){
    for(int i = 0; i < 64; i++){
        if(is_valid(n, i) == 1){
            return 0;
        }
    }
    return 1;
}