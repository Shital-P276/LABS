#include <iostream>
#include <string>
using namespace std;

class Spell { 
private:
    string scrollName;
public:
    Spell(): scrollName("") { }
    Spell(string name): scrollName(name) { }
    virtual ~Spell() { }
    string revealScrollName() {
        return scrollName;
    }
};

class Fireball : public Spell { 
private: 
    int power;
public:
    Fireball(int power): power(power) { }
    void revealFirepower() {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell {
private: 
    int power;
public:
    Frostbite(int power): power(power) { }
    void revealFrostpower() {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell { 
private: 
    int power;
public:
    Thunderstorm(int power): power(power) { }
    void revealThunderpower() {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell { 
private: 
    int power;
public:
    Waterbolt(int power): power(power) { }
    void revealWaterpower() {
        cout << "Waterbolt: " << power << endl;
    }
};

void counterspell(Spell* spell) {
    // Check if the spell is of a specific type
    Fireball* fireballSpell = dynamic_cast<Fireball*>(spell);
    if (fireballSpell != nullptr) {
        fireballSpell->revealFirepower();
        return;
    }
    
    Frostbite* frostbiteSpell = dynamic_cast<Frostbite*>(spell);
    if (frostbiteSpell != nullptr) {
        frostbiteSpell->revealFrostpower();
        return;
    }
    
    Thunderstorm* thunderstormSpell = dynamic_cast<Thunderstorm*>(spell);
    if (thunderstormSpell != nullptr) {
        thunderstormSpell->revealThunderpower();
        return;
    }
    
    Waterbolt* waterboltSpell = dynamic_cast<Waterbolt*>(spell);
    if (waterboltSpell != nullptr) {
        waterboltSpell->revealWaterpower();
        return;
    }

    // For unknown spells, no action is taken
}

int main() {
    Fireball fireballSpell(5);
    counterspell(&fireballSpell);  // Should output Fireball: 5
    
    Frostbite frostbiteSpell(7);
    counterspell(&frostbiteSpell);  // Should output Frostbite: 7
    
    // No generic spell handling here
    Spell* unknownSpell = new Spell("AquaVitae");
    counterspell(unknownSpell);  // No output, as no generic spell is handled
    
    delete unknownSpell;
    return 0;
}
