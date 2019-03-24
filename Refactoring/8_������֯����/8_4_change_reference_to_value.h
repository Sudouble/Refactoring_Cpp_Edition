#ifndef 8_4_CHANGEREFERENCETOVALUE_H
#define 8_4_CHANGEREFERENCETOVALUE_H

// 适用情景：不可变值对象，在并发系统中不适用。

#include <string>
#include <QSet>
#include <QMap>
using std::string;

//// 见8.3的逆过程
//// 原版本
//class Currency{
//private:
//    string _code;
//public:
//    string GetCode(){
//        return _code;
//    }
//private:
//    Currency(string code){
//        _code = code;
//    }
//};

//void Usage(){
//    Currency usd = Cu
//}

// 新版本

#endif // 8_4_CHANGEREFERENCETOVALUE_H
