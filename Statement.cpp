/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Statement.h"
#include "Thing.h"
#include "Shop.h"
#include "Plot.h"
#include "Home.h"
#include "MyExc.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

Statement::Statement()
{
    Name = "N/A";
    Address = "N/A";
    Afm = "N/A";
    Yearb = 0;
    Count = 0;
    valid = false;
}

Statement::Statement(string name, string address, string afm, int year)
{
    Name=name;
    Address=address;
    Afm=afm;
    Yearb=year;
    Count = 0;
    valid = true;
}

Statement::~Statement(){
    for (int i=0; i<things.size(); i++)
    {
        things.erase(things.begin()+i);
    }
}

void Statement::insertBuilding(ifstream &F)
{
    Thing *ptr;
    string type,address;
    int year;
    float sureface;

    getline(F, type,'|');

    getline(F, address, '|');

    F>>sureface;
    F.ignore(1, '|');

    F>>year;
    F.ignore(1, '|');

    if((type.compare("E")) == 0)
    {
            int commersiality;
            F>>commersiality;

            if (commersiality<0 || commersiality>10)
                    throw MyExc(3478, "Commersiality reference is not accepted!");

            
            things.push_back(new Shop(type,address,sureface,year,commersiality));
            
            ptr = things.back();
            ptr ->countEnfia();
            ptr->display();
            F.ignore(1, '\n');
    }
    else if((type.compare("O")) == 0)
    {
            int ffc;	//far from city
            F>>ffc;
            F.ignore(1, '|');
            if (ffc!=1 && ffc!=0)
            {
                    throw MyExc(1002, "Far From City reference is no accepted!\nAt 5th column must be 0/1!");
            }
            int cultivation;
            F>>cultivation;		//if kaliergritai~1 else ~0

            if (cultivation!=1 && cultivation!=0)
            {
                    throw MyExc(1032, "Cultivation reference is not accepted!\nAt 6th column must be 0/1!");
            }
            
            things.push_back(new Plot(type,address,sureface,year,ffc,cultivation));
            
            ptr = things.back();
            ptr ->countEnfia();
            ptr->display();
            F.ignore(1, '\n');
    }
    else if((type.compare("K")) == 0)
    {
            int floor;
            F>>floor;
            F.ignore(1, '|');

            if (floor > 15)
            {
                    throw MyExc(1044, "Floor reference at 6th column is big!\nFloors value is big for Greece's buylding");
            }
            
            int bof;
            F>>bof;		//block of floors

            if (bof!=0 && bof!=1)
            {
                    throw MyExc(1054, "Block of floors reference is not right!\nAt 5th column must be 0/1!");
            }

            
            things.push_back(new Home(type,address,sureface,year,bof,floor));
            
            ptr = things.back();
            ptr ->countEnfia();
            ptr ->display();
            F.ignore(1, '\n');
    }
    else if ( !F.eof() )
    {
            throw MyExc(3567, "Software does not support UTF-8 format!\nOr type of ownership is not valid!\nPlease try with lattin charachters (K, O, E)!");
    }
}

void Statement::calculation()
{
    float count=0;
    Thing *ptr;
    for(int i=0; i<things.size(); i++)
    {
        ptr = things[i];
        string t = ptr->getType();
        float e = ptr->getEnfia();
            if(t.compare("K") == 0 || t.compare("E") == 0 || t.compare("O") == 0)
            {
                    count=count+e;
            }
    }
    Count = count;

    cout<<"------------------------------------"<<endl;
    cout<<"#Number of ownerships: "<<things.size()<<endl;
    cout<<"#All enfia Counted: "<<count<<"$"<<endl;
    cout<<"------------------------------------"<<endl;
}

float Statement::getCount() const
{
    return Count;
}

bool Statement::operator == (Statement &st) const
{
    bool found = false;
    if (Afm == st.Afm && Name == st.Name && Yearb == st.Yearb && Address == st.Address)
            found = true;
    return found;
}

