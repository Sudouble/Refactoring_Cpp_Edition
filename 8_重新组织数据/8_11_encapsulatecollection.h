#ifndef 8_11_ENCAPSULATECOLLECTION_H
#define 8_11_ENCAPSULATECOLLECTION_H

// 适用情景：防止集合被修改，只返回其只读对象。（限制外部对于集合的访问权限）


#include <string>
#include <QSet>
#include <QMap>
using std::string;

//// 原版本1
//class Course{
//public:
//    Course(string name, bool isAdvanced){
//        _name = name;
//        _bAdvanced = isAdvanced;
//    }
//    bool isAdvanced() {
//        return _bAdvanced;
//    }
//private:
//    string _name;
//    bool _bAdvanced;
//};

//class Person
//{
//public:
//    Person() {}
//    QSet<Course>& GetCourse(){
//        return _course;
//    }
//    void SetCourse(QSet<Course> arg){
//        _course = arg;
//    }

//private:
//    QSet<Course> _course;
//};

//void Usage(){
//    Person kent;
//    QSet<Course> s;
//    s.insert(Course("Smalltalk Programming", false));
//    s.insert(Course("Appreciating Single Malts", true));
//    kent.SetCourse(s);
//    Q_ASSERT(2 == kent.GetCourse().size());

//    Course refact("Refactoring", true);
//    kent.GetCourse().insert(refact);
//    kent.GetCourse().insert(Course("Brutal Sarcasm", false));
//    Q_ASSERT(4 == kent.GetCourse().size());

//    kent.GetCourse().remove(refact);
//    Q_ASSERT(3 == kent.GetCourse().size());
//}


// 新版本1
class Course{
public:
    Course(string name, bool isAdvanced){
        _name = name;
        _bAdvanced = isAdvanced;
    }
    bool isAdvanced() {
        return _bAdvanced;
    }
private:
    string _name;
    bool _bAdvanced;
};

class Person
{
public:
    Person() {}
    const QSet<Course> GetCourse(){ //不让其他人变更内部变量
        return _course;
    }

    void InitializeCourses(QSet<Course> arg){
        Q_ASSERT(arg.isEmpty());
        foreach (Course ag, arg) {
            AddCourse(ag);
        }
    }
    // 统一对外接口，只开放这个
    void AddCourse(Course arg){
        _course.insert(arg);
    }
    void RemoveCourse(Course arg){
        _course.remove(arg);
    }
    int NumberOfAdvancedCourses(){
        int count = 0;
        foreach (Course course, GetCourse()) {
            if (course.isAdvanced())
                count++;
        }
        return count;
    }
    int NumberOfCourses(){
        return _course.size();
    }

private:
    QSet<Course> _course;
};

void Usage(){
    Person kent;
    QSet<Course> s;
    kent.AddCourse(Course("Smalltalk Programming", false));
    kent.AddCourse(Course("Appreciating Single Malts", true));
    //kent.InitializeCourses(s);
    Q_ASSERT(2 == kent.GetCourse().size());

    Course refact("Refactoring", true);
    kent.AddCourse(refact);
    kent.AddCourse(Course("Brutal Sarcasm", false));
    Q_ASSERT(4 == kent.GetCourse().size());

    kent.RemoveCourse(refact);
    Q_ASSERT(3 == kent.GetCourse().size());
}

#endif // 8_11_ENCAPSULATECOLLECTION_H
