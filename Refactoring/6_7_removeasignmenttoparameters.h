#ifndef 6_7_REMOVEASIGNMENTTOPARAMETERS_H
#define 6_7_REMOVEASIGNMENTTOPARAMETERS_H

// 适用情景：按引用传递时。按值传递尚可

//// 原版本
//int discount(int inputVal, int quntity, int yearToDate){
//    if (inputVal > 50) inputVal -= 2;
//    if (quntity > 100) inputVal -= 1;
//    if (yearToDate > 10000) inputVal -= 4;

//    return inputVal;
//}


// 新版本
int discount(int inputVal, int quntity, int yearToDate){
    int result = inputVal;
    if (inputVal > 50) result -= 2;
    if (quntity > 100) result -= 1;
    if (yearToDate > 10000) result -= 4;
    return result;
}

#endif // 6_7_REMOVEASIGNMENTTOPARAMETERS_H
