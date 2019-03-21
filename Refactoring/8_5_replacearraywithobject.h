#ifndef 8_5_REPLACEARRAYWITHOBJECT_H
#define 8_5_REPLACEARRAYWITHOBJECT_H

// 适用情景：对象更合适存数据，数组定点存数的约束太大了。


#include <string>
#include <QSet>
#include <QMap>
using std::string;

//// 原版本
//void Usage(){
//    string row[3];
//    row[0] = "Liverpool";
//    row[1] = "15";

//    string name = row[0];
//    int wins = atoi(row[1].c_str());
//}


//// 新版本——第一步
//class Performance{
//public:
//    string _data[3];
//};
//void Usage(){
//    Performance perform;

//    string name = perform._data[0];
//    int wins = atoi(perform.data[1].c_str());
//}


//// 新版本——第二步，设置Set/Get函数
//class Performance{
//public:
//    string _data[3];

//    void setName(string name){
//        _data[0] = name;
//    }
//    string getName(){
//        return _data[0];
//    }

//    void setWins(string wins){
//        _data[1] = wins;
//    }
//    int getWins(){
//        return atoi(_data[1].c_str());
//    }
//};
//void Usage(){
//    Performance perform;
//    perform.setName("Liverpool");
//    perform.setWins("15");

//    string name = perform.getName();
//    int wins = atoi(perform.getWins());
//}


// 新版本——第三步，去除数组，进一步封装
class Performance{
private:
    string _name;
    string _wins;
public:
    void setName(string name){
        _name = name;
    }
    string getName(){
        return _name;
    }

    void setWins(string wins){
        _wins = wins;
    }
    int getWins(){
        return atoi(_wins.c_str());
    }
};
void Usage(){
    Performance perform;
    perform.setName("Liverpool");
    perform.setWins("15");

    string name = perform.getName();
    int wins = atoi(perform.getWins());
}



#endif // 8_5_REPLACEARRAYWITHOBJECT_H
