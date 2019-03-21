#ifndef 8_3_CHANGEVALUETOREFERENCE_H
#define 8_3_CHANGEVALUETOREFERENCE_H

// 适用情景：唯一对象，对此对象的修改会作用于所有引用此对象的事物

#include <string>
#include <QSet>
#include <QMap>
using std::string;

//// 原版本
//class Customer { // 值对象
//public:
//    Customer(string name){
//        _name = name;
//    }

//    const string GetName() {
//        return _name;
//    }
//private:
//    string _name;
//};

//class Order{
//public:
//    Order(string customerName){
//        _customer = Customer(customerName);
//    }
//    void SetCustomer(string customerName){
//        _customer = Customer(customerName);
//    }
//    string GetCustomer(){
//        return _customer.GetName();
//    }

//private:
//    Customer _customer;
//};

//static int numberOfOrdersFor(QSet<Order> orders, string customer){
//    int result = 0;
//    foreach (Order order, orders) {
//        if (order.GetCustomer() == customer)
//            result++;
//    }
//    return result;
//}


// 新版本
class Customer { // 值对象
public:
//    stage 1: 生成公用产品
//    static Customer create(string name){
//        return Customer(name);
//    }

//    stage 2: 返回唯一字段
    static Customer* GetNamed(string name){
        return _instance.value(name);
    }
    static void loadCustomers(){
        Customer("Lemon Car Hide").store();
        Customer("Associated Coffee Machines").store();
        Customer("Bilston Gasworks").store();
    }
private:
    string GetName() {
        return _name;
    }
private:
    Customer(string name){}
    Customer() {}

    void store(){
        _instance.insert(this->GetName(), this);
    }
private:
    string _name;
    static QMap<string ,Customer*> _instance;
};

class Order{
public:
    Order(string customerName){
        _customer = Customer::GetNamed(customerName); //
    }
    void SetCustomer(string customerName){
        _customer = Customer::GetNamed(customerName); //
    }
    string GetCustomer(){
        return _customer.GetName();
    }

private:
    Customer _customer;
};

static int numberOfOrdersFor(QSet<Order> orders, string customer){
    int result = 0;
    foreach (Order order, orders) {
        if (order.GetCustomer() == customer)
            result++;
    }
    return result;
}



#endif // 8_3_CHANGEVALUETOREFERENCE_H
