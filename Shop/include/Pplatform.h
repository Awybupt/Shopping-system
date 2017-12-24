#ifndef PPLATFORM_H
#define PPLATFORM_H
#include "Pproduct.h"
#include "Puser.h"
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;
typedef struct jiaoyirecord{
    string Userid;
    string goodsid;
    time_t recordtime;
    string addi;//附加说明，比如购买方式还有其他的
    jiaoyirecord(string u,string g,string a)
    {
        Userid=u;
        goodsid=g;
        recordtime=time(NULL);
        addi=a;
    }
    jiaoyirecord(string u,string g,time_t t,string a)
    {
        Userid=u;
        goodsid=g;
        recordtime=t;
        addi=a;
    }
    bool operator <(const jiaoyirecord &a)
    {
        if(a.recordtime<recordtime)
            return false;
        else
            return true;
    }
}record;
class Pplatform
{
    public:
        Pplatform();
        ~Pplatform();
        void registuser();
        void hello();
        void run();
        void buy(string buyid);
        void manager();//ZHIYOU GUANLI YUAN YOU NENG LI
        void discount();
        void ViewAllProduct();
        void addlike();
        int idtouser(string id);
        int idtoproduct(string id);
        void changeinfo();
        bool zhifu(double localjine);
    private:
        vector<customer> customers;

        vector<Pfood> fe;//食物
        double Pfoodeff;//折扣系数
        vector<Pclother> ce;//衣服
        double Pclothereff;
        vector<Pbook> be;//书
        double Pbookeff;

        vector<record> platrecord;
        int local;
};

#endif // PPLATFORM_H
