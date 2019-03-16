#ifndef EXTRACTMETHOD_H
#define EXTRACTMETHOD_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string _name = "Extract Method";

//// 例子1：无局部变量——原先写法
//void printOwing()
//{
//    vector<double> orders;
//    double outstanding = 0.0;

//    // print banner
//    cout << "*************************" << endl;
//    cout << "*******Customer Owes*****" << endl;
//    cout << "*************************" << endl;

//    // calculate outstanding
//    for (size_t i = 0; i < orders.size(); i++)
//    {
//        double each = orders.at(i);
//        outstanding += each;
//    }

//    // print details
//    cout << "name:" << _name << endl;
//    cout << "amount:" << outstanding << endl;
//}

////=======================================
//// 例子1：无局部变量——新写法
//void printBanner()
//{
//    cout << "*************************" << endl;
//    cout << "*******Customer Owes*****" << endl;
//    cout << "*************************" << endl;
//}

//void printOwing()
//{
//    vector<double> orders;
//    double outstanding = 0.0;

//    printBanner();

//    // calculate outstanding
//    for (size_t i = 0; i < orders.size(); i++)
//    {
//        double each = orders.at(i);
//        outstanding += each;
//    }

//    // print details
//    cout << "name:" << _name << endl;
//    cout << "amount:" << outstanding << endl;
//}

////=======================================
//// 例子2：有局部变量——新写法
//void printBanner()
//{
//    cout << "*************************" << endl;
//    cout << "*******Customer Owes*****" << endl;
//    cout << "*************************" << endl;
//}

//void printDetails(double outstanding)
//{
//    cout << "name:" << _name << endl;
//    cout << "amount:" << outstanding << endl;
//}

//void printOwing()
//{
//    vector<double> orders;
//    double outstanding = 0.0;

//    printBanner();

//    // calculate outstanding
//    for (size_t i = 0; i < orders.size(); i++)
//    {
//        double each = orders.at(i);
//        outstanding += each;
//    }

//    printDetails(outstanding);
//}

//=======================================
// 例子3：对局部变量再赋值——新写法
void printBanner()
{
    cout << "*************************" << endl;
    cout << "*******Customer Owes*****" << endl;
    cout << "*************************" << endl;
}

double getOutstanding()
{
    vector<double> orders;
    double result = 0.0;
    for (size_t i = 0; i < orders.size(); i++)
    {
        double each = orders.at(i);
        result += each;
    }
    return result;
}

void printDetails(double outstanding)
{
    cout << "name:" << _name << endl;
    cout << "amount:" << outstanding << endl;
}

void printOwing()
{
    printBanner();

    double outstanding = getOutstanding();

    printDetails(outstanding);
}

#endif // EXTRACTMETHOD_H
