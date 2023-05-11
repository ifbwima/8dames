# include <MLV/MLV_all.h>
# include <stdlib.h>
# include <stdio.h>

# include "../include/display.h"
# include "../include/dames.h"


int main(int argc, char *argv[]){
    int x, y, i, j, step;
    int count = 0;
    unsigned long int n = 0;

    //create window and get image
    create_window();

    while (1){
        display_queens(n);
        MLV_actualise_window();

        MLV_wait_mouse(&x,&y);

        if(x<=RES_Y && y<=RES_Y){
            MLV_draw_filled_rectangle(RES_Y+10, 10, 200, 20, MLV_COLOR_BLACK);

            i = (int) x/(RES_Y/8);
            j = (int) y/(RES_Y/8);

            step = (j*8)+i;

            set_positive_bit_ULI(&n, step);
            count++;

            if(is_valid(n, step) == 0){
                MLV_draw_text(RES_Y+10, 10, "et merde", MLV_COLOR_RED);
            }
            else{
                if(count == 8){
                    MLV_draw_text(RES_Y+10, 10, "et c'est gagné", MLV_COLOR_GREEN);
                }
                else if(is_over(n) == 1){
                    MLV_draw_text(RES_Y+10, 10, "et c'est perdu", MLV_COLOR_RED);
                }
                else{
                    MLV_draw_text(RES_Y+10, 10, "et c'est pas fini", MLV_COLOR_BLACK);
                }
            }
        }
    }
    
    MLV_free_window();

    return 0;
}