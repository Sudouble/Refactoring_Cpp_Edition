#ifndef INLINEMETHOD_H
#define INLINEMETHOD_H

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
