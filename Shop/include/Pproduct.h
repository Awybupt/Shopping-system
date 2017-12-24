#ifndef PPRODUCT_H
#define PPRODUCT_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Pproduct
{
    public:
        Pproduct();
        Pproduct(double p,string n,int nu,string d,string id);
        ~Pproduct();

        void changePrice(double p);
        virtual double getPrice();
        virtual void show()=0;
        double gp();
        void changename(string n);
        string getname();

        void changenumber(int n);
        int getnumber();

        void changeid(string i);
        string getid();
        void changedescribe(string d);
        string getdescribe();

    private:
        double Price;
        string name;
        int number;
        string describe;
        string pid;
};

class Pfood:public Pproduct
{
private:
    int producetime;
    int term;
    double Foodsize;
public:

    Pfood();
    Pfood(int p,int t,double fs,double pp,string n,int nu,string d,string id);
    ~Pfood();
    void show();
    void fchangeproducetime(int pr);
    int getproducetime();
    void changefoodsize(double fs);
    double getfoodsize();
    virtual double getPrice();
    void fchangeterm(int te);
    int getterm();
    bool judgefresh();
};

class Pclother:public Pproduct
{
private:
    string color;
    string style;
public:
    Pclother(string c,string st,double p,string n,int nu,string d,string id);
    ~Pclother();
    string getstyle();
    string getcolor();
    void show();
    void changestyle(string s);
    void addcolor(string s);
};

class Pbook:public Pproduct
{
private:
    int edition;
    string press;
public:
    Pbook(int e,string p,double pp,string n,int nu,string d,string id);
    ~Pbook();
    void show();
    void changeedition(int n);
    void changepress(string p);
    string getpress();
    int getedition();
};
#endif // PPRODUCT_H
