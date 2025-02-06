#include <iostream>
#include "time.h"
#include <fstream>
#include "unclassified_array.h"
#include "classified_array.h"
#include "binary_search_tree.h"
#include "hashing_table.h"
#include <stdlib.h>
using namespace std;
const int Q_SIZE=1000;//ΜΕΓΕΘΟΣ ΣΥΝΟΛΟΥ Q
int main() {
  string Q[Q_SIZE];//ΠΙΝΑΚΑΣ ΓΙΑ ΤΟ ΣΥΝΟΛΟ Q
  string *Pairs, *temp;
  Pairs= new string[100000];
  int pointer=0, sizeofP=100000, rep;
  una unarray;//ΑΝΤΙΚΕΙΜΕΝΟ ΚΛΑΣΗΣ ΑΤΑΞΙΝΟΜΗΤΟΥ ΠΙΝΑΚΑ
  cda clarray;//ΑΝΤΙΚΕΙΜΕΝΟ ΚΛΑΣΗΣ ΤΑΞΙΝΟΜΗΜΕΝΟΥ ΠΙΝΑΚΑ
  bst bstree;//ΑΝΤΙΚΕΙΜΕΝΟ ΚΛΑΣΗΣ ΔΥΑΔΙΚΟΥ ΔΕΝΔΡΟΥ ΑΝΑΖΗΤΗΣΗΣ
  int pQ=0, r=0;//ΔΕΚΤΕΙΣ ΤΟΥ Q
  int i;//ΜΕΤΑΒΛΗΤΗ ΓΙΑ ΤΙΣ  ΕΠΑΝΑΛΗΨΕΙΣ
  char x;//ΓΡΑΜΜΑ ΤΟΥ ΚΕΙΜΕΝΟΥ 
  bool flag=true, flag2;//ΑΠΑΡΑΙΤΗΤΟΙ ΔΙΑΚΟΠΤΕΣ
  clock_t tuna=0, tunas, tunae, tcda=0, tcdas, tcdae,tbst=0,tbsts,tbste,tha=0,thas,thae;//t...:ΑΘΡΟΙΣΜΑ ΤΩΝ CLOCKS ΓΙΑ ΤΗΝ ΚΑΑΤΣΚΕΥΗ ΤΩΝ ΔΟΜΩΝ , t...s:ΧΡΟΝΟΣ ΕΚΚΙΝΗΣΗΣ ΜΕΜΟΝΩΜΕΝΩΝ ΕΙΣΑΓΩΓΩΝ ΖΕΥΓΑΡΙΟΥ ,  t...e:ΧΡΟΝΟΣ ΤΕΡΜΑΤΙΣΜΟΥ ΜΕΜΟΝΩΜΕΝΩΝ ΕΙΣΑΓΩΓΩΝ ΖΕΥΓΑΡΙΟΥ
  string line, x1,x2, pair;//ΑΠΟΘΗΚΕΥΣΗ ΓΡΑΜΜΩΝ, ΠΡΩΤΗ ΛΕΞΗ ΖΕΥΓΑΡΙΟΥ, ΔΕΥΤΕΡΗ ΛΕΞΗ ΖΕΥΓΑΡΙΟΥ
  ifstream f;//ΡΕΥΜΑ ΕΙΣΟΔΟΥ ΓΙΑ ΤΟ ΑΡΧΕΙΟ
  f.open("small-file.txt");//ΑΝΟΙΓΜΑ ΤΟΥ ΑΡΧΕΙΟΥ ΓΙΑ ΑΝΑΓΝΩΣΗ
  if(!(f.is_open())){//ΕΛΕΓΧΟΣ ΓΙΑ ΤΟ ΑΝΟΙΓΜΑ ΤΟΥ ΑΡΧΕΙΟΥ
    cerr<<"Could not open file..."<<endl;
  }
  else{
    while(!f.eof()){//ΚΑΤΑΣΚΕΥΗ ΤΩΝ ΔΟΜΩΝ 
      getline(f,line);
      r++;
      //ΔΗΜΙΟΥΡΓΙΑ ΠΡΩΤΗΣ ΛΕΞΗΣ ΜΕ ΚΑΤΑΛΛΗΛΕΣ ΕΠΕΞΕΡΓΑΣΙΕΣ
        for(i=0;i<line.size()&&flag;i++){
            x=line[i];
            if(((x>=97&&x<=122)||(x>=65&&x<=90))&&flag){
              if((x>=65&&x<=90)){
                x=x+32;
              }
               x1.push_back(x);  
           }
           else{
               flag=false;
               }
          
      }
      //ΔΗΜΙΟΥΡΓΙΑ ΤΩΝ ΖΕΥΓΑΡΙΩΝ ΛΕΞΕΩΝ ΤΟΥ ΚΕΙΜΕΝΟΥ ΜΕ ΚΑΤΑΛΛΗΛΕΣ ΕΠΕΞΕΡΓΑΣΙΕΣ
    for(i=i;i<line.size();i++){
      x=line[i];
      if(((x>=97&&x<=122)||(x>=65&&x<=90))){
        if((x>=65&&x<=90)){
            x=x+32;
          }
        x2.push_back(x);
        flag2=true;
      }
      else if(flag2==true){
        pair=x1+" "+x2;
        if(pointer==sizeofP){
          temp= new string[sizeofP+10000];
          for(rep=0;rep<sizeofP;rep++){
            temp[rep]=Pairs[rep];
          }
          sizeofP=sizeofP+10000;
          delete [] Pairs;
          Pairs=temp;
        }        
          Pairs[pointer]=pair;
          pointer++;        
        x1=x2;
        x2.clear();
        flag2=false;
      }
    }
    }
    f.close();
  har hasha(sizeofP);//ΑΝΤΙΚΕΙΜΕΝΟ ΚΛΑΣΗΣ ΠΙΝΑΚΑ ΚΑΤΑΚΕΡΜΑΤΙΣΜΟΥ    
for(i=0;i<Q_SIZE;i++){
  Q[i]=Pairs[rand()%pointer];
}    
    double ttuna, ttcda,ttbst, ttha;
    int minuna, mincda,minbst, minha;
    ofstream f1;   
    tunas=clock();    
    for(i=0;i<pointer;i++){
     unarray.push(Pairs[i]);
    }
    tunae=clock();
    tuna=tunae-tunas;
    ttuna=((double) (tuna)/CLOCKS_PER_SEC);
    minuna=ttuna/60;
    ttuna=ttuna-minuna*60; 
    unarray.search(Q);
    f1.open("output.txt", ios::out | ios::app);
    f1<<"Time required for construction of unclassified array: "<<minuna<<" minutes && "<<ttuna<<"seconds."<<endl<<endl<<"--------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    f1.close();
    tcdas=clock();
    for(i=0;i<pointer;i++){
      clarray.push(Pairs[i]);
    }
    tcdae=clock();
    tcda=tcdae-tcdas;
    ttcda=((double) (tcda)/CLOCKS_PER_SEC);
    mincda=ttcda/60;
    ttcda=ttcda-mincda*60;
    clarray.search(Q);
    f1.open("output.txt", ios::out | ios::app);
    f1<<"Time required for construction of classified array: "<<mincda<<" minutes && "<<ttcda<<"seconds."<<endl<<endl<<"--------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    f1.close();
    tbsts=clock();
    for(i=0;i<pointer;i++){
      bstree.insert(Pairs[i]);
    }
    tbste=clock();
    tbst=tbste-tbsts;
    ttbst=((double) (tbst)/CLOCKS_PER_SEC);   
    minbst=ttbst/60;
    ttbst=ttbst-minbst*60;
    bstree.search(Q);
    f1.open("output.txt", ios::out | ios::app);
    f1<<"Time required for construction of binary search tree: "<<minbst<<" minutes && "<<ttbst<<"seconds."<<endl<<endl<<"--------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    f1.close();
    thas=clock();
    for(i=0;i<pointer;i++){
      hasha.insert(Pairs[i]);
    }
    thae=clock();
    tha=thae-thas;
    ttha=((double) (tha)/CLOCKS_PER_SEC);
    minha=ttha/60;
    ttha=ttha-minha*60;
    hasha.search(Q);
     f1.open("output.txt", ios::out | ios::app);
    f1<<"Time required for construction of hashing table: "<<minha<<" minutes && "<<ttha<<"seconds."<<endl<<endl<<"--------------------------------------------------------------------------------------------------------------------------";
    
    f1.close();
  }
}
