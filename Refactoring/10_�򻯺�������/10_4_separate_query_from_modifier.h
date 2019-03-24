#ifndef 10_4_SEPARATE_QUERY_FROM_MODIFIER_H
#define 10_4_SEPARATE_QUERY_FROM_MODIFIER_H

// 适用情景：有返回值的函数，尽量不要有副作用（做多余的事情）


#include <string>
#include <vector>
using std::string;
using std::vector;


void sendAlert(){

}
//// 原始版本
//string findMiscreant(vector<string> people){
//    for (int i = 0; i < people.size(); i++){
//        if (people[i] == "Don"){
//            sendAlert();
//            return "Don";
//        }
//        if (people[i] == "John"){
//            sendAlert();
//            return "John";
//        }
//    }
//    return "";
//}

//void someLaterCode(string a){

//}
//void checkSecurity(vector<string> people){
//    string found = findMiscreant(people);
//    someLaterCode(found);
//}

// 新版本
string foundPerson(vector<string> people){
    for (int i = 0; i < people.size(); i++){
        if (people[i] == "Don"){
            return "Don";
        }
        if (people[i] == "John"){
            return "John";
        }
    }
    return "";
}

////string findMiscreant(vector<string> people){
//void findMiscreant(vector<string> people){
//    for (int i = 0; i < people.size(); i++){
//        if (people[i] == "Don"){
//            sendAlert();
//            return;
////            return foundPerson(people);
//        }
//        if (people[i] == "John"){
//            sendAlert();
//            return;
////            return foundPerson(people);
//        }
//    }
//    return "";
//}
void findMiscreant(vector<string> people){
    if (foundPerson(people) != "")
        sendAlert();
}

void someLaterCode(string a){

}
void checkSecurity(vector<string> people){
    findMiscreant(people);
    string found = foundPerson(people);

    someLaterCode(found);
}

#endif // 10_4_SEPARATE_QUERY_FROM_MODIFIER_H
