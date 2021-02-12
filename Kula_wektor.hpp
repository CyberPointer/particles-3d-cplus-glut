
//nazwa pliku Kula_wektor.hpp

#ifndef Kula_wektor_hpp
#define Kula_wektor_hpp

#include <GL/glut.h>
class Kula_wektor{
    protected :
        GLdouble act_x;
        GLdouble act_y;
        GLdouble act_z;
        GLdouble radius;

        GLdouble dir_x;
        GLdouble dir_y;
        GLdouble dir_z;

    public :
        Kula_wektor();
        Kula_wektor(GLdouble, GLdouble, GLdouble, GLdouble,GLdouble,GLdouble,GLdouble);

        void calc_edge(GLdouble,GLdouble,GLdouble);
        void calculate_colision(Kula_wektor);
        GLdouble getX();
        GLdouble getY();
        GLdouble getZ();
        GLdouble getRadius();
        GLdouble getDirX();
        GLdouble getDirY();
        GLdouble getDirZ();


        void negDirX();
        void negDirY();
        void negDirZ();


        void setX(GLdouble);
        void setY(GLdouble);
        void setZ(GLdouble);

        void setDirX(GLdouble);
        void setDirY(GLdouble);
        void setDirZ(GLdouble);
        void setRadius(GLdouble);




        void showPos();








};

#endif
