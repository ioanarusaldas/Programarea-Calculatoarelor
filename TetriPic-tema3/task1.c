//Savu Ioana Rusalda
//315CB
#include <stdio.h> 
#include <stdint.h> 
#include <string.h>
#include <malloc.h> 
#include "bmp_header.h"

// functia create_bmp seteaza fiecare camp din headerconform cerintei
bitmap* create_bmp(int height, int width){
   int line_size;
  unsigned long _pixelbytesize;
   line_size = width * 3;

   if (line_size % 4 != 0)
      line_size += 4 - (line_size % 4);
   //line_size este calculat astfel incat sa fie multiplu de 4

   _pixelbytesize = height * line_size;
   bitmap * WorkingBitmap = (bitmap * ) calloc(1, sizeof(bitmap));

   WorkingBitmap -> bmp_fileheader.fileMarker1 = 'B';
   WorkingBitmap -> bmp_fileheader.fileMarker2 = 'M';
   WorkingBitmap -> bmp_fileheader.bfSize = sizeof(struct Bmp_fileheader) + 
                              sizeof(struct Bmp_infoheader) + _pixelbytesize;
   WorkingBitmap -> bmp_fileheader.imageDataOffset = 
               sizeof(struct Bmp_fileheader) + sizeof(struct Bmp_infoheader);
   WorkingBitmap -> bmp_infoheader.biSize = 40;
   WorkingBitmap -> bmp_infoheader.width = width;
   WorkingBitmap -> bmp_infoheader.height = height;
   WorkingBitmap -> bmp_infoheader.planes = 1;
   WorkingBitmap -> bmp_infoheader.bitPix = 24;
   WorkingBitmap -> bmp_infoheader.biCompression = 0;
   WorkingBitmap -> bmp_infoheader.biSizeImage = _pixelbytesize;
   WorkingBitmap -> bmp_infoheader.biXPelsPerMeter = 0;
   WorkingBitmap -> bmp_infoheader.biYPelsPerMeter = 0;
   WorkingBitmap -> bmp_infoheader.biClrUsed = 0;
   WorkingBitmap -> bmp_infoheader.biClrImportant = 0;
   return WorkingBitmap;
}
//urmatoarele functii coloreaza pixelii in functie de codul RGB
void yellow(uint8_t * pixelbuffer, int i) {
   pixelbuffer[i] = 0;
   pixelbuffer[i + 1] = 255;
   pixelbuffer[i + 2] = 255;
}

void orange(uint8_t * pixelbuffer, int i) {
   pixelbuffer[i] = 0;
   pixelbuffer[i + 1] = 140;
   pixelbuffer[i + 2] = 255;
}

void pink(uint8_t * pixelbuffer, int i) {
   pixelbuffer[i] = 255;
   pixelbuffer[i + 1] = 0;
   pixelbuffer[i + 2] = 255;
}

void white(uint8_t * pixelbuffer, int i) {
   pixelbuffer[i] = 255;
   pixelbuffer[i + 1] = 255;
   pixelbuffer[i + 2] = 255;
}

void blue(uint8_t * pixelbuffer, int i) {
   pixelbuffer[i] = 255;
   pixelbuffer[i + 1] = 0;
   pixelbuffer[i + 2] = 0;
}
void red(uint8_t * pixelbuffer, int i) {
   pixelbuffer[i] = 0;
   pixelbuffer[i + 1] = 0;
   pixelbuffer[i + 2] = 255;
}
void green(uint8_t * pixelbuffer, int i) {
   pixelbuffer[i] = 0;
   pixelbuffer[i + 1] = 255;
   pixelbuffer[i + 2] = 0;
}
void purple(uint8_t * pixelbuffer, int i) {
   pixelbuffer[i] = 255;
   pixelbuffer[i + 1] = 0;
   pixelbuffer[i + 2] = 130;
}

