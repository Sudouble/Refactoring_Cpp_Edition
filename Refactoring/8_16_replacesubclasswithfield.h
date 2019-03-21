#ifndef 8_16_REPLACESUBCLASSWITHFIELD_H
#define 8_16_REPLACESUBCLASSWITHFIELD_H

// 适用情景：只存在常量函数，且类价值不大，造成复杂性，直接压缩类


//// 原版本
//class Person{
//    virtual bool isMale()=0;
//    virtual char getCode()=0;
//};
//class Male : public Person{
//    bool isMale(){
//        return true;
//    }
//    char getCode(){
//        return 'M';
//    }
//};
//class Female : public Person{
//    bool isMale(){
//        return false;
//    }
//    char getCode(){
//        return 'F';
//    }
//};


// 新版本
class Male;
class Female;

class Person{
private:
    // 1
    bool _isMale;
    char _code;
public:
    Person(bool isMale, char code){
        _isMale = isMale;
        _code = code;
    }
// 2
//    virtual bool isMale()=0;
//    virtual char getCode()=0;

// 3
//    static Person* createMale(){
//        return new Male();
//    }
//    static Person* createFemale(){
//        return new Female();
//    }
};
// 3
//class Male : public Person{
//public:
//    //1
//    Male(bool isMale, char code):
//        Person(isMale, code)
//    {

//    }
//// 2
////    bool isMale(){
////        return true;
////    }
////    char getCode(){
////        return 'M';
////    }
//};
//class Female : public Person{
//public:
//    //1
//    Female(bool isMale, char code):
//        Person(isMale, code)
//    {

//    }
//// 2
////    bool isMale(){
////        return false;
////    }
////    char getCode(){
////        return 'F';
////    }
//};

void Usage(){
    //Person kent = new Male();
    //Person kent = Person::createMale();
    Person kent = Person(true, "M");
}


#endif // 8_16_REPLACESUBCLASSWITHFIELD_H
