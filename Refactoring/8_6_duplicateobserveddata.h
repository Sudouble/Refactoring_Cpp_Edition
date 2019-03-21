#ifndef 8_6_DUPLICATEOBSERVEDDATA_H
#define 8_6_DUPLICATEOBSERVEDDATA_H

// 适用情景：领域数据、GUI分离。（业务逻辑和GUI分离）

#include <QLineEdit>
#include <QMainWindow>
#include <QString>

//// 原版本
//// 代码中的结构仅用于示意，实际不可运行
//class ItervalWindow : public QMainWindow
//{
//private:
//    QLineEdit _startField;
//    QLineEdit _endField;
//    QLineEdit _lengthField;

//public:
//    void FocusLost(QLineEdit &event){
//        if (event.objectName() == _startField.objectName())
//            ;
//    }

//    void StartField_FocusLost(QLineEdit &event){
//        if (isNotInteger(_startField.text()))
//            _startField.setText("0");
//        calculateLength();
//    }

//    void EndField_FocusLost(){
//        if (isNotInteger(_endField.text()))
//            _endField.setText("0");
//        calculateLength();
//    }

//    void LengthField_FocusLost(){
//        if (isNotInteger(_lengthField.text()))
//            _lengthField.setText("0");
//        calculateEnd();
//    }

//    bool isNotInteger(QString str){
//        return false;
//    }

//    void calculateLength(){
//        try{
//            int start = _startField.text().toInt();
//            int end = _endField.text().toInt();
//            int length = end - start;
//            _lengthField.setText(QString::number(length));
//        }catch(){
//            // ...
//        }
//    }

//    void calculateEnd(){
//        try{
//            int start = _startField.text().toInt();
//            int length = _lengthField.text().toInt();
//            int end = start + length;
//            _endField.setText(QString::number(end));
//        }catch(){
//            // ...
//        }
//    }
//};

// 新版本
// 新建业务类，单独处理
class Interval{
public:
    QString GetEnd(){
        return _end;
    }
    void SetEnd(QString arg){
        _end = arg;
    }
    ///
    QString GetStart(){
        return _start;
    }
    void SetStart(QString arg){
        _start = arg;
    }
    ///
    QString GetLength(){
        return _length;
    }
    void SetLength(QString arg){
        _length = arg;
    }
public:
    void calculateLength(){
        try{
            int start = _startField.text().toInt();
            int end = GetEnd().toInt();
            int length = end - start;
            _lengthField.setText(QString::number(length));

            NotifyObserver();
        }catch(){
            // ...
        }
    }

    void calculateEnd(){
        try{
            int start = _startField.text().toInt();
            int length = _lengthField.text().toInt();
            int end = start + length;
            SetEnd(QString::number(end));

            NotifyObserver();
        }catch(){
            // ...
        }
    }

public:
    void AddObserver(QMainWindow &window){
        Q_UNUSED(window)
    }
    void SetChanged() {}
    void NotifyObserver() {}
private:
    QString _end;
    QString _start;
    QString _length;
};

class ItervalWindow : public QMainWindow
{
private:
    QLineEdit _startField;
    QLineEdit _endField;
    QLineEdit _lengthField;

    Interval _subject;

public:
    ItervalWindow(){
        // ...

        _subject.AddObserver(this);
        update(_subject, "1");
    }
public:
    QString GetEnd(){
        return _subject.GetEnd();
    }

    void SetEnd(QString &name){
        _subject.SetEnd(name);
    }
    ///
    QString GetStart(){
        return _subject.GetStart();
    }
    void SetStart(QString arg){
        _subject.SetStart(arg);
    }
    ///
    QString GetLength(){
        return _subject.GetLength();
    }
    void SetLength(QString arg){
        _subject.SetLength(arg);
    }
public:
    //================================
    void FocusLost(QLineEdit &event){
        if (event.objectName() == _startField.objectName())
            StartField_FocusLost(event);
        else if (event.objectName() == _endField.objectName())
            EndField_FocusLost(event);
        else if (event.objectName() == _lengthField.objectName())
            LengthField_FocusLost(event);
    }

    void StartField_FocusLost(QLineEdit &event){
        if (isNotInteger(GetStart()))
            SetStart("0");
        _subject.calculateLength();
    }

    void EndField_FocusLost(QLineEdit &event){
        if (isNotInteger(GetEnd())) //
            SetEnd("0"); //
        _subject.calculateLength();
    }

    void LengthField_FocusLost(QLineEdit &event){
        if (isNotInteger(GetLength()))
            SetLength("0");
        _subject.calculateEnd();
    }

    bool isNotInteger(QString str){
        return false;
    }

    // void calculateLength(){...}
    // void calculateEnd(){...}

    void update(Interval observed, QString object){
        _endField.setText(_subject.GetEnd());
        _startField.setText(_subject.GetStart());
        _lengthField.setText(_subject.GetLength());
    }
};

#endif // 8_6_DUPLICATEOBSERVEDDATA_H
