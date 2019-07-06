/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.cpp
 * Author: oulis
 *
 * Created on 11 Ιουνίου 2017, 4:26 μμ
 */

#include <cstdlib>
#include "MyExc.h"
#include "Thing.h"
#include "Home.h"
#include "Plot.h"
#include "Shop.h"
#include "Statement.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 
 */
void checkFile (vector<string> &f, string &fname)
{
	for (int i=0; i<f.size(); i++)
	{
		if (f[i].compare(fname) == 0)
			throw MyExc(1975, "File has already metioned!");
	}
}

void checkFile1 (vector<string> &f, string &name)
{
	if (f.size() == 0)
		throw MyExc(4783, "No statement has metioned!");
	for (int i=0; i<f.size(); i++)
	{
		if (!(f[i].compare(name) == 0))
			throw MyExc(1976, "File has not metioned!\nPlese first metion a file at statement and then add ownership at statement!");
	}
}

void createStatement(vector<string> &files, vector<Statement> &ste)
{
    ifstream fn;
    try{
	
	string ep,filename;
	cout<<"For Exit Press exit else <enter>: ";
	getline(cin, ep);
	if (ep.compare("exit") == 0 || ep.compare("e") == 0)
		return;
		
	Statement *state_ptr;
	string address,afm,name;
	int yearb;
	
	cout<<"Give your name:\t";
	getline(cin, name);
	
	cout<<"Give primary address:\t";
	getline(cin, address);
	
	cout<<"Give your afm:\t";
	getline(cin, afm);
        
	filename = afm + ".txt";
	checkFile(files, filename);	//method that checks if file has metioned.
	
	string str = "000000000";
	if (afm.length() != str.length())
		throw MyExc(1376, "AFM number is not valid!\nPlese enter a number that is 9digits!");
	
	cout<<"Give birthday year:\t";
	cin>>yearb;
	
        while ( !cin.good() )
        {
                cin.clear();
                cout<<"Incorect Input!"<<endl;
                cout<<"Give again:\t";

                cin.ignore(100, '\n');
                cin >> yearb;
        }
	
	if (yearb<1900 || yearb>1999)
		throw MyExc(5004, "Year of birth was out of limits!");
	
	Statement s1;
	s1 = Statement(name,address,afm,yearb);
	state_ptr = &s1;
        
	fn.open(filename.c_str());
        
	if(!fn.is_open())
		throw MyExc(1065, "File does not open with success!");
        
	while ( !fn.eof() )
	{
		state_ptr->insertBuilding(fn);
	}
	
	state_ptr->calculation();
	ste.push_back(*state_ptr);
	files.push_back(filename);
        
        fn.close();
    }
    catch (MyExc e)
    {
        if (fn.is_open())
        {
            fn.close();
            cout<<"File stream closed after exception explosed!"<<endl;
        }
        throw e;
    }
}


void deleteStatement (vector<Statement> &ste)
{
	if (ste.size()==0)
		throw MyExc(2367, "Empty Vector");
		
	string ep;
	cout<<"For Exit Press exit else <enter>:\t";
	getline(cin, ep);
	if (ep.compare("exit") == 0 || ep.compare("e") == 0)
		return;
	
	Statement s;
	string name, address, afm;
	int year;
	
	cout<<"Give name:\t";
	getline(cin, name);
					
	cout<<"Give primary address:\t";
	getline(cin, address);
					
	cout<<"Give afm:\t";
	getline(cin, afm);
	
	string str = "000000000";
	if (afm.length() != str.length())
		throw MyExc(1376, "AFM number is not valid!\nPlese enter a number that is 9digits!");
					
	cout<<"Give birthday:\t";
	cin>>year;
	
        while ( !cin.good() )
        {
                cin.clear();
                cout<<"Incorect Input!"<<endl;
                cout<<"Give again:\t";

                cin.ignore(100, '\n');
                cin >> year;
        }
	
	if (year<1900 || year>1999)
		throw MyExc(5004, "Year of birth was out of limits!");
	
	s = Statement(name, address, afm, year);
        Statement *s_ptr;
        bool ok = false;
	for (int i=0; i<ste.size(); i++)
	{
            s_ptr = &ste[i];
		if (*s_ptr == s && s_ptr->state())
		{
			s_ptr->cancelState();
			cout<<"!!!!!Statement canceled!!!!!!"<<endl;
                        ok = true;
		}
	}
        
        if (!ok)
            throw MyExc(3428, "Statement does not fount to disable!");
}

