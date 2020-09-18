//Savu Ioana Rusalda
//315CB

#include <stdio.h>
#include <stdint.h> 
#include <string.h> 
#include <malloc.h> 
#include "bmp_header.h"
#include "color.h"
#include "piece.h"

//functia map genereaza harta fara piese pe acelasi principiu de la 
  //generarea pieselor din celelalte task-uri
void map(uint8_t * pixelbuffer, int height, int width, int line_size) {
  int i, j, offset;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width * 3; j = j + 3) {

      offset = i * line_size + j;

      if ((i >= 0) && (i < height - 40) &&
        (j >= 0 * 3) && (j < width * 3))

        break;

      else

        white(pixelbuffer, offset);

    }
  }
}

// functia create_bmp seteaza fiecare camp din header conform cerintei

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

int main() {

  int nrpiece, width1, height1, i, width, height;
  int rotation[1000], col[100];
  char name[1000][1000];
  //se citeste din fisier
  FILE * file = fopen("cerinta3.in", "rt");
  fscanf(file, "%d", & nrpiece);
  fscanf(file, "%d", & height1);
  fscanf(file, "%d", & width1);
 
  for (i = 0; i < nrpiece; i++) {

    fscanf(file, "%s", name[i]);
    fscanf(file, "%d", & rotation[i]);
    fscanf(file, "%d", & col[i]);
   

  }

  width = width1 * 10;  //se calculeaza latimea hartii
  height = (height1 + 4) * 10; //se calculeaza lungimea hartii

  FILE * fp = fopen("task3.bmp", "wb");

  int line_size = width * 3;

  if (line_size % 4 != 0)
    line_size += 4 - (line_size % 4);
  int _pixelbytesize = height * line_size;
  uint8_t * pixelbuffer = calloc(_pixelbytesize, sizeof(uint8_t));
  bitmap * WorkingBitmap = (bitmap * ) calloc(1, sizeof(bitmap));

  WorkingBitmap = create_bmp(height, width);

  map(pixelbuffer, height, width, line_size);//creeaza harta fara piese

  fwrite(WorkingBitmap, 1, sizeof(bitmap), fp);
//se adauga fiecare piesa in functie de coloana unde trebuie pozitionata,
  //rotatie si numele piesei.


  //functiile raman aceleasi ca la taskuri-le precedente modificand doar pozitia
        //in care urmeaza sa fie plasata piesa si nu se mai genereaza
            //bordura alba
  for (i = 0; i < nrpiece; i++) {
    switch (name[i][0]) {
    case 'I':
      {
        if (rotation[i] == 90)
          piece_I_90(pixelbuffer, height, width, line_size, col[i]);
        if (rotation[i] == 0)
          piece_I_0(pixelbuffer, height, width, line_size, col[i]);
        if (rotation[i] == 270)
          piece_I_270(pixelbuffer, height, width, line_size, col[i]);

      }
      break;
    case 'L':
      if (rotation[i] == 0)
        piece_L_0(pixelbuffer, height, width, line_size, col[i]);
      break;
    case 'S':
      {
        if (rotation[i] == 90)
          piece_S_90(pixelbuffer, height, width, line_size, col[i]);
        if (rotation[i] == 0)
          piece_S_0(pixelbuffer, height, width, line_size, col[i]);
      }
      break;
    case 'T':
      if (rotation[i] == 270)
        piece_T_270(pixelbuffer, height, width, line_size, col[i]);
      break;
    case 'Z':
      if (rotation[i] == 90)
        piece_Z_90(pixelbuffer, height, width, line_size, col[i]);
      break;
    case 'J':
      if (rotation[i] == 270) {

        piece_J_270(pixelbuffer, height, width, line_size, col[i]);
       
      }
      break;
    case 'O':
      {

        piece_O(pixelbuffer, height, width, line_size, col[i]);
      }
      break;

    }
  }
  //se scrie vectorul in fisier

  fwrite(pixelbuffer, 1, _pixelbytesize, fp);

  fclose(fp);

  free(WorkingBitmap);
  free(pixelbuffer);

  fclose(file);
  return 0;

}