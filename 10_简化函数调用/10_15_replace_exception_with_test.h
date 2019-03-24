#ifndef 10_15_REPLACE_EXCEPTION_WITH_TEST_H
#define 10_15_REPLACE_EXCEPTION_WITH_TEST_H

// 适用情景：异常处理主要用于异常的、罕见的行为，不适配的话，考虑用测试来避免这种情况

#include <vector>
#include <QString>
using namespace std;
//// 原始版本
//class Resource{};
//class ResourcePool{
//    Resource* getResource(){
//        try{
//            Resource* result = _avialable.pop_back();
//            _allocated.push_back(result);
//            return result;
//        } catch (){
//            Resource* result = new Resource();
//            _allocated.push_back(result);
//            return result;
//        }
//        return
//    }
//private:
//    vector<Resource*> _avialable;
//    vector<Resource*> _allocated;
//};


// 新版本
class Assert{
    static void shouldNeverReachHere(QString str){
        throw QString("Assert failed:" + str);
    }
};

class Resource{};
class ResourcePool{
    Resource* getResource(){
        // new added
        if (_avialable.empty()){
            Resource* result = new Resource();
            _allocated.push_back(result);
            return result;
        } // end
//        try{
        Resource* result = _avialable.pop_back();
        _allocated.push_back(result);
        return result;
//        } catch (){
//            // new added
//            Assert::shouldNeverReachHere("available was empty on pop");
//            // end
//            Resource* result = new Resource();
//            _allocated.push_back(result);
//            return result;
//        }
        return
    }
private:
    vector<Resource*> _avialable;
    vector<Resource*> _allocated;
};

#endif // 10_15_REPLACE_EXCEPTION_WITH_TEST_H
