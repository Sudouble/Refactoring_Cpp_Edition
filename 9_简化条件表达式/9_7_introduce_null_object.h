#ifndef 9_7_INTRODUCE_NULL_OBJECT_H
#define 9_7_INTRODUCE_NULL_OBJECT_H

// 适用情景：基于多态的放回Null版本


#include <string>
#include <vector>
using std::string;
using std::vector;
//// 原版本
//class BillingPlan{
//    BillingPlan* basic(){
//        return this;
//    }
//};
//class PaymentHistory{
//    int getWeeksDelinquentInLastYear(){
//        return 1;
//    }
//};
//class Customer{
//public:
//    string getName(){
//        return "123";
//    }
//    BillingPlan* getPlan(){
//        return _billing;
//    }
//    PaymentHistory *getHistory(){
//        return _paymentHistory;
//    }

//private:
//    BillingPlan *_billing;
//    PaymentHistory *_paymentHistory;
//};

//class Site{
//    Customer* getCustomer(){
//        return _customer;
//    }
//    Customer *_customer;
//};

//void Usage(){
//    Site site;
//    Customer *customer = site.getCustomer();
//    BillingPlan *plan;
//    if (customer == nullptr)
//        plan = BillingPlan.basic();
//    else
//        plan = customer->getPlan();
//    // ...
//    string customerName;
//    if (customer == nullptr)
//        customer = "occupant";
//    else
//        customerName = customer->getName();
//    //...
//    int weeksDelinquent;
//    if (customer == nullptr)
//        weeksDelinquent = 0;
//    else
//        weeksDelinquent = customer->getHistory()->getWeeksDelinquentInLastYear();
//}

// 新版本
class BillingPlan{
    BillingPlan* basic(){
        return this;
    }
};
class PaymentHistory{
    int getWeeksDelinquentInLastYear(){
        return 1;
    }
};

class NullCustomer;
class Customer{
public:
    string getName(){
        return "123";
    }
    BillingPlan* getPlan(){
        return _billing;
    }
    PaymentHistory *getHistory(){
        return _paymentHistory;
    }
    //1 new added
    bool isNull(){
        return false;
    }
    static Customer* newNull(){
        return new NullCustomer();
    }
private:
    BillingPlan *_billing;
    PaymentHistory *_paymentHistory;
};

//1 new added
class NullCustomer : public Customer{
public:
    bool isNull(){
        return true;
    }
    // 2 added
    string getName(){
        return "occupant";
    }
    // 3 added
    BillingPlan* getPlan(){
        return new BillingPlan();
    }
    PaymentHistory *getHistory(){
        return new PaymentHistory();
    }
};

class Site{
    Customer* getCustomer(){
        // 1 changed
//        return _customer;
        return _customer->isNull() ? Customer::newNull() : _customer;

    }
    Customer *_customer;
};

void Usage(){
    Site site;
    Customer *customer = site.getCustomer();
    BillingPlan *plan;
    // 1 changed
    //if (customer == nullptr)
    if (customer->isNull())
        plan = BillingPlan.basic();
    else
        plan = customer->getPlan();
    // ...
    string customerName;
    // 2 changed
//    // 1 changed
//    //if (customer == nullptr)
//    if (customer->isNull())
//        customer = "occupant";
//    else
    customerName = customer->getName();
    //...
    int weeksDelinquent;
    // 1 changed
    //if (customer == nullptr)
    if (customer->isNull())
        weeksDelinquent = 0;
    else
        weeksDelinquent = customer->getHistory()->getWeeksDelinquentInLastYear();
}

#endif // 9_7_INTRODUCE_NULL_OBJECT_H
