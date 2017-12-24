//
//  sBank.hpp
//  System
//
//  Created by 魏晓 on 11/11/17.
//  Copyright © 2017 魏晓. All rights reserved.
//
#ifndef SBANK_H
#define SBANK_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <time.h>

using namespace std;

typedef struct sbankuser{//用户类
    string bankusername;//必须是符合id,且第一位不能是数字,等于10位
    string bankuserid;//8位数字
    string bankuseridcard;//十八位数字字符串
    string bankuserpassword;//密码,要实现隐形输入
    string banktype;//可选名称中的一种,注册后不可改变
    double userbalance;//余额

    sbankuser(){//无参数构造函数
        bankusername="";
        bankuserid="";
        bankuseridcard="";
        bankuserpassword="";
        banktype="";
        userbalance=0.0;
    }

    sbankuser(string a,string b,string c,string d,string e,double f){//有参数构造函数
        bankusername=a;
        bankuserid=b;
        bankuseridcard=c;
        bankuserpassword=d;
        banktype=e;
        userbalance=0.0;
    }
}banker;

typedef struct Transactionrecord{//记录函数
    time_t bankrecarditime;//产生记录的时间
    string bankrecordid;//记录的id
    string bankrecordtype;//记录的 类型
    string bankaddition;//记录的备注信息
    double bankrecordnum;//记录的顺序

    Transactionrecord(time_t e,string a,string b,string c,double d){
        bankrecarditime=e;
        bankrecordid=a;
        bankrecordtype=b;
        bankaddition=c;
        bankrecordnum=d;
    }

}bankrecord;

class sBankinterface{//银行类

private:
    vector<string> bankname;//设置可以选择的银行名单

    map<string,banker> bankerlist;//id/人员记录
    vector<bankrecord> BTrecord;
    string nowlocal;

public:

    sBankinterface();//构造函数
    ~sBankinterface();//析构函数
    bool banklogin(string a,string b);//登陆,a和b分别是用户名和密码
    void bankregister();//zhuceyonghu
    void banksignout();//退出登录
    void banktransfer(string distination,double b);//转账
    int  quicktransfer(string owner,string pass,string distination,double b);//未登录转台下转账
    void bankchangeinformation();//修改信息
    void getinformation();//得到信息
    void Moneydeal();//自己存钱取钱
    string getlocal();//得到档期按登陆
    int sBankrun();//运行银行
    int jianting();//运行socket
};




#endif // SBANK_H
