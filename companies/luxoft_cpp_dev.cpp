#include <iostream>
#include <string.h>

struct A
{
   char* data;

   A(const char* msg = 0)
     : data(new char[msg ? strlen(msg) : 0 + 1 ])
   {
     if(msg)
       { memcpy(data, msg, strlen(msg)); }
   }

   A& operator=(A& a) {
     char * tmp
     tmp = new char[strlen(b.data)+1];
     memcpy(tmp, b.data, strlen(b.data));
     delete data;
     data = tmp;
     return *this;
   }
   
   virtual void say()
     { std::cout << "A::say " << data << std::endl; }

   virtual ~A()
     { delete data; }
};

struct B: public A
{
  int *data;

  virtual void say()
    { std::cout << "B::say " << *data << std::endl; }

  B() : A() , data(new int(0))
    { }

  ~B() { delete data; }
};


int main(int, char**) try
{
  A* a = new A("");
  A* b = new B();

  a->say();

  *b = *a;

  b->say();

  delete a;
  delete b;
}
catch( std::exception const& ex)
  { std::cout << ex.what() << std::endl; }
