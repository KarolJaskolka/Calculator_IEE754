#include "floatingpoint.h"

FloatingPoint::FloatingPoint(){}
float FloatingPoint::add(float x, float y){
    /*
    _asm(
    "mov %%eax, %%ebx \n"
    );
    return x;
    */
    return x+y;
}
float FloatingPoint::subtract(float x, float y){
    /*
    asm(
    "FLDS %1 \n"
    "FSUBS %2  \n"
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x),"m"(y)
    );
    return x;
    */
    return x-y;
}
float FloatingPoint::multiply(float x, float y){
    /*
    asm(
    "FLDS %1 \n"
    "FMULS %2  \n"
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x),"m"(y)
    );
    return x;
    */
    return x*y;
}
float FloatingPoint::divide(float x, float y){
/*
    asm(
    "FLDS %1 \n"
    "FDIVS %2  \n"
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x),"m"(y)
    );
    return x;
    */
    return x/y;
}
float FloatingPoint::sqrt(float x){
    /*
    asm(
    "FLDS %1 \n"
    "FSQRT  \n"
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x)
    );
    return x;
    */
    return x;
}

