#include<iostream>
/* funkcja do wyświetlania zawartości tablicy,
 * będę jej używał zamiast powtarzania po kilka razy tej samej pętli
 * funkcja jest typu void, jako argumenty przyjmuje tablice typu int
 * oraz zmienna odpowiadajaca za rozmiar (size, typ int).*/
void arrayDisplayer(int tab [], int start, int meta){
    for (int i = start; i<=meta; i++){
        std::cout<<tab[i] << " ";
    }
    std::cout<<std::endl;
}
//9 4 6 2 7 1 3 5
void MergeSort(int tab[], int pom[], int poczatek, int koniec)
{
    //wyświetlam obecnie badaną tablicę
    arrayDisplayer(tab, poczatek, koniec);
    /* liczę środek badanej tablicy jako iloczyn sumy początkowego i końcowego indeksu + 1 (ponieważ tablice
     * indeksujemy od zera) */
    int srodek = (poczatek + koniec + 1) / 2;
    /* Sprawdzam czy potrzebne jest dalsze dzielenie tablicy na mniejsze części; tutaj warto się zatrzymać, ponieważ
     * dodałem do Pana kodu dodatkowego ifa z negacją obydwóch warunków, jedyną jego funkcją jest wyświetlanie
     * komunikatu gdy nie ma już potrzeby dzielenia tablicy.
     */
    if (!(srodek - poczatek >1 || koniec-srodek > 0)){
        std::cout<<"Tablica nie wymaga podzielenia\n";
    }
    if(srodek - poczatek > 1) {
        std::cout << "Tablica wymaga podzielenia\n\n";
        MergeSort(tab, pom, poczatek, srodek - 1);
    }
    if(koniec - srodek > 0){
        std::cout<<"Tablica wymaga podzielenia \n \n";
        MergeSort(tab, pom, srodek, koniec);
    }
    /* kolejnym krokiem jest oczywiście wyświetlanie opisu działań sortujących, do tego służy nam dalsza część
     * programu */
    int i1 = poczatek;
    int i2 = srodek;
    std::cout<<std::endl;
    //wyświetlam tablicę którą się aktualnie zajmuje:
    std::cout<<"--- \n";
    std::cout<<"Tablica którą posortujemy: \n";
    arrayDisplayer(tab,poczatek,koniec);
    //oraz podstawowe informacje
    std::cout<<"Podstawowe parametry:\n";
    std::cout<<"Indeks początkowy (części nieposortowanej): "<<i1<< "\n";
    std::cout<<"Indeks końcowy (części nieposortowanej): "<<i2<< "\n";
    std::cout<<"Koniec: "<<koniec<< "\n";
    std::cout<<"--- \n";
    std::cout<<std::endl;
    for(int i = poczatek; i <= koniec; i++){
        /* tutaj warto zrobić coś podobnego do przykładowego rozwiązania - tj. sprawdzanie następców, czyli
        czy zmienna i1 jest równa środkowi */
        if (i1 != srodek){
            std::cout<<"Element o indeksie " << i1 << " (wartosc " <<tab[i1] << ") ma nastepce."<<std::endl;
        } else{
            std::cout<<"Element o indeksie " << i1 << " (wartosc " <<tab[i1] << ") nie ma nastepcy."<<std::endl;
        }
        /* Sprawdźmy też, jak to jest z posortowaniem elementów
           oczywistym wydaje sie jak zdefiniować czy wybrany zakres jest odpowiednio posortowany czy nie: */
        if (i2 <= koniec && (tab[i1] > tab[i2])){
            std::cout<<"Tablica nie jest jeszcze posortowana."<<std::endl;
        }
        else{
            std::cout<<"Tablica jest posortowana."<<std::endl;
        }

        /* tym razem już bardziej skrótowo, robimy podmiankę elementów gdy wykryjemy że nie są w odpowiedniej kolejności
         * i to wyświetlamy */
        if ((i1 == srodek) || ((i2 <= koniec) && (tab[i1] > tab[i2]))){
            std::cout<<"\n";
            std::cout << "Wartosc tablicy pomocniczej pom[" << i << "] równa się wartosci tab[" <<i2 << "] czyli " << tab[i2] <<std::endl;
            std::cout << "Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = "<< i2+1 <<") \n";

            pom[i] = tab[i2];
            i2++;
        }
        else{
            std::cout<<"\n";
            std::cout << "Wartosc tablicy pomocniczej pom[" << i << "] równa się wartosci tab[" <<i1 << "] czyli " << tab[i1] <<std::endl;
            std::cout << "Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = "<< i1+1  << ") \n";
            pom[i] = tab[i1];
            i1++;
        }
    }

    //nie jestem zbyt dobry w stylizowaniu outputów
    std::cout << "\n==== ---- ==== \n";
    std::cout << "Stan tablicy po sortowaniu: \n";
    arrayDisplayer(pom,poczatek,koniec);
    std::cout << "==== ---- ==== \n";

    //unifikuję dwie tablice
    for(int i = poczatek; i <= koniec; i++){
        tab[i] = pom[i];
    }
}

