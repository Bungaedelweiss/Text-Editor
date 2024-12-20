#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include <sstream>
#include <string>

using namespace std;

typedef struct Node *address;
struct Node {
    string word;
    address next;
};

struct List {
    address head;
};

address createNode(const string &word);
address copyList(address source);
void clearList();

void insertParagraph(const string &paragraph);
void insertWordAtPosition(const string &word, int position);
void deleteWordAtPosition(int position);
void displayText();
void searchWord(const string &word);
void wordCount();
void pushUndoState();
void undo();
void redo();

#endif

