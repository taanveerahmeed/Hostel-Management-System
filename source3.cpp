#include "database.h"

database :: database () {}



void database :: Adminprofile()
{
    ifstream gtntfi ("notification1.bin");
    int i;
    if (gtntfi.is_open())
    {

        gtntfi >> i;
    }

    if (i== 1)
    {
        cout << "\a1 notificaton\n";
        cout << " \nPress any key to view\n";
        getch();
        string iffn, ifln, ifocc;

        ifstream get_sign ("signup.bin");
        if (get_sign.is_open())
        {
            get_sign >> iffn >> ifln >> ifocc;

        }

        cout << iffn << " " << ifln << " wants to join in your hostel."<< endl;
        cout << "The person is a " << ifocc<< endl;

        cout << "To Add him press A or to ignore him press I\n";
        char o;
        cin >> o;
        if (o == 'a' || o== 'A')
        {
            Addmember();
            ofstream stdntnif ("notification2.bin", ios :: trunc | ios::binary);
            if (stdntnif.is_open())
            {
                stdntnif << 1 << endl;
                stdntnif.close();
            }

            ofstream ntif ("notification1.bin", ios:: trunc);
        if (ntif.is_open())
        {
            ntif << 0 << endl;
            ntif.close();
        }

        }
        if (o == 'i' || o == 'I')
        {
            ofstream ntif ("notification1.bin", ios:: trunc);
        if (ntif.is_open())
        {
            ntif << 0 << endl;
            ntif.close();

        }
        ofstream stdntnif ("notification2.bin", ios :: trunc | ios::binary);
            if (stdntnif.is_open())
            {
                stdntnif << 0 << endl;
                stdntnif.close();
            }
       ofstream get_sign ("signup.bin", ios :: trunc | ios::binary);

        }
    }
    //else cout << "No notification\n";
}

void database :: Studentprofile()
{
    ifstream gtntfi2 ("notification2.bin");
    int i;
    if (gtntfi2.is_open())
    {

        gtntfi2 >> i;
    }

    if (i== 1)
    {
        cout << " \a1 notificaton\n";
        cout << " \nPress any key to view\n";
        getch();
        string iffn, ifln, ifocc;

        ifstream get_sign ("signup.bin");
        if (get_sign.is_open())
        {
            get_sign >> iffn >> ifln >> ifocc;
        }
        cout << iffn << " " << ifln << "Has joined in the hostel"<< endl;
        cout << "He is a " << ifocc << endl;
        cout << "Press any key to proceed\n";
        getch();
        ofstream dltntfi ("signup.bin", ios :: trunc | ios::binary);
        ofstream dltntfi2 ("notification2.bin", ios :: trunc | ios::binary);
    }

}

void database :: deleteadmin()
{
    ifstream oadmin ("Admin.bin");
        if (!oadmin.is_open())
        {
            cout <<"Error\n";
            exit(1);
        }
        //while (!oadmin.eof())
        else {


            while(!oadmin.eof())  //  for (int i = 0; i !=oadmin.eof();i++)
        {

            string iffn,ifln,ifid,ifpass;
            oadmin >> iffn >> ifln >> ifid >> ifpass;

            admin temp;
            temp.setinfo(iffn,ifln,ifid,ifpass);

            nv.push_back(temp);


        }
        cout<< "\nEnter Admin's ID : ";
        string gid;
        cin >> gid;
        cout << "Enter admin's Password : ";

        string gpas = password();
        int m = srchadmin(gid,gpas);
        cout << m;

        if (m>-1) {

                nv.erase(nv.begin()+m);
                cout << "\nAcoount Has been deactivated \n\n";
                ofstream iadmin ("Admin.bin",ios::trunc | ios :: binary);
        if (iadmin.is_open())
        {
            for(int i = 0; i < nv.size(); i ++)
           {

            iadmin <<nv[i].getfn()<<" "<<nv[i].getln()<<"\t"<<nv[i].getid() << "\t" << nv[i].getpass()<< endl;
           }
            iadmin.close();
        }
        else cout << "Error" << endl;

        }
        else cout << "\n\nWrong Password or Invalid ID" << endl;

        }

}