// urmeaza functii pentru fiecare piesa
void piece_I(uint8_t * pixelbuffer, int width, int height, int line_size) {
   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         //j=j+3 trece la urmatorul pixel
         offset = i * line_size + j;
      //offset e calculat pt fiecare fixel
     //offset=(numarul_liniei_curente * latimea )+ nr_byte_de pe linia curenta

         if ((i >= 10) && (i < 50) &&  // linii care nu fac parte din bordura
            (j >= 10 * 3) && (j < 20 * 3)) // pixeli care nu fac parte din bordura
            blue(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}

void piece_S(uint8_t * pixelbuffer, int width, int height, int line_size) {
   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 20) &&
            (j >= 10 * 3) && (j < 30 * 3))
            red(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 30) &&
            (j >= 20 * 3) && (j < 40 * 3))
            red(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}

void piece_Z(uint8_t * pixelbuffer, int width, int height, int line_size) {
   int i, j, offset;;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 20) &&
            (j >= 20 * 3) && (j < 40 * 3))
            green(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 30) &&
            (j >= 10 * 3) && (j < 30 * 3))
            green(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}

void piece_T(uint8_t * pixelbuffer, int width, int height, int line_size) {
   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 20) &&
            (j >= 20 * 3) && (j < 30 * 3))
            purple(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 30) &&
            (j >= 10 * 3) && (j < 40 * 3))
            purple(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}
void piece_O(uint8_t * pixelbuffer, int width, int height, int line_size) {
   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 30) &&
            (j >= 10 * 3) && (j < 30 * 3))
            yellow(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);
      }
   }

}

void piece_L(uint8_t * pixelbuffer, int width, int height, int line_size) {
   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 20) &&
            (j >= 10 * 3) && (j < 30 * 3))
            orange(pixelbuffer, offset);
         else

         if ((i >= 20) && (i < 40) &&
            (j >= 10 * 3) && (j < 20 * 3))
            orange(pixelbuffer, offset);
         else

            white(pixelbuffer, offset);
      }
   }

}

void piece_J(uint8_t * pixelbuffer, int width, int height, int line_size) {
   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 20) &&
            (j >= 10 * 3) && (j < 30 * 3))
            pink(pixelbuffer, offset);
         else

         if ((i >= 20) && (i < 40) &&
            (j >= 20 * 3) && (j < 30 * 3))
            pink(pixelbuffer, offset);
         else

            white(pixelbuffer, offset);
      }
   }
}
void generate(int height, int width, char P) {
   char FileName[255] = {0};
   sprintf(FileName, "piesa_%c.bmp", P);
   FILE * fp = fopen(FileName, "wb");
   //se deschide fisierul
   //sprintf genereaza numele pt fiecare piesa
 

   int line_size = width * 3;

   if (line_size % 4 != 0)
      line_size += 4 - (line_size % 4);
   int _pixelbytesize = height * line_size;
   uint8_t * pixelbuffer = calloc(_pixelbytesize, sizeof(uint8_t));
   bitmap * WorkingBitmap = (bitmap * ) calloc(1, sizeof(bitmap));
   //se aloca memorie pt matricea de pixeli
   WorkingBitmap = create_bmp(height,width);

   fwrite (WorkingBitmap, 1, sizeof(bitmap),fp);  
   //se scrie header-ul in fisier

   switch (P) {
   case 'O':
      piece_O(pixelbuffer, width, height, line_size);
      break;

   case 'I':
      piece_I(pixelbuffer, width, height, line_size);
      break;

   case 'L':
      piece_L(pixelbuffer, width, height, line_size);
      break;

   case 'J':
      piece_J(pixelbuffer, width, height, line_size);
      break;

   case 'S':
      piece_S(pixelbuffer, width, height, line_size);
      break;

   case 'Z':
      piece_Z(pixelbuffer, width, height, line_size);
      break;

   case 'T':
      piece_T(pixelbuffer, width, height, line_size);
      break;
   }

   fwrite(pixelbuffer, 1, _pixelbytesize, fp);
   //se scrie matricea in fisier
   fclose(fp);
   free(WorkingBitmap);
   free(pixelbuffer);
}

int main() {
   //se apeleaza functia cu dimensiunile specifice fiecarei piese
   generate(40, 40, 'O');

   generate(60, 30, 'I');

   generate(40, 50, 'S');

   generate(40, 50, 'Z');

   generate(50, 40, 'L');

   generate(50, 40, 'J');

   generate(40, 50, 'T');
   return 0;
}