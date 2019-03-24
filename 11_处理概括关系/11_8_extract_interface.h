#ifndef 11_8_EXTRACT_INTERFACE_H
#define 11_8_EXTRACT_INTERFACE_H


// 适用情景：提炼接口，为扩展做准备


//// 原始版本
//class Employee{
//public:
//    double getRate(){
//        return 1.1;
//    }
//    bool hasSpecialSkill(){
//        return true;
//    }
//};

//void charge(Employee* emp, iny days){
//    int base = emp->getRate();
//    if (emp->hasSpecialSkill()){
//        return base*1.05;
//    }
//    return base;
//}

// 新版本
class Billable{
public:
    virtual double getRate() = 0;
    virtual bool hasSpecialSkill() = 0;
};

class Employee : public Billable{
public:
    double getRate(){
        return 1.1;
    }
    bool hasSpecialSkill(){
        return true;
    }
};

void charge(Billable* emp, iny days){
    int base = emp->getRate();
    if (emp->hasSpecialSkill()){
        return base*1.05;
    }
    return base;
}

#endif // 11_8_EXTRACT_INTERFACE_H
