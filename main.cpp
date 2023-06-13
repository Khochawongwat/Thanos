#include <iostream>
#include "Thanos.h"

using namespace std;

int countSurvivors(monster*m , int n){
  int count = 0;
  for(int i=0;i<n;i++)
      if(m[i].not_dead()){
        count++;
  }
  return count;
}

void simulate(int n, monster* m, int s, Thanos& T) {
    for (int i = 0; i < n;) {
      if(T.getStones() >= 6){
        cout << "Thanos has collected 6 stones." << endl;
        break;
      }
      if(countSurvivors(m, n) <= 1 ){
        cout << "There is only 1 monster left." << endl;
        break;
      }
      int j = getRandom(s), k = getRandom(s);
      if(j != k && m[j].not_dead() && m[k].not_dead()){
        i++;
        int a = getRandom(2);
        if(a == 1){
          m[j].Attack(m[k]);
          int b = getRandom(10);
          if(b == 0){
            ++T;
          }else{
            m[j].heal();
          }
        }else{
          m[j].steal(m[k]);
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
  simulate(500, m, n, T);
  while(T.getStones() < 6){
    ++T;
  }
  T.snap_finger(m, n);
  cout<<"-----------"<<endl;
  for(int i=0;i<n;i++)
      if(m[i].not_dead()){
        m[i].print();
        cout<<"------------"<<endl;
  }
  cout << "There are a total of " << countSurvivors(m, n) << " survivors out of " << n  << "." << endl;
  delete [] m;
}