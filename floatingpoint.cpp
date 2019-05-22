#include "floatingpoint.h"

FloatingPoint::FloatingPoint(){}
float FloatingPoint::add(float x, float y){

    asm(
    "FLDS %1 \n"
    "FADDS %2  \n"
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x),"m"(y)
    );
    return x;
}
float FloatingPoint::subtract(float x, float y){

    asm(
    "FLDS %1 \n"
    "FSUBS %2  \n"
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x),"m"(y)
    );
    return x;

}
float FloatingPoint::multiply(float x, float y){

    asm(
    "FLDS %1 \n"
    "FMULS %2  \n"
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x),"m"(y)
    );
    return x;

}
float FloatingPoint::divide(float x, float y){

    asm(
    "FLDS %1 \n"
    "FDIVS %2  \n"
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x),"m"(y)
    );
    return x;

}
float FloatingPoint::sqrt(float x){

    asm(
    "FLDS %1 \n"
    "FSQRT  \n"
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x)
    );
    return x;

}

