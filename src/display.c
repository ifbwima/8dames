# include <MLV/MLV_all.h>
# include <stdlib.h>
# include <stdio.h>

# include "../include/display.h"
# include "../include/dames.h"

void create_window(){
    MLV_create_window("Dames", NULL, RES_X, RES_Y);
    int startX;
    int startY;

    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            startX = i*(RES_Y/8);
            startY = j*(RES_Y/8);

            if(i%2==0 && j%2==0){
                MLV_draw_filled_rectangle(startX, startY, RES_Y/8, RES_Y/8, MLV_COLOR_WHITE_SMOKE);
            }
            else if(i%2==1 && j%2==1){
                MLV_draw_filled_rectangle(startX, startY, RES_Y/8, RES_Y/8, MLV_COLOR_WHITE_SMOKE);
            }
            else{
                MLV_draw_filled_rectangle(startX, startY, RES_Y/8, RES_Y/8, MLV_COLOR_GRAY100);
            }
        }
    }
    
}

void display_queens(unsigned long int n){
    for (int i = 63; i>=0; i--)
    {
        if (bit_value_ULI(n, i) == 1)
        {
            MLV_draw_filled_rectangle((i%8)*RES_Y/8, (i/8)*RES_Y/8, RES_Y/8, RES_Y/8, MLV_COLOR_BLUE1);
        }
        
    }
    
}


