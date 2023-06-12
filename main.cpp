#include <iostream>
#include "Thanos.h"

using namespace std;


void simulate(int n, monster* m, int s) {
    for (int i = 0; i < n;) {
      int j = getRandom(s);
      int k = getRandom(j);
      if(j != k && m[j].not_dead() && m[k].not_dead()){
        int prob = getRandom(2);
          if(prob == 1) {
              m[j].Attack(m[k]);
              i++;
          }else{
            int prob_b = getRandom(3);
            if(prob_b == 1){
               m[j].heal();
               i++;
            }else if(prob_b == 2){
              m[j].steal(m[k]);
                i++;
            }else{
              m[j].Attack(m[k]);
              i++;
            }
        }
      }
    }
}

int main() {
  Thanos T;
  int n;
  cout<<"How many monster?";
  cin>>n;

  monster *m=new monster[n];
  simulate(50, m, n);
  ++T;
  ++T;
  T.snap_finger(m,n);
  ++T;
  ++T;
  T.snap_finger(m,n);
  ++T;
  ++T;
  T.snap_finger(m,n);
  ++T;
  ++T;
  cout << "<Survivors>" << endl;
  int count = 0;
  for(int i=0;i<n;i++)
      if(m[i].not_dead()){
        m[i].print();
        count++;
        cout<<"-----"<<endl;
    }
  cout << "There are a total of " << count << " survivors out of " << n  << "." << endl;
  delete [] m;
}