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

// En uzun ismi bulan fonksiyon
const char* enUzunIsim(struct Ogrenci* bas) {
    struct Ogrenci* temp = bas;
    const char* enUzun = ""; // Başlangıçta en uzun isim boş bir karakter dizisi olarak atanır

    while (temp != NULL) {
        if (strlen(temp->isim) > strlen(enUzun)) {
            enUzun = temp->isim;
        }
        temp = temp->sonraki;
    }

    return enUzun;
}

int main() {
    // Öğrenci bilgileri için düğümleri oluşturun
    struct Ogrenci* ogrenci1 = yeniOgrenci(2010206044, "Ali", 22);
    struct Ogrenci* ogrenci2 = yeniOgrenci(2010206001, "Ayşe", 21);
    struct Ogrenci* ogrenci3 = yeniOgrenci(2010206055, "Mehmet", 23);

    // Düğümleri birbirine bağlayın (liste oluşturun)
    ogrenci1->sonraki = ogrenci2;
    ogrenci2->sonraki = ogrenci3;

    // En uzun ismi bulan fonksiyonu çağırın
    const char* enUzun = enUzunIsim(ogrenci1);

    printf("En uzun isim: %s\n", enUzun);

    // Belleği temizle
    free(ogrenci1);
    free(ogrenci2);
    free(ogrenci3);

    return 0;
}
