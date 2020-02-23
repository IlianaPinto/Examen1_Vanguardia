#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Pokemon {
public:
    virtual void Pokedex() = 0;
    virtual void Capture() = 0;
    virtual void Speak() = 0;
    static Pokemon* make_pokemon(int choice);
};

class Charmander: public Pokemon {
public:
    void Pokedex() {
        cout << "*------------------*" << endl;
        cout << "* National #: 4    *" << endl;
        cout << "* Height: 0.6m     *" << endl;
        cout << "* Weight: 8.5kg    *" << endl;
        cout << "* Type: Fire       *" << endl;
        cout << "* Category: Lizard *" << endl;
        cout << "*------------------*" << endl;
    }
    void Capture() {
        int random = rand() % 100 + 1;
        if (random < 46) {
            cout << "Gotcha!"<<endl;
            cout << "Your pokemon was captured!" << endl;
        }
        else {
            cout << "Charmander flew away"<<endl;
        }
        
    }

    void Speak() {
        cout << "Your pokemon says: Charmander!" << endl;
    }
};

class Bulbasaur : public Pokemon {
public:
    void Pokedex() {
        cout << "*---------------------*" << endl;
        cout << "* National #: 1       *" << endl;
        cout << "* Height: 0.7m        *" << endl;
        cout << "* Weight: 6.9kg       *" << endl;
        cout << "* Type: Grass, Poison *" << endl;
        cout << "* Category: Seed      *" << endl;
        cout << "*---------------------*" << endl;
    }
    void Capture() {
        int random = rand() % 100 + 1;
        if (random < 46) {
            cout << "Gotcha!" << endl;
            cout << "Your pokemon was captured!" << endl;
        }
        else {
            cout << "Bulbasaur flew away" << endl;
        }

    }

    void Speak() {
        cout << "Your pokemon says: Bulbasaur!" << endl;
    }
};

class Squirtle : public Pokemon {
public:
    void Pokedex() {
        cout << "*-----------------------*" << endl;
        cout << "* National #: 7         *" << endl;
        cout << "* Height: 0.7m          *" << endl;
        cout << "* Weight: 6.9kg         *" << endl;
        cout << "* Type: Water           *" << endl;
        cout << "* Category: Tiny Turtle *" << endl;
        cout << "*-----------------------*" << endl;
    }
    void Capture() {
        int random = rand() % 100 + 1;
        if (random < 46) {
            cout << "Gotcha!" << endl;
            cout << "Your pokemon was captured!" << endl;
        }
        else {
            cout << "Squirtle flew away" << endl;
        }

    }

    void Speak() {
        cout << "Your pokemon says: Squirtle Squirtle!" << endl;
    }


};

Pokemon* Pokemon::make_pokemon(int choice) {
    if (choice == 1) {
        return new Charmander;
    }
    else if (choice == 2) {
        return new Bulbasaur;
    }
    else {
        return new Squirtle;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "Choose a Pokemon" << endl;
        cout << "1. Charmander" << endl;
        cout << "2. Bulbasaur" << endl;
        cout << "3. Squirtle" << endl;
        cout << "4. Quit" << endl;
        cin >> choice;
        if (choice == 4)
        {
            break;
        }
        Pokemon::make_pokemon(choice)->Pokedex();
        cout << endl;
        Pokemon::make_pokemon(choice)->Speak();
        cout << endl;
        Pokemon::make_pokemon(choice)->Capture();
        cout << endl;
    } while (true);
    
}

