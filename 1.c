#include <stdio.h>
#include <stdlib.h>

// Maksimum eleman sayısını burada belirleyin
#define MAX_ELEMAN_SAYISI 100

void ekleListeye(int liste[], int eleman, int *bas, int *son) {
    if (eleman % 2 == 0) {
        // Çift sayıları listenin sonuna ekle
        liste[*son] = eleman;
        (*son)++;
    } else {
        // Tek sayıları listenin başına ekle
        for (int i = *son; i > *bas; i--) {
            liste[i] = liste[i - 1];
        }
        liste[*bas] = eleman;
        (*son)++;
    }
}

int main() {
    int liste[MAX_ELEMAN_SAYISI];
    int eleman, bas = 0, son = 0;

    printf("Sayilari girin (-1 girerek cikis yapabilirsiniz):\n");

    while (1) {
        scanf("%d", &eleman);

        if (eleman == -1) {
            break;
        }

        ekleListeye(liste, eleman, &bas, &son);
    }

    printf("Sonuc: ");
    for (int i = bas; i < son; i++) {
        printf("%d ", liste[i]);
    }

    return 0;
}