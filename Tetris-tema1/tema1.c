//Nume: Savu Ioana Rusalda
//Grupa: 315CB

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//printmap e functia care afiseaza harta
void printmap(unsigned long long int h)
{
	unsigned long long int mask1 = 1, mask;
	int i, nr = 0;
	for (i = 63; i >= 0; i--)
	{
		mask = mask1 << i;
		if ((mask & h) != 0)
			printf("#");
		else printf(".");
		nr++;
		if (nr % 8 == 0)
			printf("\n");
		if (i == 0)
			break;
	}
	printf("\n");
}

//movedown muta piesa in jos pe harta
unsigned long long int movedown(unsigned long long int piece, int j)
{
	return (unsigned long long int) piece << (8 * (j - 1));
}

//rightcollision face coliziunea cu peretele din dreapta al hartii

int rightcollision(int piece)
{
	int mask = 257;
	if ((mask & piece) != 0)
		return 1;
	return 0;

}

//leftcollision face coliziunea cu peretele din stanga al hartii
int leftcollision(int piece)
{
	int mask = 32896;
	if ((mask & piece) != 0)
		return 1;
	return 0;

}
//collision face coliziunea intre piese si harta
int collision(unsigned long long int piece, unsigned long long int map)
{
	if ((piece & map) != 0)
		return 1;
	return 0;
}

//deleteline face eliminarea liniei complete
unsigned long long int deleteline(unsigned long long int map, int pozition)
{
	unsigned long long int up, down;
	up = map >> 8 * (9 - pozition);
	down = map << 8 * pozition;
	down = down >> 8 * pozition;
	if (pozition == 8)
		down = 0;
	map = (up << 8 * (8 - pozition)) | down;
	return map;
}

//score calculeaza scorul
void score(int zeroNr, int completedLine)
{
	float score_points;
	score_points = sqrt(zeroNr) + pow(1.25, completedLine);
	printf("%.2f", score_points);
}

int main()
{
	unsigned long long int h, maskrow = 255, maskrow1, maskbit = 1, maskbit1;
	unsigned long long int hinterim, piecepozition1, map;
	int i, piece, moves, j, m, skip = 0, newpiece, k, zeroNr = 0;
	int delete = 0, p, completedLine = 0, pozition, l, t;
	scanf("%llu ", &h);	//h este harta initiala
	map = h;
	scanf("%d ", &m);	//m reprezinta numarul de mutari
	printmap(h);
	for (i = m; i > 0; i--)	//acesta este for-ul care parcurge piesele
	{
		if (skip != 0)	//skip ajuta la citirea mutarilor ce nu se mai pot realiza
		{
			while (skip != 0)
			{
				scanf("%d", &moves);	//moves reprezinta mutarea piesei
				skip--;
			}
		}
		scanf("%d", &piece);	//piece este piesa initiala
		//piecepozition retine pozitia piesei si initial este 0;
		unsigned long long int piecepozition = 0;
		for (j = 8; j >= 1; j--)	//acesta este for-ul care parcurge mutarile
		{
			scanf("%d", &moves);
			piecepozition = movedown(piece, j);	//aici piesa coboara cu un rand
			if (collision(piecepozition, h) == 0)	// se verifica coliziunea cu harta
			{
				for (k = abs(moves); k >= 1; k--)	//for-ul care ajuta la shiftarea pe orizontala
				{
					newpiece = piece;	//newpiece retine piesa
					if (moves > 0)
					{
						if (rightcollision(newpiece) == 0)
						{
							newpiece = piece >> 1;	//shiftare dreapta
						}
						else
							newpiece = piece;
					}
					if (moves < 0)
					{
						if (leftcollision(newpiece) == 0)
						{
							newpiece = piece << 1;	//shiftare stanga
						}
						else newpiece = piece;
					}

					piecepozition1 = movedown(newpiece, j);	//mutare in jos

					if (collision(piecepozition1, h) == 0)	//verificare coliziune
					{
						piece = newpiece;
					}
					else
					{
						break;
					}
				}
				piecepozition = movedown(piece, j);
				if (collision(piecepozition, h) == 0)	//verificare coliziune
				{
					printmap(piecepozition | h);	//printare harta
					hinterim = piecepozition | h;
					//hinterim retine harta dupa realizarea mutarilor
				}
			}
			else
			{
				l = j;	//l retine linia pe care se produce coliziunea
				skip = j - 1;
				break;
			}
		}

		h = hinterim;
		for (t = 8; t >= 1; t--)
		{
			//for-ul acesta parcurge liniile
			maskrow1 = maskrow << 8 * (t - 1);
			//maskrow este o masca cu un rand numai de 1;
			if ((h & maskrow1) == maskrow1)
			{
				pozition = 9 - t;	//retine linia ce trebuie eliminata
				completedLine++;
				h = deleteline(h, pozition);
				delete = 1;
				//delete e un contor ce memoreaza daca s-a eliminat o linie
			}
		}
		if (delete == 1)
		{
			printmap(h);
			delete = 0;
		}
		int e18 = 255;
		if (((l >= 7) && (piece > e18)) || ((l > 7) && (piece < (e18 + 1))))
			break;
	}

	for (p = 63; p >= 0; p--)	//for-ul care parcurge fiecare bit al hartii
	{
		maskbit1 = maskbit << p;
		if ((h & maskbit1) == 0)
			zeroNr++;	//zeroNr numara zerouri
	}
	int e20 = 56;
	if (((maskrow << (e20)) & h) != ((maskrow << (e20)) & map))
		if (m != 0)
			printmap(h);
	printf("GAME OVER!");
	printf("\n");
	printf("Score:");
	score(zeroNr, completedLine);
	printf("\n");
	return 0;
}