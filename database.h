#include "admin.h"
#include <vector>

class database
{
    vector <member> m;
    vector <admin> a;
    vector <admin> nv;
    vector <member> mnv;
    vector <signingmember> sv;
    vector <mealmanage> mg;
    int ch;
public :

    database ();
    void writingmember();
    void readingmember();
    void readingadmin();
    void writingadmin();
    void setcheck(int i) {ch = i;}
    int getnotifi() {return ch;}
    void Adminprofile();
    void Studentprofile();
    void signup();
    void Addmember ();
    void Addadmin ();
    void showmember ();
    void showadmin ();
    string password();
    int srchadmin(string gs,string gi);
    int srchmember2(string gs,string gi);
    int srchmember(string gs,string gi);
    int srchmember1(string gs,string gi);
    void deleteadmin();
    void deletemember();
    void editadmin();
    void editmember();
    void givingmeal();
    void login();
    void deletEallmember();


    //void handler();


};
