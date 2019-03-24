#ifndef CHANGESINGLE2TWO_H
#define CHANGESINGLE2TWO_H

#include <QSet>
#include <algorithm>
using namespace std;

// 8.7 单向关联改为双向关联

//// 原始版本
//class Order;
//class Customer
//{
//public:
//    Customer() {}
//private:
//    QSet<Order*> m_order; // 单向，无法访问
//};

//class Order{
//public:
//    Customer GetCustomer()
//    {
//        return m_customer;
//    }

//    void SetCustomer(Customer &arg)
//    {
//        m_customer = arg;
//    }
//private:
//    Customer m_customer;
//};


// 新版本1
// 通过Order中的m_customer即可查询到所有的Order
// 一对多：一个顾客多个订单，访问控制权在Order
class Order;
class Customer
{
public:
    Customer() {}
    QSet<Order*> friendOrders(){
        return m_order;
    }
private:
    QSet<Order*> m_order; // 无法访问
};

class Order{
public:
    Customer GetCustomer()
    {
        return m_customer;
    }

    void SetCustomer(Customer &arg)
    {
        // m_customer = arg; //原先的设置
        m_customer.friendOrders().remove(this);

        m_customer = arg;
        m_customer.friendOrders().insert(this);
    }
private:
    Customer m_customer;
};


//// 新版本2——类互相应用，编译失败。Failed
//// 通过Order中的m_customer即可查询到所有的Order
//// 多对多：Customer也能修改Order，控制权在Order
//class Order;
//class Customer
//{
//public:
//    Customer() {}
//    QSet<Order*> friendOrders(){
//        return m_order;
//    }

//    void AddOrder(Order *arg)
//    {
//        arg->AddCustomer(this);
//    }

//    void RemoveOrder(Order *arg)
//    {
//        arg->RemoveCustomer(this);
//    }
//private:
//    QSet<Order*> m_order; // 无法访问
//};

//class Order{
//public:
//    void AddCustomer(Customer &arg)
//    {
//        arg.friendOrders().;
//        m_customer.insert(arg);
//    }

//    void RemoveCustomer(Customer &arg)
//    {
//        arg.friendOrders().erase(this);
//        m_customer.erase(arg);
//    }
//private:
//    QSet<Customer> m_customer;
//};

#endif // CHANGESINGLE2TWO_H
