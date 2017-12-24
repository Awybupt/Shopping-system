#ifndef PUSER_H
#define PUSER_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;


class Puser
{
    public:
        Puser();
        Puser(string na,string id,string ba,string ad,string pa);
        virtual ~Puser();
        void changename(string newname);
        void changeid(string newid);
        void changebankid(string newbankid);
        void changeaddition(string newaddition);
        void changepassword(string newpassword);
        string getPuname();
        string getPuid();
        string getPubankid();
        string getPuaddition();
        string getpassword();
    private:
        string Puname;
        string Puid;
        string PuBankid;
        string Puaddition;
        string Pupassword;
};
class customer:public Puser
{
private:
    vector <string> Pulike;
public:
    customer(vector <string> &li,string na,string id,string ba,string ad,string pa);
    ~customer();
    void addlike(string productid);
    void deletelike(string productid);
    void getPulike(vector <string> &ans);
};

#endif // PUSER_H
