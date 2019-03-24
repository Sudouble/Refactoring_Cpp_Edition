#ifndef REPLACE_ERROR_CODE_WITH_EXCEPTION_H
#define REPLACE_ERROR_CODE_WITH_EXCEPTION_H

// 适用情景：将“普通程序”和“错误处理”分开的

#include <string>
#include <iostream>
using namespace std;
#include <QString>

//// 原始版本
//class Account{
//public:
//    int withDraw(int amount){
//        if (amount > _balance)
//            return -1;
//        else
//            _balance -= amount;
//    }
//private:
//    int _balance;
//};
//void handleOverdrawn(){}
//void doTheUsualThing(){}
//void Usage(){
//    Account account;
//    if (account.withDraw(10) == -1){
//        handleOverdrawn();
//    } else {
//        doTheUsualThing();
//    }
//}

//// 新版本1——非受控异常  （不在客户端显式去处理异常情况）
//void IllegalArgumentException(string arg){
//    cout << arg << endl;
//}
//class Assert{
//    static void isTrue(QString str, bool test){
//        if (!test)
//            throw QString("Assert failed:" + str);
//    }
//};
//class Account{
//public:
//    int withDraw(int amount){
//            Assert::isTrue("Amount too large", amount > _balance);
////        if (amount > _balance)
////            throw QString("Amount too large");
//        _balance -= amount;
//    }
//// 2 removed
////    bool canWithdraw(int amount){
////        if (amount > _balance)
////            return false;
////        return true;
////    }


//private:
//    int _balance;
//};

//void handleOverdrawn(){}
//void doTheUsualThing(){}
//void Usage(){
////    Account account;
////    if (!account.canWithdraw(10)){
////        handleOverdrawn();
////    } else {
////        account.withDraw(10);
////        doTheUsualThing();
////    }
//}

// 新版本2——受控异常
class BalanceException{};

class Account{
public:
    int withDraw(int amount){
        if (amount > _balance)
            throw BalanceException();
        _balance -= amount;
    }
private:
    int _balance;
};

void handleOverdrawn(){}
void doTheUsualThing(){}
void Usage(){
    try{
        Account account;
        account.withDraw(10);
        doTheUsualThing();
    } catch (BalanceException e){
        handleOverdrawn();
    }
}

#endif // 10_14_REPLACE_ERROR_CODE_WITH_EXCEPTION_H
