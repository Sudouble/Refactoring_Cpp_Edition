#ifndef 9_1_DECOMPOSE_CONDITIONAL_H
#define 9_1_DECOMPOSE_CONDITIONAL_H

// 适用情景：复杂、意图不明的条件语句

#include <QDate>
const int SUMMER_START = 6;
const int SUMMER_END = 8;

int quantity;
double _winterRate, _winterServiceCharge, _summerRate;

// 原版本
//void Usage(int time){
//    int charge = 0;
//    if (time < SUMMER_START || time > SUMMER_END) {
//        charge = quantity * _winterRate + _winterServiceCharge;
//    } else {
//        charge = quantity * _summerRate;
//    }
//}

// 新版本
bool notSummer(int time){
    return time < SUMMER_START || time > SUMMER_END;
}
double winterCharge(int quantity_){
    return quantity_ * _winterRate + _winterServiceCharge;
}
double summerCharge(int quantity_){
    return quantity_ * _summerRate;
}

void Usage(int time){
    double charge = 0;
    if (notSummer(time)){
        charge = winterCharge(quantity);
    } else {
        charge = summerCharge(quantity);
    }
}

#endif // 9_1_DECOMPOSE_CONDITIONAL_H
