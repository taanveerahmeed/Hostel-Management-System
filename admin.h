#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include "member.h"

using namespace std;

class admin : public member
{

public:
    admin();
    virtual void setinfo(string fn, string ln,string i, string p);
   virtual void show();

};
