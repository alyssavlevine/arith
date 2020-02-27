#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "uarray2.h"
#include "assert.h"
#include "pnm.h"


float calculate_Y(Pnm_rgb rgb);
float calculate_Pb(Pnm_rgb rgb);
float calculate_Pr(Pnm_rgb rgb);
unsigned int calculate_r(Pnm_rgb rgb);
unsigned int calculate_g(Pnm_rgb rgb);
unsigned int calculate_b(Pnm_rgb rgb);
void color_to_bw(int i, int j, UArray2_T arr, void *elem, void *cl);
void bw_to_color(int i, int j, UArray2_T arr, void *elem, void *cl);
void rgb_to_cv(Pnm_ppm p);
void cv_to_rgb(Pnm_ppm p);
