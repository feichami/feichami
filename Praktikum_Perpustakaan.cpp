#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

#define size 100

struct Buku {
    string judul;
    string pengarang;
    string isbn;
    int tahunRilis;
    bool dipinjam;

    Buku() : judul(""), pengarang(""), isbn(""), tahunRilis(0), dipinjam(false) {}

    Buku(string j, string p, string i, int t, bool d)
        : judul(j), pengarang(p), isbn(i), tahunRilis(t), dipinjam(d) {}
};

class Perpustakaan {
private:
    string Salinan[size];
public:
    Buku table[size];

    void hash(const Buku& book, int key);
    int hashFunction(int key);
    void ShowBook();
    int CariBukuLinear(const string& searchBook);
    bool pinjamBuku(const string& judul);
    bool kembalikanBuku(const string& judul);
    void merge(int L, int M, int R);
    void mergeSort(int L, int R);
};

int Perpustakaan::hashFunction(int key) {
    return abs(key) % size;
}

void Perpustakaan::hash(const Buku& book, int key) {
    int index = hashFunction(key);

    while (!table[index].judul.empty()) {
        index = (index + 1) % size; 
    }

    table[index] = book;
    mergeSort(0, size - 1);
}

void Perpustakaan::merge(int L, int M, int R) {
    int n1 = M - L + 1;
    int n2 = R - M;

    vector<string> Left(n1), Right(n2);

    for (int i = 0; i < n1; i++)
        Left[i] = Salinan[L + i];
    for (int j = 0; j < n2; j++)
        Right[j] = Salinan[M + 1 + j];

    int i = 0, j = 0, k = L;
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            Salinan[k] = Left[i];
            i++;
        } else {
            Salinan[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        Salinan[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        Salinan[k] = Right[j];
        j++;
        k++;
    }
}

void Perpustakaan::mergeSort(int L, int R) {
    if (L < R) {
        int M = L + (R - L) / 2;

        mergeSort(L, M);
        mergeSort(M + 1, R);

        merge(L, M, R);
    }
}

void Perpustakaan::ShowBook() {
    for (int i = 0; i < size; ++i) {
        if (!table[i].judul.empty()) {
            cout << "Judul: " << table[i].judul << ", Pengarang: " << table[i].pengarang
                << ", ISBN: " << table[i].isbn << ", Tahun Rilis: " << table[i].tahunRilis
                << ", Status: " << (table[i].dipinjam ? "Dipinjam" : "Tersedia")
                << " berada pada index: " << i << endl;
        }
    }
}

int Perpustakaan::CariBukuLinear(const string& searchBook) {
    for (int i = 0; i < size; ++i) {
        if (table[i].judul == searchBook) {
            return i; 
        }
    }
    return -1; 
}

bool Perpustakaan::pinjamBuku(const string& judul) {
    int index = CariBukuLinear(judul);

    if (index != -1 && !table[index].dipinjam) {
        table[index].dipinjam = true;
        return true;
    }
    return false;
}

bool Perpustakaan::kembalikanBuku(const string& judul) {
    int index = CariBukuLinear(judul);

    if (index != -1 && table[index].dipinjam) {
        table[index].dipinjam = false;
        return true;
    }
    return false;
}

void tambahBuku(Perpustakaan& perpustakaan) {
    string judul, pengarang, isbn;
    int tahunRilis, key;

    system("cls");
    cout << "===========================================\n";
    Sleep(200);
    cout << "Masukkan Buku yang ingin anda tambahkan: " << endl;
    Sleep(200);
    cout << "===========================================\n";
    Sleep(200);

    do {
        cout << "Ketik nama buku: ";
        getline(cin, judul);
        cout << "Ketik nama pengarang: ";
        getline(cin, pengarang);
        cout << "Ketik ISBN: ";
        getline(cin, isbn);
        cout << "Ketik tahun rilis: ";
        cin >> tahunRilis;
        cin.ignore();
        cout << "Ketik Key (masukkan -1 untuk berhenti): ";
        cin >> key;
        cin.ignore();

        if (key != -1) {
            Buku book(judul, pengarang, isbn, tahunRilis, false);
            perpustakaan.hash(book, key);
        }
    } while (key != -1);
}

void cariBuku(Perpustakaan& perpustakaan) {
    string judul;
    system("cls");
    cout << "==================================\n";
    Sleep(200);
    cout << "  Pencarian dengan Linear Search: " << endl;
    Sleep(200);
    cout << "==================================\n";
    Sleep(200);
    cout << "Masukkan nama buku yang ingin dicari: ";
    getline(cin, judul);

    int foundIndex = perpustakaan.CariBukuLinear(judul);

    if (foundIndex != -1) {
        cout << "Buku ditemukan pada index " << foundIndex << endl;
        cout << "Judul: " << perpustakaan.table[foundIndex].judul << ", Pengarang: " << perpustakaan.table[foundIndex].pengarang
            << ", ISBN: " << perpustakaan.table[foundIndex].isbn << ", Tahun Rilis: " << perpustakaan.table[foundIndex].tahunRilis
            << ", Status: " << (perpustakaan.table[foundIndex].dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }
    else {
        cout << "Buku tidak ditemukan." << endl;
    }
}

void pinjamBuku(Perpustakaan& perpustakaan) {
    string judul;
    system("cls");
    cout << "==================================\n";
    Sleep(200);
    cout << "         Peminjaman Buku: " << endl;
    Sleep(200);
    cout << "==================================\n";
    Sleep(200);
    cout << "Masukkan nama buku yang ingin dipinjam: ";
    getline(cin, judul);

    if (perpustakaan.pinjamBuku(judul)) {
        cout << "Buku berhasil dipinjam." << endl;
    }
    else {
        cout << "Buku tidak tersedia atau sedang dipinjam." << endl;
    }
}

void kembalikanBuku(Perpustakaan& perpustakaan) {
    string judul;
    system("cls");
    cout << "==================================\n";
    Sleep(200);
    cout << "        Pengembalian Buku: " << endl;
    Sleep(200);
    cout << "==================================\n";
    Sleep(200);
    cout << "Masukkan nama buku yang ingin dikembalikan: ";
    getline(cin, judul);

    if (perpustakaan.kembalikanBuku(judul)) {
        Sleep(200);
        cout << "Buku berhasil dikembalikan." << endl;
    }
    else {
        Sleep(200);
        cout << "Buku tidak ditemukan atau belum dipinjam." << endl;
    }
}

int main() {
    Perpustakaan x;
    int pilihan;

    do {
        system("cls");

        cout << "====== Perpustakaan Digital ======\n";
        Sleep(200);
        cout << "1. Tambah Buku\n";
        Sleep(200);
        cout << "2. Cari Buku\n";
        Sleep(200);
        cout << "3. Pinjam Buku\n";
        Sleep(200);
        cout << "4. Kembalikan Buku\n";
        Sleep(200);
        cout << "0. Keluar\n";
        Sleep(200);
        cout << "==================================\n";
        Sleep(200);
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            tambahBuku(x);
            break;

        case 2:
            cariBuku(x);
            break;

        case 3:
            pinjamBuku(x);
            break;

        case 4:
            kembalikanBuku(x);
            break;

        case 0:
            cout << "\nKeluar dari program...\n";
            break;

        default:
            cout << "\nPilihan tidak valid. Silakan masukkan angka antara 0 dan 4.\n";
        }

        cout << "\nTekan Enter untuk kembali ke menu utama...\n";
        cin.ignore(); // Wait for user input to continue
    } while (pilihan != 0);

    return 0;
}
