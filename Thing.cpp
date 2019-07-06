/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Thing.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string Thing::getType() const
{
    return Type;
}

float Thing::getEnfia() const
{
    return Enfia;
}

bool Thing::operator == (Thing &h) const
{
        bool found = false;
        if (Type == h.Type && Address == h.Address && Sureface == h.Sureface && Year == h.Year)
                found = true;
        return found;
}