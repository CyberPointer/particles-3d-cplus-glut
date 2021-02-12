#include "Kula_wektor.hpp"
#include <math.h>
#include <stdio.h>




Kula_wektor::Kula_wektor(){
  act_x = 0.0;
  act_y = 0.0;
  act_z = 0.0;

  dir_x = 0.0;
  dir_y = 0.0;
  dir_z = 0.0;
  radius = 0.0;

}

Kula_wektor::Kula_wektor(GLdouble x, GLdouble y,GLdouble z,GLdouble d_x,GLdouble d_y,GLdouble d_z, GLdouble rad){
    act_x = x;
    act_y = y;
    act_z = z;

    dir_x = d_x;
    dir_y = d_y;
    dir_z = d_z;
    radius = rad;

}

void Kula_wektor::negDirX(){
    dir_x = -dir_x;
}
void Kula_wektor::negDirY(){
    dir_y = -dir_y;
}

void Kula_wektor::negDirZ(){
    dir_z = -dir_z;
}

void Kula_wektor::calc_edge(GLdouble edge_x, GLdouble edge_y, GLdouble edge_z){

    if ((( act_x + dir_x ) >= edge_x ) || (( act_x + dir_x )<=-edge_x )){ act_x = act_x-dir_x; negDirX(); }
    else {act_x = act_x + dir_x; }

    if ((( act_y + dir_y ) >= edge_y ) || (( act_y + dir_y )<=-edge_y )){ act_y = act_y-dir_y; negDirY(); }
    else {act_y = act_y + dir_y; }

    if ((( act_z + dir_z ) >= edge_z ) || (( act_z + dir_z )<=-edge_z )){ act_z = act_z-dir_z; negDirZ(); }
    else {act_z = act_z + dir_z; }


}

GLdouble Kula_wektor::getX(){
    return act_x;
}

GLdouble Kula_wektor::getY(){
    return act_y;
}

GLdouble Kula_wektor::getZ(){
    return act_z;
}


GLdouble Kula_wektor::getDirX(){
    return dir_x;
}

GLdouble Kula_wektor::getDirZ(){
    return dir_z;
}

GLdouble Kula_wektor::getDirY(){
    return dir_y;
}

GLdouble Kula_wektor::getRadius(){
    return radius;
}

void Kula_wektor::setX(GLdouble x){
    act_x = x;
}

void Kula_wektor::setY(GLdouble y){
    act_y = y;
}

void Kula_wektor::setZ(GLdouble z){
    act_z = z;
}

void Kula_wektor::setDirX(GLdouble x){
    dir_x = x;
}

void Kula_wektor::setDirY(GLdouble y){
    dir_y = y;
}

void Kula_wektor::setDirZ(GLdouble z){
    dir_z = z;
}

void Kula_wektor::setRadius(GLdouble r){
    radius = r;
}

void Kula_wektor::showPos(){
   printf("X : %f Y : %f Z : %f \n",act_x, act_y, act_z);
}

void Kula_wektor::calculate_colision(Kula_wektor kula){
    GLdouble detX, detY, detZ, col_x, col_y, col_z,  col_dirX,  col_dirY,  col_dirZ;
    GLdouble act_newX, act_newY,act_newZ, col_newX,col_newZ, col_newY,odl;

    col_x = kula.getX();
    col_y = kula.getY();
    col_z = kula.getZ();

    col_dirX = kula.getDirX();
    col_dirY = kula.getDirY();
    col_dirZ = kula.getDirZ();



    detX = act_x-col_x;
    detY = act_y-col_y;
    detZ = act_z-col_z;
    //char z;

    odl=sqrt((detX*detX)+(detY*detY)+(detZ*detZ));
    //printf("odleglosc %f \n",odl);
   // gets(&z);
    if (odl<2*radius){
            //printf("odleglosc %f \n",odl);
            act_newX=(act_y*col_z-col_y*act_z)/10.0;
            act_newY=(act_x*col_z-col_x*act_z)/10.0;
            act_newZ=(act_x*col_y-col_x*act_y)/10.0;
           //printf("iloczyn skalarny aktualny X %f Y %f Z %f \n", act_newX, act_newY, act_newZ);

            col_newX=(col_y*act_z-act_y*col_z)/10.0;
            col_newY=(col_x*act_z-act_x*col_z)/10.0;
            col_newZ=(col_x*act_y-act_x*col_y)/10.0;

            dir_x=act_newX;
            dir_y=act_newY;
            dir_z=act_newZ;

            kula.setDirX(col_newX);
            kula.setDirY(col_newY);
            kula.setDirZ(col_newZ);
          // printf("iloczyn skalarny kolizji X %f Y %f Z %f \n", col_newX, col_newY, col_newZ);



    }



}
