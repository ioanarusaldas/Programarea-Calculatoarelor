//Savu Ioana Rusalda
//315CB

#include <stdio.h>
#include <stdint.h> 
#include <string.h> 
#include <malloc.h> 
#include "bmp_header.h"

// functia create_bmp seteaza fiecare camp din headerconform cerintei
bitmap * create_bmp(int height, int width) {
   int line_size;
   unsigned long _pixelbytesize;
   line_size = width * 3;

   if (line_size % 4 != 0)
      line_size += 4 - (line_size % 4);

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
// urmeaza functii pentru fiecare piesa pentru fiecare rotatie
void piece_I_90(uint8_t * pixelbuffer, int width, int height, int line_size) {
   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
          //j=j+3 trece la urmatorul pixel
         offset = i * line_size + j;
          //offset e calculat pt fiecare fixel
     //offset=(numarul_liniei_curente * latimea )+ nr_byte_de pe linia curenta

         if ((i >= 10) && (i < 20) && // linii care nu fac parte din bordura
            (j >= 10 * 3) && (j < 50 * 3)) // pixeli care nu fac parte din bordura
            blue(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);
      }
   }

}

void piece_I_180(uint8_t * pixelbuffer, int width, int height, int line_size) {
   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 50) &&
            (j >= 10 * 3) && (j < 20 * 3))
            blue(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}
void piece_I_270(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 20) &&
            (j >= 10 * 3) && (j < 50 * 3))
            blue(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);
      }
   }

}

void piece_J_90(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 20) &&
            (j >= 10 * 3) && (j < 40 * 3))
            pink(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 30) &&
            (j >= 10 * 3) && (j < 20 * 3))
            pink(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}

void piece_J_180(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 40) &&
            (j >= 10 * 3) && (j < 20 * 3))
            pink(pixelbuffer, offset);
         else
         if ((i >= 30) && (i < 40) &&
            (j >= 20 * 3) && (j < 30 * 3))
            pink(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}

void piece_J_270(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 20) && (i < 30) &&
            (j >= 10 * 3) && (j < 40 * 3))
            pink(pixelbuffer, offset);
         else
         if ((i >= 10) && (i < 20) &&
            (j >= 30 * 3) && (j < 40 * 3))
            pink(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}

void piece_L_90(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 30) &&
            (j >= 10 * 3) && (j < 20 * 3))
            orange(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 30) &&
            (j >= 20 * 3) && (j < 40 * 3))
            orange(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}
void piece_L_180(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 30) &&
            (j >= 20 * 3) && (j < 30 * 3))
            orange(pixelbuffer, offset);
         else
         if ((i >= 30) && (i < 40) &&
            (j >= 10 * 3) && (j < 30 * 3))
            orange(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}

void piece_L_270(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 20) &&
            (j >= 10 * 3) && (j < 40 * 3))
            orange(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 30) &&
            (j >= 30 * 3) && (j < 40 * 3))
            orange(pixelbuffer, offset);
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
void piece_S_90(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 30) &&
            (j >= 20 * 3) && (j < 30 * 3))
            red(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 40) &&
            (j >= 10 * 3) && (j < 20 * 3))
            red(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}

void piece_S_180(uint8_t * pixelbuffer, int width, int height, int line_size) {

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

void piece_S_270(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 30) &&
            (j >= 20 * 3) && (j < 30 * 3))
            red(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 40) &&
            (j >= 10 * 3) && (j < 20 * 3))
            red(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}

void piece_T_90(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 40) &&
            (j >= 20 * 3) && (j < 30 * 3))
            purple(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 30) &&
            (j >= 10 * 3) && (j < 20 * 3))
            purple(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}

void piece_T_180(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 20) &&
            (j >= 10 * 3) && (j < 40 * 3))
            purple(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 30) &&
            (j >= 20 * 3) && (j < 30 * 3))
            purple(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}

void piece_T_270(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 40) &&
            (j >= 10 * 3) && (j < 20 * 3))
            purple(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 30) &&
            (j >= 20 * 3) && (j < 30 * 3))
            purple(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}
void piece_Z_90(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 30) &&
            (j >= 10 * 3) && (j < 20 * 3))
            green(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 40) &&
            (j >= 20 * 3) && (j < 30 * 3))
            green(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}
