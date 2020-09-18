#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>
void black(uint8_t * pixelbuffer, int i) {
   pixelbuffer[i] = 0;
   pixelbuffer[i + 1] = 0;
   pixelbuffer[i + 2] = 0;
}

void  yellow(uint8_t *pixelbuffer, int i)
{
    pixelbuffer[i]=0;
    pixelbuffer[i+1]=255;
    pixelbuffer[i+2]=255;
}

void orange(uint8_t *pixelbuffer,int i)
{
    pixelbuffer[i]=0;
    pixelbuffer[i+1]=140;
    pixelbuffer[i+2]=255;
}

void pink(uint8_t *pixelbuffer,int i)
{
    pixelbuffer[i]=255;
    pixelbuffer[i+1]=0;
    pixelbuffer[i+2]=255;
}

void  white(uint8_t *pixelbuffer,int i)
{
    pixelbuffer[i]=255;
    pixelbuffer[i+1]=255;
    pixelbuffer[i+2]=255;
}

void blue(uint8_t *pixelbuffer, int i)
{
    pixelbuffer[i]=255;
    pixelbuffer[i+1]=0;
    pixelbuffer[i+2]=0;
}
void red(uint8_t *pixelbuffer, int i)
{
    pixelbuffer[i]=0;
    pixelbuffer[i+1]=0;
    pixelbuffer[i+2]=255;
}
void green(uint8_t *pixelbuffer, int i)
{
    pixelbuffer[i]=0;
    pixelbuffer[i+1]=255;
    pixelbuffer[i+2]=0;
}
void purple(uint8_t *pixelbuffer, int i)
{
    pixelbuffer[i]=255;
    pixelbuffer[i+1]=0;
    pixelbuffer[i+2]=130;
}

