struct Ogrenci* ogrenciAra(struct Ogrenci* bas, const char* arananIsim) {
    struct Ogrenci* temp = bas;

    while (temp != NULL) {
        if (strcmp(temp->isim, arananIsim) == 0) {
            return temp; // Öğrenci adı bulundu
        }
        temp = temp->sonraki;
    }

    return NULL; // Öğrenci adı bulunamadı
}