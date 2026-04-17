#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int matriks[3][3];
    
    // Bikin seed biar angkanya beneran acak tiap di-run
    srand(time(0)); 

    cout << "==== Matriks Acak 3x3 ====\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            // Generate angka acak dari 1 sampai 9
            matriks[i][j] = (rand() % 9) + 1; 
            cout << matriks[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n==== Hasil Transpose ====\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            // Nampilin transpose (baris ditukar jadi kolom)
            cout << matriks[j][i] << " "; 
        }
        cout << "\n";
    }

    return 0;
}