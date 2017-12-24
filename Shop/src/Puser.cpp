#include "Puser.h"

bool invector(vector<string> &s,string tar)
{
    for(int i=0;i<s.size();i++)
        if(s[i]==tar)
            return true;
    return false;
}

void SplitSring(const std::string& s, std::vector<std::string>& v, const std::string& c)//cfenge/v ans/s bei
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));

    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

Puser::Puser()
{

}
Puser::Puser(string na,string id,string ba,string ad,string pa)
{
    this->Puname=na;
    this->Puid=id;
    this->PuBankid=ba;
    this->Puaddition=ad;
    this->Pupassword=pa;
}
Puser::~Puser()
{

}

void Puser::changename(string newname)
{
    this->Puname=newname;
}

void Puser::changeid(string newid)
{
    this->Puid=newid;
}

void Puser::changebankid(string newbankid)
{
    this->PuBankid=newbankid;
}

void Puser::changeaddition(string newaddition)
{
    this->Puaddition=newaddition;
}

void Puser::changepassword(string newpassword)
{
    this->Pupassword=newpassword;
}

string Puser::getPuname()
{
    return this->Puname;
}
string Puser::getPuid()
{
    return this->Puid;
}
string Puser::getPubankid()
{
    return this->PuBankid;
}
string Puser::getPuaddition()
{
    return this->Puaddition;
}
string Puser::getpassword()
{
    return this->Pupassword;
}

customer::customer(vector <string> &li,string na,string id,string ba,string ad,string pa):Puser(na,id,ba,ad,pa)
{
    (this->Pulike).assign(li.begin(),li.end());
}
customer::~customer()
{

}
void customer::addlike(string productid)
{
    vector<string>ans;
    SplitSring(productid,ans,",");

    for(int i=0;i<ans.size();i++){
        if(!invector(Pulike,ans[i]))
            (this->Pulike).push_back(ans[i]);
        else
            cout<<"你已经收藏了！"<<endl;
    }
}
void customer::deletelike(string productid)
{
    for(int i=0;i<Pulike.size();i++)
    {
        if(Pulike[i]==productid)
        {
            for(int j=i;j<Pulike.size()-1;j++)
                Pulike[j]=Pulike[j+1];
            Pulike.pop_back();
            break;
        }
        if(i==Pulike.size()-1)
            cout<<"没有该商品！"<<endl;
    }
}
void customer::getPulike(vector <string> &ans)
{
    ans.assign(Pulike.begin(),Pulike.end());
}























