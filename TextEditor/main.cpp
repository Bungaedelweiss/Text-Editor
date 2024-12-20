#include "TextEditor.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int choice, position;
    string text, word;
    address head;

    while (true) {
        cout << "\n+===========================+\n";
        cout << "|       Text Editor         |\n";
        cout << "\n+===========================+\n";
        cout << "| 1. Masukkan Kalimat       |\n";
        cout << "| 2. Sisipkan Kata          |\n";
        cout << "| 3. Hapus Kata             |\n";
        cout << "| 4. Tampilkan Teks         |\n";
        cout << "| 5. Cari Kata              |\n";
        cout << "| 6. Total Kata             |\n";
        cout << "| 7. Undo                   |\n";
        cout << "| 8. Redo                   |\n";
        cout << "| 9. Keluar                 |\n";
        cout << "+===========================+\n";
        cout << " Pilihan: ";
        cin >> choice;
        cin.ignore();
        system("cls");
        switch (choice) {
            case 1:
                cout << "+-----------------------------+\n";
                cout << "|       Masukkan Kalimat      |\n";
                cout << "+-----------------------------+\n";
                getline(cin, text);
                insertParagraph(text);
                break;
            case 2:
                cout << "+-----------------------------+\n";
                cout << "|        Sisipkan Kata        |\n";
                cout << "+-----------------------------+\n";
                displayText();
                cout << "============================" << endl;
                cout << "Masukkan Kata: ";
                cin >> word;
                cout << "Masukan posisi kata yang ingin di sisipkan: ";
                cin >> position;
                cout << endl;
                insertWordAtPosition(word, position);
                break;
            case 3:
                cout << "+-----------------------------+\n";
                cout << "|         Hapus Kata          |\n";
                cout << "+-----------------------------+\n";
                displayText();
                cout << "============================" << endl;
                cout << "Masukkan posisi yang ingin dihapus: ";
                cin >> position;
                cout << endl;
                deleteWordAtPosition(position);
                break;
            case 4:
                cout << "+-----------------------------+\n";
                cout << "|       Tampilkan Teks        |\n";
                cout << "+-----------------------------+\n";
                displayText();
                break;
            case 5:
                cout << "+-----------------------------+\n";
                cout << "|          Cari Kata          |\n";
                cout << "+-----------------------------+\n";
                cout << "Masukkan Kata yang ingin dicari: ";
                cin >> word;
                cout << endl;
                displayText();
                cout << endl;
                searchWord(word);
                break;
            case 6:
                cout << "+-----------------------------+\n";
                cout << "|          Total Kata         |\n";
                cout << "+-----------------------------+\n";
                wordCount();
                break;
            case 7:
                undo();
                break;
            case 8:
                redo();
                break;
            case 9:
                clearList();
                return 0;
            default:
                cout << "Opsi tidak valid!" << endl;
        }
    }
}
