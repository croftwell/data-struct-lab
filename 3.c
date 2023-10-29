#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Öğrenci bilgisini saklayacak olan düğüm yapısı
struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci* sonraki;
};

// Yeni bir öğrenci düğümü oluşturan fonksiyon
struct Ogrenci* yeniOgrenci(int numara, const char* isim, int yas) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    ogrenci->numara = numara;
    strcpy(ogrenci->isim, isim);
    ogrenci->yas = yas;
    ogrenci->sonraki = NULL;
    return ogrenci;
}

// Bağlı listeyi dolaşan ve bilgileri ekrana yazan fonksiyon
void listeDolas(struct Ogrenci* bas) {
    struct Ogrenci* temp = bas;
    int ogrenciSayisi = 0;

    while (temp != NULL) {
        printf("Öğrenci Numarası: %d, İsim: %s, Yaş: %d\n", temp->numara, temp->isim, temp->yas);
        temp = temp->sonraki;
        ogrenciSayisi++;
    }

    printf("Toplam Öğrenci Sayısı: %d\n", ogrenciSayisi);
}

int main() {
    // Öğrenci bilgileri için düğümleri oluşturun
    struct Ogrenci* ogrenci1 = yeniOgrenci(2010206044, "Ali", 22);
    struct Ogrenci* ogrenci2 = yeniOgrenci(2010206001, "Ayşe", 21);
    struct Ogrenci* ogrenci3 = yeniOgrenci(2010206055, "Mehmet", 23);

    // Düğümleri birbirine bağlayın (liste oluşturun)
    ogrenci1->sonraki = ogrenci2;
    ogrenci2->sonraki = ogrenci3;

    // Listeyi dolaşan ve bilgileri ekrana yazan fonksiyonu çağırın
    listeDolas(ogrenci1);

    // Belleği temizle
    free(ogrenci1);
    free(ogrenci2);
    free(ogrenci3);

    return 0;
}
