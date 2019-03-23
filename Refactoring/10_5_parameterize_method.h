#ifndef 10_5_PARAMETERIZE_METHOD_H
#define 10_5_PARAMETERIZE_METHOD_H

// 适用情景：多个函数极度相似，除了部分代码行不同。——进行提取，并以参数取代之


//// 原始版本1
//class Employee{
//    void tenPercentRaise(){
//        salary *= 1.1;
//    }
//    void fivePercentRaise(){
//        salary *= 1.05;
//    }

//    int salary;
//};

//// 新版本1
//class Employee{
////    void tenPercentRaise(){
////        salary *= 1.1;
////    }
////    void fivePercentRaise(){
////        salary *= 1.05;
////    }
//    void percentRaise(double factor){
//        salary *= (1 + factor);
//    }

//    int salary;
//};


#include <cmath>
#include <climits>
// 原始版本2
int lastUsage;
double baseCharge(){
    double result = min(lastUsage, 100) * 0.03;
    if (lastUsage > 100){
        result += (min(lastUsage, 200) - 100) * 0.05;
    }
    if (lastUsage > 200){
        result += (lastUsage - 200) * 0.07;
    }
    return result;
}

// 新始版本2
double lastUsage;

int usageInRange(int start, int end){
    if (lastUsage > start)
        return min(lastUsage, end) - start;
    return 0;
}
double baseCharge(){
    double result = usageInRange(0, 100) * 0.03;
    result += usageInRange(100, 200) * 0.05;
    result += usageInRange(200, INT_MAX) * 0.07;
    return result;
}


#endif // 10_5_PARAMETERIZE_METHOD_H
