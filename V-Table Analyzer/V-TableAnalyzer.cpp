//V-TableAnalizer.cpp

using namespace std;

#include<iostream>

class Base
{
    public :
            int i,j;

            virtual void fun()                  //1000
            {
                cout<<"Base Fun"<<endl;
            }

            virtual void gun()                  //2000
            {
                cout<<"Base Gun"<<endl;
            }

            void sun()                          //3000
            {
                cout<<"Base Sun"<<endl;
            }
};

class Derived : public Base
{
    public :
            int x,y;

            void fun()                      //4000
            {
                cout<<"Derived Fun"<<endl;
            }

            void sun()                          //5000
            {
                cout<<"Derived Sun"<<endl;
            }

            virtual void run()                      //6000
            {
                cout<<"Derived Run"<<endl;
            }
           
};
int main()
{
    Base bobj;
    Derived dobj;

    cout<<"Total size of Base Class is :-\t "<<sizeof(bobj)<<endl;			//16
    cout<<"Total size of Derived Class is :-\t "<<sizeof(dobj)<<endl;				//24

    cout<<"Address Of Base Class is :-\t"<<&bobj<<endl;						//100
    cout<<"Address Of Derived Class is :-\t"<<&dobj<<endl;								//300

    cout<<endl;

    long int *op = (long int*)(&dobj);									//300
    cout<<"Base Address of dobj :-\t"<<op<<endl;									//300

    long int *VPTR = (long int*)(*op);								//400
    cout<<"Address of VTABLE :-\t"<<VPTR<<endl;								//400

    void (*fp)();

    fp = (void(*)())(*VPTR);										//400
    fp();											//Call : 400

    fp = (void(*)())(*VPTR);						//400
    fp();													//Call : 400

    fp = (void(*)())(*(VPTR+1));					//400 + 8  = 408
    fp();										// Call : 408

    fp = (void(*)())(*(VPTR+2));
    fp();
    
   	//fp = (void(*)())(*(VPTR+3));			//
   // fp();				

    return 0;
}
