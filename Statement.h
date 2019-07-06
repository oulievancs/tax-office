/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Statement.h
 * Author: oulis
 *
 * Created on 11 Ιουνίου 2017, 4:16 μμ
 */
#include <string>
#include <vector>
#include "Thing.h"
using namespace std;
#ifndef STATEMENT_H
#define STATEMENT_H
class Statement {
private: 
        string Name;
        string Address;
        string Afm;
        int Yearb;
        float Count;
        bool valid;

protected:
        vector<Thing *> things;     //vector that saves pointer of Thing <Thing *>

public:
        Statement();
        Statement(string name,string address,string afm,int year);
        ~Statement();
        void insertBuilding(ifstream &F);
        void calculation();
        float getCount() const;
        bool operator == (Statement &st) const;
        bool operator > (Statement &st) const;
        void display() const;
        void displ() const;
        void cancelState();
        bool state() const;
        void insertBuilding(ofstream &F);
        bool deleteOwnership(Thing &th);
        void displa(int &c) const;
        void display(ofstream &f) const;
};
        


#endif /* STATEMENT_H */