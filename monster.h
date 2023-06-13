#include <string.h>
#include <iostream>
using namespace std;
#ifndef monster_h

string monster_names[] = {
        "Gorgon",
        "Cerberus",
        "Banshee",
        "Chimera",
        "Kraken",
        "Medusa",
        "Siren",
        "Hydra",
        "Vampire",
        "Werewolf",
        "Zombie",
        "Ghost",
        "Witch",
        "Frankenstein",
        "Mummy",
        "Demon",
        "Dragon",
        "Orc",
        "Troll",
        "Goblin",
        "Specter",
        "Phantom",
        "Succubus",
        "Incubus",
        "Lich",
        "Poltergeist",
        "Yeti",
        "Wendigo",
        "Sasquatch",
        "Leviathan",
        "Minotaur",
        "Cyclops",
        "Ogre",
        "Basilisk",
        "Harpy",
        "Wraith",
        "Ghoul",
        "Lamia",
        "Griffin",
        "Centaur",
        "Manticore",
        "Satyr",
        "Selkie",
        "Kelpie",
        "Faun",
        "Nymph",
        "Dryad",
        "Pegasus",
        "Gargoyle",
        "Gnoll",
        "Hobgoblin",
        "Chupacabra",
        "Jersey Devil",
        "Bigfoot",
        "Jackalope",
        "Thunderbird",
        "Cockatrice",
        "Unicorn",
        "Peryton",
        "Valkyrie",
        "Banshee",
        "Chimera",
        "Kraken",
        "Medusa",
        "Siren",
        "Hydra",
        "Vampire",
        "Werewolf",
        "Zombie",
        "Ghost",
        "Witch",
        "Frankenstein",
        "Mummy",
        "Demon",
        "Dragon",
        "Orc",
        "Troll",
        "Goblin",
        "Specter",
        "Phantom",
        "Succubus",
        "Incubus",
        "Lich",
        "Poltergeist",
        "Yeti",
        "Wendigo",
        "Sasquatch",
        "Leviathan",
        "Minotaur",
        "Cyclops",
        "Ogre",
        "Basilisk",
        "Harpy",
        "Wraith",
        "Ghoul",
        "Lamia",
        "Griffin",
        "Centaur",
        "Manticore",
        "Satyr",
        "Selkie",
        "Kelpie",
        "Faun",
        "Nymph",
        "Dryad",
        "Pegasus",
        "Gargoyle",
        "Gnoll",
        "Hobgoblin",
        "Chupacabra",
        "Jersey Devil",
        "Bigfoot",
        "Jackalope",
        "Thunderbird",
        "Cockatrice",
        "Unicorn",
        "Peryton",
        "Valkyrie"
      };

int getRandom(int N = 100){
  if(N > 0){
    return rand() % N;
  }
  return 0;
}

class monster{
  private:
  	string name;
  	int hp,potion;

  public:
    void operator++();
    void operator--();
    void operator+=(int); // += hp
    void Attack(monster &);
    void print();
    bool not_dead() { return hp>0;}
    void die();
    void heal();
    void steal(monster&);
    monster(string = "", int =
10, int = 5);
    ~monster();
};

void monster::print(){
  cout<<"Monster: "<< name << endl;
  cout<<"HP: "<<hp << endl;
  cout<<"Potion:  "<< potion <<endl;
}

void monster::steal(monster & b){
  if(b.potion > 0){
    int amount = getRandom((int)(b.potion/2));
    b.potion -= amount;
    if(amount > 0){
      cout << name << " has stolen " << amount << " potions from " << b.name << "." << endl;
    }
  }
}
 
void monster::Attack(monster & b){
     cout << name << " attacked " << b.name << endl;
     b.hp -= (int)(getRandom(hp)/1.5);
     cout << b.name << " has " << b.hp << " HP left" << endl;
     if(b.hp <= 0){
        b.die();
     }  
}

void monster::heal(){
  if(potion > 0){
    potion--;
    int h = 1;
    if(h > 0){
      hp += h;
      cout << name << " has used a potion and healed "<< h << " HP"<< endl;
    }
  }
}
monster::monster(string n, int p, int h){
  if(n.empty()){
    int s = getRandom();
    n = monster_names[s-1];
  }
  name = n;
  hp=h ;
  potion=p;
  cout<< name << " has spawned." << endl;
}

monster::~monster(){
}

void monster::die(){
  hp = 0;
  cout << "<Update> " << name << " has died." << endl;
}

#endif
