#ifndef __CLASSFACTORY_
#define __CLASSFACTORY_

#include <iostream>
#include <string>
#include <map>

#define REGISTER(className) 											\
	className* objectCreator##className(){     							\
        return new className;                                         	\
    }                                                                  	\
    RegisterAction g_creatorRegister##className(                        \
		#className,(PTRCreateObject)objectCreator##className)

//定义函数指针
typedef void* (*create_fun)();

class ClassFactory{
public:
    ~ClassFactory() {}; 

    //根据类注册时的名字, 创建类实例, 并返回
    void* getClassByName(std::string &name);

    //注册类名称与指针函数到映射关系
    void registClass(std::string &name, create_fun fun);

    //单例模式
    static ClassFactory& getInstance();

private:
    ClassFactory() {};  //私有
    std::map<std::string, create_fun> my_map;
}; 

#endif