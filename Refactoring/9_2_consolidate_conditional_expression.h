#ifndef 9_2_CONSOLIDATE_CONDITIONAL_EXPRESSION_H
#define 9_2_CONSOLIDATE_CONDITIONAL_EXPRESSION_H

// 适用情景：判断含义相近，且返回一致的结果


int _seniority, _monthsDisabled, _isPartTime;
//// 原版本
//double disabilityAmount(){
//    if (_seniority < 2)
//        return 0;
//    if (_monthsDisabled > 12)
//        return 0;
//    if (_isPartTime)
//        return 0;
//    //....
//}

// 新版本
bool isNotEligibleForDisability(){
    return (_seniority < 2 || _monthsDisabled > 12 || _isPartTime);
}
double disabilityAmount(){
    if (isNotEligibleForDisability())
    //if (_seniority < 2 || _monthsDisabled > 12 || _isPartTime)
        return 0;
    //...
}

#endif // 9_2_CONSOLIDATE_CONDITIONAL_EXPRESSION_H
