#include "TextEditor.h"
#include <iostream>
#include <sstream>

address head = nullptr; // Linked list head
List undoStack[100], redoStack[100]; // Stack untuk undo/redo
int undoTop = -1, redoTop = -1;       // Indeks stack

address createNode(const string &word) {
    // I.S: word berisi kata yang akan dimasukkan ke dalam node baru
    // F.S: Node baru dibuat dengan kata word, next diset ke nullptr, dan mengembalikan alamat node baru

    address newNode = new Node;
    newNode->word = word;
    newNode->next = nullptr;
    return newNode;
}

address copyList(address source) {
    // I.S: source adalah head dari linked list yang akan disalin
    // F.S: Mengembalikan alamat head dari linked list baru yang merupakan salinan dari source

    if (source == nullptr) {
        return nullptr;

    }
    address newHead = createNode(source->word);
    address tempSrc = source->next;
    address tempDest = newHead;

    while (tempSrc != nullptr) {
        tempDest->next = createNode(tempSrc->word);
        tempDest = tempDest->next;
        tempSrc = tempSrc->next;
    }
    return newHead;
}

void pushUndoState() {
    // I.S: undoTop menunjukkan indeks terakhir dalam undoStack
    // F.S: Menyimpan salinan linked list saat ini ke undoStack dan mengatur ulang redoTop

    if (undoTop < 99) {
        undoStack[++undoTop].head = copyList(head);
        redoTop = -1;
    }
}

void clearList() {
    // I.S: head menunjuk ke linked list yang ada
    // F.S: Semua elemen linked list dihapus dan head disetel ke nullptr

    while (head) {
        address temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

void insertParagraph(const string &paragraph) {
    // I.S: paragraph berisi teks yang akan dimasukkan ke dalam linked list
    // F.S: Paragraf dipecah menjadi kata-kata dan dimasukkan ke dalam linked list

    pushUndoState();
    stringstream ss(paragraph);
    string word;
    address last = head;

    while (ss >> word) {
        address newNode = createNode(word);
        if (!head) {
            head = newNode;
            last = head;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
    cout << endl;
    cout << "Yeey Paragraf Berhasil Dimasukkan!" << endl;

}

void insertWordAtPosition(const string &word, int position) {
    // I.S: word berisi kata yang akan dimasukkan pada posisi tertentu dalam linked list
    // F.S: Kata dimasukkan ke dalam linked list pada posisi yang ditentukan

    pushUndoState();
    address newNode = createNode(word);

    if (position <= 1 || !head) {
        newNode->next = head;
        head = newNode;
    } else {
        int i = 1;
        address temp = head;
        while (i < position && temp->next) {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "+-----------------------------+\n";
    cout << "| Word inserted successfully! |" << endl;
    cout << "+-----------------------------+\n";
    displayText();
}

void deleteWordAtPosition(int position) {
    // I.S: position adalah posisi kata yang akan dihapus dari linked list
    // F.S: Kata pada posisi yang ditentukan dihapus jika ada

    if (!head) {
        pushUndoState();
    }
    if (position == 1) {
        address temp = head;
        head = head->next;
        delete temp;
    } else {
        address temp = head;
        for (int i = 1; i < position - 1 && temp->next; ++i) {
            temp = temp->next;
        }
        if (temp->next) {
            address toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }
    cout << "+-----------------------------+\n";
    cout << "|    Kata berhasil dihapus!   |" << endl;
    cout << "+-----------------------------+\n";

    displayText();
}

void displayText() {
    // I.S: head menunjuk ke linked list yang ada
    // F.S: Semua kata dalam linked list ditampilkan ke layar

    address temp = head;
    while (temp) {
        cout << temp->word << " ";
        temp = temp->next;
    }
    cout << endl;
}

void searchWord(const string &word) {
    // I.S: word berisi kata yang akan dicari dalam linked list
    // F.S: Menampilkan posisi kata jika ditemukan, jika tidak menampilkan pesan tidak ditemukan

    address temp = head;
    int position = 1;
    bool found = false;

    while (temp) {
        if (temp->word == word) {
            cout << "Kata di temukan di posisi: " << position << endl;
            found = true;
        }
        temp = temp->next;
        position++;
    }
    if (!found) cout << "Kata tidak di temukan!." << endl;
}

void wordCount() {
    // I.S: head menunjuk ke linked list yang ada
    // F.S: Menampilkan jumlah total kata dalam linked list

    int Count = 0;
    address temp = head;

    while (temp) {
        Count++;
        temp = temp->next;
    }
    cout << "Total word count: " << Count << endl;
}

void undo() {
    // I.S: undoStack berisi setidaknya satu status sebelumnya
    // F.S: Mengembalikan linked list ke status sebelumnya

    if (undoTop >= 0) {
        redoStack[++redoTop].head = copyList(head);
        clearList();
        head = undoStack[undoTop--].head;

        cout << "+--------------------------+\n";
        cout << "|      Undo Berhasil!      |\n";
        cout << "+--------------------------+\n";
        displayText();
    } else {
        cout << "Tidak ada yang bisa di-undo." << endl;
    }
}

void redo() {
    // I.S: redoStack berisi setidaknya satu status yang dapat dipulihkan
    // F.S: Mengembalikan linked list ke status yang terakhir dihapus

    if (redoTop >= 0) {
        undoStack[++undoTop].head = copyList(head);
        clearList();
        head = redoStack[redoTop--].head;

        cout << "+--------------------------+\n";
        cout << "|      Redo Berhasil!      |\n";
        cout << "+--------------------------+\n";
        displayText();
    } else {
        cout << "Tidak ada yang bisa di-redo." << endl;
    }
}

