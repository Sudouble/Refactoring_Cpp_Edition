#ifndef 7_1_MOVEMETHOD_H
#define 7_1_MOVEMETHOD_H

// 适用情景：一个类，用别人的比用自己的还勤快。——移动使类间关系更简单

//// 原版本
//class AcountType{
//public:
//    bool isPremium(){
//        return true;
//    }
//};

//class Account{
//public:
//    double overDraftCharge(){
//        if (_type.isPremium()){
//            double result = 10;
//            if (_daysOverdrawn > 7)
//                result += (_daysOverdrawn-7)*0.85;
//        }
//        else {
//            return _daysOverdrawn*1.75;
//        }
//    }

//    double bankCharge(){
//        double result = 4.5;
//        if (_daysOverdrawn > 0)
//            result += overDraftCharge();
//        return result;
//    }

//private:
//    AcountType _type;
//    int _daysOverdrawn;
//};


// 新版本
// 耦合变量少的情况就是直接提取，多了可能得直接传递对象过去了。。
class AcountType{
public:
    double overDraftCharge(int daysOverdrawn){
        if (isPremium()){
            double result = 10;
            if (daysOverdrawn > 7)
                result += (daysOverdrawn-7)*0.85;
        }
        else {
            return daysOverdrawn*1.75;
        }
    }

    bool isPremium(){
        return true;
    }
};

class Account{
public:

    double bankCharge(){
        double result = 4.5;
        if (_daysOverdrawn > 0)
            result += _type.overDraftCharge(_daysOverdrawn);
        return result;
    }

private:
    AcountType _type;
    int _daysOverdrawn;
};

#endif // 7_1_MOVEMETHOD_H