void piece_Z_180(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

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

void piece_Z_270(uint8_t * pixelbuffer, int width, int height, int line_size) {

   int i, j, offset;

   for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
         offset = i * line_size + j;

         if ((i >= 10) && (i < 30) &&
            (j >= 10 * 3) && (j < 20 * 3))
            green(pixelbuffer, offset);
         else
         if ((i >= 20) && (i < 40) &&
            (j >= 20 * 3) && (j < 30 * 3))
            green(pixelbuffer, offset);
         else
            white(pixelbuffer, offset);

      }
   }

}
void generate(int height, int width, char P, int rotation) {
   char FileName[255] = {0};
   sprintf(FileName, "piesa_%c_%d.bmp", P, rotation);
   FILE * fp = fopen(FileName, "wb");
    //se deschide fisierul
   //sprintf genereaza numele pt fiecare piesa

   int line_size = width * 3;

   if (line_size % 4 != 0)
      line_size += 4 - (line_size % 4);
   int _pixelbytesize = height * line_size;
   uint8_t * pixelbuffer = calloc(_pixelbytesize, sizeof(uint8_t));
   bitmap * WorkingBitmap = (bitmap * ) calloc(1, sizeof(bitmap));
   WorkingBitmap = create_bmp(height, width);

   fwrite(WorkingBitmap, 1, sizeof(bitmap), fp);
    //se scrie header-ul in fisier

   switch (P) {
   case 'O':
      {

         piece_O(pixelbuffer, width, height, line_size);

      }

      break;

   case 'I':
      {
         if (rotation == 90)
            piece_I_90(pixelbuffer, width, height, line_size);
         if (rotation == 180)
            piece_I_180(pixelbuffer, width, height, line_size);
         if (rotation == 270)
            piece_I_270(pixelbuffer, width, height, line_size);
      }

      break;

   case 'L':
      {
         if (rotation == 90)
            piece_L_90(pixelbuffer, width, height, line_size);
         if (rotation == 180)
            piece_L_180(pixelbuffer, width, height, line_size);
         if (rotation == 270)
            piece_L_270(pixelbuffer, width, height, line_size);
      }
      break;

   case 'J':
      {
         if (rotation == 90)
            piece_J_90(pixelbuffer, width, height, line_size);
         if (rotation == 180)
            piece_J_180(pixelbuffer, width, height, line_size);
         if (rotation == 270)
            piece_J_270(pixelbuffer, width, height, line_size);
      }

      break;

   case 'S':
      {
         if (rotation == 90)
            piece_S_90(pixelbuffer, width, height, line_size);
         if (rotation == 180)
            piece_S_180(pixelbuffer, width, height, line_size);
         if (rotation == 270)
            piece_S_270(pixelbuffer, width, height, line_size);
      }
      break;
   case 'T':
      {
         if (rotation == 90)
            piece_T_90(pixelbuffer, width, height, line_size);
         if (rotation == 180)
            piece_T_180(pixelbuffer, width, height, line_size);
         if (rotation == 270)
            piece_T_270(pixelbuffer, width, height, line_size);
      }
      break;
   case 'Z':
      {
         if (rotation == 90)
            piece_Z_90(pixelbuffer, width, height, line_size);
         if (rotation == 180)
            piece_Z_180(pixelbuffer, width, height, line_size);
         if (rotation == 270)
            piece_Z_270(pixelbuffer, width, height, line_size);
      }
      break;

   }

   fwrite(pixelbuffer, 1, _pixelbytesize, fp); // se scrie matricea in fisier
   fclose(fp);
   free(WorkingBitmap);
   free(pixelbuffer);
}

int main() {
//se apeleaza functia cu dimensiunile specifice fiecarei piese ,numele
   //si rotatia
   generate(30, 60, 'I', 90);
   generate(60, 30, 'I', 180);
   generate(30, 60, 'I', 270);

   generate(40, 50, 'J', 90);
   generate(50, 40, 'J', 180);
   generate(40, 50, 'J', 270);

   generate(40, 50, 'L', 90);
   generate(50, 40, 'L', 180);
   generate(40, 50, 'L', 270);

   generate(40, 40, 'O', 90);
   generate(40, 40, 'O', 180);
   generate(40, 40, 'O', 270);

   generate(50, 40, 'S', 90);
   generate(40, 50, 'S', 180);
   generate(50, 40, 'S', 270);

   generate(50, 40, 'T', 90);
   generate(40, 50, 'T', 180);
   generate(50, 40, 'T', 270);

   generate(50, 40, 'Z', 90);
   generate(40, 50, 'Z', 180);
   generate(50, 40, 'Z', 270);

   return 0;
}