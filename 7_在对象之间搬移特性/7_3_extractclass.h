#ifndef 7_3_EXTRACTCLASS_H
#define 7_3_EXTRACTCLASS_H

// 适用情景：类的职责在扩展，有的就该自立门户了

#include <string>
using std::string;
// 原版本
class Person{
public:
    string GetName(){
        return _name;
    }

    string GetTelephoneNumber(){
        return "(" + _officeAreaCode + ")" + _officeNumber;
    }

    void SetOfficeAreaCode(string arg){
        _officeAreaCode = arg;
    }

    string GetOfficeNumber(){
        return _officeNumber;
    }

    void SetOfficeNumber(string arg){
        _officeNumber = arg;
    }

private:
    string _name;
    string _officeAreaCode;
    string _officeNumber;
};


// 新版本
// 要不要公开新类问题的讨论：
// 1. 运行任意访问，但必须是唯一访问点。 p179的“将值替换为引用对象”
// 2. 不允许修改
// 3. 直接更新整个TelephoneNumber对象
class TelephoneNumber
{
public:
    string GetTelephoneNumber(){
        return "(" + _officeAreaCode + ")" + _officeNumber;
    }

    void SetOfficeAreaCode(string arg){
        _officeAreaCode = arg;
    }

    string GetOfficeNumber(){
        return _officeNumber;
    }

    void SetOfficeNumber(string arg){
        _officeNumber = arg;
    }

private:
    string _officeAreaCode;
    string _officeNumber;
};

class Person{
public:
    string GetName(){
        return _name;
    }

    string GetTelephoneNumber(){
        return phoneNumber.GetTelephoneNumber();
    }

    string GetOfficeNumber(){
        return phoneNumber.GetOfficeNumber();
    }

private:
    string _name;
    TelephoneNumber phoneNumber;
};

#endif // 7_3_EXTRACTCLASS_H
