#ifndef 7_5_HIDEDELEGATE_H
#define 7_5_HIDEDELEGATE_H

// 适用情景：得墨忒定律再现，方法的方法的方法。——直接封装起来

#include <string>
using std::string;

//// 原版本
//class Person;
//class Department
//{
//public:
//    Department(Person *manager) {
//        _manager = manager;
//    }

//    Person* GetManager(){
//        return _manager;
//    }

//private:
//    string _chargeCode;
//    Person *_manager;
//};

//class Person{
//public:
//    Department GetDepartment(){
//        return _department;
//    }

//    void SetDepartment(Department arg){
//        _department = arg;
//    }

//private:
//    Department _department;

//};

//void Usage(){
//    Person john;
//    Person manager;

//    Department department(&manager);
//    john.SetDepartment(department);

//    // 获取经理的途径
//    john.GetDepartment().GetManager();
//}

// 新版本
class Person;
class Department
{
public:
    Department(Person *manager) {
        _manager = manager;
    }

    Person* GetManager(){
        return _manager;
    }

private:
    string _chargeCode;
    Person *_manager;
};

class Person{
public:
    Department GetDepartment(){
        return _department;
    }

    void SetDepartment(Department arg){
        _department = arg;
    }

    Person GetManager(){
        return _department.GetManager();
    }

private:
    Department _department;

};

void Usage(){
    Person john;
    Person manager;

    Department department(&manager);
    john.SetDepartment(department);

    // 获取经理的途径----
    john.GetManager();
}

#endif // 7_5_HIDEDELEGATE_H
