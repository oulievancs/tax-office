/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Home.h
 * Author: oulis
 *
 * Created on 11 Ιουνίου 2017, 4:11 μμ
 */
#include <string>
#include "Thing.h"
using namespace std;

#ifndef HOME_H
#define HOME_H
class Home : public Thing {
    private: 
        int Floor;
        int TypeOfBuilding;
    public:
        Home();
        Home(string type,string address,float sureface,int year,int typeofbuilding,int floor);
        ~Home();
        void countEnfia();
        void display() const;
        void display(ofstream &f) const;
        bool operator == (Home &h) const;
        
};


#endif /* HOME_H */

