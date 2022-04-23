#include <iostream>
#include <string>

namespace Views {
    class CompositionItemBase_C {
    std::string str;
    public:
        CompositionItemBase_C(std::string id): str(id) {
            std::cout << "Created" << std::endl;
        }
    };

}
std::string item1 = "Hello";
class MakoDemoPointCompisitionItem_C {
    std::string item1 = "Hello";
public:
    static std::string getName() {
        return "Mako";
    }

    static Views::CompositionItemBase_C createFactory() {
        Views::CompositionItemBase_C obj(MakoDemoPointCompisitionItem_C::getName());
        return obj;
    }
    static std::string foo() {
        return ::item1;
    }
};

int main() {

    ::MakoDemoPointCompisitionItem_C::createFactory();
    return 0;
}
