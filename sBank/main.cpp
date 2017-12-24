//#include <iostream>
//
//  main.cpp
//  System
//银行门户的设计
//该门户是一个单独的程序，程序要求至少支持以下功能：
//注册银行卡，银行可选；
//修改银行卡密码；
//存款取款；
//银行卡至少需要有卡号，密码，所属银行名称，持卡人身份证号，卡内金额等内容。
//要求1：请把所有的银行名写入文件（或数据库），注册银行卡的时候，要求只能选择已经存在的银行进行注册。
//要求2：请做好错误场景的处理，例如读银行文件错误，输入数据不合法等等。
//  Created by 魏晓 on 11/11/17.
//  Copyright © 2017 魏晓. All rights reserved.
//
#include "sBank.h"
int main() {
    sBankinterface s;//实例化对象
    int input;
    cout<<"please input choice:"<<endl;
    cin>>input;
    if(input==1)
        s.sBankrun();//调用对象的方法
    else
    {
        cout<<"listening port6000:"<<endl;
        s.jianting();
    }

    return 0;
}
