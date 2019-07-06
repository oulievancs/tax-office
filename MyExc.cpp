/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "MyExc.h"
#include <string>
#include <iostream>
using namespace std;
MyExc::MyExc()
{
        err_cod = 0;
        err_descr = "N/A";
}

MyExc::MyExc(int code, string desc)
{
        err_cod = code;
        err_descr = desc;
}
MyExc::~MyExc() throw () {	};

void MyExc::what()
{
        cout<<"*************ERROR*************"<<endl;
        cout<<"Error Code: "<<err_cod<<endl;
        cout<<"Error Description: "<<err_descr<<endl;
        cout<<"*******************************"<<endl;
}