/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plot.h
 * Author: oulis
 *
 * Created on 11 Ιουνίου 2017, 4:05 μμ
 */
#include <string>
#include "Thing.h"
using namespace std;
#ifndef PLOT_H
#define PLOT_H
class Plot : public Thing {
    private: 
        int FarFromCity;
        int Cultivation;
    public:
        Plot();
        Plot(string type,string address,float sureface,int year,int farfromcity,int cultivation);
        ~Plot();
        void countEnfia();
        void display() const;
        void display(ofstream &f) const;
        bool operator == (Plot &h) const;
        
};


#endif /* PLOT_H */

