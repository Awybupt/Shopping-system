#ifndef PPRODUCT_H
#define PPRODUCT_H

#include <iostream>//输入输出
#include <string>//string
#include <vector>//引入vector

using namespace std;

class Pproduct
{
    public:
        Pproduct();//无参数产品构造函数
        Pproduct(double p,string n,int nu,string d,string id);//有参数铲平父类构造函数
        ~Pproduct();//析构函数

        void changePrice(double p);//改变价格
        virtual double getPrice();//得到价格
        virtual void show()=0;//完全虚函数
        double gp();//得到单纯价格
        void changename(string n);//盖面姓名
        string getname();//得到名字

        void changenumber(int n);//改变数量
        int getnumber();//得到数量

        void changeid(string i);//改变id
        string getid();//得到id
        void changedescribe(string d);//改变描述
        string getdescribe();//得到描述

    private:
        double Price;//价格
        string name;//姓名
        int number;//数量
        string describe;//描述
        string pid;//产品id
};

class Pfood:public Pproduct//食物子类
{
private://私有
    int producetime;//产生时间
    int term;//保质期
    double Foodsize;//食物大小
public:

    Pfood();//食物无参数构造函数
    Pfood(int p,int t,double fs,double pp,string n,int nu,string d,string id);//有参数构造函数
    ~Pfood();//析构函数

    void show();//展示函数，定义父类中的子类
    void fchangeproducetime(int pr);//改变生产时间

    int getproducetime();//的到生产时间
    void changefoodsize(double fs);//改变食物大小

    double getfoodsize();//得到食物大小
    virtual double getPrice();//得到价格

    void fchangeterm(int te);//改变周期
    int getterm();//得到保质期

    bool judgefresh();//判断是不是新鲜
};

class Pclother:public Pproduct//衣服子类
{
private:
    string color;//颜色
    string style;//风格
public:
    Pclother(string c,string st,double p,string n,int nu,string d,string id);//衣服带参数构造函数
    ~Pclother();//析构函数
    string getstyle();//得到这件衣服的风格
    string getcolor();//得到颜色
    void show();//展示
    void changestyle(string s);//改变分割
    void addcolor(string s);//得到颜色
};

class Pbook:public Pproduct//书子类
{
private:
    int edition;//得到版本
    string press;//出版社
public:
    Pbook(int e,string p,double pp,string n,int nu,string d,string id);//带参数构造函数
    ~Pbook();//析构函数
    void show();//展示函数
    void changeedition(int n);//改编版本
    void changepress(string p);//改变出版社
    string getpress();//得到出版社
    int getedition();//得到版本
};
#endif // PPRODUCT_H
