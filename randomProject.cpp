#include <bits/stdc++.h>

using namespace std;

// Deklarasi fungsi-fungsi
void menuMatriks();
void menuBitwise();
void menuAkademik();
void menuAkarKuadrat();
void catatRiwayat(string pesan);

void catatRiwayat(string pesan) {
    // Membuka file "riwayat_project.txt"
    ofstream file("riwayat_project.txt", ios::app); 
    
    if (file.is_open()) {
        file << pesan << "\n";
        file.close();
    } else {
        cout << "Error: Sistem gagal membuka atau membuat file riwayat!\n";
    }
}

int main() {
    int pilihan;
    bool lanjut = true;

    while (lanjut) {
        cout << "\n=====================================\n";
        cout << "     MEGA PROJECT ALGORITMA CLI\n";
        cout << "=====================================\n";
        cout << "1. Operasi Matriks (Transpose & Determinan)\n";
        cout << "2. Konverter Desimal ke Biner & Bitwise\n";
        cout << "3. Evaluator Predikat Nilai Ujian\n";
        cout << "4. Pencari Akar Persamaan Kuadrat\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuMatriks();
                break;
            case 2:
                menuBitwise();
                break;
            case 3:
                menuAkademik();
                break;
            case 4:
                menuAkarKuadrat();
                break;
            case 5:
                cout << "Keluar dari program. Mantap progresnya!\n";
                lanjut = false;
                break;
            default:
                cout << "Input tidak valid. Coba lagi.\n";
        }
    }

    return 0;
}

// === IMPLEMENTASI FUNGSI ===

void menuMatriks() {
    int jenis;
    cout << "\n=====================================\n";
    cout << "          MENU OPERASI MATRIKS\n";
    cout << "=====================================\n";
    cout << "1. Hitung Determinan Matriks 2x2\n";
    cout << "2. Hitung Determinan Matriks 3x3\n";
    cout << "Pilih jenis matriks (1/2): ";
    cin >> jenis;

    if (jenis == 1) {
        float m[2][2];
        cout << "\n[Input Matriks 2x2]\n";
        // Nested loop untuk input data
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                cout << "Masukkan elemen baris " << i+1 << " kolom " << j+1 << ": ";
                cin >> m[i][j];
            }
        }

        // Cetak matriks biar keren
        cout << "\nMatriks Anda:\n";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                cout << m[i][j] << "\t";
            }
            cout << "\n";
        }

        // Rumus Determinan 2x2: (ad - bc)
        float det = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
        cout << "\nDeterminan = " << det << "\n";

    } else if (jenis == 2) {
        float m[3][3];
        cout << "\n[Input Matriks 3x3]\n";
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << "Masukkan elemen baris " << i+1 << " kolom " << j+1 << ": ";
                cin >> m[i][j];
            }
        }

        cout << "\nMatriks Anda:\n";
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << m[i][j] << "\t";
            }
            cout << "\n";
        }

        // Rumus Determinan 3x3 (Aturan Sarrus)
        // Hati-hati nulis indeksnya, rawan typo!
        float det = (m[0][0] * m[1][1] * m[2][2]) 
                  + (m[0][1] * m[1][2] * m[2][0]) 
                  + (m[0][2] * m[1][0] * m[2][1])
                  - (m[0][2] * m[1][1] * m[2][0]) 
                  - (m[0][0] * m[1][2] * m[2][1]) 
                  - (m[0][1] * m[1][0] * m[2][2]);
                  
        cout << "\nDeterminan (Aturan Sarrus) = " << det << "\n";

    } else {
        cout << "Pilihan tidak valid, kembali ke menu utama.\n";
    }
    cout << "-------------------------------------\n";
}

void menuBitwise() {
    cout << "\n[Masuk ke Menu Bitwise]\n";
    cout << "=== Konverter Biner & Operasi Bitwise ===\n\n";

    int angka1, angka2;

    // Kita batasi 0-255 biar pas 8-bit (1 byte)
    cout << "Masukkan angka pertama (0-255): ";
    cin >> angka1;
    cout << "Masukkan angka kedua (0-255): ";
    cin >> angka2;

    // bitset<8> fungsinya buat ngubah integer jadi format biner 8 digit
    bitset<8> biner1(angka1);
    bitset<8> biner2(angka2);

    cout << "\n[Representasi Biner (8-bit)]\n";
    cout << "Angka 1 (" << angka1 << ")\t= " << biner1 << "\n";
    cout << "Angka 2 (" << angka2 << ")\t= " << biner2 << "\n";

    cout << "\n[Hasil Kalkulasi Bitwise]\n";

    // 1. AND (&) - Bit akan 1 HANYA JIKA kedua bit atas dan bawah bernilai 1
    cout << "1. AND (&)\t: " << (biner1 & biner2) << " (Desimal: " << (angka1 & angka2) << ")\n";

    // 2. OR (|) - Bit akan 1 JIKA SALAH SATU atau KEDUA bit bernilai 1
    cout << "2. OR (|)\t: " << (biner1 | biner2) << " (Desimal: " << (angka1 | angka2) << ")\n";

    // 3. XOR (^) - Bit akan 1 HANYA JIKA kedua bit BERBEDA (satu 1, satu 0)
    cout << "3. XOR (^)\t: " << (biner1 ^ biner2) << " (Desimal: " << (angka1 ^ angka2) << ")\n";

    // 4. NOT (~) - Membalikkan semua bit (0 jadi 1, 1 jadi 0)
    cout << "4. NOT (~A1)\t: " << (~biner1) << "\n";

    cout << "-------------------------------------\n";
}

