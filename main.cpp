#include <iostream>

using namespace std;

struct liczba {
    int a;
    struct liczba *wsk;
};

void dodaj(int x, struct liczba *&kolejka) {
    if (kolejka == NULL) {
        kolejka = new struct liczba;
        kolejka->wsk = NULL;
        kolejka->a = x;
    } else if (kolejka->wsk == NULL) {
        kolejka->wsk = new struct liczba;
        kolejka->wsk->wsk = NULL;
        kolejka->wsk->a = x;
    } else {
        dodaj(x, kolejka->wsk);
    }
}

void wypisz(struct liczba *kolejka) {
    if (kolejka != NULL) {
        cout << kolejka->a << " ";
        wypisz(kolejka->wsk);
    }
}

struct liczba *scal(struct liczba *kolejka1, struct liczba *kolejka2) {
    struct liczba *wynik = NULL;

    while (kolejka1 != NULL || kolejka2 != NULL) {
        if (kolejka1 == NULL) {
            dodaj(kolejka2->a, wynik);
            kolejka2 = kolejka2->wsk;
        } else if (kolejka2 == NULL) {
            dodaj(kolejka1->a, wynik);
            kolejka1 = kolejka1->wsk;
        } else {
            if (kolejka1->a < kolejka2->a) {
                dodaj(kolejka1->a, wynik);
                kolejka1 = kolejka1->wsk;
            } else {
                dodaj(kolejka2->a, wynik);
                kolejka2 = kolejka2->wsk;
            }
        }
    }

    return wynik;
}

void sortuj(struct liczba *&kolejka) {
    struct liczba *aktualny = kolejka;
    while (aktualny != NULL) {
        struct liczba *nastepny = aktualny->wsk;
        while (nastepny != NULL) {
            if (aktualny->a < nastepny->a) {
                swap(aktualny->a, nastepny->a);
            }
            nastepny = nastepny->wsk;
        }
        aktualny = aktualny->wsk;
    }
}

int main() {
    struct liczba *kolejka1 = NULL;
    struct liczba *kolejka2 = NULL;
    dodaj(9, kolejka1);
    dodaj(7, kolejka1);
    dodaj(3, kolejka1);
    dodaj(1, kolejka1);
    dodaj(10, kolejka2);
    dodaj(9, kolejka2);
    dodaj(8, kolejka2);
    dodaj(7, kolejka2);
    dodaj(3, kolejka2);
    struct liczba *scaloneKolejki = scal(kolejka1, kolejka2);

    sortuj(scaloneKolejki);

    cout << "Scalone Kolejki: ";
    wypisz(scaloneKolejki);
    cout << endl;

    return 0;
}
