#ifndef 9_4_REMOVE_CONTROL_FLAG_H
#define 9_4_REMOVE_CONTROL_FLAG_H

// 适用情景：break,continue语句的使用

#include <string>
#include <vector>
using std::string;
using std::vector;

//// 原版本
//void sendAlert(){

//}

//void checkSecurity(vector<string> people){
//    bool found = false;
//    for (int i = 0; i < people.size(); i++){
//        if (!found){
//            if (people[i] == "Don"){
//                sendAlert();
//                found = true;
//            }
//            if (people[i] == "John"){
//                sendAlert();
//                found = true;
//            }
//        }
//    }
//}

// 新版本1——break方式
void sendAlert(){

}

void checkSecurity(vector<string> people){
    for (int i = 0; i < people.size(); i++){
        if (people[i] == "Don"){
            sendAlert();
            break;
        }
        if (people[i] == "John"){
            sendAlert();
            break;
        }
    }
}

// 新版本2——return方式，与上述版本类似，不赘述

#endif // 9_4_REMOVE_CONTROL_FLAG_H
