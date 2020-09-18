Savu Ioana Rusalda
315 CB


	In functia main am separat argumentele comenzii prima data prin virgula si 
apoi prin spatiu si le-am salvat intr-o matrice cu 3 coloane. 

	Pe prima coloana se afla tipul functiei(operatia ce urmeaza sa fie 
aplicata textului).
	Pe a doua coloana se afla maximul necesar pt wrap,sau start_line-ul 
celorlalte operatii.
	Pe a treia coloana se afla end_line-ul operatiilor.

	Tot in main am calculat lungimile cuvintelor si le-am salvat in matricea nr,
dar si lungimile liniilor pe care le-am salvat intr-un vector.
Cu ajutorul vectorului am calculat in maxlen linia cea mai lunga.

	Functia trwhitespaces sterge spatiile ,taburile si \n-urile in plus si le  
adauga doar in pozitiile corecte.(functia este luata de pe internet)

	Functia alignleft aliniaza textul la stanga mutand caracter cu  caracter 
pana cand nu mai exista spatii la inceputul liniilor.

	Functia alignright aliniaza textul la dreapta mutand caracter cu caracter 
la dreapta pana gand toate ajung la dimensiunea liniei maxime,si adaugand 
spatii la inceputul liniilor.

	Functia centre calculeaza numarul de spatii necesare liniei curente pentru 
a ajunge la dimensiunea liniei maxime.Apoi se vor muta caracterele la dreapta 
cu jumatate din nr spatiilor necesare si tot atea spatii se vor adauga la 
ineceputul liniilor.

	Functia paragraph adauga spatii la inceputul liniei fiecarui paragraf 
tot prin mutarea caracterelor.

	Functia list muta caracterele la dreapta in functie de tipul listei si 
adauga caracterele specifice.

	Functia orderlist ordoneaza alfabetic lista(crescator/descrescator) iar 
apoi o implementeaza cu ajutorul functiei lists.

	Apelarea functiei se face in main cu ajutorul functiei strtol(care 
converteste caracterele in numere in baza 10) si a matricei argumentelor.


