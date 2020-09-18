#include <stdio.h>
#include <stdint.h> 
#include <string.h> 
#include <malloc.h>

  void piece_I_90(uint8_t * pixelbuffer, int width, int height, int line_size, int col) {
    int i, j, offset;

    for (i = 0; i < height; i++) {
      for (j = 0; j < width * 3; j = j + 3) {
        offset = i * line_size + j;

        if ((i >= 0) && (i < 10) &&
          (j >= col * 10 * 3) && (j < (col + 4) * 10 * 3))
          blue(pixelbuffer, offset);

      }
    }

  }
void piece_L_0(uint8_t * pixelbuffer, int width, int height, int line_size, int col) {
  int i, j, offset;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width * 3; j = j + 3) {
      offset = i * line_size + j;

      if ((i >= 0) && (i < 10) &&
        (j >= col * 10 * 3) && (j < (col + 2) * 10 * 3))
        orange(pixelbuffer, offset);
      else

      if ((i >= 10) && (i < 30) &&
        (j >= col * 10 * 3) && (j < (col + 1) * 10 * 3))
        orange(pixelbuffer, offset);

    }
  }

}
void piece_S_90(uint8_t * pixelbuffer, int width, int height, int line_size, int col) {

  int i, j, offset;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width * 3; j = j + 3) {
      offset = i * line_size + j;

      if ((i >= 0) && (i < 20) &&
        (j >= (col + 1) * 10 * 3) && (j < (col + 2) * 10 * 3))
        red(pixelbuffer, offset);
      else
      if ((i >= 10) && (i < 30) &&
        (j >= col * 10 * 3) && (j < (col + 1) * 10 * 3))
        red(pixelbuffer, offset);

    }
  }

}
void piece_T_270(uint8_t * pixelbuffer, int width, int height, int line_size, int col) {

  int i, j, offset;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width * 3; j = j + 3) {
      offset = i * line_size + j;

      if ((i >= 0) && (i < 30) &&
        (j >= col * 10 * 3) && (j < (col + 1) * 10 * 3))
        purple(pixelbuffer, offset);
      else
      if ((i >= 10) && (i < 20) &&
        (j >= (col + 1) * 10 * 3) && (j < (col + 2) * 10 * 3))
        purple(pixelbuffer, offset);

    }
  }

}
void piece_Z_90(uint8_t * pixelbuffer, int width, int height, int line_size, int col) {

  int i, j, offset;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width * 3; j = j + 3) {
      offset = i * line_size + j;

      if ((i >= 0) && (i < 20) &&
        (j >= col * 10 * 3) && (j < (col + 1) * 10 * 3))
        green(pixelbuffer, offset);
      else
      if ((i >= 10) && (i < 30) &&
        (j >= (col + 1) * 10 * 3) && (j < (col + 2) * 10 * 3))
        green(pixelbuffer, offset);

    }
  }

}
void piece_O(uint8_t * pixelbuffer, int width, int height, int line_size, int col) {

  int i, j, offset;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width * 3; j = j + 3) {
      offset = i * line_size + j;

      if ((i >= 0) && (i < 20) &&
        (j >= col * 10 * 3) && (j < (col + 2) * 10 * 3))
        yellow(pixelbuffer, offset);

    }
  }

}
void piece_J_270(uint8_t * pixelbuffer, int width, int height, int line_size, int col) {

  int i, j, offset;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width * 3; j = j + 3) {
      offset = i * line_size + j;

      if ((i >= 0) && (i < 10) &&
        (j >= (col + 2) * 10 * 3) && (j < (col + 3) * 10 * 3)) {
        pink(pixelbuffer, offset);
      } else
      if ((i >= 10) && (i < 20) &&
        (j >= col * 10 * 3) && (j < (col + 3) * 10 * 3))
        pink(pixelbuffer, offset);

    }
  }
}

void piece_S_0(uint8_t * pixelbuffer, int width, int height, int line_size, int col) {
  int i, j, offset;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width * 3; j = j + 3) {
      offset = i * line_size + j;

      if ((i >= 0) && (i < 10) &&
        (j >= col * 10 * 3) && (j < (col + 2) * 10 * 3))
        red(pixelbuffer, offset);
      else
      if ((i >= 10) && (i < 20) &&
        (j >= (col + 1) * 10 * 3) && (j < (col + 3) * 10 * 3))
        red(pixelbuffer, offset);

    }
  }

}
void piece_I_0(uint8_t * pixelbuffer, int width, int height, int line_size, int col) {
  int i, j, offset;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width * 3; j = j + 3) {

      offset = i * line_size + j;

      if ((i >= 0) && (i < 40) &&
        (j >= col * 10 * 3) && (j < (col + 1) * 10 * 3))
        blue(pixelbuffer, offset);

    }
  }

}
void piece_I_270(uint8_t * pixelbuffer, int width, int height, int line_size, int col) {

  int i, j, offset;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width * 3; j = j + 3) {
      offset = i * line_size + j;

      if ((i >= 0) && (i < 10) &&
        (j >= col * 10 * 3) && (j < (col + 4) * 10 * 3))
        blue(pixelbuffer, offset);

    }
  }

}