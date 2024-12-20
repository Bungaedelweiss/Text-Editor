#include <iostream>
#include "textEditor.h"

using namespace std;

int main() {
    ListParagraph paragraf;
    createListParagraph(&paragraf);

    int choice;
    do {
        cout << "\n=== Text Editor Menu ===" << endl;
        cout << "1. Tambah Paragraf Baru" << endl;
        cout << "2. Tambah Kata ke Paragraf" << endl;
        cout << "3. Tampilkan Semua Paragraf" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Infotype paragraph_id;
                cout << "Masukkan Paragraf ID: ";
                cin.ignore();
                getline(cin, paragraph_id);

                AdrParagraph newParagraph = createParagraphElement(paragraph_id);
                if (paragraf.first == nullptr) {
                    paragraf.first = newParagraph;
                    paragraf.last = newParagraph;
                } else {
                    paragraf.last->next = newParagraph;
                    newParagraph->prev = paragraf.last;
                    paragraf.last = newParagraph;
                }
                cout << "Paragraf baru berhasil ditambahkan!" << endl;
                break;
            }
            case 2: {
                Infotype paragraph_id, word;
                cout << "Masukkan Paragraf ID yang ingin ditambahkan kata: ";
                cin.ignore();
                getline(cin, paragraph_id);

                AdrParagraph targetParagraph = paragraf.first;
                while (targetParagraph != nullptr && targetParagraph->info.paragraph_id != paragraph_id) {
                    targetParagraph = targetParagraph->next;
                }

                if (targetParagraph == nullptr) {
                    cout << "Paragraf dengan ID '" << paragraph_id << "' tidak ditemukan!" << endl;
                } else {
                    cout << "Masukkan kata: ";
                    getline(cin, word);

                    AdrWord newWord = createWordElement(word);
                    if (targetParagraph->info.words.first == nullptr) {
                        targetParagraph->info.words.first = newWord;
                    } else {
                        AdrWord temp = targetParagraph->info.words.first;
                        while (temp->next != nullptr) {
                            temp = temp->next;
                        }
                        temp->next = newWord;
                    }
                    cout << "Kata berhasil ditambahkan ke paragraf!" << endl;
                }
                break;
            }
            case 3: {
                printAll(paragraf);
                break;
            }
            case 4: {
                cout << "Keluar dari program. Terima kasih!" << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
    } while (choice != 4);

    return 0;
}
