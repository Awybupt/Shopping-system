/*
* create by 魏晓
* 2017/12/12
*/

#ifndef PPLATFORM_H
#define PPLATFORM_H

#include "Pproduct.h"//产品单例
#include "Puser.h"//用户单例
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;
typedef struct jiaoyirecord{//交易记录
    string Userid;
    //交易的id
    string goodsid;
    //货物的id，或者缺省
    time_t recordtime;
    //发生交易的时间
    string addi;
    //附加说明，比如购买方式还有其他的
    jiaoyirecord(string u,string g,string a)//交易记录的构造函数
    {
        Userid=u;
        goodsid=g;
        recordtime=time(NULL);
        addi=a;
    }
    jiaoyirecord(string u,string g,time_t t,string a)//交易记录的现场构造函数
    {
        Userid=u;
        goodsid=g;
        recordtime=t;
        addi=a;
    }
    bool operator <(const jiaoyirecord &a)//重载比较运算符
    {
        if(a.recordtime<recordtime)
            return false;
        else
            return true;
    }
}record;

class Pplatform//平台类
{
    public:
        Pplatform();
        //构造函数，读取文件
        ~Pplatform();
        //析构函数
        void registuser();
        //注册用户
        void hello();
        //初始化程序，进行一些简单的问狗
        void run();
        //运行程序，总体调度整个类
        void buy(string buyid);
        //购买函数，为了方便以后使用，做成有参数无引导的形式
        void manager();
        //ZHIYOU GUANLI YUAN YOU NENG LI
        void discount();
        //交易函数
        void ViewAllProduct();
        //查看所有产品
        void addlike();
        //添加到喜欢函数
        int idtouser(string id);
        //从id对应到响应的顾客
        int idtoproduct(string id);
        //从给铲平对应到相应的铲平
        void changeinfo();//改变信息
        bool zhifu(double localjine);
        //支付，方便第三期产品
    private:

        vector<customer> customers;
        //顾客的信息，是数据结构的基础
        vector<Pfood> fe;
        //食物
        double Pfoodeff;
        //食物的折扣系数折扣系数
        vector<Pclother> ce;
        //衣服
        double Pclothereff;
        //衣服的折扣
        vector<Pbook> be;
        //书
        double Pbookeff;
        //书的折扣
        double manjianmenxian;
        //满减门限，超过这个数目就减少
        double manjianjine;
        //慢件金额，用于减少的数目
        vector<record> platrecord;
        //产生平台的记录，统一保存在这个数据结构里，用来浏览，检索
        int local;
        //当前登录者在customers中的位置
        void addproduct(int choice);
        //私有方法，添加上平，作用于私有的manager
};

#endif // PPLATFORM_H
