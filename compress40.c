#include "compress40.h"
#include "uarray2.h"
#include "a2plain.h"
#include "pnm.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "color.h"

Pnm_ppm read_in_pixels(FILE *input);
void check_dimensions(Pnm_ppm arr);

extern void decompress40(FILE *input)
{
    Pnm_ppm decompress_pixels = read_in_pixels(input);
    check_dimensions(decompress_pixels);
    return;
}
extern void compress40(FILE *input)
{
    // UArray2_T compress_pixels = read_in_pixels(input);
    // check_dimensions(compress_pixels);
    // rgb_to_cv(compress_pixels);
    Pnm_ppm compress_pixels = read_in_pixels(input);
   // Pnm_ppmwrite(stdout, compress_pixels);
    check_dimensions(compress_pixels);
    rgb_to_cv(compress_pixels);
    Pnm_ppmwrite(stdout, compress_pixels);
}

Pnm_ppm read_in_pixels(FILE *fp)
{
    A2Methods_T methods = uarray2_methods_plain;
    assert(methods);
    Pnm_ppm pic1 = Pnm_ppmread(fp, methods);
    assert(pic1);
   // Pnm_ppmwrite(stdout, pic1);
    //return UArray2_new(pic1->width, pic1->height, sizeof(Pnm_rgb));
    return pic1;
}

void check_dimensions(Pnm_ppm pic){
    // if (UArray2_width(arr) %2 != 0 && UArray2_height(arr)%2 != 0){
    //     UArray2_T trimmed_arr = UArray2_new(UArray2_width(arr) - 1, UArray2_height(arr) - 1, sizeof(Pnm_rgb));
    //     UArray2_free(&arr);
    if (pic->width % 2 != 0 && pic->height % 2 != 0){
        pic->width = pic->width - 1;
        pic->height = pic->height - 1;
        //UArray2_free(&arr);
        //return pic1;
    }
    else if(pic->width % 2 != 0){
        pic->width = pic->width - 1;
    }
    else if (pic->height % 2 != 0){
        pic->height = pic->height - 1;
    }
}
