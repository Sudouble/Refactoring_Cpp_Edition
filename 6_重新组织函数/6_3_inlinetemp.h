#ifndef 6_3_INLINETEMP_H
#define 6_3_INLINETEMP_H

// 适用情景：函数内，间接层多了，改成更易理解的形式

class Order{
    static double basePrice(){
        return 100;
    }
};

//// 原始版本
//bool CalcPrice()
//{
//    double basePrice = Order::basePrice();
//    return basePrice > 100;
//}

// 新版本
bool CalcPrice()
{
    return Order::basePrice() > 100;
}

#endif // 6_3_INLINETEMP_H
