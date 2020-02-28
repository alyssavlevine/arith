#include "color.h"
#include "uarray2.h"
//red = Y, green = pb, blue = pr



float calculate_Y(Pnm_rgb rgb)
{
  float y = (0.299 * rgb->red) + (0.587 * rgb->green) + (0.114 * rgb->blue);
  return y;
}

float calculate_Pb(Pnm_rgb rgb)
{
    float pb = (-0.168736 * rgb->red) - (0.331264 * rgb->green) + (0.5 * rgb->blue);
    return pb;
}

float calculate_Pr(Pnm_rgb rgb)
{
    float pr = (0.5 * rgb->red) - (0.418688 * rgb->green) - (0.081312 * rgb->blue);
    return pr;

}

unsigned int calculate_r(Pnm_rgb rgb)
{
    //red = Y, green = pb, blue = pr
    unsigned int r = 1.0 * (rgb->red) + 0.0 * (rgb->blue) + 1.402 * (rgb->green);
    return r;

}
unsigned int calculate_g(Pnm_rgb rgb)
{
    unsigned int g = 1.0 * (rgb->red) - 0.344136 * (rgb->green) - 0.714136 * (rgb->blue);
    return g;
}
unsigned int calculate_b(Pnm_rgb rgb)
{
    unsigned int b = 1.0 * (rgb->red) + 1.772 * (rgb->green) + 0.0 * (rgb->blue);
    return b;
}

void color_to_bw(int i, int j, A2Methods_Object *arr, void *elem, void *cl)
{
    (void) elem;
    (void) cl;
    Pnm_rgb rgbValues = UArray2_at(arr, i, j);
    rgbValues->red = calculate_Y(rgbValues);
    rgbValues->green = calculate_Pb(rgbValues);
    rgbValues->blue = calculate_Pr(rgbValues);
}

void bw_to_color(int i, int j, A2Methods_Object *arr, void *elem, void *cl)
{
    (void) elem;
    (void) cl;
    Pnm_rgb rgbValues = UArray2_at(arr, i, j);
    rgbValues->red = calculate_r(rgbValues);
    rgbValues->green = calculate_g(rgbValues);
    rgbValues->blue = calculate_b(rgbValues);
}

void rgb_to_cv(Pnm_ppm p)
{
  p->methods->map_row_major(p->pixels, color_to_bw, NULL);
}


void cv_to_rgb(Pnm_ppm p)
{
    p->methods->map_row_major(p->pixels, bw_to_color, NULL);
}