void deleteOwntership (vector<Statement> &ste)
{
	if (ste.size()==0)
		throw MyExc(2367, "Empty Vector");
		
	string ep;
	cout<<"For Exit Press exit else <enter>:\t";
	getline(cin, ep);
	if (ep.compare("exit") == 0 || ep.compare("e") == 0)
		return;
	
	Statement s;
	string name, address, afm;
	int year;
	
	cout<<"Give name:\t";
	getline(cin, name);
					
	cout<<"Give primary address:\t";
	getline(cin, address);
					
	cout<<"Give afm:\t";
	getline(cin, afm);
	
	string str = "000000000";
	if (afm.length() != str.length())
		throw MyExc(1376, "AFM number is not valid!\nPlese enter a number that is 9digits!");
					
	cout<<"Give birthday:\t";
	cin>>year;
        
        while ( !cin.good() )
        {
                cin.clear();
                cout<<"Incorect Input!"<<endl;
                cout<<"Give again:\t";

                cin.ignore(100, '\n');
                cin >> year;
        }
        
        
	cin.ignore(1, '\n');
	
	if (year<1900 || year>1999)
		throw MyExc(5004, "Year of birth was out of limits!");
	
	s = Statement(name, address, afm, year);
	Statement *s_ptr;
	for (int i=0; i<ste.size(); i++)
	{
            s_ptr = &ste[i];
		if (*s_ptr == s && s_ptr->state())
		{
			s_ptr->display();
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
				
				ptr = new Shop(type,address,sureface,year,commersiality);
			}
			else if((type.compare("O")) == 0)
			{
				int ffc;	//far from city
				cout<<"If is far from sity: (0-1)";
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
				cout<<"If is cultivated: (0-1):\t";
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
				ptr = new Plot(type,address,sureface,year,ffc,cultivation);
			}
			else if((type.compare("K")) == 0)
			{
				int floor;
				int bof;
				cout<<"Give the number of floor: (>15)\t";
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
				
				ptr = new Home(type,address,sureface,year,bof,floor);
			}
			else
			{
				throw MyExc(3567, "Type of ownership is not valid!\nPlease try with lattin charachters");
			}
			
			bool ok = s_ptr -> deleteOwnership(*ptr);
			if (ok)
                        {
				cout<<"!!!!!!!Ownership deleted!!!!!!"<<endl;
                                s_ptr->calculation();
                        }
			else
				throw MyExc(5630, "Something went wrong and Ownrship not deleted!");
		}
                else if (*s_ptr == s && !s_ptr->state())
                    throw MyExc(2649, "You can not edit the Statement\nBecause is not in Valid!");
	}
}
			

void showAll (vector<Statement> &state)
{
	if (state.size()==0)
		throw MyExc(2367, "Empty Vector");
		
	Statement *ptr;
        int cn = 0;
	for (int i=0; i<state.size(); i++)
	{
		ptr = &state[i];
		if (ptr->state())
		{
			ptr->display();
                        cn++;
		}
	}
        if (cn == 0)
            throw MyExc(4290, "No Statements in Force!");
}

void printAll (vector<Statement> &state, ofstream &file)
{
	if (state.size()==0)
		throw MyExc(2367, "Empty Vector");
		
	string ep;
	cout<<"For Exit Press (e)xit else <enter>:\t";
	getline(cin, ep);
	if (ep.compare("exit") == 0 || ep.compare("e") == 0)
		return;
		
	if (!file.is_open())
		throw MyExc(4534, "File for output stream did not open!");
        
	Statement *s_ptr;
	for (int i=0; i<state.size(); i++)
	{
		s_ptr = &state[i];
		s_ptr->display(file);
	}
	cout<<"Proccess ends!\nFile whrote"<<endl;
}

void showDisabled (vector<Statement> &state)
{
	if (state.size()==0)
		throw MyExc(2367, "Empty Vector");
		
	Statement *ptr;
        int cn = 0;
	for (int i=0; i<state.size(); i++)
	{
		ptr = &state[i];
		if (!ptr->state())
                {
			ptr->display();
                        cn++;
                }
	}
        if (cn == 0)
            throw MyExc(1207, "No Disabled Dtatements!");
}

