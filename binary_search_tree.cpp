#include "binary_search_tree.h"
#include <string>
#include <iostream>
#include <fstream>
#include "time.h"
using namespace std;
const int Q_SIZE=1000;//ΔΗΛΩΣΗ ΜΕΓΕΘΟΥΣ ΤΟΥ ΣΥΝΟΛΟΥ Q
//ΥΛΟΠΟΙΗΣΗ ΤΗΣ ΚΛΑΣΗΣ ΔΥΑΔΙΚΟΥ ΔΕΝΔΡΟΥ ΑΝΑΖΗΤΗΣΗΣ
bst::bst(){
    pos2=0;
  size=40000000;
  size2=10000;
  bt=new string[size];
  bt2=new string[size2];
  count=new int [size];
  count2=new int[size2];
  int i;
  for(i=0;i<size;i++){//ΑΡΧΙΚΟΠΟΙΗΣΗ ΤΟΥ ΠΙΝΑΚΑ ΜΕ ΚΕΝΟ ΓΙΑ ΕΛΕΓΧΟ ΕΙΣΑΓΩΓΗΣ
    bt[i]=" ";
    count[i]=0;
  }
}

bst::~bst(){
  delete[]bt;
  delete[]count;
  delete[]bt2;
  delete[]count2;
}

void bst::insert(string x){//ΕΙΣΑΓΩΓΗ ΖΕΥΓΟΥΣ
  int i=0,w, y, *tempi;
  string *temp;
  bool flag=false;

    while(!flag){
      if(bt[i]==" "){//ΑΝ Ο ΚΟΜΒΟΣ ΕΙΝΑΙ ΚΕΝΟΣ ΕΙΣΑΓΕΤΑΙ ΤΟ ΖΕΥΓΟΣ
        bt[i]=x;
        count[i]=1;
        flag=true;
      }
      else if(x==bt[i]){//ΑΝ ΤΟ ΖΕΥΓΟΣ ΥΠΑΡΧΕΙ ΣΤΟ ΔΕΝΔΡΟ ΑΥΞΑΝΟΝΤΑΙ ΟΙ ΕΜΦΑΝΙΣΕΙΣ ΤΟΥ
        flag=true;
        count[i]+=1;
      }
      else if(x<bt[i]){//ΜΕ ΒΑΣΗ ΤΗΝ ΘΕΩΡΙΑ ΤΩΝ ΔΥΑΔΙΚΩΝ ΔΕΝΔΡΩΝ ΑΝΑΖΗΤΗΣΗΣ ΑΝ ΤΟ ΣΤΟΙΧΕΙΟ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΟ ΑΠΟ ΤΟΝ ΚΟΜΒΟ (i) ΕΛΕΓΧΟΥΜΕ ΤΟ ΜΙΚΡΟΤΕΡΟ (ΑΡΙΣΤΕΡΑ) ΠΑΙΔΙ ΤΟΥ ΠΟΥ ΒΡΙΣΚΕΤΑΙ ΣΤΗΝ 2*i+1
        i=2*i+1;
      }
      else if(x>bt[i]){//ΜΕ ΒΑΣΗ ΤΗΝ ΘΕΩΡΙΑ ΤΩΝ ΔΙΑΔΙΚΩΝ ΔΕΝΔΡΩΝ ΑΝΑΖΗΤΗΣΗΣ ΑΝ ΤΟ ΣΤΟΙΧΕΙΟ ΕΙΝΑΙ ΜΕΓΑΛΥΤΕΡΟ ΑΠΟ ΤΟΝ ΚΟΜΒΟ (i) ΕΛΕΓΧΟΥΜΕ ΤΟ ΜΕΓΑΛΥΤΕΡΟ (ΔΕΞΙΑ) ΠΑΙΔΙ ΤΟΥ ΠΟΥ ΒΡΙΣΚΕΤΑΙ ΣΤΗΝ 2*i+2
        i=2*i+2;
      }
      if(i>=size){//ΧΡΗΣΙΜΟΠΟΙΕΙΤΑΙ Ο BT2 ΛΟΓΩ ΠΑΡΟΥΣΙΑΣΗΣ ΠΡΟΒΛΗΜΑΤΟΣ ΣΤΗΝ ΠΑΡΑΧΩΡΗΣΗ ΜΝΗΜΗΣ.
       if (pos2>=size2){
        temp=new string[size2+1000];
        tempi=new int[size2+1000];
        for(int k=0;k<size2;k++){
            temp[k]=bt2[k];
            tempi[k]=count2[k];
        }
        delete[] count2;
        delete[] bt2;
        bt2=temp;
        count2=tempi;
        size2+=1000;
       }
       bt2[pos2++]=x;
       flag=true;
       }
       }
  }

