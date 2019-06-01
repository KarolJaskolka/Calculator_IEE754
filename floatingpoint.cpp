#include "floatingpoint.h"

FloatingPoint::FloatingPoint(){}

float FloatingPoint::power(float x, int n){

    float res = 1.0;

    asm(
    "   FINIT \n"
    "   FLDS %2 \n"
    "   FLDS %1 \n"
    "   cmpl $0, %%ecx \n"
    "   jge loop \n"
    "   mov $0, %%edx \n"
    "   mov $-1, %%eax \n"
    "   imul %%ecx \n"
    "   mov %%eax, %%ecx \n"
    "   FDIV %%st(0), %%st(1) \n"
    "loop: \n"
    "   FMUL %%st(1), %%st(0) \n"
    "   decl %%ecx  \n"
    "   cmpl $0, %%ecx  \n"
    "   jne loop \n"
    "exit: \n"
    "   FSTPS %0 \n"
    :"=m"(res)
    :"m"(res),"m"(x),"c"(n)
    );

    return res;
}

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

float FloatingPoint::root(float x, float n){
    float r = x;
    int a = static_cast<int>(n - 1);
    for(int i=0;i<1000;i++){
        r = multiply( divide(1,n) , add( multiply(a,r), divide(x, power(r,a)) ) );
    }
    return r;
}
