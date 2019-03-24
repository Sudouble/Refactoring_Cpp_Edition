#ifndef 7_7_INTRODUCEFOREIGNMETHOD_H
#define 7_7_INTRODUCEFOREIGNMETHOD_H

// 适用情景：通过函数为类扩展新功能


#include <QDate>

//// 原版本
//QDate previousEnd;
//QDate newStart = QDate(previousEnd.year(), previousEnd.month(), previousEnd.day() + 1);


// 新版本
static QDate GetNextDay(QDate arg){
    return QDate(arg.year(), arg.month(), arg.day() + 1);
}

#endif // 7_7_INTRODUCEFOREIGNMETHOD_H
