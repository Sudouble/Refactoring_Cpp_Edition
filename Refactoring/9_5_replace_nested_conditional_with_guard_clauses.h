#ifndef 9_5_REPLACE_NESTED_CONDITIONAL_WITH_GUARD_CLAUSES_H
#define 9_5_REPLACE_NESTED_CONDITIONAL_WITH_GUARD_CLAUSES_H

// 适用情景：卫语句——凸显出罕见、重要语句


bool _isDead, _isSeparated, _isRetired;
double deadAmount(){
    return 10.0;
}
double separatedAmount(){
    return 11.0;
}
double retiredAmount(){
    return 12.0;
}
double normalAmount(){
    return 13.0;
}
//// 原版本
//double getPayAmount(){
//    double result;
//    if (_isDead) result = deadAmount();
//    else{
//        if (_isSeparated) result = separatedAmount();
//        else{
//            if (_isRetired) result = retiredAmount();
//            else result = normalAmount();
//        }
//    }
//    return result;
//}


// 新版本
double getPayAmount(){
    if(_isDead)
        return deadAmount();
    if (_isSeparated)
        return separatedAmount();
    if (_isRetired)
        return retiredAmount();
    return normalAmount();
}

// 其他例子：条件反转——反转后，逻辑简化，然后精简

#endif // 9_5_REPLACE_NESTED_CONDITIONAL_WITH_GUARD_CLAUSES_H
