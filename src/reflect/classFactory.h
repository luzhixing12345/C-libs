#ifndef __CLASSFACTORY_
#define __CLASSFACTORY_

#include <iostream>
#include <string>
#include <map>



//定义函数指针
// typedef void* (*create_fun)();

class ClassFactory{
public:
    ~ClassFactory() {}; 

    //根据类注册时的名字, 创建类实例, 并返回
    void* getClassByName(std::string &name);

    //注册类名称与指针函数到映射关系
    void registClass(std::string &name, void* fun);

    //单例模式
    static ClassFactory& getInstance();

private:
    ClassFactory() {};  //私有
    std::map<std::string, void*> my_map;
}; 

#define REGISTER(__className,__callbackFunc) ClassFactory::getInstance().registClass(__className,__callbackFunc)
#define REFLECT(__className) ClassFactory::getInstance().getClassByName(__className)
#define REFLECT_TYPE(__type,__class_p) (*(__type (*)(void))__class_p)

#endif