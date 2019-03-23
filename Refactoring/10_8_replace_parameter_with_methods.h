#ifndef 10_8_REPLACE_PARAMETER_WITH_METHODS_H
#define 10_8_REPLACE_PARAMETER_WITH_METHODS_H

// 适用情景：保持参数列表的健康，以及关注列表长度之外的其他影响因素：如历史接口、灵活性等


//// 原始版本
//double _quantity, _itemPrice;

//double discountedPrice(int basePrice, int discountLevel){
//    if (discountLevel == 2)
//        return basePrice * 0.1;
//    else {
//        return basePrice *0.05;
//    }
//}

//double getPrice(){
//    int basePrice = _quantity * _itemPrice;
//    int discountLevel;
//    if (_quantity > 100) discountLevel = 2;
//    else discountLevel = 1;
//    double finalPrice = discountedPrice(basePrice, discountLevel);
//    return finalPrice;
//}


// 新版本
double _quantity, _itemPrice;

// 1 add
int getDiscountLevel(){
    if (_quantity > 100)
        return 2;
    else
        return 1;
}

// 5 add
double getBasePrice(){
    return _quantity * _itemPrice;
}

// 7 final
double discountedPrice(){
    if (getDiscountLevel() == 2)
        return getBasePrice() * 0.1;
    else {
        return getBasePrice() * 0.05;
    }
}
// 6 rewrite
////double discountedPrice(int basePrice, int discountLevel){
//double discountedPrice(int basePrice){
//    if (getDiscountLevel() == 2)
//        return basePrice * 0.1;
//    else {
//        return basePrice *0.05;
//    }
//}

//double getPrice(){
//    int basePrice = _quantity * _itemPrice;
//// 4 remove
////    int discountLevel = getDiscountLevel();
//// 2 remove
////    if (_quantity > 100) discountLevel = 2;
////    else discountLevel = 1;
//// 3 change
////    double finalPrice = discountedPrice(basePrice, discountLevel);
//    double finalPrice = discountedPrice(basePrice);
//    return finalPrice;
//}


#endif // 10_8_REPLACE_PARAMETER_WITH_METHODS_H
