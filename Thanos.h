#include "monster.h"
#include <iostream>

using namespace std;

class Thanos {
  private:
      int stones;
      int hp;
  
  public:
      Thanos(int = 0);
      void snap_finger(monster[], int);
      void operator++();
      void kill(monster& monster);
      int countSurviving(monster[], int);
};

Thanos::Thanos(int hpVal) {
    hp = hpVal;
    stones = 0;
}

void Thanos::kill(monster& monster) {
    monster.die();
}

void Thanos::operator++() {
    stones++;
}

int Thanos::countSurviving(monster* m, int n){
  int count = 0;
  for(int i = 0; i < n; i++){
    if(m[i].not_dead()){
        count++;
    }
  }
  return count;
}

void Thanos::snap_finger(monster* monsters, int n) {
    if (stones >= 6) {
        cout << "Thanos can now kill half of the population (6/6)" << endl;
        int counter = 0, neededToKill = (int)(countSurviving(monsters, n)/2);
        for (int i = 0; i < n; i++) {
            if(monsters[i].not_dead() && counter < neededToKill){
              kill(monsters[i]);
              counter++;
            }
        }
    } else {
        cout << "Thanos does not have enough stones (" << stones << "/6)" << endl;  // Added missing closing parenthesis
    }
}
