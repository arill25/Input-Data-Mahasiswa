#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string jurusan;
    string angkatan;
};

class SistemInformasi {
private:
    vector<Mahasiswa> mahasiswaList;

public:
    void tambahMahasiswa(const Mahasiswa& mahasiswa) {
        mahasiswaList.push_back(mahasiswa);
        cout << "Mahasiswa " << mahasiswa.nama << " berhasil ditambahkan.\n";
    }

    void tampilkanSemuaMahasiswa() {
        if (mahasiswaList.empty()) {
            cout << "Tidak ada data mahasiswa.\n";
            return;
        }
        cout << "Daftar Mahasiswa:\n";
        for (const auto& m : mahasiswaList) {
            cout << "NIM: " << m.nim << ", Nama: " << m.nama << ", Jurusan: " << m.jurusan << ", Angkatan: " << m.angkatan << "\n";
        }
    }

    void cariMahasiswaByNIM(const string& nim) {
        for (const auto& m : mahasiswaList) {
            if (m.nim == nim) {
                cout << "Data Mahasiswa Ditemukan:\n";
                cout << "NIM: " << m.nim << ", Nama: " << m.nama << ", Jurusan: " << m.jurusan << ", Angkatan: " << m.angkatan << "\n";
                return;
            }
        }
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
    }
};

int main() {
    SistemInformasi sistem;
    int pilihan;

    do {
        cout << "\nSistem Informasi Mahasiswa\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Semua Mahasiswa\n";
        cout << "3. Cari Mahasiswa Berdasarkan NIM\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer input

        if (pilihan == 1) {
            Mahasiswa m;
            cout << "Masukkan NIM: "; getline(cin, m.nim);
            cout << "Masukkan Nama: "; getline(cin, m.nama);
            cout << "Masukkan Jurusan: "; getline(cin, m.jurusan);
            cout << "Masukkan Angkatan: "; getline(cin, m.angkatan);
            sistem.tambahMahasiswa(m);
        } else if (pilihan == 2) {
            sistem.tampilkanSemuaMahasiswa();
        } else if (pilihan == 3) {
            string nim;
            cout << "Masukkan NIM yang dicari: ";
            cin >> nim;
            sistem.cariMahasiswaByNIM(nim);
        } else if (pilihan != 4) {
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);

    cout << "Keluar dari sistem. Terima kasih.\n";
    return 0;
}
