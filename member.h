#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>

using namespace std;
class mealmanage
{
    string frstname, lastname, hostelid,pass;
    int totalmeal;
public :
   virtual void setinfo(string fn, string ln, string i,string p,int m) ;

   string getpass() {return pass;}
   string getfn() {return frstname;}
   string getln() {return lastname;}
   string getid() {return hostelid;}
   int gettotalmeal() {return totalmeal;}
};

class member {
    protected:
    string frstname, lastname, hostelid, password, occupation, admission_date,room_no,age, dt_of_brth;

    string  monthlyfes, paymnt,du;
    int meal,totalmeal;

public:

    member();
   virtual void setinfo(string fn, string ln, string i, string p, string o, string a, string dtb, string r, string ag);
    virtual void setname (string fn, string ln);
    virtual void setid(string i);
    virtual void setpass(string p);
   virtual  void setocc(string o);
    virtual void setdb(string dtb);
    virtual void setroom(string r);
    virtual void setfees(string mf);
    virtual void setpay(string p);
    virtual void setdue(string d) ;
    virtual string getfn();
    virtual string getln();
    virtual string getocc();
    virtual string getdb();
    virtual string getroom();
    virtual string getfess();
    virtual string getpay();
    virtual string getdue();
    virtual string getadd();
    virtual string getid();
    virtual string getpass();
    virtual string getage();
    void setmeal(int a) {meal = a;}
    int getmeal() {return meal;}
    int gettotalmeal() {return totalmeal;}
    virtual void show();
    virtual void showfradmin();

};

class signingmember : public member
{
public:
    signingmember () {}
   virtual void setinfo(string fname,string lname,string occ) ;

};


