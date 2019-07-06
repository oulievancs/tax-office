/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Home.h"
#include "Thing.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Home::Home()
{
    Type = "home";
    Address = "N/A";
    Sureface = 0;
    Year = 0;
    TypeOfBuilding = 0;
    Floor = 0;
}

Home::Home(string type, string address, float sureface, int year, int typeofbuilding, int floor)
{
    Type=type;
    Address=address;
    Sureface=sureface;
    Year=year;
    TypeOfBuilding=typeofbuilding;
    Floor=floor;
    Enfia=0;
}
Home::~Home(){	};
void Home::countEnfia()
{
    if(TypeOfBuilding==0)
            Enfia = (float) 1.3*Sureface+150;
    else
            Enfia = (float) 1.1*Sureface+5*Floor+100;
    cout<<"-------------------------------"<<endl;
    cout<<"#Home Enfia counted: "<<Enfia<<"$"<<endl;
    cout<<"-------------------------------"<<endl;
}

void Home::display() const
{
    cout<<"======================================"<<endl;
    cout<<"-----------Ownership(Home)------------"<<endl;
    cout<<"Type: "<<Type<<endl;
    cout<<"Address: "<<Address<<endl;
    cout<<"Sureface: "<<Sureface<<endl;
    cout<<"Year: "<<Year<<endl;
    cout<<"Floor: "<<Floor<<endl;
    cout<<"TypeOfBulding: "<<TypeOfBuilding<<endl;
    cout<<"Enfia: "<<Enfia<<"$"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"======================================"<<endl;
}

void Home::display(ofstream &f) const
{
    f<<"-------------Ownership(Home)-------------"<<endl;
    f<<"Type: "<<Type<<endl;
    f<<"Address: "<<Address<<endl;
    f<<"Sureface: "<<Sureface<<endl;
    f<<"Year: "<<Year<<endl;
    f<<"Floor: "<<Floor<<endl;
    f<<"TypeOfBulding: "<<TypeOfBuilding<<endl;
    f<<"Enfia: "<<Enfia<<"$"<<endl;
    f<<"-----------------------------------------"<<endl;
}

bool Home::operator == (Home &h) const
{
    bool found = false;
    if (Type == h.Type && Address == h.Address && Sureface == h.Sureface && Year == h.Year && Floor == h.Floor && TypeOfBuilding == h.TypeOfBuilding)
            found = true;
    return found;
}