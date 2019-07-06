/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Shop.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Shop::Shop()
{
        Type = "Shop";
        Address = "N/A";
        Sureface = 0;
        Year = 0;
        Commersiality = 0;
        Enfia = 0;
}

Shop::Shop(string type, string address, float sureface, int year, int commersiality)
{
        Type=type;
        Address=address;
        Sureface=sureface;
        Year=year;
        Commersiality=commersiality;
        Enfia=0;
}

Shop::~Shop(){	};

void Shop::countEnfia()
{
        Enfia = (float) 2*Sureface+200*Commersiality;
        cout<<"-----------------------------"<<endl;
        cout<<"#Shop Enfia counted: "<<Enfia<<"$"<<endl;
        cout<<"-----------------------------"<<endl;
}

void Shop::display() const
{
        cout<<"===================================="<<endl;
        cout<<"----------Ownership(Shop)-----------"<<endl;
        cout<<"Type: "<<Type<<endl;
        cout<<"Address: "<<Address<<endl;
        cout<<"Sureface: "<<Sureface<<endl;
        cout<<"Year: "<<Year<<endl;
        cout<<"Commersiality: "<<Commersiality<<endl;
        cout<<"Enfia: "<<Enfia<<"$"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"==================================="<<endl;
}

void Shop::display(ofstream &f)const
{
        f<<"-----------Ownership(Shop)-----------"<<endl;
        f<<"Type: "<<Type<<endl;
        f<<"Address: "<<Address<<endl;
        f<<"Sureface: "<<Sureface<<endl;
        f<<"Year: "<<Year<<endl;
        f<<"Commersiality: "<<Commersiality<<endl;
        f<<"Enfia: "<<Enfia<<"$"<<endl;
        f<<"-------------------------------------"<<endl;
}


bool Shop::operator == (Shop &h) const
{
        bool found = false;
        if (Type == h.Type && Address == h.Address && Sureface == h.Sureface && Year == h.Year && Commersiality == h.Commersiality)
                found = true;
        return found;
}