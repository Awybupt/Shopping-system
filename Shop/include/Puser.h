#ifndef PUSER_H
#define PUSER_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>//用于生成记录的时候调用当前时间

using namespace std;

class Puser//用户类
{
    public:
        Puser();//无参数构造函数
        Puser(string na,string id,string ba,string ad,string pa);//有参数构造函数
        virtual ~Puser();//析构函数
        void changename(string newname);//改变名字
        void changeid(string newid);//改变id
        void changebankid(string newbankid);//改变银行账户ud
        void changeaddition(string newaddition);//改变附加信息
        void changepassword(string newpassword);//改变密码
        string getPuname();//得到名字
        string getPuid();//得到id
        string getPubankid();//得到银行id
        string getPuaddition();//得到附加信息
        string getpassword();//得到密码
    private:
        string Puname;//名字
        string Puid;//id
        string PuBankid;//yinhangid
        string Puaddition;//附加信息
        string Pupassword;//密码
};
class customer:public Puser//顾客
{
private:
    vector <string> Pulike;//喜欢列表
public:
    customer(vector <string> &li,string na,string id,string ba,string ad,string pa);//构造函数
    ~customer();
    void addlike(string productid);//对于单个用户的添加喜欢功能
    void deletelike(string productid);//删除喜欢
    void getPulike(vector <string> &ans);//得到喜欢vector
};

#endif // PUSER_H
