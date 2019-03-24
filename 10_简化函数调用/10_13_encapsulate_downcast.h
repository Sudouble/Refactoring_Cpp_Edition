#ifndef 10_13_ENCAPSULATE_DOWNCAST_H
#define 10_13_ENCAPSULATE_DOWNCAST_H

// 适用情景：不让用户承担向下转型的任务


class Object{
};
class Reading : public Object{
};
//// 原始版本
//Object *read = new Reading();
//Object* lastReading(){
//    return read;
//}


// 新版本
Object *read = new Reading();
Reading lastReading(){
    return (Reading)read;
}


#endif // 10_13_ENCAPSULATE_DOWNCAST_H