void showOwnerships (vector<Statement> &state, int x)
{
	if (state.size()==0)
		throw MyExc(2367, "Empty Vector");
		
	int count = 0;
        Statement *ptr;
	for (int i=0; i<state.size(); i++)
	{
		ptr = &state[i];
                if (ptr->state())
                {
                    ptr->displ();

                    ptr->displa(count);
                }
	}
	cout<<"Found "<<count<<" ownerships that Emfia is >"<<x<<endl;
	cout<<"----------------------------------------------------"<<endl;
}

void showStatements (vector<Statement> &sta, int x)
{
	if (sta.size()==0)
		throw MyExc(2367, "Empty Vector");
		
	int count = 0;
	float enf;
        Statement *ptr;
	for (int i=0; i<sta.size(); i++)
	{
		ptr = &sta[i];
                if (ptr->state())
                {
                    enf = ptr->getCount();
                    if (enf > x)
                    {
                            ptr->displ();
                            count++;
                    }
                }
	}
	cout<<"Found "<<count<<" statements that Emfia is >"<<x<<endl;
	cout<<"--------------------------------------------"<<endl;
}


Statement *MaxEnfia (vector<Statement> &sta)
{
	if (sta.size()==0)
		throw MyExc(2367, "Empty Vector");
	
	Statement *max, *ptr;
	ptr = &sta[0];
	max = ptr;
	for (int i=1; i<sta.size(); i++)
	{
		ptr = &sta[i];
		if (ptr->getCount() > max->getCount() && ptr->state())
		{
			max = ptr;
		}
	}
        if (!max->state())
            throw MyExc(4390, "The Only statement that there is, is Not Valid");
	return max;
}

		

void insertOwnership (vector<Statement> &sta, vector<string> &files)
{
    ofstream fn;
    try{
	if (sta.size()==0)
		throw MyExc(2367, "Empty Vector");
	
	string ep,filename;
        
	cout<<"For Exit Press (e)xit else <enter>:\t";
	getline(cin, ep);
	if (ep.compare("exit") == 0 || ep.compare("e") == 0)
		return;
	
	Statement s, *ptr;
	string name, address, afm;
	int year;
	
	cout<<"Give name:\t";
	getline(cin, name);
					
	cout<<"Give primary address:\t";
	getline(cin, address);
					
	cout<<"Give afm:\t";
	getline(cin, afm);
	filename = afm + ".txt";
	
	string str = "000000000";
	if (afm.length() != str.length())
		throw MyExc(1376, "AFM number is not valid!\nPlese enter a number that is 9digits!");
        
        checkFile1(files, filename);    //check if file has not metioned in a statement
					
	cout<<"Give birthday:\t";
	cin>>year;
	
        while ( !cin.good() )
        {
                cin.clear();
                cout<<"Incorect Input!"<<endl;
                cout<<"Give again:\t";

                cin.ignore(100, '\n');
                cin >> year;
        }
        
        cin.ignore(1, '\n');

	if (year<1900 || year>1999)
		throw MyExc(5004, "Year of birth was out of limits!");
	
	s = Statement(name, address, afm, year);
	
	bool found = false;
	
        
	fn.open(filename.c_str(), ios_base::app);   //file operation to append the new ownership
	if (!fn.is_open())
		throw MyExc(4534, "File for output stream did not open!");
        bool inValid;
	
	for (int i=0; i<sta.size() && !found; i++)
	{
		ptr = &sta[i];
		if (*ptr == s && ptr->state())
		{
			found = true;
			ptr->insertBuilding(fn);
                        ptr->calculation();
                        inValid = false;
		}
                else if(*ptr == s && !ptr->state())
                {
                    inValid = true;
                }
	}
        fn.close();
	if (!found)
		throw MyExc(3208, "Statement not found Or out of order!");
	if (inValid)
            throw MyExc(4398, "Statement is not Avalable!");
    }
    catch (MyExc e)
    {
        if (fn.is_open())
        {
            fn.close();
            cout<<"File stream closed after exception excplotion"<<endl;
        }
        throw e;
    }
}

