/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyExc.h
 * Author: oulis
 *
 * Created on 11 Ιουνίου 2017, 3:25 μμ
 */
#include <exception>
#include <string>
using namespace std;

#ifndef MYEXC_H
#define MYEXC_H
class MyExc : public exception
{
    private:
        int err_cod;
        string err_descr;
    public:
        MyExc();
        MyExc(int code, string desc);
        virtual ~MyExc() throw ();
        void what();
};


#endif /* MYEXC_H */

