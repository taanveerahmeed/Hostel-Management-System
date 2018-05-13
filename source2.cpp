#include "admin.h"

    admin :: admin(){}
    void admin ::  setinfo(string fn, string ln,string i, string p)
    {
        frstname = fn;
        lastname = ln;
        hostelid = i;
        password = p;
    }

    void admin :: show()
    {
        cout << "--------------------------------------------------";
        cout << "!                 ADMIN DETAILS                  !";
        cout << "--------------------------------------------------";
        cout << "\n             Admin Name : " << frstname << " " << lastname << endl;
        cout << "\n             ID : " << hostelid << endl;
        cout << "\n--------------------------------------------------";
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        cout << "--------------------------------------------------";
    }

