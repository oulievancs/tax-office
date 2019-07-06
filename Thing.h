/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Thing.h
 * Author: oulis
 *
 * Created on 11 Ιουνίου 2017, 3:53 μμ
 */
#include <string>
using namespace std;

#ifndef THING_H
#define THING_H
class Thing {
    protected:
        string Type;
        string Address;
        float Sureface;
        int Year;
        float Enfia;
    public:
        virtual void countEnfia() = 0;
        virtual void display() const = 0;
        virtual void display(ofstream &f) const = 0;
        string getType() const;
        float getEnfia() const;
        virtual bool operator == (Thing &h) const;
    
};


#endif /* THING_H */

