#include "test.h"
#include "classFactory.h"

int main(){
    //注册
    std::string class_name = "Test";

    ClassFactory::getInstance().registClass(class_name, create_Test);

    //获取类对象
    Test *t = (Test*)ClassFactory::getInstance().getClassByName(class_name);
    if (!t){
        std::cout << "get instnce Test err;" << std::endl;
        return 1;
    }   
    
    t->print();
    delete t;
    return 0;
}