#ifndef WEKTOR_HPP_INCLUDED
#define WEKTOR_HPP_INCLUDED

#include <GL/gl.h>
#include <GL/glu.h>

class Wektor{
        protected :
            GLdouble x;
            GLdouble y;
            GLdouble z;

        public :
            Wektor();
            Wektor(GLdouble,GLdouble,GLdouble);
            GLdouble OUT_x();
            GLdouble OUT_y();
            GLdouble OUT_z();


            void nowy (GLdouble,GLdouble,GLdouble);
            void nowy (Wektor);
            void nowyx ( GLdouble );
            void nowyy ( GLdouble );
            void nowyz ( GLdouble );

            void suma ( GLdouble,GLdouble,GLdouble );
            void suma (Wektor);
            void sumax (GLdouble );
            void sumay (GLdouble );
            void sumaz (GLdouble );

            void negacja();
            void negacjax();
            void negacjay();
            void negacjaz();


            GLdouble dlugosc();
            void normalizacja();
            void iloczyn(GLdouble);
            Wektor kopia();
            void wypiszDane();
            bool zaMalo(GLdouble);
            GLdouble iloczynSkalarny(Wektor);
            bool wiecejMinusow();

    };

#endif // WEKTOR_HPP_INCLUDED
