
#include "classFactory.h"

void *ClassFactory::getClassByName(std::string &name) {
    std::map<std::string, create_fun>::iterator it = my_map.find(name);
    if (it == my_map.end()) { return NULL; }

    create_fun fun = it->second;
    if (!fun) { return NULL; }

    return fun();
}

void ClassFactory::registClass(std::string &name, create_fun fun) {
    my_map[name] = fun;
}

ClassFactory& ClassFactory::getInstance() {
    static ClassFactory fac;
    return fac;
}