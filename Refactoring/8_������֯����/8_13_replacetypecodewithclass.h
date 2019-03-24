#ifndef 8_13_REPLACETYPECODEWITHCLASS_H
#define 8_13_REPLACETYPECODEWITHCLASS_H

// 适用情景：需对类型码做检查，因为类型码背后仅表示一个数字。
// 方法：抽离出单独的类，进行封装，并进行调用


//// 原版本
//class Person{
//public:
//    static int O = 0;
//    static int A = 1;
//    static int B = 2;
//    static int AB = 3;
//private:
//    int _bloodGroup;
//public:
//    Person(int bloodGroup){
//        _bloodGroup = bloodGroup;
//    }
//    int GetBloodGroupCode(){
//        return _bloodGroup;
//    }
//};

//void Usage(){
//    Person thePerson(Person::O);
//    int code = thePerson.GetBloodGroupCode();
//}

// 新版本
class BloodGroup
{
public:
    static BloodGroup *O = new BloodGroup(0);
    static BloodGroup *A = new BloodGroup(1);
    static BloodGroup *B = new BloodGroup(2);
    static BloodGroup *AB = new BloodGroup(3);

    BloodGroup(int code) {
        _code = code;
    }

    int GetCode(){
        return _code;
    }

//    static BloodGroup* code(int arg){
//        return _values[arg];
//    }
private:
//    static BloodGroup* _values[4] = {O, A, B, AB};
    int _code;
};

class Person{
//public:
//    static int O = BloodGroup.O->GetCode();
//    static int A = BloodGroup.A->GetCode();
//    static int B = BloodGroup.B->GetCode();
//    static int AB = BloodGroup.AB->GetCode();
private:
    BloodGroup *_bloodGroup;
public:
    Person(BloodGroup *bloodGroup){
        _bloodGroup = bloodGroup;
    }
    BloodGroup* GetBloodGroup(){
        return _bloodGroup;
    }
    void SetBloodGroup(BloodGroup *arg){
        _bloodGroup = arg;
    }
};

void Usage(){
    // Person thePerson(Person::O);
    // int code = thePerson.GetBloodGroup();
    Person thePerson(BloodGroup::O);
    int code = thePerson.GetBloodGroup()->GetCode();
}

#endif // 8_13_REPLACETYPECODEWITHCLASS_H
