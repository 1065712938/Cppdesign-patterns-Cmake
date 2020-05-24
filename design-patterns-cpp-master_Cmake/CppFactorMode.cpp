//https://blog.csdn.net/wuzhekai1985/article/details/6660462
#include <iostream>
using namespace std;
enum CTYPE{
    COREA,
    COREB
};
//基类
class SingleCore
{
    public:
         virtual void show() = 0;
         virtual ~SingleCore(){
             cout<<"~SingleCore"<<endl;
         };
};
class SingleCoreA:public SingleCore{
    public:
        void show(){
          cout<<"singlecore A"<<endl;
         }
    };
class SingleCoreB:public SingleCore{
    public:
        void show(){
            cout<<"singleCore B"<<endl;
        }
};
class MultiCore{
  public:
      virtual void Show() = 0;
};
class MultiCoreA:public MultiCore{
    public:
        void Show(){cout<<"MUlti Core A"<<endl;}

};
class MultiCoreB:public MultiCore
{
    public:
       void Show(){cout<<"Multi Core B"<<endl;}
};
class CoreFactory{
    public:
      virtual SingleCore* CreatSingleCore()=0;
      virtual MultiCore* CreateMultiCore() = 0;
      virtual ~CoreFactory(){};
};
class FactoryA:public CoreFactory
{
  public:
      SingleCore* CreatSingleCore(){return new SingleCoreA();}
      MultiCore* CreateMultiCore(){return new MultiCoreA();}
};
class FactoryB:public CoreFactory
{
    public:
      SingleCore* CreatSingleCore(){return new SingleCoreB();}
      MultiCore* CreateMultiCore(){return new MultiCoreB();}
};
int main(int argc, char const *argv[])
{
     FactoryA* FactoryAll = new FactoryA;
     SingleCore*SA = FactoryAll->CreatSingleCore();
     SA->show();
     return 0;
}
