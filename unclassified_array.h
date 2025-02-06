#ifndef UNCLASSIFIED_ARRAY_H
#define UNCLASSIFIED_ARRAY_H
#include <string>
using namespace std;
//ΔΗΛΩΣΗ ΤΗΣ ΚΛΑΣΗΣ ΑΤΑΞΙΝΟΜΗΤΟΥ ΠΙΝΑΚΑ
class una{ //κλάση για τον αδόμητο πίνακα
private:string *ua;//Πίνακας για τον αδόμητο πίνακα
int *count, size, p;// Πίνακας για το πλήθος εμφανίσεων ζευγαριών, μέγεθος πίνακα, θέση του τελευταίου στοιχείου
public:
una();//constructor για την κατασκευή αντικειμένων
~una();//destructor για την διαγραφή αντικειμένων
void push(string x);//συνάρτηση για την εισαγωγή του ζευγαριού
bool search_string(string x,int &pos);//συνάρτηση για την αναζήτηση του ζευγαριού στον πίνακα
void search(string Q[]);//συνάρτηση για την αναζήτηση των ζευγαριών του συνόλου Q στον πίνακα και εκτύπωση των κατάλληλων πληροφοριών
};
#endif