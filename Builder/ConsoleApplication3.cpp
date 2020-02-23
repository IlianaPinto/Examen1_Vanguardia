#include <iostream>
using namespace std;

class House {
    string _house;
    string _roof;
    string _structure;
    string _floor;
public:
    House(string houseType) {
      _house = houseType;
    }
    void setRoof(string roof) { _roof = roof; }
    void setStructure(string structure) { _structure = structure; }
    void setFloor(string floor) { _floor = floor; }
    string getRoof() { return _roof; }
    string getStructure() { return _structure; }
    string getFloor() { return _floor; }

    void show() {
        cout << "House Type: " << _house<<endl;
        cout << "Roof: " << _roof << endl;
        cout << "Structure: " << _structure << endl;
        cout << "Floor: " << _floor << endl;
    }
};

class HouseBuilder {
protected:
    House* _house;
public:
    virtual void getPartsDone() = 0;
    virtual void buildRoof() = 0;
    virtual void buildStructure() = 0;
    virtual void buildFloor() = 0;
    virtual ~HouseBuilder(){}
    House* getHouse() { return _house; }
};

class HutBuilder : public HouseBuilder {
public:
    void getPartsDone() { _house = new House("Hut"); }
    void buildRoof() { _house->setRoof("Building roof"); }
    void buildStructure() { _house->setStructure("Building Structure"); }
    void buildFloor() { _house->setFloor("Building Floor"); }
    ~HutBuilder(){delete _house;}
};

class CastleBuilder : public HouseBuilder {
public:
    void getPartsDone() { _house = new House("Castle"); }
    void buildRoof() { _house->setRoof("Building roof"); }
    void buildStructure() { _house->setStructure("Building Structure"); }
    void buildFloor() { _house->setFloor("Building floor"); }
    ~CastleBuilder(){delete _house;}
};

class BobConstruye {
    HouseBuilder* builder;
public:
    House* createHouse(HouseBuilder* builder) {
        builder->getPartsDone();
        builder->buildRoof();
        builder->buildStructure();
        builder->buildFloor();
        return builder->getHouse();
    }
};

int main() {

    BobConstruye bob;
    HutBuilder hb;
    House* hut = bob.createHouse(&hb);
    CastleBuilder cb;
    House* castle = bob.createHouse(&cb);
    int resp;
    do
    {

        cout << "Bob el Constructor" << endl;
        cout << "1. Hut" << endl;
        cout << "2. Castle" << endl;
        cout << "3. Quit" << endl;
        cin >> resp;
        if (resp == 1)
        {
            cout << endl;
            hut->show();
            cout <<"____ || ____"<<endl
                <<"///////////  "<<endl
                <<"///////////  "<<endl
                <<"|    _    |  |"<<endl
                <<"|[] | |[] |[]|"<<endl
                <<"|   | |   |  |" <<endl;

        }
        else if (resp == 2) {
            castle->show();
            cout << endl;
            cout << "_   |~  _" << endl
                << "[_]--'--[_]" << endl
                << "|'|""`""|'|" << endl
                << "| |  ^  | |" << endl
                << "|_|_|I|_|_| " << endl;
        }
        else if (resp == 3) {
            break;
        }
        cout << endl;
    } while (true);
    //delete hut;
    //delete castle;

    return 0;
}
