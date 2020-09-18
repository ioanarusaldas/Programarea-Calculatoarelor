//Savu Ioana Rusalda
//315CB

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trwhitespace(char *str)
{
  int index, i;
  index = -1;
  i = 0;
  while (str[i] != '\0')
  {
    if ((str[i] != ' ') && (str[i] != '\t') && (str[i] != '\n'))
      index = i;
    i++;
  }

  str[index + 1] = '\n';
  str[index + 2] = '\0';
}

void wrap(int max, int original_line_count, int nr[100][100],
  char original[1000][1000], char result[1000][1000])
{
  int i, j, ok = 1, y = 0, poz, sum = 0, m = 0, n = 0;
  char wrapp[1000][1000];
  for (i = 0; i < original_line_count; i++)
    for (j = 0;; j++)
    {
      if (original[i][j] != '\0')
      {
        if (ok == 1)
        {
          //se adauga la suma lungimea cuvintelor pana la maximul stabilit
          sum = sum + nr[i][y] + 1;
          poz = j;
          ok = 0;
        }

        //se adauga caracter cu caracter fiecare cuvant care respecta conditia
        if (sum < max)
        {
          wrapp[m][n] = original[i][j];
          n++;
          if ((j - poz) == nr[i][y])
          {
            ok = 1;
            y++;
          }
        }
        else
        {
          wrapp[m][n + 1] = '\0';
          m++;
          n = 0;
          sum = 0;
          ok = 1;
          j--;
        }
      }
      else
        break;
    }

  original_line_count = m;
  for (i = 0; i < original_line_count; i++)
    for (j = 0;; j++)
    {
      //se trece rezulatul in matrixa result
      original[i][j] = wrapp[i][j];
      if (wrapp[i][j] == '\0')
      {
        break;
      }
    }
}

void alignleft(int start_line, int end_line, char original[1000][1000])
{
  int i, j, nrspaces;
  for (i = start_line; i <= end_line; i++)
  {
    nrspaces = 0;
    for (j = 0;; j++)
    {
      if (original[i][j] == ' ')
        nrspaces++;
      else
        break;
    }

    for (j = 0; j < 1000; j++)
      original[i][j] = original[i][j + nrspaces];
  }
}

void alignright(int start_line, int end_line, int maxlen, 
  char original[1000][1000], int original_line_count)
{
  int i, j, k, sp = 0;
  int min = end_line;
  if (original_line_count < end_line)
    min = original_line_count;
  for (i = start_line; i <= min; i++)
  {
    k = maxlen;
    if (strlen(original[i]) != 1) //ignora liniile goale
    {
      for (j = strlen(original[i]); j >= 0; j--)
      {
        if (j == 0)
        {
          sp = j - 1;
        } //fiecare caracter este mutat la dreapta
        original[i][k] = original[i][j];
        k--;
      }

      if (sp < 0)
      {
        while (k >= 0)
        {
          //se adauga spatii pana linia ajunge la dimeniunea liniei maxime
          original[i][k] = ' ';
          k--;
        }
      }
    }
  }
}

void centre(int start_line, int end_line, char original[1000][1000], int maxlen)
{
  int i, j, add, spacesadd, k;
  alignleft(start_line, end_line, original);
  for (i = start_line; i <= end_line; i++)
  {
    if (original[i][0] != '\n')
    {
      //calculeaza cate spatii sunt necesare pentru ca 
      //linia sa ajunga la dimenisunea maxima
      k = strlen(original[i]);
      spacesadd = maxlen - k;
      if (spacesadd % 2 == 0)
        add = spacesadd / 2;
      else
        add = (spacesadd / 2) + 1;
      while (add != 0)
      {
        //se muta caracterele la dreapta si se adauga spatii
        for (j = strlen(original[i]); j >= 0; j--)
          original[i][j + 1] = original[i][j];
        original[i][0] = ' ';
        add = add - 1;
      }
    }
  }
}

void paragraph(int ident_lenght, int start_line, int end_line,
  char original[1000][1000])
{
  int i, j, ident;
  for (i = start_line; i <= end_line; i++)
  {
    ident = ident_lenght;
    if (original[i - 1][0] == '\n')
    {
      while (ident != 0)
      {
        for (j = strlen(original[i]); j >= 0; j--)
          original[i][j + 1] = original[i][j];
        original[i][0] = ' ';
        ident--;
      }
    }

    if (i == 0)
      while (ident != 0)
      {
        for (j = strlen(original[i]); j >= 0; j--)
          original[i][j + 1] = original[i][j];
        original[i][0] = ' ';
        ident--;
      }
  }
}