void menuAkademik() {
    cout << "\n[Masuk ke Menu Akademik]\n";
    cout << "=== Evaluator Predikat Nilai ===\n\n";

    float tugas, uts, uas, nilaiAkhir;

    // Minta input nilai dari user
    cout << "Masukkan Nilai Tugas (0-100): ";
    cin >> tugas;
    cout << "Masukkan Nilai UTS (0-100): ";
    cin >> uts;
    cout << "Masukkan Nilai UAS (0-100): ";
    cin >> uas;

    // Validasi sederhana, mastiin input nggak ngaco
    if (tugas < 0 || tugas > 100 || uts < 0 || uts > 100 || uas < 0 || uas > 100) {
        cout << "\nError: Nilai harus berada di rentang 0 sampai 100!\n";
        return; // Balik ke menu utama
    }

    // Hitung Nilai Akhir (Contoh Bobot: Tugas 20%, UTS 30%, UAS 50%)
    nilaiAkhir = (tugas * 0.20) + (uts * 0.30) + (uas * 0.50);
    
    cout << "\n-------------------------------------\n";
    cout << "Nilai Akhir Anda : " << nilaiAkhir << "\n";
    cout << "Predikat         : ";

    // Bikin variabel string buat nyimpen kalimat yang mau ditulis ke file txt
    string teksRiwayat = "Nilai Akhir: " + to_string(nilaiAkhir) + " | Predikat: ";

    // Logika if-else beruntun untuk nentuin predikat
    if (nilaiAkhir >= 85) {
        cout << "A (Sangat Baik)\n";
        teksRiwayat += "A"; // Tambahin huruf A ke teksRiwayat
    } else if (nilaiAkhir >= 70) {
        cout << "B (Baik)\n";
        teksRiwayat += "B";
    } else if (nilaiAkhir >= 55) {
        cout << "C (Cukup)\n";
        teksRiwayat += "C";
    } else if (nilaiAkhir >= 40) {
        cout << "D (Kurang)\n";
        teksRiwayat += "D";
    } else {
        cout << "E (Gagal - Silakan ngulang tahun depan ya!)\n";
        teksRiwayat += "E";
    }
    
    // PANGGIL FUNGSI PENCATAT DI SINI
    catatRiwayat(teksRiwayat);
    cout << "\n[!] Data berhasil disimpan ke riwayat_project.txt\n";
    
    cout << "-------------------------------------\n";
}

void menuAkarKuadrat() {
    cout << "\n[Masuk ke Menu Akar Kuadrat]\n";
    cout << "Persamaan Kuadrat: ax^2 + bx + c = 0\n\n";
    
    // Pakai float biar bisa nampung angka desimal
    float a, b, c, D, x1, x2;

    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "Masukkan nilai c: ";
    cin >> c;

    // Validasi: Nilai 'a' gak boleh 0, karena kalau 0 jadinya persamaan linear biasa
    if (a == 0) {
        cout << "Gagal: Nilai 'a' tidak boleh 0!\n";
        return; // Langsung keluar dari fungsi dan balik ke menu utama
    }

    // Hitung Diskriminan
    D = (b * b) - (4 * a * c);
    cout << "\nNilai Diskriminan (D) = " << D << "\n";

    // Logika penentuan akar berdasarkan nilai D
    if (D > 0) {
        cout << "Status: Akar Real dan Berbeda\n";
        // Rumus ABC: (-b +- akar(D)) / 2a
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
        
    } else if (D == 0) {
        cout << "Status: Akar Real dan Kembar\n";
        x1 = -b / (2 * a);
        cout << "x1 = x2 = " << x1 << "\n";
        
    } else {
        cout << "Status: Akar Imajiner (Kompleks)\n";
        // Kalau imajiner, bagian real dan imajinernya dihitung terpisah biar bisa diprint
        float bagianReal = -b / (2 * a);
        float bagianImajiner = sqrt(-D) / (2 * a); // -D biar angkanya jadi positif sebelum diakar
        
        cout << "x1 = " << bagianReal << " + " << bagianImajiner << "i\n";
        cout << "x2 = " << bagianReal << " - " << bagianImajiner << "i\n";
    }
    
    cout << "-------------------------------------\n";
}