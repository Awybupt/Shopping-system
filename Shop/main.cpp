/*
 * create by κ��
 * 2017/12/12
 * ˼�룺�����Ǹ��˶���
 ����ṹ
 source-
 Pplatform-|
          |Puser
          |Pproduct
____________________________

*/
#include "Pplatform.h"

int main()
{
    Pplatform temp;//ƽ̨����ʵ����
    try{
        temp.run();
    }
    catch(exception& e)
    {
        cout<<"Exception"<<e.what()<<endl;
    }
    //temp.run();//ʵ������
    return 0;
}
