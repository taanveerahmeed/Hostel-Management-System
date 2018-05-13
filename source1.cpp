#include "member.h"

    member :: member()
    {

        meal = 0;
        totalmeal =0;
    }
    void member :: setinfo(string fn, string ln, string i, string p, string o, string a, string dtb, string r, string ag)

    {
        frstname =fn;
        lastname =ln;
        hostelid = i;
        password = p;
        occupation =o;
        admission_date = a;
        dt_of_brth = dtb;
        room_no = r;
        age = ag;
    }
    void member :: setname (string fn, string ln)

    {
        frstname =fn;
        lastname =ln;
    }
    void member :: setid(string i)
    {
        hostelid = i;
    }
    void member :: setpass(string p)
    {
        password = p;
    }
    void member :: setocc(string o)
    {
         occupation =o;
    }
    void member :: setdue(string d) {du = d;}
    void member :: setdb(string dtb)
    {
         dt_of_brth = dtb;
    }
    void member :: setroom(string r)
    {
        room_no = r;
    }
     void member :: setpay(string p)
     {
         paymnt =p;
     }
    string member :: getid(){return hostelid;}
    void member :: setfees(string mf) {monthlyfes = mf;}
    string member :: getpass(){return password;}
    void member :: show()
    {
        system("mode 60");
        cout << "============================================================\n";
        cout << "\n          Member Name : " <<frstname << " " << lastname << endl;
        cout << "\n          Member ID : " << hostelid << endl;
        cout << "\n============================================================";
        cout << "                     OTHER INFORMATION                     \n";
        cout << "============================================================" << endl;
        cout << "Member room number : " << room_no << endl;
        cout << "\nMember Occupation : " << occupation << endl;
        cout << "\nDate of birth : "<<dt_of_brth << endl;
        cout << "\nAge : " << age << endl;
        cout << "\nAdmission Date : " << admission_date << endl;
        cout << "\nAmount to be paid : " << monthlyfes << endl;
        cout << "\nAmount paid : " << paymnt << endl;
        cout << "\nDue amount : " << du << endl;
        cout << "============================================================";
        cout << "============================================================";
    }
    string member :: getfn(){return frstname;}
    string member :: getln(){return lastname;}
    string member :: getocc(){return occupation;}
    string member :: getdb(){return dt_of_brth;}
    string member :: getroom(){return room_no;}
    string member :: getfess(){return monthlyfes;}
    string member :: getpay() {return paymnt;}
    string member :: getdue() {return du;}
    string member :: getadd() {return admission_date;}
    string member :: getage() {return age;}

    void signingmember :: setinfo(string fname,string lname,string occ)
    {
        frstname = fname;
        lastname = lname;
        occupation = occ;
    }
    void mealmanage :: setinfo (string fn, string ln, string i,string p,int m)
    {
        frstname = fn;
        lastname = ln;
        hostelid = i;
        totalmeal = m;
        pass = p;

    }
    void member :: showfradmin()
    {
        cout << "\n\n-----------------------------------------\n\n";
        cout << "Name : " << frstname << " " << lastname << endl;
        cout << "ID : " << hostelid << endl;
        cout << "Occupation : " << occupation << endl;
        cout << "Monthly payment : " << monthlyfes << endl;
        cout << "Due fees : " << du << endl;
    }
