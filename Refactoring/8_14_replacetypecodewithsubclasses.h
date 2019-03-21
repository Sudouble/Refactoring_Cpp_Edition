#ifndef REPLACETYPECODEWITHSUBCLASSES_H
#define REPLACETYPECODEWITHSUBCLASSES_H

// 适用情景：类型码不会影响宿主行为，使用8.13即可。会影响的话，使用多态，（前提是本类型码产生的对象是持久对象），即本方法。
// 使用Conditional with Polymorphism的前置步骤


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
//};


// 新版本
class Engineer;
class Salesman;
class Manager;

class Employee{
public:
    int _type;
    const static int ENGINEER = 0;
    const static int SALESMAN = 1;
    const static int MANAGER = 2;
private:
    Employee(int type){
        _type = type;
    }
public:
    static Employee* create(int type){
        switch(type){
        case ENGINEER:
            return new Engineer();
        case SALESMAN:
            return new Salesman();
        case MANAGER:
            return new Manager();
        }
    }
    int GetType(){
        return _type;
    }
};

class Engineer : public Employee
{
public:
    int GetType(){
        Employee::ENGINEER;
    }
};

class Salesman : public Employee
{
public:
    int GetType(){
        Employee::SALESMAN;
    }
};

class Manager : public Employee
{
public:
    int GetType(){
        Employee::MANAGER;
    }
};


#endif // 8_14_REPLACETYPECODEWITHSUBCLASSES_H
