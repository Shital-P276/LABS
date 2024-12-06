#include <iostream>
#include <string>
using namespace std;

class Spell { 
private:
    string scrollName;
    int power;  // Adding power directly to Spell class

public:
    Spell(string name, int p) : scrollName(name), power(p) { }
    virtual ~Spell() { }

    string revealScrollName() {
        return scrollName;
    }

    // Now we have a common method to reveal power for all spells
    virtual void revealPower() {
        cout << scrollName << ": " << power << endl;
    }
};

class Fireball : public Spell {
public:
    Fireball(int power) : Spell("Fireball", power) { }
    // No need for revealFirepower method anymore
};

class Frostbite : public Spell {
public:
    Frostbite(int power) : Spell("Frostbite", power) { }
    // No need for revealFrostpower method anymore
};

class Thunderstorm : public Spell {
public:
    Thunderstorm(int power) : Spell("Thunderstorm", power) { }
    // No need for revealThunderpower method anymore
};

class Waterbolt : public Spell {
public:
    Waterbolt(int power) : Spell("Waterbolt", power) { }
    // No need for revealWaterpower method anymore
};

void counterspell(Spell* spell) {
    // No need for dynamic_cast here if power is now in the base class
    spell->revealPower();  // Directly call the common revealPower method
}

int main() {
    Fireball fireball(10);
    Frostbite frostbite(7);
    Thunderstorm thunderstorm(12);
    Waterbolt waterbolt(5);

    counterspell(&fireball);      // Outputs: Fireball: 10
    counterspell(&frostbite);     // Outputs: Frostbite: 7
    counterspell(&thunderstorm);  // Outputs: Thunderstorm: 12
    counterspell(&waterbolt);     // Outputs: Waterbolt: 5

    return 0;
}
