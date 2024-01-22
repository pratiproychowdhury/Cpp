#include <iostream>
#include <string>
#include <functional>

using namespace std;

class Reptile {
public:
    virtual std::function<void(void)> lay() {
        cout << "laying a reptile egg" << std::endl;
        return std::bind(&Reptile::beBorn, this);
    }

    virtual void beBorn() {
        cout << "a reptile is born" << std::endl;
    }
};

class ReptileEgg
{
    Reptile* thisBeast;
    std::function<void(void)> hatcher;

public:
    ReptileEgg(Reptile* bicho) {
        thisBeast = bicho;
        hatcher = thisBeast->lay();
    }

    void hatchIt() {
        hatcher();
    }
};

class Dragon : public Reptile { 
public:
    std::function<void(void)> lay () {
        cout << "laying a dragon egg" << std::endl;
        return std::bind(&Dragon::beBorn, this);
    }

    void beBorn() {
        cout << "a dragon is born" << std::endl;
    }
};


int main()
{
    Reptile* beast = new Dragon();
    ReptileEgg* egg = new ReptileEgg(beast);
    egg->hatchIt();

    Reptile* beast2 = new Reptile();
    ReptileEgg* egg2 = new ReptileEgg(beast2);
    egg2->hatchIt();
}
