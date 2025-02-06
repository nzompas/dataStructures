#include "unclassified_array.h"
#include <iostream>
#include <string>
#include "time.h"
#include <fstream>
#include <cmath>
using namespace std;
const int Q_SIZE=1000;//ΔΗΛΩΣΗ ΜΕΓΕΘΟΥΣ ΤΟΥ ΣΥΝΟΛΟΥ Q
//ΥΛΟΠΟΙΗΣΗ ΤΗΣ ΚΛΑΣΗΣ ΑΤΑΞΙΝΟΜΗΤΟΥ ΠΙΝΑΚΑ
una::una(){//ΑΡΧΙΚΟΠΟΙΗΣΗ ΤΩΝ ΜΕΤΑΒΛΗΤΩΝ ΚΑΙ ΔΗΜΙΟΥΡΓΙΑ ΤΩΝ ΠΙΝΑΚΩΝ
  size=10000;
  p=-1;
  ua=new string[10000];
  count= new int[10000];
}
una::~una(){
  delete[]ua;
  delete[]count;
}
void una::push(string x){
  int pos, i;
  if(search_string(x, pos)){
    count[pos]++;//αν το ζευγάρι υπάρχει οι εμφανίσεις αυξάνονται κατα 1
  }
  else{//αν δεν υπάρχει εισάγεται στον πίνακα και οι εμφανίσεις θέτονται σε 1
    if((p+1)==size){
      string *temps;
      int *tempi;
      temps=new string[size+1000];
      tempi=new int[size+1000];
      for(i=0;i<=p;i++){
        temps[i]=ua[i];
        tempi[i]=count[i];
      }
      delete []ua;
      delete []count;
      ua=temps;
      count=tempi;
      size=size+100;
      p++;
      ua[p]=x;
      count[p]=1;
    }
    else{
      p++;
      ua[p]=x;
      count[p]=1;      
    }
  }
}

bool una::search_string(string x, int &pos){
  int i, elements;//αναζητείται το στοιχείο στον πίνακα και αν βρεθεί επιστρέφεται η θέση του στον πίνακα και true
  elements=p;
  bool flag=false;
  for(i=0;i<=elements&&(!flag);i++){
    if(ua[i]==x){
      flag=true;
      pos=i;
    }
  }
  return flag;
}
void una::search(string Q[]){
  int i,j,pos, positions[Q_SIZE];
  ofstream f;
  f.open("output.txt",ios::out | ios::app );
  clock_t start, end;
  double tt;
  start=clock();
  f<<"UNCLASSIFIED ARRAY"<<endl<<endl;
  for(i=0;i<Q_SIZE;i++){//αναζήτηση των στοιχείων του συνόλου Q στον πίνακα
      search_string(Q[i],pos);
      positions[i]=pos;
  }
  end=clock();
  tt=((double) (end-start)/CLOCKS_PER_SEC);
    for(i=0;i<Q_SIZE;i++){//ΑΠΟΘΗΚΕΥΣΗ ΣΤΟ ΑΡΧΕΙΟ ΕΞΟΔΟΥ ΤΩΝ ΖΗΤΟΥΜΕΝΩΝ ΠΛΗΡΟΦΟΡΙΩΝ ΓΙΑ ΚΑΘΕ ΣΤΟΙΧΕΙΟ ΤΟΥ ΣΥΝΟΛΟΥ Q
      f<<"\""<<Q[i]<<"\""<<" : "<<count[positions[i]]<<" times found in the text."<<endl;
  }
  int min,t;
  double sec;
 // tt=round(tt*100)/100;
  min=tt/60;
  sec=tt-min*60;
  f<<endl<<"Total time of search in unclassified array : "<<min<<" minutes & "<<sec<<" seconds."<<endl<<endl;//ΑΠΟΘΗΚΕΥΣΗ ΤΟΥ ΣΥΝΟΛΙΚΟΥ ΧΡΟΝΟΥ ΑΝΑΖΗΤΗΣΗΣ ΤΩΝ ΣΤΟΙΧΕΙΩΝ ΤΟΥ ΣΥΝΟΛΟΥ Q ΣΤΟ ΑΡΧΕΙΟ ΕΞΟΔΟΥ
 f.close(); 
}
