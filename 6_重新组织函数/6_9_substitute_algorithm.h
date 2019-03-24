#ifndef 6_9_SUBSTITUTEALGORITHM_H
#define 6_9_SUBSTITUTEALGORITHM_H

// 适用情景：原有算法过大，单独一个对象去更新算法体系，甚至重写

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 原版本
string foundPerson(vector<string> people){
    for (int i = 0; i < people.size(); i++)
    {
        if (people[i] == "Don")
            return "Don";
        if (people[i] == "John")
            return "John";
        if (people[i] == "Kent")
            return "Kent";
    }

    return "";
}

// 新版本
string foundPerson(vector<string> people){

    for (int i = 0; i < people.size(); i++)
    {
        if (contains(people[i]))
            return people[i];
    }
    return "";
}

bool contains(string value){
    vector<string> strSrc;
    strSrc.push_back("Don");
    strSrc.push_back("John");
    strSrc.push_back("Kent");

    vector<string>::iterator it = find(strSrc.begin(), strSrc.end(), value);
    if(it != strSrc.end())
        return true;
    return false;
}

#endif // 6_9_SUBSTITUTEALGORITHM_H
