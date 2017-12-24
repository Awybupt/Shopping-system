#include "Pproduct.h"
#include <time.h>

/*
基类，方法的实现
*/
unsigned int RSHash(string mas)              //hash函数
{
    const char *str = mas.c_str();
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * a + (*str++);
        a *= b;
    }

    return (hash  & 0x3FFF);
}

Pproduct::Pproduct()
{
    this->Price=0.0;
    this->name="name";
    this->number=0;
    this->describe="";
    //ctor
}

Pproduct::~Pproduct()
{
//dtor
}
Pproduct::Pproduct(double p,string n,int nu,string d,string id)
{
    this->Price=p;
    this->name=n;
    this->number=nu;
    this->describe=d;
    this->pid=id;
}
void Pproduct::changePrice(double p)
{
    this->Price=p;
}
double Pproduct::getPrice()
{
     return this->Price;
}
double Pproduct::gp()
{
    return this->Price;
}
void Pproduct::changename(string n)//唯一标识
{
    this->name=n;
}
string Pproduct::getname()
{
    return this->name;
}

void Pproduct::changenumber(int n)
{
    this->number=n;
}
int Pproduct::getnumber()
{
    return this->number;
}

void Pproduct::changedescribe(string d)
{
    this->describe=d;
}
string Pproduct::getdescribe()
{
    return this->describe;
}
void Pproduct::changeid(string i)
{
    this->pid=i;
}

string Pproduct::getid()
{
    return this->pid;
}
Pfood::Pfood():Pproduct()
{

}

/*
food类，方法的实现
*/
void Pfood::show()
{
    cout<<this->getname()<<"\t"<<this->getnumber()<<"\t"<<this->getPrice()<<"id:"<<this->getid()<<endl;
}

void Pclother::show()
{
    cout<<this->getname()<<"\t"<<this->getnumber()<<"\t"<<this->getPrice()<<"id:"<<this->getid()<<endl;
}

void Pbook::show()
{
    cout<<this->getname()<<"\t"<<this->getnumber()<<"\t"<<this->getPrice()<<"id:"<<this->getid()<<endl;
}

Pfood::Pfood(int p,int t,double fs,double pp,string n,int nu,string d,string id):Pproduct(pp,n,nu,d,id)
{
    this->producetime=p;
    this->term=t;
    this->Foodsize=fs;
}

 Pfood::~Pfood()
 {

 }
bool Pfood::judgefresh()
{
    time_t now=time(NULL);
    if((now-this->producetime)/86400>this->term)
        return false;
    return true;
}
void Pfood::fchangeproducetime(int pr)
{
    this->producetime=pr;
}
int Pfood::getproducetime()
{
    return this->producetime;
}
void Pfood::fchangeterm(int te)
{
    this->term=te;
}
int Pfood::getterm()
{
    return this->term;
}
double Pfood::getfoodsize()
{
    return this->Foodsize;
}
double Pfood::getPrice()
{
    return (this->Foodsize*gp());
}
void Pfood::changefoodsize(double fs)
{
    this->Foodsize=fs;
}

/*
clother类，方法的实现
*/

Pclother::Pclother(string c,string st,double p,string n,int nu,string d,string id):Pproduct(p,n,nu,d,id)
{
    this->color=c;
    this->style=st;
}
Pclother::~Pclother(){

}
string Pclother::getstyle()
{
    return this->style;
}
string Pclother::getcolor()
{
    return this->color;
}
void Pclother::changestyle(string s)
{
    this->style=s;
}
void Pclother::addcolor(string s)
{
    this->color=this->color+"/"+s;
}

/*
book类，方法的实现
*/

Pbook::Pbook(int e,string p,double pp,string n,int nu,string d,string id):Pproduct(pp,n,nu,d,id)
{
    this->edition=e;
    this->press=p;
}
Pbook::~Pbook()
{

}
void Pbook::changeedition(int n)
{
    this->edition=n;
}
void Pbook::changepress(string p)
{
    this->press=p;
}
string Pbook::getpress()
{
    return this->press;
}
int Pbook::getedition()
{
    return this->edition;
}
