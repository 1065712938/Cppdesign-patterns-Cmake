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
class Factory{
    public:
      virtual SingleCore* CreatSingleCore()=0;
      virtual ~Factory(){};
};
class FactoryA:public Factory
{
   public:
       SingleCoreA* CreatSingleCore(){return new SingleCoreA;}
};
class FactoryB:public Factory
{
    public:
      SingleCoreB* CreatSingleCore(){return new SingleCoreB;}
};
int main(int argc, char const *argv[])
{
     FactoryA* FactoryAll = new FactoryA;
     SingleCoreA*SA = FactoryAll->CreatSingleCore();
     SA->show();
     return 0;
}
