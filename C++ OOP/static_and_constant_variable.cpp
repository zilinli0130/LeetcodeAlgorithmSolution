#include <iostream>


auto& foo() {

    static auto num = 5;
    return num;
}

int main(int argc, char** argv) {

    std::cout << foo() << std::endl;
    return 0;
}


/*
1. Static variables must be initialized before the program starts
2. Variables that can be evaluated at compile time (those initialized by a constant expression) are const-initialized
3. All other static variables are zero-initialized during static initialization

4. constexpr forces the evaluation of a variable as a constant expression and implies const
5. constinit forces the evaluation of a variable as a constant expression and doesn’t imply const
6. After static initialization dynamic initialization takes places, which happens at runtime before main()
7. const can be initialized (gives a variable an initial value at the point ) and evaluated (gives a variable a different value after creation) at 
   compiler time or run time
*/