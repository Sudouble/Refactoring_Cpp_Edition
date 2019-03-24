#ifndef 10_7_PRESERVE_WHOLE_OBJECT_H
#define 10_7_PRESERVE_WHOLE_OBJECT_H

// 适用情景：传递一个完整参数——参数传递的完整性。多权衡利弊，有时候把整个函数移到对象里更合适


//// 原始版本
//class TempRange{
//public:
//    int getLow(){
//        return low;
//    }
//    int getHigh(){
//        return high;
//    }
//private:
//    int low;
//    int high;
//};
//class HeatingPlan
//{
//public:
//    bool withinRange(int low, int high){
//        return (low >= range.getLow() && high < range.getHigh());
//    }
//private:
//    TempRange range;
//};
//class Room{
//public:
//    TempRange getTemprange(){
//        return range;
//    }
//    bool withinPlan(HeatingPlan plan){
//        int low = getTemprange().getLow();
//        int high = getTemprange().getHigh();
//        return plan.withinRange(low, high);
//    }
//private:
//    TempRange range;
//};


// 新版本
class TempRange{
public:
    int getLow(){
        return low;
    }
    int getHigh(){
        return high;
    }
private:
    int low;
    int high;
};
class HeatingPlan
{
public:
//    bool withinRange(int low, int high){
//        return (low >= range.getLow() && high < range.getHigh());
//    }
    bool withinRange(TempRange rangeRoom){
        return (rangeRoom.getLow() >= range.getLow() && rangeRoom.getHigh() < range.getHigh());
    }
private:
    TempRange range;
};
class Room{
public:
    TempRange getTemprange(){
        return range;
    }
    bool withinPlan(HeatingPlan plan){
//        int low = getTemprange().getLow();
//        int high = getTemprange().getHigh();
        return plan.withinRange(getTemprange());
    }
private:
    TempRange range;
};

#endif // 10_7_PRESERVE_WHOLE_OBJECT_H
