/*
 * create by 魏晓
 * 2017/12/12
 * 思想：代码是给人读的
 代码结构
 source-
 Pplatform-|
          |Puser
          |Pproduct
____________________________

*/
#include "Pplatform.h"

int main()
{
    Pplatform temp;//平台方法实例化
    try{
        temp.run();
    }
    catch(exception& e)
    {
        cout<<"Exception"<<e.what()<<endl;
    }
    //temp.run();//实例调用
    return 0;
}
