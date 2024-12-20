#include "textEditor.h"
#include <iostream>

using namespace std;

void createListParagraph(ListParagraph *L){
    /* I.S. -
       F.S. Dihasilkan sebuah ListParagraph kosong dengan pointer first dan last bernilai nullptr */

    L->first = nullptr; // Set pointer first ke null
    L->last = nullptr; // Set pointer last ke null
}

void createListWord(ListWord *L){
     /* I.S. -
       F.S. Dihasilkan sebuah ListWord kosong dengan pointer first bernilai nullptr */

    L->first = nullptr; // Set pointer first ke null
}

void createListAction(ListAction *L){
    /* I.S. -
       F.S. Dihasilkan sebuah ListAction kosong dengan pointer first dan last bernilai nullptr */

    L->first = nullptr; // Set pointer first ke null
    L->last = nullptr; // Set pointer last ke null
}

AdrWord createWordElement(Infotype word){
    /* I.S. Tidak ada elemen untuk kata
       F.S. Sebuah elemen kata baru berhasil dibuat, dengan info = word dan next = nullptr */

    AdrWord newWord = new ElmWord; // Alokasi memori untuk elemen baru
    newWord->info = word;          // Mengisi elemen dengan data kata
    newWord->next = nullptr;       // Pointer next diset ke null
    return newWord;
}

AdrParagraph createParagraphElement(Infotype paragraph_id){
    /* I.S. Tidak ada elemen untuk paragraf
       F.S. Sebuah elemen paragraf baru berhasil dibuat, dengan info.paragraph_id = paragraph_id,
            words sebagai ListWord kosong, next = nullptr, dan prev = nullptr */

    AdrParagraph newParagraph = new ElmParagraph;   // Alokasi memori untuk elemen baru
    newParagraph->info.paragraph_id = paragraph_id; // Mengisi ID paragraf
    createListWord(&newParagraph->info.words);      // Inisialisasi list kata kosong
    newParagraph->next = nullptr;                   // Pointer next diset ke null
    newParagraph->prev = nullptr;                   // Pointer prev diset ke null
    return newParagraph;
}

AdrAction createActionElement(Infotype action_desc, ListParagraph state){
    /* I.S. Tidak ada elemen untuk aksi
       F.S. Sebuah elemen aksi baru berhasil dibuat, dengan info.action = action_desc,
            state berisi snapshot ListParagraph, next = nullptr, dan prev = nullptr */

    AdrAction newAction = new ElmAction;  // Alokasi memori untuk elemen baru
    newAction->info.action = action_desc; // Mengisi deskripsi aksi
    newAction->info.state = state;        // Menyimpan snapshot state paragraf
    newAction->next = nullptr;            // Pointer next diset ke null
    newAction->prev = nullptr;            // Pointer prev diset ke null
    return newAction;
}
void insertParagraph(ListParagraph *L, Infotype id);
void insertWord(ListWord *L, Infotype word);
void addWordToParagraph(ListParagraph *L, Infotype paragraph_id, Infotype word);
void insertAction(ListAction *L, Infotype action_desc, ListParagraph state);
void deleteParagraph(ListParagraph *L, Infotype id);
void deleteWord(ListWord *L, Infotype word);
void deleteWordInParagraph(ListParagraph *L, Infotype paragraph_id, Infotype word);
void deleteLastAction(ListAction *L);
AdrParagraph searchParagraph(ListParagraph L, Infotype id);
AdrWord searchWord(ListWord L, Infotype word);
void printAll(ListParagraph L) {
    /* I.S. Terdefinisi ListParagraph L yang berisi elemen-elemen paragraf
       F.S. Seluruh paragraf dalam L, beserta kata-kata di dalamnya, ditampilkan ke layar.
            Jika tidak ada paragraf, akan ditampilkan pesan "tidak ada paragraf." */

    // Kamus Data:
    // currentParagraph : AdrParagraph (pointer untuk traversal pada ListParagraph)
    // currentWord      : AdrWord (pointer untuk traversal pada ListWord di tiap paragraf)

    // Algoritma:
    AdrParagraph currentParagraph = L.first; // Pointer untuk traversal paragraf
    if (currentParagraph == nullptr) {
        // Jika tidak ada paragraf
        cout << "tidak ada paragraf." << endl; // Pesan jika ListParagraph kosong
        return;
    }

    cout << "=== Semua Paragraf ===" << endl; // Header untuk output paragraf
    while (currentParagraph != nullptr) {
        // Cetak ID paragraf
        cout << "Paragraf: " << currentParagraph->info.paragraph_id << endl;

        // Traversal kata-kata di dalam paragraf
        AdrWord currentWord = currentParagraph->info.words.first; // Pointer untuk sublist kata
        if (currentWord == nullptr) {
            // Jika sublist kosong
            cout << "  (tidak ada kata)" << endl; // Pesan jika tidak ada kata dalam paragraf
        } else {
            while (currentWord != nullptr) {
                // Cetak setiap kata
                cout << currentWord->info << " ";
                currentWord = currentWord->next; // Pindah ke kata berikutnya
            }
            cout << endl; // Baris baru setelah mencetak semua kata
        }
        currentParagraph = currentParagraph->next; // Pindah ke paragraf berikutnya
    }
}


void printWordsInParagraph(ListParagraph L, Infotype paragraph_id);
void printActions(ListAction L);
void saveUndo(ListAction *undo, ListParagraph *current);
void performUndo(ListAction *undo, ListAction *redo, ListParagraph *current);
void performRedo(ListAction *redo, ListAction *undo, ListParagraph *current);
