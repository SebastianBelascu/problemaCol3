#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    BUN,
    MEDIU,
    SLAB
} CALITATE;

typedef struct {
    char nume[21];
    int an;
    char gen[21];
    float scor;
    CALITATE calitate;
} FILM;

void citesteFilm(const char* txt, FILM* film) {
    sscanf(txt, "%s %d %s %f", film->nume, &film->an, film->gen, &film->scor);
    if (film->scor <= 2.0) {
        film->calitate = SLAB;
    } else if (film->scor > 2.0 && film->scor < 4.0) {
        film->calitate = MEDIU;
    } else if (film->scor >= 4.0) {
        film->calitate = BUN;
    }
}

void afisareFilmVechi(FILM film) {
    if ((strcmp(film.gen, "THRILLER") == 0) || (strcmp(film.gen, "HORROR") == 0)) {
        printf("Numele filmului este %s+18 \n", film.nume);
    } else {
        printf("Numele filmului este %s \n", film.nume);
    }
    printf("Anul filmului este %d \n", film.an);
    printf("Genul filmului este %s \n", film.gen);
    printf("Scorul filmului este %f \n", film.scor);
}


void afisareFilm(FILM film) {
    printf("Numele filmului este %s \n", film.nume);
    printf("Anul filmului este %d \n", film.an);
    printf("Genul filmului este %s \n", film.gen);
    printf("Scorul filmului este %f \n", film.scor);
    if (film.calitate == SLAB) {
        printf("Calitatea filmului este slaba\n");
    } else if (film.calitate == MEDIU) {
        printf("Calitatea filmului este medie\n");
    } else if (film.calitate == BUN) {
        printf("Calitatea filmului este buna\n");
    }
}

int main(void) {
    FILE* f;
    f = fopen("C:\\Users\\belas\\CLionProjects\\labtest3\\filme.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    fgetc(f);
    char chr;
    printf("Introdu operatia pe care vrei sa o faci: ( a si b ) \n");
    scanf("%c", &chr);
    FILM* filme = (FILM*)malloc(n * sizeof(FILM));
    char enunt[101];
    for (int i = 0; i < n; i++) {
        fgets(enunt, sizeof(enunt), f);
        citesteFilm(enunt, &filme[i]);
    }
    if (chr == 'a') {
        for (int i = 0; i < n; i++) {
            afisareFilmVechi(filme[i]);
        }
    }
    if (chr == 'b') {
        for (int i = 0; i < n; i++) {
            afisareFilm(filme[i]);
        }
    }
    return 0;
}