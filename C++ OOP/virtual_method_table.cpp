#include <iostream>

class B
{
public:
  virtual void bar();
  virtual void qux();
  virtual ~B() {std::cout << "Destructed B" << std::endl;}
};

void B::bar()
{
  std::cout << "This is B's implementation of bar" << std::endl;
}

void B::qux()
{
  std::cout << "This is B's implementation of qux" << std::endl;
}

class C : public B
{
public:
  void bar() override;
  ~C() override {std::cout << "Destructed C" << std::endl;}
};

void C::bar()
{
  std::cout << "This is C's implementation of bar" << std::endl;
}

int main(int argc, char** argv) {
    
    B* b = new C();
    b->bar();
    delete b;
    return 0;
}

/*
1. Function overriding makes it impossible to dispatch virtual functions statically (at compile time)
2. Dispatching of virtual functions needs to happen at runtime
3. The virtual table method is a popular implementation of dynamic dispatch
4. For every class that defines or inherits virtual functions the compiler creates a virtual table
5. The virtual table stores a pointer to the most specific definition of each virtual function
6. For every class that has a vtable, the compiler adds an extra member to the class: the vpointer
7. The vpointer points to the corresponding vtable of the class
8. Always declare desctructors of base classes as virtual
9. Why not virtual constructor: the virtual table exisits after the constructing of class object
   The compiler does not have memory for the virtual table of a class object until it is constructed



*/