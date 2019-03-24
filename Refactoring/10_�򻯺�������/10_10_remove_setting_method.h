#ifndef 10_10_REMOVE_SETTING_METHOD_H
#define 10_10_REMOVE_SETTING_METHOD_H

// 适用情景：不希望外界通过设值函数进行修改——权责分离

#include <string>
#include <vector>
using std::string;
using std::vector;

//// 原始版本
//// 原始形态1
class Account{
private:
    string _id;
    Account(string id){
        _id = id;
    }
    void setID(string arg){
        _id = arg;
    }
};

class InterestAccount : public Account{
private:
    double _interestRate;
public:
    InterestAccount(string id, double rate){
        setID(id);
        _interestRate = rate;
    }
};

//// 原始形态2
//class Account{
//private:
//    string _id;
//    Account(string id){
//        _id = id;
//    }
////    void setID(string arg){
////        _id = "ZZ" + arg; //做了额外处理，但函数名称不好
////    }
//    void initializeID(string arg){
//        _id = "ZZ" + arg; //做了额外处理，但函数名称不好
//    }
//};

// 新版本


#endif // 10_10_REMOVE_SETTING_METHOD_H
