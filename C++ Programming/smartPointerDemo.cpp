#include <memory>
#include <iostream>

// Class declaration
class RootNode;
class ChildNodeA;
class ChildNodeB;

// Class definition
class RootNode 
{

public:
    RootNode()
    {
        std::cout << "RootNode is constructed" << std:: endl;
    }

    ~RootNode() 
    {
        std::cout << "RootNode is destructed" << std:: endl;
    }

    void setChildA(const std::shared_ptr<ChildNodeA> objA)
    {
        childA = objA;
    }

    void setChildB(const std::shared_ptr<ChildNodeB> objB)
    {
        childB = objB;
    }

private:
    std::shared_ptr<ChildNodeA> childA;
    std::shared_ptr<ChildNodeB> childB;
};

class ChildNodeA 
{

public:
    ChildNodeA() {}
    ChildNodeA(const std::shared_ptr<RootNode> obj)
    : rootNode(obj)
    {
        std::cout << "ChildNodeA is constructed" << std:: endl;
    }

    ~ChildNodeA()
    {
        std::cout << "ChildNodeA is destructed" << std:: endl;
    }

private: 
    std::weak_ptr<const RootNode> rootNode;
};

class ChildNodeB
{

public:
    ChildNodeB() {}
    ChildNodeB(const std::shared_ptr<RootNode> obj)
    : rootNode(obj)
    {
        std::cout << "ChildNodeB is constructed" << std:: endl;
    }

    ~ChildNodeB()
    {
        std::cout << "ChildNodeB is destructed" << std:: endl;
    }

private: 
    std::weak_ptr<const RootNode> rootNode;
};

int main(int argc, char** argv)
{
    std::shared_ptr<RootNode> r = std::shared_ptr<RootNode>(new RootNode());
    std::shared_ptr<ChildNodeA> aChild = std::shared_ptr<ChildNodeA>(new ChildNodeA(r));
    std::shared_ptr<ChildNodeB> bChild = std::shared_ptr<ChildNodeB>(new ChildNodeB(r));
    r->setChildA(aChild);
    r->setChildB(bChild);
    return 0;
}
