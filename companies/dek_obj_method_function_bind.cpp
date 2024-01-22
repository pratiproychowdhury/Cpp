#include <iostream>
#include <string>
#include <functional>

using namespace std;

class Reptile {
public:
    virtual std::function<void(string)> lay() {
        cout << "laying a reptile egg" << std::endl;
        return std::bind(&Reptile::beBorn, this, std::placeholders::_1);
    }

    virtual void beBorn(string name) {
        cout << "a reptile is born named " << name << std::endl;
    }
};

class ReptileEgg
{
    Reptile* thisBeast;
    std::function<void(string)> hatcher;

public:
    ReptileEgg(Reptile* bicho) {
        thisBeast = bicho;
        hatcher = thisBeast->lay();
    }

    void hatchIt(string name) {
        hatcher(name);
    }
};

class Dragon : public Reptile { 
public:
    std::function<void(string)> lay () {
        cout << "laying a dragon egg" << std::endl;
        return std::bind(&Dragon::beBorn, this, std::placeholders::_1);
    }

    void beBorn(string name) {
        cout << "a dragon is born named " << name << std::endl;
    }
};


int main()
{
    Reptile* beast = new Dragon();
    ReptileEgg* egg = new ReptileEgg(beast);
    egg->hatchIt("Joe");

    Reptile* beast2 = new Reptile();
    ReptileEgg* egg2 = new ReptileEgg(beast2);
    egg2->hatchIt("Bob");
}
