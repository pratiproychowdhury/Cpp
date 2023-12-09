// Solve diamond depedency issue

#include <iostream>
using std::cout;

class Base
{
public:
    virtual void print() const = 0;

    int field1;

    Base() : field1(0)
    {
        static int f1 = 0;
        f1++;
        field1 = f1;
    }
};

class DerivedOne : virtual public Base
{
public:
    void print() const
    {
        cout << field1 << " DerivedOne\n";
    }
};

class DerivedTwo : virtual public Base
{
public:
    void print() const
    {
        cout << field1 << " DerivedTwo\n";
    }
};

class Multiple : public DerivedOne, public DerivedTwo
{
public:
    void print() const
    {
        cout << DerivedOne::field1 << " Multiple\n";
    }
};

int main()
{
    Multiple both;
    DerivedOne one;
    DerivedTwo two;
    //Base base;

    Base *array[ 4 ];
    array[ 0 ] = &both;
    array[ 1 ] = &one;
    array[ 2 ] = &two;
    //array[ 3 ] = &base;

    for ( int i = 0; i < 3; i++ )
        array[ i ]->print();

    return 0;
}
