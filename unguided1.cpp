#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Mahasiswa {
    string nim_2311102013;
    string nama_wrrp; 
    int nilai;
};

class HashTable {
private:
    unordered_map<string, Mahasiswa> data;

public:
    void tambahData(const Mahasiswa& mhs) {
        data[mhs.nim_2311102013] = mhs;
    }

    void hapusData(const string& nim_2311102013) {
        data.erase(nim_2311102013);
    }

    Mahasiswa* cariBynim_2311102013(const string& nim_2311102013) {
        if (data.find(nim_2311102013) != data.end()) {
            return &data[nim_2311102013];
        }
        return nullptr;
    }

    vector<Mahasiswa> cariByNilai() {
        vector<Mahasiswa> result;
        for (auto& pair : data) {
            if (pair.second.nilai >= 80 && pair.second.nilai <= 90) {
                result.push_back(pair.second);
            }
        }
        return result;
    }
};

void tampilkanMenu() {
    cout << "Menu :\n";
    cout << "1. Tambah data mahasiswa\n";
    cout << "2. Hapus data mahasiswa\n";
    cout << "3. Cari data mahasiswa berdasarkan NIM\n";
    cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80 - 90)\n";
    cout << "5. Keluar\n";
    cout << "Pilih : ";
}

int main() {
    HashTable hashTable;
    int pilihan;
    string nim_2311102013;
    string nama_wrrp;
    int nilai;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                Mahasiswa mhs;
                cout << "Masukkan NIM : ";
                cin >> mhs.nim_2311102013;
                cout << "Masukkan Nama : ";
                cin.ignore(); 
                getline(cin, mhs.nama_wrrp);
                cout << "Masukkan nilai : ";
                cin >> mhs.nilai;
                hashTable.tambahData(mhs);
                cout << "Data Berhasil Ditambahkan!\n";
                break;
            }
            case 2: {
                cout << "Masukkan NIM mahasiswa yang akan dihapus : ";
                cin >> nim_2311102013;
                hashTable.hapusData(nim_2311102013);
                cout << "Data Berhasil Dihapus!\n";
                break;
            }
            case 3: {
                cout << "Masukkan NIM mahasiswa yang akan dicari : ";
                cin >> nim_2311102013;
                Mahasiswa* mhs = hashTable.cariBynim_2311102013(nim_2311102013);
                if (mhs != nullptr) {
                    cout << "nim_2311102013 : " << mhs->nim_2311102013 << ", Nama : " << mhs->nama_wrrp << ", Nilai : " << mhs->nilai << endl;
                } else {
                    cout << "Mahasiswa dengan NIM tersebut tidak ditemukan!\n";
                }
                break;
            }
            case 4: {
                vector<Mahasiswa> result = hashTable.cariByNilai();
                if (result.empty()) {
                    cout << "Tidak ada mahasiswa dengan nilai di rentang (80 - 90)!\n";
                } else {
                    cout << "Mahasiswa dengan nilai di rentang (80 - 90) :\n";
                    for (const Mahasiswa& mhs : result) {
                        cout << "NIM : " << mhs.nim_2311102013 << ", Nama : " << mhs.nama_wrrp << ", Nilai : " << mhs.nilai << endl;
                    }
                }
                break;
            }
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali!\n";
        }

    } while (pilihan != 5);

    return 0;
}