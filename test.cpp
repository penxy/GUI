#include <iostream>

struct Node {
    int val;
}node;


void A(){
    node.val = 1;
}
Node&  B(){
    return node;
}
void C(){
    Node c = B();
    B().val = 3;
    std::cout << c.val << std::endl;
    c.val = 2;

}

int main(){
    A();
    C();
    std::cout << node.val << std::endl;
    return 0;
}

