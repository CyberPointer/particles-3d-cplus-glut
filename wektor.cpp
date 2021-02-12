#include "Wektor.hpp"
#include <math.h>
#include <iostream>

using namespace std;

Wektor::Wektor(){
    x = 0.0;
    y = 0.0;
    z = 0.0;

}

Wektor::Wektor(GLdouble tx,GLdouble ty,GLdouble tz){
    x = tx;
    y = ty;
    z = tz;

}



GLdouble Wektor::OUT_x(){
    return x;
}

GLdouble Wektor::OUT_y(){
    return y;
}

GLdouble Wektor::OUT_z(){
    return z;
}





void Wektor::nowy(GLdouble tx,GLdouble ty,GLdouble tz){
    x = tx;
    y = ty;
    z = tz;

}

void Wektor::nowy(Wektor tW){
    x = tW.OUT_x();
    y = tW.OUT_y();
    z = tW.OUT_z();

}

void Wektor::nowyx ( GLdouble tx ){
    x = tx;
}

void Wektor::nowyy ( GLdouble ty){
    y = ty;
}

void Wektor::nowyz ( GLdouble tz){
    z = tz;
}

void Wektor::suma ( GLdouble tx,GLdouble ty,GLdouble tz ){
    x += tx;
    y += ty;
    z += tz;
}

void Wektor::suma (Wektor tW){
    x += tW.OUT_x();
    y += tW.OUT_y();
    z += tW.OUT_z();
}

void Wektor::sumax (GLdouble tx){
    x += tx;
}

void Wektor::sumay (GLdouble ty){
    y += ty;
}

void Wektor::sumaz (GLdouble tz){
    z += tz;
}

void Wektor::negacja(){
    x = -x;
    y = -y;
    z = -z;
}

void Wektor::negacjax(){
    x = -x;
}

void Wektor::negacjay(){
    y = -y;
}

void Wektor::negacjaz(){
    z = -z;
}

GLdouble Wektor::dlugosc(){
    GLdouble tskalar = 0.0;
    tskalar = sqrt((x*x)+(y*y)+(z*z) );
    return tskalar;
}

void Wektor::normalizacja(){
    GLdouble dzielnik = dlugosc();
    x = x/dzielnik;
    y = y/dzielnik;
    z = z/dzielnik;
}

void Wektor::iloczyn(GLdouble mnoznik){
    x = x * mnoznik;
    y = y * mnoznik;
    z = z * mnoznik;
}



Wektor Wektor::kopia(){
    Wektor tW(x,y,z);
    return tW;
}

void Wektor::wypiszDane(){
    cout<<"X: "<<x<<"\nY: "<<y<<"\nZ: "<<z<<"\nSkalar: "<<dlugosc()<<"\n";
}

bool Wektor::zaMalo(GLdouble min){
    GLdouble tx = x;
    GLdouble ty = y;
    GLdouble tz = z;
    if(x<0) { tx = -x; }
    if(y<0) { ty = -y; }
    if(z<0) { tz = -z; }
    if(tx<=min){
        if(ty<=min){
            if(tz<=min){return true;}
        }
    }
    return false;
}

GLdouble Wektor::iloczynSkalarny(Wektor tW){
    return (x*tW.OUT_x()+y*tW.OUT_y()+z*tW.OUT_z());
}

bool Wektor::wiecejMinusow(){
    if ( x < 0 ) {
        if ( y< 0 ) {
            return true;
        }
        if ( z < 0 ) {
            return true;
        }
    }

    if ( y < 0 ) {
        if ( x< 0 ) {
            return true;
        }
        if ( z < 0 ) {
            return true;
        }
    }

    return false;
}
