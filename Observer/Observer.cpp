#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Blackboard {
    vector < class Observer * > _students;
    string _activity;
  public:
    void attach(Observer *student) {
        _students.push_back(student);
    }
    void setActivity(string activity) {
        _activity = activity;
        notify();
    }
    string getActivity() {
        return _activity;
    }
    void notify();
};

class Observer {
    Blackboard *_blackboard;
  public:
    Observer(Blackboard *blackboard) {
      _blackboard = blackboard;
      _blackboard->attach(this);
    }
    virtual void update() = 0;
  protected:
    Blackboard *getBlackboard() {
        return _blackboard;
    }
};

void Blackboard::notify() {
  for (int i = 0; i < _students.size(); i++)
    _students[i]->update();
}

class Student: public Observer {
  public:
    Student(Blackboard *blackboard): Observer(blackboard){}
    void update() {
        string act = getBlackboard()->getActivity();
        cout<<"Activity "<<act<<" recieved!"<<endl;
    }
};

int main() {
  string resp, mystr;
  Blackboard* bb = new Blackboard();
  Student std (bb);
  do {
    cout<<"1. New activity "<<endl;
    cout<<"2. Quit"<<endl;
    getline(cin,resp);
    if (resp == "1") {
      cout<<"Introduce activity: "<<endl;
      getline(cin,mystr);
      bb->setActivity(mystr);
    }else if (resp == "2"){
      break;
    }
    cout<<endl;
  } while(true);
}