bool Statement::operator > (Statement &st) const
{
    bool found = false;
    if (Count > st.Count)
            found = true;
    return found;
}

void Statement::display() const
{
    cout<<"#########################################"<<endl;
    cout<<"-----------------STATEMENT---------------"<<endl;
    cout<<"Name: "<<Name<<endl;
    cout<<"Address: "<<Address<<endl;
    cout<<"Afm: "<<Afm<<endl;
    cout<<"Birthday: "<<Yearb<<endl;
    cout<<"Count: "<<Count<<endl;
    if (valid)
        cout<<"Statement is Valid!"<<endl;
    else
        cout<<"Statement is not Valid!"<<endl;
    for (int i=0; i<things.size(); i++)
    {
            things[i]->display();
    }
    cout<<"#########################################"<<endl;
}

void Statement::displ() const
{
    cout<<"########################################"<<endl;
    cout<<"----------------STATEMENT---------------"<<endl;
    cout<<"Name: "<<Name<<endl;
    cout<<"Address: "<<Address<<endl;
    cout<<"Afm: "<<Afm<<endl;
    cout<<"Birthday: "<<Yearb<<endl;
    cout<<"Count: "<<Count<<endl;
    if (valid)
        cout<<"Statement is Valid!"<<endl;
    else
        cout<<"Statement is not Valid!"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"########################################"<<endl;
}

void Statement::cancelState()
{
    valid = false;
}

bool Statement::state() const
{
    return valid;
}

void Statement::insertBuilding(ofstream &F)
{
    Thing *ptr;
    string type, address;
    int year;
    float sureface;

    cout<<"Give type of:\t";
    getline(cin, type);

    cout<<"Give the address:\t";
    getline(cin, address);

    cout<<"Give the sureface:\t";
    cin>>sureface;
    
    while ( !cin.good() )
    {
            cin.clear();
            cout<<"Incorect Input!"<<endl;
            cout<<"Give again:\t";

            cin.ignore(100, '\n');
            cin >> sureface;
    }

    if (sureface <=0 )
            throw MyExc(9503, "Sureface of building must me grater than 0!");

    cout<<"Give the year that ownership has been issued:\t";
    cin>>year;
    
    while ( !cin.good() )
    {
            cin.clear();
            cout<<"Incorect Input!"<<endl;
            cout<<"Give again:\t";

            cin.ignore(100, '\n');
            cin >> year;
    }

    if (year < 1800)
            throw MyExc(7549, "Year was not accepted!");

    if((type.compare("E")) == 0)
    {
            int commersiality;
            cout<<"Give the commersiality: (0-10)\t";
            cin>>commersiality;
            
            while ( !cin.good() )
            {
                    cin.clear();
                    cout<<"Incorect Input!"<<endl;
                    cout<<"Give again:\t";

                    cin.ignore(100, '\n');
                    cin >> commersiality;
            }

            if (commersiality<0 || commersiality>10)
                    throw MyExc(3478, "Commersiality reference is not accepted!");

            things.push_back(new Shop(type,address,sureface,year,commersiality));
            
            ptr = things.back();
            ptr ->countEnfia();
            ptr ->display();
            
            F<<type<<"|"<<address<<"|"<<sureface<<"|"<<year<<"|"<<commersiality<<endl;
    }
    else if((type.compare("O")) == 0)
    {
            int ffc;	//far from city
            cout<<"If is far from city: (0-1)\t";
            cin>>ffc;
            
            while ( !cin.good() )
            {
                    cin.clear();
                    cout<<"Incorect Input!"<<endl;
                    cout<<"Give again:\t";

                    cin.ignore(100, '\n');
                    cin >> ffc;
            }

            if (ffc!=1 && ffc!=0)
            {
                    throw MyExc(1002, "Far From City reference is no accepted!");
            }
            int cultivation;
            cout<<"If is cultivated: (0-1)\t";
            cin>>cultivation;		//if kaliergritai~1 else ~0
            
            while ( !cin.good() )
            {
                    cin.clear();
                    cout<<"Incorect Input!"<<endl;
                    cout<<"Give again:\t";

                    cin.ignore(100, '\n');
                    cin >> cultivation;
            }

            if (cultivation!=1 && cultivation!=0)
            {
                    throw MyExc(1032, "Cultivation reference is not accepted!");
            }
            
            things.push_back(new Plot(type,address,sureface,year,ffc,cultivation));
            
            ptr = things.back();
            ptr ->countEnfia();
            ptr->display();
            
            F<<type<<"|"<<address<<"|"<<sureface<<"|"<<year<<"|"<<ffc<<"|"<<cultivation<<endl;
    }
    else if((type.compare("K")) == 0)
    {
            int floor;
            int bof;
            cout<<"Give the number of floor: (<15)\t";
            cin>>floor;		//block of floors
            
            while ( !cin.good() )
            {
                    cin.clear();
                    cout<<"Incorect Input!"<<endl;
                    cout<<"Give again:\t";

                    cin.ignore(100, '\n');
                    cin >> floor;
            }

            if (floor > 15)
            {
                    throw MyExc(1044, "Floor reference at 5th column is big!\nFloors value is big for Greece's buylding");
            }

            cout<<"Give if it's block of flats or not. (1 or 0):\t";
            cin>>bof;
            
            while ( !cin.good() )
            {
                    cin.clear();
                    cout<<"Incorect Input!"<<endl;
                    cout<<"Give again:\t";

                    cin.ignore(100, '\n');
                    cin >> bof;
            }

            if (bof!=0 && bof!=1)
            {
                    throw MyExc(1054, "Block of floors reference is not right!\nAt 6th column must be 0/1!");
            }
            things.push_back(new Home(type,address,sureface,year,bof,floor));
            
            ptr = things.back();
            ptr ->countEnfia();
            ptr ->display();
            
            F<<type<<"|"<<address<<"|"<<sureface<<"|"<<year<<"|"<<floor<<"|"<<bof<<endl;
    }
    else
    {
            throw MyExc(3567, "Type of ownership is not valid!\nPlease try with lattin charachters (K, E, O)!");
    }
}

