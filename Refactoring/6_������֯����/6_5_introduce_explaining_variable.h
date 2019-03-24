#ifndef 6_5_INTRODUCEEXPLAININGVARIABLE_H
#define 6_5_INTRODUCEEXPLAININGVARIABLE_H

// 适用情景：一长串计算或处理，用临时变量分隔开

#include <cmath>
using namespace std;

double _quantity = 10;
double _itemPrice = 101;

//// 原始版本
//double Price()
//{
//    // price is base price - quantity discount + shipping
//    return _quantity * _itemPrice -
//            max(0, _quantity - 500) * _itemPrice * 0.05 +
//            min(_quantity*_itemPrice*0.1, 100.0);
//}


// 新版本1
double Price()
{
    // price is base price - quantity discount + shipping
    // 1
    double basePrice = _quantity * _itemPrice;
    // 2
    double quantityDiscount = max(0, _quantity - 500) * _itemPrice * 0.05;
    // 3
    double shipping = min(basePrice*0.1, 100.0);

    return basePrice - quantityDiscount + shipping;
}


//// 新版本2: Extract Method
//// 提取需花费更大工作量（大量局部变量）时，不推荐使用
//double basePrice(){
//    return _quantity * _itemPrice;
//}

//double quantityDiscount(){
//    return max(0, _quantity - 500) * _itemPrice * 0.05;
//}

//double shipping() {
//    return min(basePrice()*0.1, 100.0)
//}

//double Price()
//{
//    return basePrice() - quantityDiscount() + shipping();
//}


#endif // 6_5_INTRODUCEEXPLAININGVARIABLE_H