int bst::search_string(string x,int &pos){//ΑΝΑΖΗΤΗΣΗ ΤΟΥ ΖΕΥΓΟΥΣ ΣΤΟ ΔΙΑΔΙΚΟ ΔΕΝΔΡΟ ΑΝΑΖΗΤΗΣΗΣ
  int c=0;
  while(1){
    if(x==bt[c]){
      pos=c;
      return 1;
    }
    else if(x<bt[c]){
      c=2*c+1;
    }
    else if(x>bt[c]){
      c=2*c+2;
    }
     if(c>=size)
    {
     for (int j=0;j<pos2;j++)
     {
         if (bt2[j]==x) {
            pos=j;
            return 2;
         }
     }
    }
  }
}

void bst::search(string Q[]){//ΑΝΑΖΗΤΗΣΗ ΤΩΝ ΣΤΟΙΧΕΙΩΝ ΤΟΥ ΣΥΝΟΛΟΥ Q ΣΤΟ ΔΙΑΔΙΚΟ ΔΕΝΔΡΟ ΑΝΑΖΗΤΗΣΗΣ ΚΑΙ ΑΠΟΘΗΚΕΥΣΗ ΣΤΟ ΑΡΧΕΙΟ ΚΕΙΜΕΝΟΥ ΤΩΝ ΑΠΑΙΤΟΥΜΕΝΩΝ ΠΛΗΡΟΦΟΡΙΩΝ
  int i,j,pos, positions[Q_SIZE];
  ofstream f;
  f.open("output.txt",ios::out | ios::app );
  clock_t s, e, t;
  s=clock();
  int tree[Q_SIZE];
  f<<"BINARY SEARCH TREE"<<endl<<endl;
  for(i=0;i<Q_SIZE;i++){//αναζήτηση των στοιχείων του συνόλου Q στον πίνακα
      tree[i]=search_string(Q[i],pos);
      positions[i]=pos;
  }
    e=clock();
  t=e-s;
    for(i=0;i<Q_SIZE;i++){//ΑΠΟΘΗΚΕΥΣΗ ΣΤΟ ΑΡΧΕΙΟ ΕΞΟΔΟΥ ΤΩΝ ΖΗΤΟΥΜΕΝΩΝ ΠΛΗΡΟΦΟΡΙΩΝ ΓΙΑ ΚΑΘΕ ΣΤΟΙΧΕΙΟ ΤΟΥ ΣΥΝΟΛΟΥ Q
            if (tree[i]==1){
      f<<"\""<<Q[i]<<"\""<<" : "<<count[positions[i]]<<" times found in the text."<<endl;
            }
            else
            {
               f<<"\""<<Q[i]<<"\""<<" : "<<count2[positions[i]]<<" times found in the text."<<endl;
            }
  }
  int min;
  double tt;
  tt=((double) (t)/CLOCKS_PER_SEC);
  min=tt/60;
  tt=tt-min*60;
  f<<endl<<"Total time of search in binary search tree : "<<min<<" minutes & "<<tt<<" seconds."<<endl<<endl;//ΑΠΟΘΗΚΕΥΣΗ ΤΟΥ ΣΥΝΟΛΙΚΟΥ ΧΡΟΝΟΥ ΑΝΑΖΗΤΗΣΗΣ ΤΩΝ ΣΤΟΙΧΕΙΩΝ ΤΟΥ ΣΥΝΟΛΟΥ Q ΣΤΟ ΑΡΧΕΙΟ ΕΞΟΔΟΥ
  f.close();
}