void list(char type, char character, int start_line,
  int end_line, char original[1000][1000])
{
  //se abordeaza fiecare tip de lista 
  int i, j, nr = 1, aux = 0, aux2 = 1;
  char contor, Contor;
  contor = 'a';
  Contor = 'A';
  alignleft(start_line, end_line, original);
  for (i = start_line; i <= end_line; i++)
  {
    if (type == 'b')
    {
      for (j = strlen(original[i]); j >= 0; j--)
        original[i][j + 2] = original[i][j];
      original[i][1] = ' ';
      original[i][0] = character;
    }

    if (type == 'a')
    {
      for (j = strlen(original[i]); j >= 0; j--)
        original[i][j + 3] = original[i][j];
      original[i][2] = ' ';
      original[i][1] = character;
      original[i][0] = contor;
      contor++;
    }

    if (type == 'A')
    {
      for (j = strlen(original[i]); j >= 0; j--)
        original[i][j + 3] = original[i][j];
      original[i][2] = ' ';
      original[i][1] = character;
      original[i][0] = Contor;
      Contor++;
    }

    if (type == 'n')
    {
      if (nr > 9)
      {
        for (j = strlen(original[i]); j >= 0; j--)
          original[i][j + 4] = original[i][j];
        original[i][3] = ' ';
        original[i][2] = character;
        original[i][1] = aux + '0';
        original[i][0] = aux2 + '0';
        aux++;
        if (aux == 9)
        {
          aux2 = 1;
        }
      }
      else
      {
        for (j = strlen(original[i]); j >= 0; j--)
          original[i][j + 3] = original[i][j];
        original[i][2] = ' ';
        original[i][1] = character;
        original[i][0] = nr + '0';
        nr++;
      }
    }
  }
}

void ordlist(char type, char character, char order, int start_line,
  int end_line, char original[1000][1000])
{
  //se abordeaza ambele tipuri de sortare 
  int i, j, k;
  char aux;
  if (order == 'a')
  {
    for (i = start_line; i <= end_line; i++)
      for (k = i + 1; k <= end_line; k++)
      {
        if (strcmp(original[i], original[k]) > 0)
          for (j = 0; j <= 100; j++)
          {
            aux = original[i][j];
            original[i][j] = original[k][j];
            original[k][j] = aux;
          }
      }
  }
  else
  {
    for (i = start_line; i <= end_line; i++)
      for (k = i + 1; k <= end_line; k++)
      {
        if (strcmp(original[i], original[k]) < 0)
          for (j = 0; j <= 100; j++)
          {
            aux = original[i][j];
            original[i][j] = original[k][j];
            original[k][j] = aux;
          }
      }
  }

  list(type, character, start_line, end_line, original);
}

