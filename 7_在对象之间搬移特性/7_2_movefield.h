#ifndef 7_2_MOVEFIELD_H
#define 7_2_MOVEFIELD_H

// 适用情景：与MoveMethod类似。版本更迭中，字段渐渐在另一个类里玩得更欢脱……

//// 原版本
//class Account
//{
//private:
//    AccountType _type;
//    double _interstRate;
//public:
//    Account() {}
//    double interestForAmount_days(double amount, int days){
//        return _interstRate*amount*days/365;
//    }
//};

//// 新版本1
//class AccountType{
//private:
//    double _interestRate;
//public:
//    void SetInterstRate(double arg){
//        _interestRate = arg;
//    }

//    double GetInterstRate(){
//        return _interestRate;
//    }
//};
//class Account
//{
//private:
//    AccountType _type;
//public:
//    Account() {}
//    double interestForAmount_days(double amount, int days){
//        return _type.GetInterstRate()*amount*days/365;
//    }
//};


// 新版本2:使用Self_Encapsulation
// 耦合比较多了，一次性改过去难度较大，分步骤进行
class AccountType{
private:
    double _interestRate;
public:
    void SetInterstRate(double arg){
        _interestRate = arg;
    }

    double GetInterstRate(){
        return _interestRate;
    }
};
class Account
{
private:
    AccountType _type;
public:
    Account() {}
    double interestForAmount_days(double amount, int days){
        return GetInterstRate()*amount*days/365;
    }

    void SetInterstRate(double arg){
        _type.SetInterstRate(arg);
    }
    double GetInterstRate(){
        _type.GetInterstRate();
    }
};

#endif // 7_2_MOVEFIELD_H
