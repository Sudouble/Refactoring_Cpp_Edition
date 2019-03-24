#ifndef INLINEMETHOD_H
#define INLINEMETHOD_H

// 适用情景：函数间，间接层多了，改成更易理解的形式

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int _numOfLateDeliveries = 4;

//// 例子——原先方法
//bool moreThanFiveLateDeliveries()
//{
//    return _numOfLateDeliveries > 5;
//}

//int getRating()
//{
//    return moreThanFiveLateDeliveries() ? 2 : 1;
//}

// 例子——新方法
int getRating()
{
    return (_numOfLateDeliveries > 5) ? 2 : 1;
}

#endif // 6_2_INLINEMETHOD_H