int main()
{
    int n;
    std::cout << "Podaj liczbe elementow: ";
    std::cin >> n;
    int tab[n];
    int pom[n];
    std::cout << "Podaj elementy tablicy: ";
    for(int i=0;i<n;i++)
        std::cin>>tab[i];

    MergeSort(tab, pom, 0, n-1);
    /* mam od tego metodę
    std::cout << "\nPosortowana tablica: ";
    for(int i=0;i<n;i++)
        std::cout << tab[i] << " ";
*/
    std::cout << "\n==== ***** ==== \n";
    std::cout << "     Wynik \n";
    arrayDisplayer(pom,0,n-1);
    std::cout << "==== ***** ==== \n";
    return 0;
}

/*
 * Dominik Borawski
 * A1 215IC
 * Sortowanie przez scalanie
 */

/*
Podaj liczbe elementow: 8
Podaj elementy tablicy: 9 4 6 2 7 1 3 5
9 4 6 2 7 1 3 5
Tablica wymaga podzielenia

9 4 6 2
Tablica wymaga podzielenia

9 4
Tablica nie wymaga podzielenia

---
Tablica którą posortujemy:
9 4
Podstawowe parametry:
Indeks początkowy (części nieposortowanej): 0
Indeks końcowy (części nieposortowanej): 1
Koniec: 1
---

Element o indeksie 0 (wartosc 9) ma nastepce.
Tablica nie jest jeszcze posortowana.

Wartosc tablicy pomocniczej pom[0] równa się wartosci tab[1] czyli 4
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 2)
Element o indeksie 0 (wartosc 9) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[1] równa się wartosci tab[0] czyli 9
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 1)

==== ---- ====
Stan tablicy po sortowaniu:
4 9
==== ---- ====
Tablica wymaga podzielenia

6 2
Tablica nie wymaga podzielenia

---
Tablica którą posortujemy:
6 2
Podstawowe parametry:
Indeks początkowy (części nieposortowanej): 2
Indeks końcowy (części nieposortowanej): 3
Koniec: 3
---

Element o indeksie 2 (wartosc 6) ma nastepce.
Tablica nie jest jeszcze posortowana.

Wartosc tablicy pomocniczej pom[2] równa się wartosci tab[3] czyli 2
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 4)
Element o indeksie 2 (wartosc 6) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[3] równa się wartosci tab[2] czyli 6
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 3)

==== ---- ====
Stan tablicy po sortowaniu:
2 6
==== ---- ====

---
Tablica którą posortujemy:
4 9 2 6
Podstawowe parametry:
Indeks początkowy (części nieposortowanej): 0
Indeks końcowy (części nieposortowanej): 2
Koniec: 3
---

Element o indeksie 0 (wartosc 4) ma nastepce.
Tablica nie jest jeszcze posortowana.

Wartosc tablicy pomocniczej pom[0] równa się wartosci tab[2] czyli 2
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 3)
Element o indeksie 0 (wartosc 4) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[1] równa się wartosci tab[0] czyli 4
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 1)
Element o indeksie 1 (wartosc 9) ma nastepce.
Tablica nie jest jeszcze posortowana.

Wartosc tablicy pomocniczej pom[2] równa się wartosci tab[3] czyli 6
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 4)
Element o indeksie 1 (wartosc 9) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[3] równa się wartosci tab[1] czyli 9
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 2)

==== ---- ====
Stan tablicy po sortowaniu:
2 4 6 9
==== ---- ====
Tablica wymaga podzielenia

7 1 3 5
Tablica wymaga podzielenia

7 1
Tablica nie wymaga podzielenia

---
Tablica którą posortujemy:
7 1
Podstawowe parametry:
Indeks początkowy (części nieposortowanej): 4
Indeks końcowy (części nieposortowanej): 5
Koniec: 5
---

Element o indeksie 4 (wartosc 7) ma nastepce.
Tablica nie jest jeszcze posortowana.

Wartosc tablicy pomocniczej pom[4] równa się wartosci tab[5] czyli 1
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 6)
Element o indeksie 4 (wartosc 7) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[5] równa się wartosci tab[4] czyli 7
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 5)

==== ---- ====
Stan tablicy po sortowaniu:
1 7
==== ---- ====
Tablica wymaga podzielenia

3 5
Tablica nie wymaga podzielenia

---
Tablica którą posortujemy:
3 5
Podstawowe parametry:
Indeks początkowy (części nieposortowanej): 6
Indeks końcowy (części nieposortowanej): 7
Koniec: 7
---

Element o indeksie 6 (wartosc 3) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[6] równa się wartosci tab[6] czyli 3
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 7)
Element o indeksie 7 (wartosc 5) nie ma nastepcy.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[7] równa się wartosci tab[7] czyli 5
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 8)

==== ---- ====
Stan tablicy po sortowaniu:
3 5
==== ---- ====

---
Tablica którą posortujemy:
1 7 3 5
Podstawowe parametry:
Indeks początkowy (części nieposortowanej): 4
Indeks końcowy (części nieposortowanej): 6
Koniec: 7
---

Element o indeksie 4 (wartosc 1) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[4] równa się wartosci tab[4] czyli 1
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 5)
Element o indeksie 5 (wartosc 7) ma nastepce.
Tablica nie jest jeszcze posortowana.

Wartosc tablicy pomocniczej pom[5] równa się wartosci tab[6] czyli 3
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 7)
Element o indeksie 5 (wartosc 7) ma nastepce.
Tablica nie jest jeszcze posortowana.

Wartosc tablicy pomocniczej pom[6] równa się wartosci tab[7] czyli 5
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 8)
Element o indeksie 5 (wartosc 7) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[7] równa się wartosci tab[5] czyli 7
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 6)

==== ---- ====
Stan tablicy po sortowaniu:
1 3 5 7
==== ---- ====

---
Tablica którą posortujemy:
2 4 6 9 1 3 5 7
Podstawowe parametry:
Indeks początkowy (części nieposortowanej): 0
Indeks końcowy (części nieposortowanej): 4
Koniec: 7
---

Element o indeksie 0 (wartosc 2) ma nastepce.
Tablica nie jest jeszcze posortowana.

Wartosc tablicy pomocniczej pom[0] równa się wartosci tab[4] czyli 1
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 5)
Element o indeksie 0 (wartosc 2) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[1] równa się wartosci tab[0] czyli 2
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 1)
Element o indeksie 1 (wartosc 4) ma nastepce.
Tablica nie jest jeszcze posortowana.

Wartosc tablicy pomocniczej pom[2] równa się wartosci tab[5] czyli 3
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 6)
Element o indeksie 1 (wartosc 4) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[3] równa się wartosci tab[1] czyli 4
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 2)
Element o indeksie 2 (wartosc 6) ma nastepce.
Tablica nie jest jeszcze posortowana.

Wartosc tablicy pomocniczej pom[4] równa się wartosci tab[6] czyli 5
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 7)
Element o indeksie 2 (wartosc 6) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[5] równa się wartosci tab[2] czyli 6
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 3)
Element o indeksie 3 (wartosc 9) ma nastepce.
Tablica nie jest jeszcze posortowana.

Wartosc tablicy pomocniczej pom[6] równa się wartosci tab[7] czyli 7
Przesunelismy jeden element z tablicy i2, zatem musimy tez zwiekszyc wartosc i2 o jeden (i2++ = 8)
Element o indeksie 3 (wartosc 9) ma nastepce.
Tablica jest posortowana.

Wartosc tablicy pomocniczej pom[7] równa się wartosci tab[3] czyli 9
Przesunelismy jeden element z tablicy i1, zatem musimy tez zwiekszyc wartosc i1 o jeden (i1++ = 4)

==== ---- ====
Stan tablicy po sortowaniu:
1 2 3 4 5 6 7 9
==== ---- ====

==== ***** ====
     Wynik
1 2 3 4 5 6 7 9
==== ***** ====
*/