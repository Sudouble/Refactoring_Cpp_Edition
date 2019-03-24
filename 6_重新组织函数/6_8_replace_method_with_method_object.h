#ifndef 6_8_REPLACEMETHODWITHMETHODOBJECT_H
#define 6_8_REPLACEMETHODWITHMETHODOBJECT_H

// 适用情景：大函数，内部耦合严重，难拆分

//// 原版本
//class Account{

//    int gama(int inputval, int quntity, int yearToDate){
//        int importantValue1 = (inputval * quntity) + delta();
//        int importantValue2 = (inputval * yearToDate) + 100;
//        if ((yearToDate-importantValue1)>100)
//            importantValue2 -= 20;
//        int importantValue3 = importantValue2 * 7;
//        //and so on...
//        return importantValue3 - 2*importantValue1;
//    }

//    int delta(){
//        return -1;
//    }
//};


// 新版本
class Gama{

public:
    Gama(int inputval_, int quntity_, int yearToDate_){
        inputval = inputval_;
        quntity = quntity_;
        yearToDate = yearToDate_;
    }

public:
    int compute(){
        importantValue1 = (inputval * quntity) + delta();
        importantValue2 = (inputval * yearToDate) + 100;
        ImportantThing();
        importantValue3 = importantValue2 * 7;
        //and so on...
        return importantValue3 - 2*importantValue1;
    }

    void ImportantThing(){
        if ((yearToDate-importantValue1)>100)
            importantValue2 -= 20;
    }

    int delta(){
        return -1;
    }
private:
    int inputval;
    int quntity;
    int yearToDate;

    int importantValue1;
    int importantValue2;
    int importantValue3;
};

class Account{
    int gama(int inputval, int quntity, int yearToDate){
        Gama gamma = Gama(inputval, quntity, yearToDate);
        return gamma.compute();
    }
};

#endif // 6_8_REPLACEMETHODWITHMETHODOBJECT_H
