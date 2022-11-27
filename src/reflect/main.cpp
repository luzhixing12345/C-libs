
#include "classFactory.h"

class Test{
public:
    Test(){ std::cout << "call Test Constructor fun" << std::endl; }
    ~Test(){ std::cout << "call Test Destructor fun" << std::endl; }
    void print(){ std::cout << "call Test print fun\n" << std::endl; }
};

void* create_Test(){
    Test *t = new Test;
    return (t == NULL)? NULL:t;
}

int function() {
    std::cout << "called function" << std::endl;
    return 10;
}

int function_args(int a, int b) {
    std::cout << "called function_args" << std::endl;
    std::cout << "a = " << a << "| b = " << b << std::endl;
    int c = a+b;
    return c;
}

int main(){
    //注册
    std::string class_name = "Test";
    std::string function_name = "function";
    std::string function_with_argument_name = "function_args";

    REGISTER(class_name, (void*)create_Test); // 注册类
    REGISTER(function_name,(void*)function);  // 注册函数
    REGISTER(function_with_argument_name,(void*)function_args);  // 注册函数
    //获取类对象
    void *class_p = REFLECT(class_name);
    Test *test = REFLECT_TYPE(Test*,class_p)(); // 类的反射
    test->print(); // 可以搭配多态的虚函数使用
    delete test;

    //获取函数
    void *func_p = REFLECT(function_name);
    int return_value = REFLECT_TYPE(int,func_p)();
    std::cout << "return value = " << return_value << std::endl << std::endl;

    void *func_args_p = REFLECT(function_with_argument_name);
    return_value = REFLECT_TYPE(int, func_args_p)();
    std::cout << "return value = " << return_value << std::endl;
    return 0;
}