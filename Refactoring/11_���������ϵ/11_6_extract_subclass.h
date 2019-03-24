#ifndef 11_6_EXTRACT_SUBCLASS_H
#define 11_6_EXTRACT_SUBCLASS_H


// 适用情景：以继承的方式提取子类


//// 原始版本
//class Employee{
//public:
//    int getRate(){
//        return 1;
//    }
//};

//class JobItem{
//public:
//    JobItem(int unitPrice, int quantity, bool isLabor, Employee employee){
//        _unitPrice = unitPrice;
//        _quantity = quantity;
//        _isLabor = isLabor;
//        _employee = employee;
//    }

//    int getTotalPrice(){
//        return getUnitPrice() * _quantity;
//    }
//    int getUnitPrice(){
//        return (_isLabor) ? _employee.getRate() : _unitPrice;
//    }
//    int getQuantity(){
//        return _quantity;
//    }
//    Employee getEmployee(){
//        return _employee;
//    }

//private:
//    int _unitPrice;
//    int _quantity;
//    bool _isLabor;
//    Employee _employee;
//};
//void Usage(){
//    Employee kent;
//    JobItem *j1 = new JobItem(0, 5, true, kent);
//}



// 新版本
class Employee{
public:
    int getRate(){
        return 1;
    }
};

class JobItem{
//protected:
//    JobItem(int unitPrice, int quantity, bool isLabor, Employee employee){
//        _unitPrice = unitPrice;
//        _quantity = quantity;
//        _isLabor = isLabor;
//        _employee = employee;
//    }
public:
    JobItem(int unitPrice, int quantity){
        _unitPrice = unitPrice;
        _quantity = quantity;
    }

    int getTotalPrice(){
        return getUnitPrice() * _quantity;
    }
    int getUnitPrice(){
//        return (_isLabor) ? _employee.getRate() : _unitPrice;
        return _unitPrice;
    }
    int getQuantity(){
        return _quantity;
    }
    bool isLabor(){
        return false;
    }

private:
    int _unitPrice;
    int _quantity;
//    bool _isLabor;
};

class LaborItem : public JobItem
{
public:
//    LaborItem(int unitPrice, int quantity, bool isLabor, Employee employee) :
//        JobItem(unitPrice, quantity, isLabor, employee)
//    {
//    }
    LaborItem(int quantity, Employee employee) :
        JobItem(0, quantity, employee)
    {
    }
    bool isLabor(){
        return true;
    }
    int getUnitPrice(){
        return _employee.getRate();
    }
    Employee getEmployee(){
        return _employee;
    }
private:
    Employee _employee;
};

void Usage(){
    Employee kent;
//    JobItem *j1 = new JobItem(0, 5, true, kent);
    JobItem *j2 = new LaborItem(0, 5, true, kent);
}

#endif // 11_6_EXTRACT_SUBCLASS_H
