#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Elemanları yer değiştir
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int liste[100]; // 100 elemanlık bir dizi oluşturun
    int n = 100;    // Dizi boyutu

    // Rastgele sayıları diziye ekleyin
    srand(time(NULL)); // Rastgele sayı üretimi için seed ayarlayın
    for (int i = 0; i < n; i++) {
        liste[i] = rand() % 1000; // 0 ile 999 arasında rastgele sayılar
    }

    // Diziyi Bubble Sort ile sıralayın
    bubbleSort(liste, n);

    // Sıralanmış diziyi ekrana yazdırın
    printf("Siralanan Dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", liste[i]);
    }

    return 0;
}
