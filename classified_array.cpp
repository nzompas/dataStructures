#include "classified_array.h"
#include <string>
#include <iostream>
#include <fstream>
#include "time.h"
#include <cmath>
using namespace std;
const int Q_SIZE=1000;//ΔΗΛΩΣΗ ΜΕΓΕΘΟΥΣ ΤΟΥ ΣΥΝΟΛΟΥ Q
//ΥΛΟΠΟΙΗΣΗ ΤΗΣ ΚΛΑΣΗΣ ΤΑΞΙΝΟΜΗΜΕΝΟΥ ΠΙΝΑΚΑ
cda::cda(){//ΑΡΧΙΚΟΠΟΙΗΣΗ ΤΩΝ ΜΕΤΑΒΛΗΤΩΝ ΚΑΙ ΔΗΜΙΟΥΡΓΙΑ ΤΩΝ ΠΙΝΑΚΩΝ
  size=10000;
  p=-1;//ΑΔΕΙΟΣ ΠΙΝΑΚΑΣ
  ca=new string[10000];
  count= new int[10000];
}
cda::~cda(){
  delete []ca;
  delete []count;
}

void cda::push(string x){
  int pos, i;
  if(binary_search_string(x, pos)){
    count[pos]++;//αν το ζευγάρι υπάρχει οι εμφανίσεις αυξάνονται κατα 1
  }
  else{//αν δεν υπάρχει εισάγεται στην κατάλληλη θέση του πίνακα ώστε να διατηρηθεί η φθίνουσα ταξινόμηση και οι εμφανίσεις θέτονται σε 1
    if((p+1)==size){
      string *temps;
      int *tempi;
      temps=new string[size+1000];
      tempi=new int[size+1000];
      for(i=0;i<=p;i++){
        temps[i]=ca[i];
        tempi[i]=count[i];
      }
      delete []ca;
      delete []count;
      ca=temps;
      count=tempi;
      size=size+100;
      }
      p++;
      ca[p]=x;
      count[p]=1;
    sort();
  }
}

void cda::sort(){//ΦΘΙΝΟΥΣΑ ΤΑΞΙΝΟΜΗΣΗ ΠΙΝΑΚΑ
  bool flag=false;
  string temp;
  int i, tempi;
  for(i=p;((i>0)&&(!flag));i--){
    if(ca[i]>ca[i-1]){
      temp=ca[i];
      ca[i]=ca[i-1];
      ca[i-1]=temp;
      tempi=count[i-1];
      count[i-1]=count[i];
      count[i]=tempi;
    }
    else {flag=true;}
  }
}

bool cda::binary_search_string(string x,int &pos){//ΥΛΟΠΟΙΗΣΗ ΤΗΣ ΔΥΑΔΙΚΗΣ ΑΝΑΖΗΤΗΣΗΣ
  int l, r, m;
  l=0;
  r=p;
  bool flag=false;
  while((!flag)&&(l<=r)){
    m=(l+r)/2;
    if(ca[m]==x){
      flag=true;
      pos=m;
    }
    else if(ca[m]<x){
      r=m-1;
    }
    else{
      l=m+1;
    }
  }
  return flag;
}

void cda::search(string Q[]){
  int i,j,pos, positions[Q_SIZE];
  ofstream f;
  f.open("output.txt",ios::out | ios::app );
  clock_t start, end;
  start=clock();
  f<<"CLASSIFIED ARRAY"<<endl<<endl;
  for(i=0;i<Q_SIZE;i++){//αναζήτηση των στοιχείων του συνόλου Q στον πίνακα
      binary_search_string(Q[i],pos);
      positions[i]=pos;
  }
    end=clock();
    for(i=0;i<Q_SIZE;i++){//ΑΠΟΘΗΚΕΥΣΗ ΣΤΟ ΑΡΧΕΙΟ ΕΞΟΔΟΥ ΤΩΝ ΖΗΤΟΥΜΕΝΩΝ ΠΛΗΡΟΦΟΡΙΩΝ ΓΙΑ ΚΑΘΕ ΣΤΟΙΧΕΙΟ ΤΟΥ ΣΥΝΟΛΟΥ Q
      f<<"\""<<Q[i]<<"\""<<" : "<<count[positions[i]]<<" times found in the text."<<endl;
  }
  int min;
  double sec, tt;
  tt=((double) (end-start)/CLOCKS_PER_SEC);
 // tt=round(tt*100)/100;
  min=tt/60;
  sec=tt-min*60;
  f<<endl<<"Total time of search in classified array : "<<min<<" minutes & "<<sec<<" seconds."<<endl<<endl;//ΑΠΟΘΗΚΕΥΣΗ ΤΟΥ ΣΥΝΟΛΙΚΟΥ ΧΡΟΝΟΥ ΑΝΑΖΗΤΗΣΗΣ ΤΩΝ ΣΤΟΙΧΕΙΩΝ ΤΟΥ ΣΥΝΟΛΟΥ Q ΣΤΟ ΑΡΧΕΙΟ ΕΞΟΔΟΥ
  f.close();
}