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
    int haut_gauche = step-9;
    int haut_droit = step-7;
    int bas_gauche = step+7;
    int bas_droit = step+9;

    while((haut_gauche%8!=0 || haut_gauche == 0) && haut_gauche>=0){
        if(bit_value_ULI(n, haut_gauche) == 1){
            return 1;
        }
        haut_gauche-=9;
    }

    while(haut_droit%8!=0 && haut_droit>=0){
        if(bit_value_ULI(n, haut_droit) == 1){
            return 1;
        }
        haut_droit-=7;
    }

    while(bas_gauche%9!=7 && bas_gauche<64){
        if(bit_value_ULI(n, bas_gauche) == 1){
            return 1;
        }
        bas_gauche+=7;
    }

    while(bas_droit%9!=7 && bas_droit<64){
        if(bit_value_ULI(n, bas_droit) == 1){
            return 1;
        }
        bas_droit+=9;
    }

    return 0;
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