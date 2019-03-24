#ifndef 6_6_SPLITTEMPVARIABLE_H
#define 6_6_SPLITTEMPVARIABLE_H

// 适用情景:同一临时变量职责很重，需进行分解

#include <cmath>

int _delay;
double _primaryForce, _secondaryForce, _mass;

//// 原始版本
//double GetDistanceTravelled(int time){
//    double result;
//    double acc = _primaryForce / _mass;
//    int primaryTime = min(time, _delay);
//    result = 0.5*acc*primaryTime*primaryTime;
//    int secondaryTime = time - _delay;
//    if (secondaryTime > 0){
//        double primaryVel = acc * _delay;
//        acc = (_primaryForce + _secondaryForce) / _mass;
//        result += primaryVel*secondaryTime + 0.5*acc*secondaryTime*secondaryTime;
//    }
//    return result;
//}

//// 新版本——未完成版
//double GetDistanceTravelled(int time){
//    double result;

//    int primaryTime = min(time, _delay);
//    double primaryAcc = _primaryForce / _mass;
//    result = 0.5*primaryAcc*primaryTime*primaryTime;

//    int secondaryTime = time - _delay;
//    if (secondaryTime > 0){
//        double primaryVel = primaryAcc * _delay;
//        double secondaryAcc = (_primaryForce + _secondaryForce) / _mass;
//        result += primaryVel*secondaryTime +
//                0.5*secondaryAcc*secondaryTime*secondaryTime;
//    }
//    return result;
//}


// 我的新版本——未完成版（续）
// 原则：抽离出最本质的内容
double CalcDistance(double acc, double initVel, int time)
{
    return initVel*time + 0.5*acc*time*time;
}

double calcPartOne(int time, double initVel)
{
    int primaryTime = min(time, _delay);
    double primaryAcc = _primaryForce / _mass;
    return CalcDistance(primaryAcc, initVel, primaryTime);
}

double calcPartTwo(int time, double initVel)
{
    int secondaryTime = time - _delay;
    if (secondaryTime > 0){
        double secondaryAcc = (_primaryForce + _secondaryForce)/_mass;
        return CalcDistance(secondaryAcc, initVel, secondaryTime);
    }
    return 0;
}

double GetDistanceTravelled(int time){
    double primaryAcc = _primaryForce / _mass;
    double primaryVel = primaryAcc * _delay;

    double resultPrimary = calcPartOne(time, 0);
    double resultSecondary = calcPartTwo(time, primaryVel);

    return resultPrimary + resultSecondary;
}

#endif // 6_6_SPLITTEMPVARIABLE_H
