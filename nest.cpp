#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int koef;
    int exp;
} Polinom;

// Funkcija za učitavanje polinoma iz datoteke
Polinom* ucitajPolinom(FILE *file, int *n) {
    int koef, exp;
    Polinom *polinom = NULL;
    *n = 0;

    while (fscanf(file, "%d %d", &koef, &exp) == 2) {
        polinom = realloc(polinom, (*n + 1) * sizeof(Polinom));
        polinom[*n].koef = koef;
        polinom[*n].exp = exp;
        (*n)++;
    }
    return polinom;
}

// Funkcija za sortiranje polinoma po eksponentima
void sortirajPolinom(Polinom *polinom, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (polinom[i].exp > polinom[j].exp) {
                Polinom temp = polinom[i];
                polinom[i] = polinom[j];
                polinom[j] = temp;
            }
        }
    }
}

// Funkcija za zbrajanje dvaju polinoma
Polinom* zbrojiPolinome(Polinom *p1, int n1, Polinom *p2, int n2, int *nZbroj) {
    // Implementacija za zbrajanje
}

// Funkcija za množenje dvaju polinoma
Polinom* pomnoziPolinome(Polinom *p1, int n1, Polinom *p2, int n2, int *nMnozenje) {
    // Implementacija za množenje
}

int main() {
    FILE *file = fopen("polinomi.txt", "r");
    if (!file) {
        printf("Greska pri otvaranju datoteke.\n");
        return 1;
    }

    int n1, n2;
    Polinom *p1 = ucitajPolinom(file, &n1);
    Polinom *p2 = ucitajPolinom(file, &n2);
    fclose(file);

    sortirajPolinom(p1, n1);
    sortirajPolinom(p2, n2);

    int nZbroj, nMnozenje;
    Polinom *zbroj = zbrojiPolinome(p1, n1, p2, n2, &nZbroj);
    Polinom *umnozak = pomnoziPolinome(p1, n1, p2, n2, &nMnozenje);

    // Ispis rezultata i oslobađanje memorije

    free(p1);
    free(p2);
    free(zbroj);
    free(umnozak);

    return 0;
}
