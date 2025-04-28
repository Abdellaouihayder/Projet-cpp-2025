#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream> 
#include <sstream>
using namespace std;
class Service {
protected:
    string description;
public:
    Service(string desc){description=desc;}
    virtual ~Service() {}
};
#endif

