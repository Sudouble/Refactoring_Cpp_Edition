#ifndef 9_6_REPLACE_CONDITIONAL_WITH_POLYMORPHISM_H
#define 9_6_REPLACE_CONDITIONAL_WITH_POLYMORPHISM_H

// 适用情景：多态极大适用处——根据不同类型，采用不同的行为


// 原版本
class Engineer;
class Salesman;
class Manager;

class Employee{
private:
    EmployeeType* _type;
public:
    int GetType(){
        return _type->GetTypeCode();
    }

    // 1, move to EmployeeType
//    int payAmount(){
//        switch(GetType()){
//        case EmployeeType::ENGINEER:
//            return _monthlySalary;
//        case EmployeeType::SALESMAN:
//            return _monthlySalary + _commission;
//        case EmployeeType::MANAGER:
//            return _monthlySalary + _bonus;
//        }
//    }
    // 1, add calc
    double getMonthlySalary(){
        return 1.0;
    }
    double getCommission(){
        return 1.1;
    }
    double getBonus(){
        return 1.2;
    }
    // 2, change signature
    int payAmount(){
        return _type->payAmount(this);
    }
private:
    int _monthlySalary;
    int _commission;
    int _bonus;
};

class EmployeeType{
public:
    static EmployeeType* newType(int code){
        switch(code){
        case ENGINEER:
            return new Engineer;
        case SALESMAN:
            return new Salesman;
        case MANAGER:
            return new Manager;
        }
    }

    // 2 move to subclasses and abstract
//    // 1, change signature
//    int payAmount(Employee *emp){
//        switch(GetTypeCode()){
//        case EmployeeType::ENGINEER:
//            return emp->getMonthlySalary();
//        case EmployeeType::SALESMAN:
//            return emp->getMonthlySalary() + emp->getCommission();
//        case EmployeeType::MANAGER:
//            return emp->getMonthlySalary() + emp->getBonus();
//        }
//    }
    virtual int payAmount(Employee *emp)=0;

    virtual int GetTypeCode()=0;
public:
    const static int ENGINEER = 0;
    const static int SALESMAN = 1;
    const static int MANAGER = 2;
};

class Engineer : public EmployeeType{
public:
    virtual int GetTypeCode(){
        return EmployeeType::ENGINEER;
    }
    virtual int payAmount(Employee *emp){
        return emp->getMonthlySalary();
    }
};
class Manager : public EmployeeType{
public:
    virtual int GetTypeCode(){
        return EmployeeType::MANAGER;
    }
    virtual int payAmount(Employee *emp){
        return emp->getMonthlySalary() + emp->getCommission();
    }
};
class Salesman : public EmployeeType{
public:
    virtual int GetTypeCode(){
        return EmployeeType::SALESMAN;
    }
    virtual int payAmount(Employee *emp){
        return emp->getMonthlySalary() + emp->getBonus();
    }
};

// 新版本

#endif // 9_6_REPLACE_CONDITIONAL_WITH_POLYMORPHISM_H
