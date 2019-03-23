#ifndef REPLACETYPECODEWITHSTATEORSTRATEGY_H
#define REPLACETYPECODEWITHSTATEORSTRATEGY_H

// 适用情景：类型码的值在对象生命周期中发生变化


//// 原版本
//class Employee{
//private:
//    int _type;
//    const static int ENGINEER = 0;
//    const static int SALESMAN = 1;
//    const static int MANAGER = 2;
//public:
//    Employee(int type){
//        _type = type;
//    }
//    int GetType(){
//        return _type;
//    }

//    int payAmount(){
//        switch(_type){
//        case ENGINEER:
//            return _monthlySalary;
//        case MANAGER:
//            return _monthlySalary + _commission;
//        case MANAGER:
//            return _monthlySalary + _bonus;
//        }
//    }
//private:
//    int _monthlySalary;
//    int _commission;
//    int _bonus;
//};


// 新版本
// 情况：对工程师的提拔，变成了经理
class Engineer;
class Salesman;
class Manager;
class EmployeeType;

class Employee{
private:
//     int _type;
    EmployeeType* _type;
public:
// 2 -->Move to EmployeeType Class
//    const static int ENGINEER = 0;
//    const static int SALESMAN = 1;
//    const static int MANAGER = 2;

// 1
//    Employee(int type){
//        _type = type;
//    }
//    int GetType(){
//        return _type;
//    }
    int GetType(){
        return _type->GetTypeCode();
    }

    // 3
    int payAmount(){
        switch(GetType()){
        case EmployeeType::ENGINEER:
            return _monthlySalary;
        case EmployeeType::SALESMAN:
            return _monthlySalary + _commission;
        case EmployeeType::MANAGER:
            return _monthlySalary + _bonus;
        }
    }

// 2 -->Move to EmployeeType Class
//    int setType(){
//        switch(GetType()){
//        case ENGINEER:
//            _type = new Engineer;
//            break;
//        case SALESMAN:
//            _type = new Salesman;
//            break;
//        case MANAGER:
//            _type = new Manager;
//            break;
//        }
//    }
private:
    int _monthlySalary;
    int _commission;
    int _bonus;
};

class EmployeeType{
public:
    // 2 Move destinate
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
};
class Manager : public EmployeeType{
public:
    virtual int GetTypeCode(){
        return EmployeeType::MANAGER;
    }
};
class Salesman : public EmployeeType{
public:
    virtual int GetTypeCode(){
        return EmployeeType::SALESMAN;
    }
};

#endif // 8_15_REPLACETYPECODEWITHSTATEORSTRATEGY_H
