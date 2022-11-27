---
sort: 2
---

# C++ 使用技巧

## 反射

代码位置 : https://github.com/luzhixing12345/C-libs/tree/main/src/reflect

### [使用案例](https://github.com/luzhixing12345/C-libs/blob/main/src/reflect/main.cpp)

```bash
cd src/reflect
make
./main
```

### 使用方法

其中三个宏的参数含义分别为

- #define REGISTER(__name,__callbackFunc): 用于注册

  `__name` : 一个字符串(std::string),反射函数的名字

  `__callbackFunc` : 反射函数

- #define REFLECT(__name) : 用于获取反射函数的指针

  `__name` : 一个字符串(std::string),反射函数的名字

- #define REFLECT_TYPE(__return_type,__func_p,__args)

  `__return_type` : 反射函数返回值类型

  `__func_p` : 反射函数指针 (void *)

  `__args` : 反射函数参数


```cpp
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
    std::cout << "a = " << a << " | b = " << b << std::endl;
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
    Test *test = REFLECT_TYPE(Test*,class_p,(void))(); // 类的反射
    test->print(); // 可以搭配多态的虚函数使用
    delete test;

    //获取函数
    void *func_p = REFLECT(function_name);
    int return_value = REFLECT_TYPE(int,func_p,(void))();
    std::cout << "return value = " << return_value << std::endl << std::endl;

    //函数传参
    void *func_args_p = REFLECT(function_with_argument_name);
    return_value = REFLECT_TYPE(int, func_args_p, (int,int))(10,20);
    std::cout << "return value = " << return_value << std::endl;
    return 0;
}
```

运行结果

```bash
call Test Constructor fun
call Test print fun
call Test Destructor fun

called function
return value = 10

called function_args
a = 10 | b = 20
return value = 30
```
