#ifndef HASHING_TABLE_H
#define HASHING_TABLE_H
#include <string>
#include <iostream>
using namespace std;
//ΔΗΛΩΣΗ ΤΗΣ ΚΛΑΣΗΣ ΠΙΝΑΚΑ ΚΑΤΑΚΕΡΜΑΤΙΣΜΟΥ
class har//ΚΛΑΣΗ ΓΙΑ ΤΟΝ ΠΙΝΑΚΑ ΚΑΤΑΚΕΡΜΑΤΙΣΜΟΥ
{
private:
string *ha;//ΠΙΝΑΚΑΣ ΚΑΤΑΚΕΡΜΑΤΙΣΜΟΥ
int *count;//Πίνακας για το πλήθος εμφανίσεων ζευγαριών
int size;//ΜΕΓΕΘΟΣ ΠΙΝΑΚΑ ΚΑΤΑΚΕΡΜΑΤΙΣΜΟΥ
int func_hashing(string x);//ΣΥΝΑΡΤΗΣΗ ΚΑΤΑΚΕΡΜΑΤΙΣΜΟΥ
public:
har(int t_size);
~har();//destructor για την διαγραφή αντικειμένων
void insert(string x);//συνάρτηση για την εισαγωγή του ζευγαριού
void search_string(string x,int &pos);//συνάρτηση για την αναζήτηση του ζευγαριού στον πίνακα
void search(string Q[]);//συνάρτηση για την αναζήτηση των ζευγαριών του συνόλου Q στον πίνακα και εκτύπωση των κατάλληλων πληροφοριών
};

#endif