void database :: signup()
{
    cout << "Press Y to start or N to cancel\n\n";
    char c;
     c = getch();
    if (c=='y' || c=='Y')
    {


    cout << "Enter your First name : ";
        string gfn;
        cin >> gfn;
        cout << "Enter your Last name : ";
        string gln;
        cin >> gln;
        cout << "\nEnter Member's Occupation : ";
        string go;
        cin >> go;
        signingmember ob;
        ob.setinfo(gfn,gln,go);
        sv.push_back(ob);
        ofstream sign_up ("signup.bin", ios :: trunc | ios::binary);
        if (sign_up.is_open())
        {
            sign_up << ob.getfn() << " " << ob.getln() << " " << ob.getocc() << endl;
            sv.empty();
            sign_up.close();
        }


        ofstream ntif ("notification1.bin", ios:: trunc);
        if (ntif.is_open())
        {
            ntif << 1 << endl;
            ntif.close();
        }

        setcheck(1);
        //system ("mode 135");
    }
    else setcheck(0);
}

string database :: password()
{
    char pass[32];
        char ap;
        int i;
        for(i =0;;)
        {
            ap = getch();
            if ((ap>='a'&&ap<='z')||(ap>='A'&&ap<='Z')||(ap>='0'&&ap<='9'))
            {
                pass[i]=ap+100;
                i++;
                cout<<"*";
            }
            if (ap=='\b'&& i>=1){cout << "\b \b";
            i--;}
            if (ap=='\r'){pass[i]='\0';
            break;}
        }
        string gpass;
        gpass = pass;
        return gpass;
}
    void database :: Addmember () {
        system ("mode 70");
         cout << "Enter Member's First name : ";
        string gfn;
        cin >> gfn;
        cout << "Enter Member's Last name : ";
        string gln;
        cin >> gln;
        cout << "Enter Member's RESISTERED ID : ";
        string gid;
        cin >> gid;
        cout << "Enter Student's Login password : ";

        string gpas = password();
        cout << "\nEnter Member's Occupation : ";
        string go;
        cin >> go;
        //time_t systime;

        //time(&systime);
        //cout << "current time is"<< ctime (&systime)<<endl;


        string gad;
        //gad=ctime (&systime);
//        getline(ctime (&systime),gad);
        //gets(gad) ;
        //cout << gad;
        cout << "Enter Member's Admission Date : " ;
        cin >> gad;
        cout << "Enter Member's Birthday : ";
        string gbr;
        cin >> gbr;
        cout << "Enter Member's Given Room NO : ";
        string gr;
        cin >> gr;
        cout << "Enter Member's Age : ";
        string ga;
        cin >> ga;
        cout << "Enter Monthly fees's : ";
        string gmf;
        cin >> gmf;
        cout << "Enter Paid amount : ";
        string gp;
        cin >> gp;
        cout << "Enter due fees : ";
        string gd;
        cin>> gd;

        member q;
       q.setinfo(gfn,gln,gid,gpas,go,gad,gbr,gr,ga);
        q.setfees(gmf);
        q.setpay(gp);
        q.setdue(gd);
        m.push_back(q);

        ofstream imember ("Member.bin", ios::app | ios :: binary);
        if (imember.is_open())
        {
            imember << q.getfn() << " " << q.getln() << "\t" <<q.getid() << "\t" << q.getpass() << "\t" << q.getocc() << "\t" << q.getadd()<<"\t"<<q.getdb()<< "\t"<<q.getroom()<<"\t"<<q.getage()<<"\t" <<q.getfess() << "\t" <<q.getpay() << "\t" <<q.getdue()<< endl;
            imember.close();
        }
        else cout << "Error\n";

        signingmember ob;
        ob.setinfo(gfn,gln,go);
        sv.push_back(ob);
        ofstream sign_up ("signup.bin", ios :: trunc | ios::binary);
        if (sign_up.is_open())
        {
            sign_up << ob.getfn() << " " << ob.getln() << " " << ob.getocc() << endl;
            sv.empty();
            sign_up.close();
        }

                    ofstream stdntnif ("notification2.bin", ios :: trunc | ios::binary);
            if (stdntnif.is_open())
            {
                stdntnif << 1 << endl;
                stdntnif.close();
            }

            ofstream ntif ("notification1.bin", ios:: trunc);
        if (ntif.is_open())
        {
            ntif << 0 << endl;
            ntif.close();
        }



    }

    void database :: deletemember()

    {
        cout << "Enter the member id : ";
        string gi;
        cin >>gi;
        cout << "Enter Password : ";

        string gpas = password();
        cout << endl;
        ifstream omember("Member.bin");
        if (!omember.is_open())
        {
            cout << "Error\n";
            exit(1);
        }
        while (!omember.eof())
        {
            string iffn,ifln,ifid,ifpass,ifocc,ifadd,ifdtb,ifrn,ifa;
            string iff,ifpy,ifpd;
            omember >> iffn >> ifln >>ifid>>ifpass>> ifocc >> ifadd >> ifdtb>> ifrn >> ifa >> iff >> ifpy >> ifpd;
            member temp;
            temp.setinfo(iffn,ifln,ifid,ifpass,ifocc,ifadd,ifdtb,ifrn,ifa);
            temp.setfees(iff);
            temp.setpay(ifpy);
            mnv.push_back(temp);
    }
    int m = srchmember(gi,gpas);
    if (m > -1) {
            mnv.erase(mnv.begin()+m);
            cout << "\n\nYour account has been deleted\n\n";

            ofstream imember ("Member.bin", ios::trunc | ios :: binary);
        if (imember.is_open())
        {
            for (int i = 0; i < mnv.size()-1 ; i++)
           {

            imember << mnv[i].getfn() << " " << mnv[i].getln() << "\t" <<mnv[i].getid() << "\t" << mnv[i].getpass() << "\t" << mnv[i].getocc() << "\t" << mnv[i].getadd()<<"\t"<<mnv[i].getdb()<< "\t"<<mnv[i].getroom()<<"\t"<<mnv[i].getage()<<"\t" <<mnv[i].getfess() << "\t" <<mnv[i].getpay() << "\t" <<mnv[i].getdue()<< endl;
            }
            imember.close();
        }
        else cout << "Error\n";


    }
    else cout << "Wrong Password or Invalid ID\n";
    }
    void database :: editadmin()
    {
        ifstream oadmin ("Admin.bin");
        if (!oadmin.is_open())
        {
            cout <<"Error\n";
            exit(1);
        }
        //while (!oadmin.eof())
        else {


            while(!oadmin.eof())  //  for (int i = 0; i !=oadmin.eof();i++)
        {

            string iffn,ifln,ifid,ifpass;
            oadmin >> iffn >> ifln >> ifid >> ifpass;

            admin temp;
            temp.setinfo(iffn,ifln,ifid,ifpass);

            nv.push_back(temp);


        }
        cout<< "\nEnter Admin's ID : ";
        string gid;
        cin >> gid;
        cout << "Enter admin's Password : ";

        string gpas = password();
        cout << "\n\n";
        int m = srchadmin(gid,gpas);
        //cout << m;

        if (m>-1) {

                cout << "1.Change Name \t 2.Change Password\n";
                int option ;
                cout << "Enter your choice : ";
                cin >> option;
                if (option == 1)
                    {
                        cout << "Enter your new first name : ";
                        string fn;
                        cin >> fn;
                        cout << "Enter your new last name : ";
                        string ln;
                        cin>> ln;
                        nv[m].setname(fn,ln);
                        cout << "\n\nYour name has been changed\n\n";

                    }
                    if(option == 2)
                    {
                        cout << "Enter your new password : ";
                        string gpas = password();
                        nv[m].setpass(gpas);
                        cout << "\n\nYour Password has been changed\n\n";

                    }
                ofstream iadmin ("Admin.bin",ios::trunc | ios :: binary);
        if (iadmin.is_open())
        {
            for(int i = 0; i < nv.size(); i ++)
           {

            iadmin <<nv[i].getfn()<<" "<<nv[i].getln()<<"\t"<<nv[i].getid() << "\t" << nv[i].getpass()<< endl;
           }
            iadmin.close();
        }
        else cout << "Error" << endl;

        }
        else cout << "\n\nWrong Password or Invalid ID" << endl;

        }
    }

    void database :: editmember()

    {
        cout << "Enter the member id : ";
        string gi;
        cin >>gi;
        cout << "Enter Password : ";

        string gpas = password();
        cout << endl;
        ifstream omember("Member.bin");
        if (!omember.is_open())
        {
            cout << "Error\n";
            exit(1);
        }
        while (!omember.eof())
        {
            string iffn,ifln,ifid,ifpass,ifocc,ifadd,ifdtb,ifrn,ifa;
            string iff,ifpy,ifpd;
            omember >> iffn >> ifln >>ifid>>ifpass>> ifocc >> ifadd >> ifdtb>> ifrn >> ifa >> iff >> ifpy >> ifpd;
            member temp;
            temp.setinfo(iffn,ifln,ifid,ifpass,ifocc,ifadd,ifdtb,ifrn,ifa);
            temp.setfees(iff);
            temp.setpay(ifpy);
            mnv.push_back(temp);
    }
    int m = srchmember(gi,gpas);
    if (m > -1) {
            cout << "\n\nYou Can only change your personal info like name, password, date of birth\n\n";
            cout << "1. Change name \t 2. Change date of birth \t 3.Change password\n\n";
            cout << "\nEnter your option: ";
            int option ;
            cin >> option;
            if (option == 1)
            {
                cout << "Enter your new first name : ";
                string fn;
                cin>> fn;
                cout << "Enter your new last name : ";
                string ln;
                cin >> ln;
                mnv[m].setname(fn,ln);
                cout << "Your name has been changed\n\n";
            }
            else if (option == 2)
            {
                cout <<"Enter your new date of birth : ";
                string db;
                cin>> db;
                mnv[m].setdb(db);
                cout << "Your date of birth has been changed\n\n";

            }
            else if (option == 3)
            {
                cout <<"Enter your new password : ";
                string gpas= password();
                mnv[m].setpass(gpas);
                cout << "Your password has been changed \n\n";
            }
            else
                {
                    cout <<"Wrong input\n";

                }
            ofstream imember ("Member.bin", ios::trunc | ios :: binary);
        if (imember.is_open())
        {
            for (int i = 0; i < mnv.size() ; i++)
           {

            imember << mnv[i].getfn() << " " << mnv[i].getln() << "\t" <<mnv[i].getid() << "\t" << mnv[i].getpass() << "\t" << mnv[i].getocc() << "\t" << mnv[i].getadd()<<"\t"<<mnv[i].getdb()<< "\t"<<mnv[i].getroom()<<"\t"<<mnv[i].getage()<<"\t" <<mnv[i].getfess() << "\t" <<mnv[i].getpay() << "\t" <<mnv[i].getdue()<< endl;
            }
            imember.close();
        }
        else cout << "Error\n";


    }
    else cout << "Wrong Password or Invalid ID\n";


    }



    void database :: Addadmin () {
        cout << "Enter Admin's First name : ";
        string gfn;
        cin>> gfn;
        cout<< "Enter Admin's Last name : ";
        string gln;
        cin>>gln;
        cout<< "Enter Admin's ID : ";
        string gid;
        cin >> gid;
        cout << "Enter admin's Password : ";

        string gpas = password();
    admin k;
    k.setinfo (gfn,gln,gid,gpas);
    a.push_back(k);
    ofstream iadmin ("Admin.bin",ios::app | ios :: binary);
        if (iadmin.is_open())
        {
            iadmin <<k.getfn()<<" "<<k.getln()<<"\t"<<k.getid() << "\t" << k.getpass()<< endl;
            iadmin.close();
        }
        else cout << "Error" << endl;
    }
    void database :: showmember () {

        cout << "Enter the member id : ";
        string gi;
        cin >>gi;
        cout << "Enter Occupation : ";

        string gpas = password();
        cout << endl;
        ifstream omember("Member.bin");
        if (!omember.is_open())
        {
            cout << "Error\n";
            exit(1);
        }
        while (!omember.eof())
        {
            string iffn,ifln,ifid,ifpass,ifocc,ifadd,ifdtb,ifrn,ifa;
            string iff,ifpy,ifpd;
            omember >> iffn >> ifln >>ifid>>ifpass>> ifocc >> ifadd >> ifdtb>> ifrn >> ifa >> iff >> ifpy >> ifpd;
            member temp;
            temp.setinfo(iffn,ifln,ifid,ifpass,ifocc,ifadd,ifdtb,ifrn,ifa);
            temp.setfees(iff);
            temp.setpay(ifpy);
            temp.setdue(ifpd);
            mnv.push_back(temp);
    }
    int m = srchmember2(gi,gpas);
    if (m > -1) mnv[m].show();
    else cout << "Wrong Password or Invalid ID\n";
    }

    void database :: showadmin () {

        ifstream oadmin ("Admin.bin");
        if (!oadmin.is_open())
        {
            cout <<"Error\n";
            exit(1);
        }
        //while (!oadmin.eof())
        else {


            while(!oadmin.eof())  //  for (int i = 0; i !=oadmin.eof();i++)
        {

            string iffn,ifln,ifid,ifpass;
            oadmin >> iffn >> ifln >> ifid >> ifpass;

            admin temp;
            temp.setinfo(iffn,ifln,ifid,ifpass);

            nv.push_back(temp);


        }
        cout<< "\nEnter Admin's ID : ";
        string gid;
        cin >> gid;
        cout << "Enter admin's Password : ";

        string gpas = password();
        int m = srchadmin(gid,gpas);

        if (m>-1) nv[m].show();
        else cout << "\n\nWrong Password or Invalid ID" << endl;

        }


    }
    int database :: srchadmin(string gs,string gi)
    {
        for(int i = 0; i < nv.size() ; i++)
        {
            if (nv[i].getid()== gs && nv[i].getpass()==gi) return i;
        }
        return -1;
    }
    int database :: srchmember(string gs,string gi)
    {
        for(int i = 0; i < mnv.size() ; i++)
        {
            if (mnv[i].getid()== gs&& mnv[i].getpass()== gi) return i;
        }
        return -1;
    }
    int database :: srchmember1(string gs,string gi)
    {
        for(int i = 0; i < mg.size() ; i++)
        {
            if (mg[i].getid()== gs&& mg[i].getpass()== gi) return i;
        }
        return -1;
    }
    int database :: srchmember2(string gs,string gi)
    {
        for(int i = 0; i < mnv.size() ; i++)
        {
            if (mnv[i].getid()== gs&& mnv[i].getocc()== gi) return i;
        }
        return -1;
    }

    void database :: givingmeal()
    {


    }

    void database :: login()

    {
        system("color 70");
        system ("mode 70");
        char chr;
        while (chr != 'n')
        {

        cout << "----------------------------------------------------------------------";
        cout << "!                  WELCOME TO HOSTEL MANAGEMENT SYSTEM               !";
        cout << "----------------------------------------------------------------------";
        cout << " \n!\t\t\t<1> Login as Member\t\t\t     !\n!\t\t\t<2> Login as Admin\t\t\t     !\n!\t\t<3> Add Admin (If Any admin has not been added)\t     !\n!\t\t<4> Send request to be a member\t\t\t     !\n!\t\t\t<5> Quit Programme\t\t\t     !\n";
        cout << "----------------------------------------------------------------------";
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        cout << "----------------------------------------------------------------------";
        int option;
        cout << "Enter option: ";
        cin >> option;
        if (option == 5) break;
        if (option == 4) signup();
        if (option == 3)
        {

                ofstream oadmin ("Admin.bin", ios::trunc |ios :: binary);
        if (!oadmin.is_open())
        {
            cout <<"Error\n";
            exit(1);
        }

        else {


        readingadmin();

        //cout << nv.size();
        if (nv.size() < 2) {

            cout << "Enter Admin's First name : ";
        string gfn;
        cin>> gfn;
        cout<< "Enter Admin's Last name : ";
        string gln;
        cin>>gln;
        cout<< "Enter Admin's ID : ";
        string gid;
        cin >> gid;
        cout << "Enter admin's Password : ";

        string gpas = password();
    admin k;
    k.setinfo (gfn,gln,gid,gpas);
    a.push_back(k);
    ofstream iadmin ("Admin.bin",ios::trunc | ios :: binary);
        if (iadmin.is_open())
        {
            iadmin <<k.getfn()<<" "<<k.getln()<<"\t"<<k.getid() << "\t" << k.getpass()<< endl;
            iadmin.close();
        }
        else cout << "Error" << endl;
        }
        else cout << "This is for the first time.\nAdmin already exists.\nAn admin can only add another admin\n";
        }
        }
        if (option == 1)
        {
            //system ("color 0F");
            cout << "Enter the member id : ";
        string gi;
        cin >>gi;
        cout << "Enter Password : ";

        string gpas = password();
        cout << endl;
        ifstream omember("Member.bin");
        if (!omember.is_open())
        {
            cout << "Error\n";
            exit(1);
        }
        readingmember();

    int m = srchmember(gi,gpas);
    if (m > -1) {
            char c;
    while (c!='n'){
            system ("mode 60");
            Studentprofile();
            system ("mode 60");
            cout << "------------------------------------------------------------";
            cout << "!                        MENU BAR                          !";
            cout << "------------------------------------------------------------";
            cout << "\n!                  <1> Edit Account                        !";
            cout << "\n!                  <2> Show Information                    !";
            cout << "\n!                  <3> Delete Account                      !";
            cout << "\n!                  <4> Back to Main Menu                   !\n";
            cout << "------------------------------------------------------------";
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            cout << "------------------------------------------------------------";
            int option;
            cout << "\n\n Enter Option : ";
            cin >> option;
            if (option == 4) break;
            if (option == 1)
            {
                system("mode 60");
            cout << "!----------------------------------------------------------!";
            cout << "\n!      You Can only change your personal Information       !";
            cout << "\n!            like name, password, date of birth            !";
            cout << "\n!----------------------------------------------------------!";
            cout <<   "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            cout <<   "!----------------------------------------------------------!";
                    // char c;
                     while (1) {

            cout <<"\n\n\n";
            cout <<   "!----------------------------------------------------------!";
            cout <<   "!                         MENU BAR                         !";
            cout <<   "!----------------------------------------------------------!";
            cout <<   "\n!                      1. Change name                      !";
            cout <<   "\n!                  2. Change date of birth                 !";
            cout <<   "\n!                    3. Change password                    !";
            cout <<   "\n!                      4. Go back                          !\n";
            cout <<   "!==========================================================!";
            cout <<   "!==========================================================!";
            cout << "\nEnter your option: ";
            int option ;
            cin >> option;
            if (option == 4) break;

            if (option == 1)
            {
                cout << "Enter your new first name : ";
                string fn;
                cin>> fn;
                cout << "Enter your new last name : ";
                string ln;
                cin >> ln;
                mnv[m].setname(fn,ln);
                writingmember();
                cout << "Your name has been changed\n\n";

            }
            else if (option == 2)
            {
                cout <<"Enter your new date of birth : ";
                string db;
                cin>> db;
                mnv[m].setdb(db);
                writingmember();
                cout << "Your date of birth has been changed\n\n";

            }
            else if (option == 3)
            {
                cout <<"Enter your new password : ";
                string gpas= password();
                mnv[m].setpass(gpas);
                cout << "\n\nYour password has been changed \n\n";
                writingmember();
                //system("mode 60");
            }
            else
                {
                    cout <<"Wrong input\n";

                }
                cout << "Press n to go Member Menu or any key to edit again\n";
                c = getch();
                system("mode 60");
                if (c == 'n'|| c == 'N') break;
                }

            }
            if (option == 2) mnv[m].show();
            if (option == 3)
            {
                mnv.erase(mnv.begin()+m);
            cout << "\n\nYour account has been deleted\n\n";
            writingmember();
            break;


        }
        //else cout << "Error\n";
        cout << "\n\nPress n to go main menu or any key to proceed again \n";
        c = getch();
        if (c == 'n') break;

            }
            //else cout << "Wrong input\n\n";

    }
    else cout << "Wrong Password or Invalid ID\n";
        }
        if (option == 2)
        {

            ifstream oadmin ("Admin.bin");
        if (!oadmin.is_open())
        {
            cout <<"Error\n";
            exit(1);
        }
        //while (!oadmin.eof())
        else {
                readingadmin();


        cout<< "\nEnter Admin's ID : ";
        string gid;
        cin >> gid;
        cout << "Enter admin's Password : ";

        string gpas = password();
        int m = srchadmin(gid,gpas);

        if (m>-1) {

                while (1)
                    {
                        system("mode 41");
                Adminprofile();
                system("mode 41");
                cout <<"-----------------------------------------";
                cout <<"!               MENU BAR                !";
                cout <<"-----------------------------------------";
                cout << "\n!\t<1> Add Admin\t\t\t!\n!\t<2> Add New Member\t\t!\n!\t<3> Change Your Info\t\t!\n!\t<4> Show Detail\t\t\t!\n!\t<5> Delete Admin Account\t!\n!\t<6> Show Member Information\t!\n!\t<7> Back to Main Menu\t\t!\n!\t<8> Delete All member\t\t!\n!\t<9> Show All Member Information\t!";
                cout <<"-----------------------------------------";
                cout <<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
                cout <<"-----------------------------------------";
                int option;
                cout << "Enter your choice : ";
                cin>> option;
                if (option == 9)
                {
                    readingmember();
                    //cout << mnv.size();
                    for (int i = 0; i < mnv.size()-1; i++) mnv[i].showfradmin();
                }
                if (option == 8)
                {
                    ofstream omember ("Member.bin",ios :: trunc | ios::binary);
                }

                if (option == 7) break;
                if (option == 6) showmember();
                if (option == 1) Addadmin();
                if (option == 2) Addmember();
                if (option == 3) {
                        char c;
                while (c!= 'n')
                    {

                               cout << "1.Change Name \t 2.Change Password\n3. Go back\n";
                int option ;
                cout << "Enter your choice : ";
                cin >> option;
                if (option == 3) break;
                if (option == 1)
                    {
                        cout << "Enter your new first name : ";
                        string fn;
                        cin >> fn;
                        cout << "Enter your new last name : ";
                        string ln;
                        cin>> ln;
                        nv[m].setname(fn,ln);
                        cout << "\n\nYour name has been changed\n\n";
                        writingadmin();
                        continue;

                    }
                    if(option == 2)
                    {
                        cout << "Enter your new password : ";
                        string gpas = password();
                        nv[m].setpass(gpas);
                        cout << "\n\nYour Password has been changed\n\n";
                        writingadmin();
                        continue;

                    }


        cout << "Press n to go back or any key to proceed again\n";
        c = getch();
        if (c == 'n' || 'N') break;
        }


                }
                if (option == 4) {system("Cls");
                system("mode 50");
                        nv[m].show();}
                if (option == 5) {
                    nv.erase(nv.begin()+m);
                    /*ofstream iadmin ("Admin.bin",ios::trunc | ios :: binary);
        if (iadmin.is_open())
        {
            for(int i = 0; i < (nv.size()-1); i ++)
           {

            iadmin <<nv[i].getfn()<<" "<<nv[i].getln()<<"\t"<<nv[i].getid() << "\t" << nv[i].getpass()<< endl;
           }
            iadmin.close();
           // nv.empty();
        }
        else cout << "Error" << endl;*/
                    writingadmin();
                cout << "\nAcoount Has been deactivated \n\n";
                cout << "Please close and restart the program\n\n";

                break;


                }
                //else cout << "Wrong input\n";
                cout << "\n\nPress any key to back \n";
                getch();
                //if (c == 'n'|| c == 'N') {
                    system ("mode 70");
                        //cout << "\n\n\n    Please restart the program to again log in to your account\n\t\t";
                         continue;

                ///}
        }

        }
        else cout << "\n\nWrong Password or Invalid ID" << endl;

        }


        }
        cout << "press n to quit or any key to continue\n";
        chr=getch();
        system("mode 70");
        if (chr =='n') break;
        }
    }

    void database :: readingadmin()

    {
        ifstream oadmin ("Admin.bin");
          while(!oadmin.eof())  //  for (int i = 0; i !=oadmin.eof();i++)
        {

            string iffn,ifln,ifid,ifpass;
            oadmin >> iffn >> ifln >> ifid >> ifpass;

            admin temp;
            temp.setinfo(iffn,ifln,ifid,ifpass);

            nv.push_back(temp);


        }
    }

    void database :: writingadmin()
    {
                ofstream iadmin ("Admin.bin",ios::trunc | ios :: binary);
        if (iadmin.is_open())
        {
            for(int i = 0; i < nv.size(); i ++)
           {

            iadmin <<nv[i].getfn()<<" "<<nv[i].getln()<<"\t"<<nv[i].getid() << "\t" << nv[i].getpass()<< endl;
           }
            iadmin.close();
           // nv.empty();
        }
        else cout << "Error" << endl;
    }

    void database :: readingmember()
    {
        ifstream omember("Member.bin");
        while (!omember.eof())
        {
            string iffn,ifln,ifid,ifpass,ifocc,ifadd,ifdtb,ifrn,ifa;
            string iff,ifpy,ifpd;
            omember >> iffn >> ifln >>ifid>>ifpass>> ifocc >> ifadd >> ifdtb>> ifrn >> ifa >> iff >> ifpy >> ifpd;
            member temp;
            temp.setinfo(iffn,ifln,ifid,ifpass,ifocc,ifadd,ifdtb,ifrn,ifa);
            temp.setfees(iff);
            temp.setpay(ifpy);
            temp.setdue(ifpd);
            mnv.push_back(temp);
        }
    }

    void database :: writingmember()
    {
        ofstream imember ("Member.bin", ios::trunc | ios :: binary);
        if (imember.is_open())
        {
            for (int i = 0; i < mnv.size() ; i++)
           {

            imember << mnv[i].getfn() << " " << mnv[i].getln() << "\t" <<mnv[i].getid() << "\t" << mnv[i].getpass() << "\t" << mnv[i].getocc() << "\t" << mnv[i].getadd()<<"\t"<<mnv[i].getdb()<< "\t"<<mnv[i].getroom()<<"\t"<<mnv[i].getage()<<"\t" <<mnv[i].getfess() << "\t" <<mnv[i].getpay() << "\t" <<mnv[i].getdue()<< endl;
            }
            imember.close();
            mnv.empty();
        }
    }
    void database :: deletEallmember()
    {
       // readingmember();
       ifstream omember("Member.bin");
        while (!omember.eof())
        {
            string iffn,ifln,ifid,ifpass,ifocc,ifadd,ifdtb,ifrn,ifa;
            string iff,ifpy,ifpd;
            omember >> iffn >> ifln >>ifid>>ifpass>> ifocc >> ifadd >> ifdtb>> ifrn >> ifa >> iff >> ifpy >> ifpd;
            member temp;
            temp.setinfo(iffn,ifln,ifid,ifpass,ifocc,ifadd,ifdtb,ifrn,ifa);
            temp.setfees(iff);
            temp.setpay(ifpy);
            temp.setdue(ifpd);
            mnv.push_back(temp);
        }
        mnv.empty();
        //writingmember();
        ofstream imember ("Member.bin", ios::trunc | ios :: binary);
        if (imember.is_open())
        {
            for (int i = 0; i < mnv.size() ; i++)
           {

            imember << mnv[i].getfn() << " " << mnv[i].getln() << "\t" <<mnv[i].getid() << "\t" << mnv[i].getpass() << "\t" << mnv[i].getocc() << "\t" << mnv[i].getadd()<<"\t"<<mnv[i].getdb()<< "\t"<<mnv[i].getroom()<<"\t"<<mnv[i].getage()<<"\t" <<mnv[i].getfess() << "\t" <<mnv[i].getpay() << "\t" <<mnv[i].getdue()<< endl;
            }
            imember.close();
            mnv.empty();
        }
    }
   /* {
        cout << " \n<1> Login as Member \t <2> Login as Admin \n\n";
        int option;
        cout << "Enter option: ";
        cin >> option;
        if (option == 2)
        {
            vector <admin> nv;
            ifstream oadmin ("Admin.bin");
        if (!oadmin.is_open())
        {
            cout <<"Error\n";
            exit(1);
        }
        //while (!oadmin.eof())
        else {
                system("color 70");
                system("mood 70");

            while(!oadmin.eof())  //  for (int i = 0; i !=oadmin.eof();i++)
        {

            string iffn,ifln,ifid,ifpass;
            oadmin >> iffn >> ifln >> ifid >> ifpass;

            admin temp;
            temp.setinfo(iffn,ifln,ifid,ifpass);

            nv.push_back(temp);


        }
        cout<< "\nEnter Admin's ID : ";
        string gid;
        cin >> gid;
        cout << "Enter admin's Password : ";

        char pass[32];
        char ap;
        int i;
        for(i =0;;)
        {
            ap = getch();
            if ((ap>='a'&&ap<='z')||(ap>='A'&&ap<='Z')||(ap>='0'&&ap<='9'))
            {
                pass[i]=ap;
                i++;
                cout<<"*";
            }
            if (ap=='\b'&& i>=1){cout << "\b \b";
            i--;}
            if (ap=='\r'){pass[i]='\0';
            break;}
        }
        string gpass;
        gpass = pass;


        for(int i = 0; i < nv.size() ; i++)
        {
            if (nv[i].getid()== gid && nv[i].getpass()==gpass) nv[i].show();
        }





//        else cout << "\n\nWrong Password or Invalid ID" << endl;

        }


        }
    }




  /*
    void database :: handler()
    {
        char ch;
        while (ch!='n')
        {
            cout << "1.Add admin\t2.Add member\t3.Show Admin detail\t4.Show member detail\n";
            int option;
            //cout << "Enter your option : ";
            cin >> option;
            if (option == 1) Addadmin();
            else if (option == 2) Addmember();
            else if (option == 3) showadmin();
            else if (option == 4) showmember();
          //  else cout << "Invalid option\n";
            cout << "\npress n to quit or any othe key to continue\n";
            cin >> ch;
        }
    }
*/
