/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shop.h
 * Author: oulis
 *
 * Created on 11 Ιουνίου 2017, 4:01 μμ
 */
#include <string>
#include "Thing.h"
using namespace std;
#ifndef SHOP_H
#define SHOP_H
class Shop : public Thing {
    private: 
        int Commersiality;
    public:
        Shop();
        Shop(string type,string address,float sureface,int year,int commersiality);
        ~Shop();
        void countEnfia();
        void display() const;
        void display(ofstream &f) const;
        bool operator == (Shop &h) const;
};


#endif /* SHOP_H */