void tenMaxs (vector<Statement> &sta)
{
	if (sta.size()==0)
		throw MyExc(2367, "Empty Vector");
		
	int cn=0;
	Statement *ptr, *ptr1;
	for(int i=0; i<sta.size(); i++)
	{
		ptr = &sta[i];
		if(ptr->state())
		{
			cn++;
		}
	}
	if(cn<10)
	{
		for (int i=0; i<sta.size(); i++)
		{
			ptr = &sta[i];
			if(ptr->state())
			{
				ptr->displ();
			}
		}
	}
	else
	{
		for (int i=0; i<sta.size(); i++)
		{
			for (int j=0; j<i; j++)
			{
				ptr = &sta[j+1];
				ptr1 = &sta[j];
				if(*ptr>*ptr1)
				{
					Statement temp;
					temp=*ptr1;
					*ptr1=*ptr;
					*ptr=temp;
				}
			}
		}
		int cn1=0;
		for(int i=0; i<10+cn1; i++)
		{
			ptr = &sta[i];
			if(ptr->state())
			{
				ptr->displ();
			}
			else
			{
				cn1++;
			}
		}						
	}
	cout<<cn<<" max statements was found!"<<endl;
	cout<<"-----------------------------------"<<endl;
}


void freeMemory(vector<Statement> &ste, vector<string> &f)
{
    for (int j=0; j<ste.size(); j++)
    {
        ste.erase(ste.begin()+j);
    }
    
    for (int j=0; j<f.size(); j++)
    {
        f.erase(f.begin()+j);
    }
}


int main()
{
	vector<Statement> ste;
	vector<string> files;
	Statement *s;
	int ep;
	do{
		try{	
			string filename;
			int y;		
			ifstream fn;
			ofstream fnn;
			cout<<"----Main Menu----\n1. Insert a statement\n2. Delete a statement\n3. Insert ownership in a statement\n4. Delete ownership from a statement\n5. More......\n0. exit"<<endl;
			cout<<"Option:\t";
			cin>>ep;
			cin.ignore(1, '\n');
			system("clear");
			switch(ep)
			{
				case 1:
					createStatement(files, ste);	//fn: infile Stream ste: vector<Statement>!(by reference)
				break;
				
				case 2:
					deleteStatement(ste);		//-||-
				break;
				
				case 3:
					insertOwnership(ste, files);
				break;
				
				case 4:
					deleteOwntership(ste);
				break;
				
				case 5:
					do{
						cout<<"1. Show all statements\n2. Show 10 highest statements\n3. Show statements than Enfia of them is > from an integer\n4. Show ownerships that Enfia of them is > from an integer\n5. Find Max Of Statement\n6. Show disabled statements\n7. Extract to a .txt file\n8. Back"<<endl;
						cout<<"Option:\t";
						cin>>ep;
						cin.ignore(1, '\n');
						system("clear");
						switch(ep)
						{
							case 1:
								showAll(ste);
							break;
						
							case 2:
								tenMaxs(ste);
							break;
						
							case 3:
								cout<<"Give a number:($) ";
								cin>>y;
								
                                                                while ( !cin.good() )
                                                                {
                                                                        cin.clear();
                                                                        cout<<"Incorect Input!"<<endl;
                                                                        cout<<"Give again:\t";

                                                                        cin.ignore(100, '\n');
                                                                        cin >> y;
                                                                }
                                                                
								showStatements(ste, y);
							break;
							
							case 4:
								cout<<"Give a number:($) ";
								cin>>y;
								
                                                                while ( !cin.good() )
                                                                {
                                                                        cin.clear();
                                                                        cout<<"Incorect Input!"<<endl;
                                                                        cout<<"Give again:\t";

                                                                        cin.ignore(100, '\n');
                                                                        cin >> y;
                                                                }
                                                                
								showOwnerships(ste, y);
							break;
						
							case 5:
								s = MaxEnfia(ste);
								s->display();
							break;
						
							case 6:
								showDisabled(ste);
							break;
							
							case 7:
								cout<<"Give filename:\t";
								cin>>filename;
								cin.ignore(1, '\n');
								checkFile(files, filename);
								fnn.open(filename.c_str());
								printAll(ste, fnn);
								fnn.close();
							break;
							
							case 8:
								cout<<"<-OK!"<<endl;
							break;
							
							case 0:
								cout<<"Press 8 to go back!"<<endl;
							break;
							
							default:
								cout<<"False selection!"<<endl;
							break;
						}
					}while (ep!=8);
				break;
				
				case 0:
					cout<<"--------BYE---------"<<endl;
				break;
				default:
					throw MyExc(3067, "False selection!\nPlease try again!");
				break;
			}
		}
		catch (MyExc e)
		{
			e.what();
		}
	}while (ep!=0);
        
        freeMemory(ste, files);
	
	return 0;
}
