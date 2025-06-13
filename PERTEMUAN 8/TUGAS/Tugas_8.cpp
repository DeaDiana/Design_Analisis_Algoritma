#include <iostream>
using namespace std;

struct Pembeli {
    int nomor;
    string nama;
    Pembeli *next;
};

Pembeli *head = NULL, *tail = NULL;

bool kosong();
void tambahPembeli(int no);
void layaniPembeli();
void tampilkanAntrian();

int main() {
    int nomor = 1;
    char pilih;

    do {
        cout << "\n=== Loket Tiket ===\n";
        cout << "1. Tambah Pembeli\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case '1': 
				tambahPembeli(nomor++); 
				break;
            case '2': 
				layaniPembeli(); 
				break;
            case '3': 
				tampilkanAntrian(); 
				break;
            case '4': 
				cout << "Keluar program\n"; 
				break;
            default:  
				cout << "Pilihan salah\n";
        }

    } while (pilih != '4');

    return 0;
}

bool kosong() {
    return head == NULL;
}

void tambahPembeli(int no) {
    string nama;
    cout << "Nama pembeli: ";
    cin.ignore();
    getline(cin, nama);

    Pembeli *baru = new Pembeli;
    baru->nomor = no;
    baru->nama = nama;
    baru->next = NULL;

    if (kosong()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }

    cout << "Nomor " << no << ": " << nama << " masuk antrian.\n";
}

void layaniPembeli() {
    if (kosong()) {
        cout << "Antrian kosong\n";
        return;
    }

    Pembeli *hapus = head;
    cout << "Melayani " << hapus->nama << " (Nomor " << hapus->nomor << ")\n";
    head = head->next;
    delete hapus;

    if (head == NULL) tail = NULL;
}

void tampilkanAntrian() {
    if (kosong()) {
        cout << "Tidak ada antrian\n";
        return;
    }

    Pembeli *bantu = head;
    cout << "Antrian saat ini:\n";
    while (bantu != NULL) {
        cout << bantu->nomor << ". " << bantu->nama << endl;
        bantu = bantu->next;
    }
}

