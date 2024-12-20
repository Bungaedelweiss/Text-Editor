#ifndef TEXTEDITOR_H_INCLUDED
#define TEXTEDITOR_H_INCLUDED

#include <string>

using namespace std;

typedef string Infotype;

typedef struct ElmWord *AdrWord;

typedef struct ElmWord {
    Infotype info;
    AdrWord next;
};

typedef struct ListWord{
    AdrWord first;
};

typedef struct InfotypeParagraph{
    Infotype paragraph_id;
    ListWord words;
};

typedef struct ElmParagraph *AdrParagraph;

typedef struct ElmParagraph {
    InfotypeParagraph info;
    AdrParagraph next;
    AdrParagraph prev;
};

typedef struct ListParagraph{
    AdrParagraph first;
    AdrParagraph last;
};

typedef struct InfotypeAction{
    Infotype action;
    ListParagraph state;
};

typedef struct ElmAction *AdrAction;

typedef struct ElmAction {
    InfotypeAction info;
    AdrAction next;
    AdrAction prev;
};

typedef struct ListAction{
    AdrAction first;
    AdrAction last;
};


void createListParagraph(ListParagraph *L);
void createListWord(ListWord *L);
void createListAction(ListAction *L);
AdrWord createWordElement(Infotype word);
AdrParagraph createParagraphElement(Infotype paragraph_id);
AdrAction createActionElement(Infotype action_desc, ListParagraph state);
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
void printAll(ListParagraph L);
void printWordsInParagraph(ListParagraph L, Infotype paragraph_id);
void printActions(ListAction L);
void saveUndo(ListAction *undo, ListParagraph *current);
void performUndo(ListAction *undo, ListAction *redo, ListParagraph *current);
void performRedo(ListAction *redo, ListAction *undo, ListParagraph *current);

#endif // TEXTEDITOR_H_INCLUDED
