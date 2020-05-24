/*
     说明
//增加新的核类型时，就需要修改工厂类。这就违反了开放封闭原则
//https://blog.csdn.net/wuzhekai1985/article/details/6660462

*/
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
class Factor
{
    public:
       SingleCore* CreateSigleCore(enum CTYPE ctype)
       {
           if(ctype == COREA)
             return new SingleCoreA();
           else if(ctype == COREB)
             return new SingleCoreB();
            else return NULL;
       }
};
int main(int argc, char const *argv[])
{
      Factor*f = new Factor;
      SingleCore* SA = f->CreateSigleCore(COREA);
      SA->show();
      delete f;
      delete SA;
     return 0;
}