bool Statement::deleteOwnership(Thing &th)
{
    bool erased = false;
    Thing *ptr;
    for (int j=0; j<things.size() && !erased; j++)
    {
        ptr = things[j];
            if (*ptr == (th))
            {
                    things.erase (things.begin()+j);
                    cout<<"------------Thing(Erased)------------"<<endl;
                    ptr->display();
                    erased = true;
            }
    }
    return erased;
}

void Statement::displa(int &c) const
{
    if (!valid)
    {
            cout<<"Statement is not valid!"<<endl;
    }
    if (things.size() == 0)
    {
            cout<<"-------Owner have not ownerships-------"<<endl;
            cout<<"#######################################"<<endl;
    }
    for (int j=0; j<things.size(); j++)
    {
            things[j]->display();
            c++;
    }
}

void Statement::display(ofstream &f) const
{
    f<<"#########################################"<<endl;
    f<<"-----------------STATEMENT---------------"<<endl;
    f<<"Name: "<<Name<<endl;
    f<<"Address: "<<Address<<endl;
    f<<"Afm: "<<Afm<<endl;
    f<<"Birthday: "<<Yearb<<endl;
    f<<"Count: "<<Count<<"$"<<endl;
    if (valid)
        f<<"Statement is Valid!"<<endl;
    else
        f<<"Statement is not Valid!"<<endl;
    f<<"-----------------------------------------"<<endl;

    if (things.size() == 0)
    {
            f<<"--------------0 Ownerships---------------"<<endl;
    }
    else
    {
            for (int i=0; i<things.size(); i++)
            {
                    things[i]->display(f);
            }
    }
    f<<"#########################################"<<endl;
}