/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include <fstream>
#include <iostream>
#include "Plot.h"
using namespace std;

Plot::Plot()
{
        Type = "Plot";
        Address = "N/A";
        Sureface = 0;
        Year = 0;
        FarFromCity = 0;
        Cultivation = 0;
        Enfia = 0;
}

Plot::Plot(string type, string address, float sureface, int year, int farfromcity, int cultivation)
{
        Type=type;
        Address=address;
        Sureface=sureface;
        Year=year;
        FarFromCity=farfromcity;
        Cultivation=cultivation;
        Enfia=0;
}
Plot::~Plot(){};

void Plot::countEnfia()
{
        if(FarFromCity==1)
                Enfia = (float) 0.3*Sureface+70;
        else
                Enfia = (float) 0.3*Sureface+250;
        cout<<"--------------------------------"<<endl;
        cout<<"#Plot Enfia counted: "<<Enfia<<"$"<<endl;
        cout<<"--------------------------------"<<endl;

}

void Plot::display() const
{
        cout<<"==================================="<<endl;
        cout<<"---------Ownership(Plot)-----------"<<endl;
        cout<<"Type: "<<Type<<endl;
        cout<<"Address: "<<Address<<endl;
        cout<<"Sureface: "<<Sureface<<endl;
        cout<<"Year: "<<Year<<endl;
        cout<<"FarFromCity: "<<FarFromCity<<endl;
        cout<<"Cultivation: "<<Cultivation<<endl;
        cout<<"Enfia: "<<Enfia<<"$"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"==================================="<<endl;
}

void Plot::display(ofstream &f) const
{
        f<<"-----------Ownership(Plot)------------"<<endl;
        f<<"Type: "<<Type<<endl;
        f<<"Address: "<<Address<<endl;
        f<<"Sureface: "<<Sureface<<endl;
        f<<"Year: "<<Year<<endl;
        f<<"FarFromCity: "<<FarFromCity<<endl;
        f<<"Cultivation: "<<Cultivation<<endl;
        f<<"Enfia: "<<Enfia<<"$"<<endl;
        f<<"--------------------------------------"<<endl;
}


bool Plot::operator == (Plot &h) const
{
        bool found = false;
        if (Type == h.Type && Address == h.Address && Sureface == h.Sureface && Year == h.Year && FarFromCity == h.FarFromCity && Cultivation == h.Cultivation)
                found = true;
        return found;
}