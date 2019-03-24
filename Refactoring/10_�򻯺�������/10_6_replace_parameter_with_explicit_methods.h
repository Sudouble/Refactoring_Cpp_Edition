#ifndef 10_6_REPLACE_PARAMETER_WITH_EXPLICIT_METHODS_H
#define 10_6_REPLACE_PARAMETER_WITH_EXPLICIT_METHODS_H

// 适用情景：提供过多的选项，不如提供一个更清晰的接口


//// 原始版本
//class Engineer;
//class Salesman;
//class Manager;

//class Employee{
//private:
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

//    static Employee* create(int type) {
//        switch(type){
//        case ENGINEER:
//             return new Engineer();
//        case SALESMAN:
//             return new Salesman();
//        case MANAGER:
//             return new Manager();
//        }
//    }
//};

//class Engineer : public Employee{
//};
//class Salesman : public Employee{
//};
//class Manager : public Employee{
//};
//void Usage(){
//    Employee *engineer = Employee::create(Employee::ENGINEER);
//}


// 新版本
class Engineer;
class Salesman;
class Manager;

class Employee{
private:
    const static int ENGINEER = 0;
    const static int SALESMAN = 1;
    const static int MANAGER = 2;
public:
    Employee(int type){
        _type = type;
    }
    int GetType(){
        return _type;
    }
// 2 remove
//    static Employee* create(int type) {
//        switch(type){
//        case ENGINEER:
//             return new Engineer();
//        case SALESMAN:
//             return new Salesman();
//        case MANAGER:
//             return new Manager();
//        }
//    }

    // 1 add
    static Employee* createEngineer() {
     return new Engineer();
    }
    static Employee* createSalesman() {
     return new Salesman();
    }
    static Employee* createManager() {
     return new Manager();
    }
};

class Engineer : public Employee{
};
class Salesman : public Employee{
};
class Manager : public Employee{
};

void Usage(){
//    Employee *engineer = Employee::create(Employee::ENGINEER);
    Employee *engineer = Employee::createEngineer();
}


#endif // 10_6_REPLACE_PARAMETER_WITH_EXPLICIT_METHODS_H
