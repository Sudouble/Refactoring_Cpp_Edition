#ifndef 7_8_INTRODUCELOCALEXTENSION_H
#define 7_8_INTRODUCELOCALEXTENSION_H

// 适用情景：通过使用独立的类，为原先的类扩展新功能


#include <QDate>

//// 原版本
//QDate previousEnd;
//QDate newStart = QDate(previousEnd.year(), previousEnd.month(), previousEnd.day() + 1);

//// 新版本1：继承
//class MyDate : public QDate{
//    MyDate(QDate arg) :
//        QDate(arg)
//    {
//    }

//    QDate GetNextDay(){
//        return QDate(year(), month(), day() + 1);
//    }
//};

// 新版本2：包装类
class MyDateWrap {
public:
    MyDate(QDate arg) :
    {
        _date = arg;
    }

    QDate GetNextDay(){
        return QDate(_date.year(), _date.month(), _date.day() + 1);
    }
private:
    QDate _date;
};

#endif // 7_8_INTRODUCELOCALEXTENSION_H
