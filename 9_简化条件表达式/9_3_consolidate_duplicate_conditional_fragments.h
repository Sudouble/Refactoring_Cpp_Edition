#ifndef 9_3_CONSOLIDATE_DUPLICATE_CONDITIONAL_FRAGMENTS_H
#define 9_3_CONSOLIDATE_DUPLICATE_CONDITIONAL_FRAGMENTS_H

// 适用情景：移出重复执行的代码段


//// 原版本
//bool isSpecialDeal(){
//    return true;
//}
//void send(){}
//void Usage(){
//    int total;
//    if (isSpecialDeal()) {
//        total = price * 0.95;
//        send();
//    } else {
//        total = price * 0.98;
//        send();
//    }
//}


// 新版本
bool isSpecialDeal(){
    return true;
}
void send(){}
void Usage(){
    int total;
    if (isSpecialDeal()) {
        total = price * 0.95;
//        send();
    } else {
        total = price * 0.98;
//        send();
    }
    send();
}


#endif // 9_3_CONSOLIDATE_DUPLICATE_CONDITIONAL_FRAGMENTS_H