int main(int argc, char *argv[])
{
  char buf[1000], // buffer folosit pentru citirea din fisier
    original[1000][1000],
    copy[1000][1000], // originalcontine textul original line cu linie
    result[1000][1000]; // text obtinut dupa aplicarea operatiilor
  int original_line_count = 0,  // numarul de linii din input
    result_line_count = 0;  // numarul de linii din output
  int i;
  if (argc != 4)
  {
    //numar invalid de argumente
    fprintf(stderr,
      "Usage: %s operations_string input_file output_file\n",
      argv[0]);
    return -1;
  }

  // deschide fisier intrare
  FILE *input_file = fopen(argv[2], "r");
  if (input_file == NULL)
  {
    fprintf(stderr, "File \"%s\" not found\n", argv[2]);
    return -2;
  }

  // citire linie cu linie
  while (fgets(buf, 1000, input_file))
  {
    strcpy(original[original_line_count], buf);
    original_line_count++;
  }

  fclose(input_file);
  //se realizeaza o copie a textului 
  for (i = 0; i < original_line_count; i++)
    strcpy(copy[i], original[i]);

  int maxlen, len[100], space, j, wordlen = 0, nr[100][100], y = 0;
  for (i = 0; i < original_line_count; i++)
  {
    //se calculeaza lungimile cuvintelor si sunt salvate intr-o matrice
    wordlen = 0;
    y = 0;
    space = 0;
    for (j = 0;; j++)
    {
      if (original[i][j] != ' ')
      {
        wordlen++;
      }
      else
      {
        //nr[i][y]=wordlen;
        wordlen = 0;
        y++;
      }

      if (original[i][j] == '\n')
      {
        //nr[i][y]=wordlen;
      }

      if (original[i][j] == '\0')
      {
        //len salveaza lungimile liniilor
        len[i] = strlen(original[i]);
        break;
      }
    }
  }

  maxlen = len[0];  //maxlen salveaza lungimea liniei maxime
  for (i = 0; i < original_line_count; i++)
    if (len[i] > maxlen)
      maxlen = len[i];
  char temp_line[1000];
  for (i = 0; i < original_line_count; i++)
  {
    strcpy(temp_line, original[i]);
    trwhitespace(temp_line);
    strcpy(original[i], temp_line);
    len[i] = strlen(original[i]);
  }

  //argumentele comenzii sunt separate prin virgula,
  //apoi prin spatiu si salvate intr-o matrice cu 3 coloane
  char *z, matrix[10][100][6], *t, *v[100];
  z = strtok(argv[1], ",");
  int k = 0, n, b = 0;
  while (z != NULL)
  {
    v[k] = z;
    k++;
    z = strtok(NULL, ",");
  }

  for (n = 0; n < k; n++)
  {
    b = 0;
    t = strtok(v[n], " ");
    while (t != NULL)
    {
      strcpy(matrix[n][b], t);
      b++;
      t = strtok(NULL, " ");
    }
  }

  int ok = 0;
  char *ptr;
  //strtol converteste caracterul in numar in baza 10
  for (i = 0; i < n; i++)
    switch (matrix[i][0][0])
    {
      //case 'W': case 'w':
      //wrap(max, original_line_count, nr,
      //original, result);
      //break;
      case 'L':
      case 'l':
        if (matrix[i][1][0] == '\0')
          alignleft(0, original_line_count, original);
        else
        if (matrix[i][2][0] == '\0')
          alignleft(strtol(matrix[i][1], &ptr, 10), original_line_count, original);
        else
          alignleft(strtol(matrix[i][1], &ptr, 10),
            strtol(matrix[i][2], &ptr, 10), original);
        break;

      case 'R':
      case 'r':
        if (matrix[i][1][0] == '\0')
          alignright(0, original_line_count, maxlen,
            original, original_line_count);
        else
        if (matrix[i][2][0] == '\0')
          alignright(strtol(matrix[i][1], &ptr, 10), original_line_count,
            maxlen, original, original_line_count);
        else
          alignright(strtol(matrix[i][1], &ptr, 10), 
            strtol(matrix[i][2], &ptr, 10), maxlen, 
              original, original_line_count);
        break;

      case 'C':
      case 'c':
        if (matrix[i][1][0] == '\0')
          centre(0, original_line_count, original, maxlen);
        else
        if (matrix[i][2][0] == '\0')
          centre(strtol(matrix[i][1], &ptr, 10),
            original_line_count, original, maxlen);
        else
          centre(strtol(matrix[i][1], &ptr, 10),
            strtol(matrix[i][2], &ptr, 10), original, maxlen);
        break;

      case 'P':
      case 'p':
        if (matrix[i][2][0] == '\0')
          paragraph(strtol(matrix[i][1], &ptr, 10), 0, 
            original_line_count, original);
        else
        if (matrix[i][3][0] == '\0')
          paragraph(strtol(matrix[i][1], &ptr, 10),
            strtol(matrix[i][2], &ptr, 10), original_line_count, original);
        else
          paragraph(strtol(matrix[i][1], &ptr, 10),
            strtol(matrix[i][2], &ptr, 10),
            strtol(matrix[i][3], &ptr, 10), original);
        break;

      case 'I':
      case 'i':
        if (matrix[i][3][0] == '\0')
          list(matrix[i][1][0], matrix[i][2][0], 0,
            original_line_count, original);
        else
        if (matrix[i][4][0] == '\0')
          list(matrix[i][1][0], matrix[i][2][0],
            strtol(matrix[i][3], &ptr, 10),
            original_line_count, original);
        else
          list(matrix[i][1][0], matrix[i][2][0],
            strtol(matrix[i][3], &ptr, 10),
            strtol(matrix[i][4], &ptr, 10), original);
        break;

      case 'O':
      case 'o':
        if (matrix[i][4][0] == '\0')
          ordlist(matrix[i][1][0], matrix[i][2][0], matrix[i][3][0], 
            0, original_line_count, original);
        else
        if (matrix[i][5][0] == '\0')
          ordlist(matrix[i][1][0], matrix[i][2][0],
            matrix[i][3][0], strtol(matrix[i][4], &ptr, 10),
            original_line_count, original);
        else
          ordlist(matrix[i][1][0], matrix[i][2][0],
            matrix[i][3][0], strtol(matrix[i][4], &ptr, 10),
            strtol(matrix[i][5], &ptr, 10), original);
        break;

      case 'J':
      case 'j':
        break;
      default:
        {
          printf("Invalid operation!\n");
          ok = 1;
        }
    }


  for (i = 0; i < original_line_count; i++)
  {
    // daca exista erori nu se efectueaza transformari asupra textului
    if (ok == 1)
      strcpy(result[i], copy[i]);
    else
      strcpy(result[i], original[i]);
  }

  result_line_count = original_line_count;
  // deschidere fisier output
  FILE *output_file = fopen(argv[3], "w");
  if (output_file == NULL)
  {
    fprintf(stderr, "Could not open or create file \"%s\"\n", argv[3]);
    return -2;
  }

  // scriere in fisier de iesire
  for (i = 0; i < result_line_count; i++)
  {
    fputs(result[i], output_file);
  }

  fclose(output_file);
}