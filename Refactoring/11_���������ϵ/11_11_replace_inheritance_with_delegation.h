#ifndef 11_11_REPLACE_INHERITANCE_WITH_DELEGATION_H
#define 11_11_REPLACE_INHERITANCE_WITH_DELEGATION_H


// 适用情景：继承后的子类功能过于丰富，需要改为委托式——在类中对原父类的变量进声明
#include <vector>
using namespace std;
// 原始版本
//template <typename MyStack>
//class Stack<MyStack> : public vector<MyStack>{
//    // vector 和 stack的很多功能不相似，不适合用继承
//}

// 新版本
template <typename MyStack>
class Stack<MyStack>{
    vector<MyStack> m_myVector;
}

#endif // 11_11_REPLACE_INHERITANCE_WITH_DELEGATION_H
