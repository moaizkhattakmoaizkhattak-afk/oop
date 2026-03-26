#include <iostream>
using namespace std;

class Hero {
protected:
    string name, type;
    int health;
    double power;
    int experience;

public:
    Hero(string n, string t, int h, double p, int e) {
        name = n;
        type = t;
        health = h;
        power = p;
        experience = e;
    }

    void showGameMessage() {
        cout << "\n===== Welcome to Fantasy Battle Arena =====\n";
        cout << "Each hero has unique attack and defense abilities!\n";
    }

    void displayBasic() {
        cout << "\nName: " << name;
        cout << "\nType: " << type;
        cout << "\nHealth: " << health;
        cout << "\nPower: " << power;
        cout << "\nExperience: " << experience << endl;
    }

    virtual double attack() = 0;
    virtual double defend() = 0;
};

class Warrior : public Hero {
private:
    string weapon;
    int armor;
    double rage;

public:
    Warrior(string n, int h, double p, int e, string w, int a, double r)
        : Hero(n, "Warrior", h, p, e) {
        weapon = w;
        armor = a;
        rage = r;
    }

    void display() {
        displayBasic();
        cout << "Weapon: " << weapon << endl;
        cout << "Armor: " << armor << endl;
        cout << "Rage: " << rage << endl;
    }

    double attack() {
        return power * rage + experience;
    }

    double defend() {
        return armor * 0.8 + health * 0.2;
    }
};

class Mage : public Hero {
private:
    string spell;
    int mana;
    double multiplier;

public:
    Mage(string n, int h, double p, int e, string s, int m, double mul)
        : Hero(n, "Mage", h, p, e) {
        spell = s;
        mana = m;
        multiplier = mul;
    }

    void display() {
        displayBasic();
        cout << "Spell: " << spell << endl;
        cout << "Mana: " << mana << endl;
        cout << "Magic Multiplier: " << multiplier << endl;
    }

    double attack() {
        return power * multiplier + mana;
    }

    double defend() {
        return mana * 0.5 + health * 0.3;
    }
};

class Archer : public Hero {
private:
    string bow;
    int arrows;
    double accuracy;

public:
    Archer(string n, int h, double p, int e, string b, int a, double acc)
        : Hero(n, "Archer", h, p, e) {
        bow = b;
        arrows = a;
        accuracy = acc;
    }

    void display() {
        displayBasic();
        cout << "Bow: " << bow << endl;
        cout << "Arrows: " << arrows << endl;
        cout << "Accuracy: " << accuracy << endl;
    }

    double attack() {
        return power * accuracy + arrows * 0.5;
    }

    double defend() {
        return accuracy * 10 + health * 0.2;
    }
};

int main() {

    Warrior w("Thor", 150, 50.5, 40, "Axe", 80, 1.5);
    Mage m("Merlin", 100, 60.0, 50, "Fireball", 120, 2.0);
    Archer a("Legolas", 120, 45.0, 35, "Longbow", 60, 0.9);

    w.showGameMessage();

    cout << "\n--- Warrior ---";
    w.display();
    double wAttack = w.attack();
    double wDef = w.defend();
    cout << "Attack: " << wAttack << endl;
    cout << "Defense: " << wDef << endl;

    cout << "\n--- Mage ---";
    m.display();
    double mAttack = m.attack();
    double mDef = m.defend();
    cout << "Attack: " << mAttack << endl;
    cout << "Defense: " << mDef << endl;

    cout << "\n--- Archer ---";
    a.display();
    double aAttack = a.attack();
    double aDef = a.defend();
    cout << "Attack: " << aAttack << endl;
    cout << "Defense: " << aDef << endl;

    cout << "\n===== Battle Summary =====\n";

    if (wAttack > mAttack && wAttack > aAttack)
        cout << "Warrior has highest attack!\n";
    else if (mAttack > wAttack && mAttack > aAttack)
        cout << "Mage has highest attack!\n";
    else
        cout << "Archer has highest attack!\n";

    return 0;
}