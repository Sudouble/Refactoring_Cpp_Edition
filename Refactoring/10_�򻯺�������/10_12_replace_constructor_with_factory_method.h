#ifndef 10_12_REPLACE_CONSTRUCTOR_WITH_FACTORY_METHOD_H
#define 10_12_REPLACE_CONSTRUCTOR_WITH_FACTORY_METHOD_H

// 适用情景：需产生不同类型对象的需求


//// 原始版本1——根据整数，创建对象
//class Employee{
//public:
//    const static int ENGINEER = 0;
//    const static int SALESMAN = 1;
//    const static int MANAGER = 2;

//    Employee(int type){
//        _type = type;
//    }
//private:
//    int _type;
//};

//// 新版本1——根据整数，创建对象
//class Employee{
//public:
//    const static int ENGINEER = 0;
//    const static int SALESMAN = 1;
//    const static int MANAGER = 2;

//    static Employee* create(int type){
//        return new Employee(type);
//    }

//private:
//    Employee(int type){
//        _type = type;
//    }
//private:
//    int _type;
//};


// C++暂不支持
// 原始版本2——根据字符串创建子类对象
// 新版本2——根据字符串创建子类对象

#endif // 10_12_REPLACE_CONSTRUCTOR_WITH_FACTORY_METHOD_H
