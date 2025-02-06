#include "hashing_table.h"
#include <string>
#include <iostream>
#include <fstream>
#include "time.h"
#include <cmath>
using namespace std;
const int Q_SIZE=1000;//ΔΗΛΩΣΗ ΜΕΓΕΘΟΥΣ ΤΟΥ ΣΥΝΟΛΟΥ Q
//ΥΛΟΠΟΙΗΣΗ ΤΗΣ ΚΛΑΣΗΣ ΠΙΝΑΚΑ ΚΑΤΑΚΕΡΜΑΤΙΣΜΟΥ
har::har(int t_size)
{
  size=t_size;
  ha=new string[size];
  count=new int[size];
  for(int i=0;i<size;i++) 
    {
      ha[i]=" ";
      }
  }

har::~har(){
  delete[]ha;
  delete[]count;
}

int har::func_hashing(string x)//ΕΠΙΣΤΡΟΦΗ ΘΕΣΗΣ ΤΟΥ ΖΕΥΓΑΡΙΟΥ(ΑΘΡΟΙΣΜΑ ΓΡΑΜΜΑΤΩΝ)
{
  int sumx=0;
  for (int i=0;i<x.size();i++)
    {
      sumx+=x[i];
    }
  return sumx;
}

void har::insert(string x)
{
  int i,pos;
  pos=func_hashing(x);
  if (ha[pos]==" ") {//ΑΝ Η ΘΕΣΗ ΠΟΥ ΠΑΡΑΓΕΙ Η ΣΥΝΑΡΤΗΣΗ ΚΑΤΑΚΕΡΜΑΤΙΣΜΟΥ ΕΙΝΑΙ ΚΕΝΗ ΕΙΣΑΓΕΤΑΙ ΤΟ ΖΕΥΓΟΣ
    ha[pos]=x;
    count[pos]=1;}
   else {//ΑΝ Η ΘΕΣΗ ΠΟΥ ΠΑΡΑΓΕΙ Η ΣΥΝΑΡΤΗΣΗ ΚΑΤΑΚΕΡΜΑΤΙΣΜΟΥ ΔΕΝ ΕΙΝΑΙ ΚΕΝΗ
    if (ha[pos]==x)//ΑΝ ΤΟ ΖΕΥΓΟΣ ΥΠΑΡΧΕΙ ΣΤΗ ΘΕΣΗ ΠΟΥ ΠΑΡΑΓΕΙ Η ΣΥΝΑΡΤΗΣΗ ΚΑΤΑΚΕΡΜΑΤΙΣΜΟΥ ΑΥΞΑΝΕΤΑΙ ΤΟ ΠΛΗΘΟΣ ΕΜΦΑΝΙΣΕΩΝ ΤΟΥ
    {
     count[pos]++; 
    }
     else{//ΑΛΛΙΩΣ ΕΚΤΕΛΕΙΤΕ ΑΝΑΖΗΤΗΣΗ ΠΡΟΚΕΙΜΕΝΟΥ ΝΑ ΒΡΕΘΕΙ Η ΕΠΟΜΕΝΗ ΚΕΝΗ ΘΕΣΗ ΤΟΥ ΠΙΝΑΚΑ ΚΑΤΑΚΕΡΜΑΤΙΣΟΥ
       bool flag=false;
       for (i=pos+1;i<size&&(!flag);i++){
         if (ha[i]==x){//ΑΝ ΟΜΩΣ ΚΑΤΑ ΤΗΝ ΔΙΑΡΚΕΙΑ ΤΗΣ ΑΝΑΖΗΤΗΣΗΣ ΒΡΕΘΕΙ ΤΟ ΖΕΥΓΟΣ ΣΕ ΑΛΛΗ ΘΕΣΗ ΑΠΟ ΑΥΤΗΝ ΠΟΥ ΔΙΝΕΙ Η ΣΥΝΑΡΤΗΣΗ ΚΑΤΑΚΕΡΜΑΤΙΣΜΟΥ ΑΥΞΑΝΕΤΑΙ ΤΟ ΠΛΗΘΟΣ ΤΟΥ ΖΕΥΓΟΥΣ ΧΩΡΙΣ ΝΑ ΓΙΝΕΙ Η ΕΙΣΣΑΓΩΓΗ ΤΟΥ
           count[i]++;
           flag=true;
         }
         else if (ha[i]==" "){//ΕΥΡΕΣΗ ΤΗΣ ΕΠΟΜΕΝΗΣ ΚΕΝΗΣ ΘΕΣΗΣ
           ha[i]=x;
           count[i]=1;
           flag=true;
         }
       }
       for(i=0;i<pos&&(!flag);i++){
         if (ha[i]==x){
           count[i]++;
           flag=true;
         }
         else if (ha[i]==" "){
           ha[i]=x;
           count[i]=1;
           flag=true;
         }
       }
     }
  }
}

void har::search_string(string x, int &pos)
{
  int i,p;
  p=func_hashing(x);
    if (ha[p]==x)
    {
     pos=p;
    }
     else{
       bool flag=false;
       for (i=p+1;i<size&&(!flag);i++){
         if (ha[i]==x){
           pos=i;
           flag=true;
         }
       }
       for(i=0;i<p&&(!flag);i++){
         if (ha[i]==x){
           pos=i;
           flag=true;
         }
       }
     }
  }
  


void har::search(string *Q){
  int i,j,pos, positions[Q_SIZE];
  ofstream f;
  f.open("output.txt",ios::out | ios::app );
  clock_t start, end;
  start=clock();
  f<<"HASHING TABLE"<<endl<<endl;
  for(i=0;i<Q_SIZE;i++){//αναζήτηση των στοιχείων του συνόλου Q στον πίνακα
      search_string(Q[i],pos);
      positions[i]=pos;
  }
    end=clock();
    for(i=0;i<Q_SIZE;i++){//ΑΠΟΘΗΚΕΥΣΗ ΣΤΟ ΑΡΧΕΙΟ ΕΞΟΔΟΥ ΤΩΝ ΖΗΤΟΥΜΕΝΩΝ ΠΛΗΡΟΦΟΡΙΩΝ ΓΙΑ ΚΑΘΕ ΣΤΟΙΧΕΙΟ ΤΟΥ ΣΥΝΟΛΟΥ Q
      f<<"\""<<Q[i]<<"\""<<" : "<<count[positions[i]]<<" times found in the text."<<endl;
  }
  int min;
  double sec, tt;
  tt=((double) (end-start)/CLOCKS_PER_SEC);
  min=tt/60;
  sec=tt-min*60;
  f<<endl<<"Total time of search in hashing table : "<<min<<" minutes & "<<sec<<" seconds."<<endl<<endl;//ΑΠΟΘΗΚΕΥΣΗ ΤΟΥ ΣΥΝΟΛΙΚΟΥ ΧΡΟΝΟΥ ΑΝΑΖΗΤΗΣΗΣ ΤΩΝ ΣΤΟΙΧΕΙΩΝ ΤΟΥ ΣΥΝΟΛΟΥ Q ΣΤΟ ΑΡΧΕΙΟ ΕΞΟΔΟΥ
  f.close();
}