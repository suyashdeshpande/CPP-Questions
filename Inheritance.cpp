#include <bits/stdc++.h>
using namespace std;

class Base {
   public:
    virtual void a() {
        cout << "a called from base" << endl;
    }
};

class Child : public Base {
   public:
    void a() {
        Base::a();
        cout << "a called from chiild" << endl;
    }
};

int main() {
    Base* a = new Child();
    a->a();
    delete a;
}