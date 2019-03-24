#ifndef 8_2_REPLACEDATAVALUEWITHOBJECT_H
#define 8_2_REPLACEDATAVALUEWITHOBJECT_H

// 适用情景：原始的简单数据对象不适用，需要封装了


#include <string>
#include <QSet>
using std::string;

//// 原版本
//class Order{
//public:
//    Order(string arg){
//        m_customer = arg;
//    }

//    string GetCustomer()
//    {
//        return m_customer;
//    }

//    void SetCustomer(string &arg)
//    {
//        m_customer = arg;
//    }
//private:
//    string m_customer;
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
class Customer{
public:
    Customer(string name){
        _name = name;
    }

    string getName(){
        return _name;
    }

private:
    string _name;
};

class Order{
public:
    Order(string arg){
        m_customer = Customer(arg);
    }

    string GetCustomerName()
    {
        return m_customer.getName();
    }

    void SetCustomer(string &arg)
    {
        m_customer = Customer(arg);
    }
private:
    Customer m_customer;
};

static int numberOfOrdersFor(QSet<Order> orders, Customer customer){
    int result = 0;
    foreach (Order order, orders) {
        if (order.GetCustomerName() == customer.getName())
            result++;
    }
    return result;
}

#endif // 8_2_REPLACEDATAVALUEWITHOBJECT_H
