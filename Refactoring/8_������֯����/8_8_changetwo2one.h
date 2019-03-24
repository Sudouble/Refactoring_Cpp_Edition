#ifndef CHANGETWO2ONE_8_8_H
#define CHANGETWO2ONE_8_8_H

#include <QSet>

//// 原始版本
//// 通过Order中的m_customer即可查询到所有的Order
//// 一对多：一个顾客多个订单，访问控制权在Order
//class Order;
//class Customer
//{
//public:
//    Customer() {}
//    QSet<Order*> friendOrders(){
//        return m_order;
//    }
//private:
//    QSet<Order*> m_order; // 无法访问
//};

//class Order{
//public:
//    Customer GetCustomer()
//    {
//        return m_customer;
//    }

//    void SetCustomer(Customer &arg)
//    {
//        // m_customer = arg; //原先的设置
//        m_customer.friendOrders().remove(this);

//        m_customer = arg;
//        m_customer.friendOrders().insert(this);
//    }
//private:
//    Customer m_customer;
//};

// 新版本
// Customer--->Order
class Order;
class Customer
{
public:
    Customer() {}
    QSet<Order*> friendOrders(){
        return m_order;
    }
    double GetDiscount(){
        return 0.2;
    }
private:
    QSet<Order*> m_order; // 无法访问
};

class Order{
public:

    double GetDiscountedPrice(Customer &arg){
        return GetGrossPrice()*(1-arg.GetDiscount());
    }

    double GetGrossPrice(){
        return 100.0;
    }

    void SetCustomer(Customer &arg)
    {
        // m_customer = arg; //原先的设置
        arg.friendOrders().remove(this);
    }
};

#endif // CHANGETWO2ONE_8_8_H
