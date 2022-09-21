/*
 *Copyright (c) 2022 All rights reserved
 *@description: C++ output format
 *@author: Zhixing Lu
 *@date: 2022-09-16
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include <stdio.h>
#include <iostream>


#define FUNCTION_INFO(format, ...) printf("[Line: %3d] %s -> %s", \
	__LINE__ , __PRETTY_FUNCTION__, ##__VA_ARGS__);


namespace OUT {
    void array(int a, int b, const char c) {
        FUNCTION_INFO("%s","print array");
    }
}