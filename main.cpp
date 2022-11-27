#include "src/reflect/classFactory.h"
#include "src/reflect/test.h"

void* create_Test(){
    Test *t = new Test;
    return (t == NULL)? NULL:t;
}

int another_funtion() {
    std::cout << "called another function" << std::endl;
    return 1;
}

int main(){
    //注册
    std::string class_name = "Test";
    std::string function_name = "another_function";

    void *p = (void*)another_funtion;

    REGISTER(class_name, create_Test);
    // REGISTER(function_name,);

    //获取类对象
    Test *t = (Test*) REFLECT(class_name);
    if (!t){
        std::cout << "get instance Test err;" << std::endl;
        return 1;
    }
    t->print();
    // REFLECT(function_name);
    delete t;
    return 0;
}