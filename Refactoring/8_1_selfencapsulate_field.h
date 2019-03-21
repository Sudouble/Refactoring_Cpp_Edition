#ifndef 8_1_SELFENCAPSULATEFIELD_H
#define 8_1_SELFENCAPSULATEFIELD_H

// 适用情景：这依旧是个论题——直接/间接使用字段


//// 原版本
//int _low, _high;
//bool includes(int arg){
//    return arg >= _low && arg <= _high;
//}

// 新版本
int _low, _high;
bool includes(int arg){
    return arg >= GetLow() && arg <= GetHigh();
}

int GetLow(){
    return _low;
}

int GetHigh(){
    return _high;
}

#endif // 8_1_SELFENCAPSULATEFIELD_H
