#ifndef 6_4_REPLACETEMPWITHQUERY_H
#define 6_4_REPLACETEMPWITHQUERY_H

// 适用情景：局部变量多，时内部逻辑严重耦合——改为查询式

double _quantity = 10;
double _itemPrice = 101;

//// 原始版本
//double GetPrice()
//{
//    int basePrice = _quantity * _itemPrice;
//    double discountFactor;
//    if (basePrice > 1000)
//        discountFactor = 0.95;
//    else
//        discountFactor = 0.98;
//    return basePrice * discountFactor;
//}

//// 新版本
//int BasePrice(){
//    return _quantity*_itemPrice;
//}

//double discountFactor(){
//    if (BasePrice() > 1000)
//        return 0.95;
//    else
//        return 0.98;
//}

//double GetPrice()
//{
//    return BasePrice()*discountFactor();
//}

// 我的想法，原因：重复计算了BasePrice
int BasePrice(){
    return _quantity*_itemPrice;
}

double discountFactor(int basePrice){
    if (basePrice > 1000)
        return 0.95;
    else
        return 0.98;
}

double GetPrice()
{
    int basePrice = BasePrice();
    return basePrice*discountFactor(basePrice);
}

#endif // 6_4_REPLACETEMPWITHQUERY_H
