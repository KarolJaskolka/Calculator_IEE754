#include "floatingpoint.h"

FloatingPoint::FloatingPoint(){}

float FloatingPoint::power(float x, int n){

    float res = 1.0;

    asm(
    "   FINIT \n"
    "   FLDS %2 \n"
    "   FLDS %1 \n"
    // sprawdzenie czy n jest liczbą nieujemną
    "   cmpl $0, %%ecx \n"
    "   jge loop \n"
    // jesli liczba n jest ujemna
    "   mov $0, %%edx \n"
    // wymnozenie liczby razy -1 oraz ...
    "   mov $-1, %%eax \n"
    "   imul %%ecx \n"
    "   mov %%eax, %%ecx \n"
    // ... podstawienie za x = 1/x
    "   FDIV %%st(0), %%st(1) \n"
    // petla obliczajaca potege
    "loop: \n"
    // za wynik podstawienie wyniku pomnozonego przez x
    "   FMUL %%st(1), %%st(0) \n"
    // zmniejszenie licznika co petle
    "   decl %%ecx  \n"
    "   cmpl $0, %%ecx  \n"
    // sprawdzenie czy koniec
    "   jne loop \n"
    "exit: \n"
    // umieszczenie wyniku w res
    "   FSTPS %0 \n"
    :"=m"(res)
    :"m"(res),"m"(x),"c"(n)
    );

    return res;
}

float FloatingPoint::add(float x, float y){

    asm(
    // umieszczenie x w st(0)
    "FLDS %1 \n"
    // dodanie y do st(0)
    "FADDS %2  \n"
    // zwrocenie wyniku
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x),"m"(y)
    );
    return x;
}
float FloatingPoint::subtract(float x, float y){

    asm(
    // umieszczenie x w st(0)
    "FLDS %1 \n"
    // odjecie od st(0) liczby y
    "FSUBS %2  \n"
    // zwrocenie wyniku
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x),"m"(y)
    );
    return x;

}
float FloatingPoint::multiply(float x, float y){

    asm(
    // umieszczenie x w st(0)
    "FLDS %1 \n"
    // wymnozenie y przez st(0)
    "FMULS %2  \n"
    // zwrocenie wyniku
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x),"m"(y)
    );
    return x;

}
float FloatingPoint::divide(float x, float y){

    asm(
    // umieszczenie x w st(0)
    "FLDS %1 \n"
    // podzielenie st(0) przez y
    "FDIVS %2  \n"
    // zwrocenie wyniku
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x),"m"(y)
    );
    return x;

}
float FloatingPoint::sqrt(float x){

    asm(
    // umieszczenie x w st(0)
    "FLDS %1 \n"
    // obliczenie pierwiastka kwadratowego z x
    "FSQRT  \n"
    // zwrocenie wyniku
    "FSTPS %0 \n"
    :"=m"(x)
    :"m"(x)
    );
    return x;

}

float FloatingPoint::root(float x, float n){
    float r = x;
    if(static_cast<int>(n)%2 == 0 && x < 0){
        // jesli n jest podzielne przez 2
        // oraz x jest liczba ujemna
        // zwrocenie NaN
        asm(
        // wytowrzenie NaN przez
        // pierwiastek z liczby ujemnej
        "FLDS %1 \n"
        "FSQRT  \n"
        "FSTPS %0 \n"
        :"=m"(x)
        :"m"(x)
        );
        return x;
    }
    int a = static_cast<int>(n - 1);
    // petla obliczajaca pierwiastek n-tego stopnia
    for(int i=0;i<1000;i++){
        // wykorzystanie poprzednich funkcji
        r = multiply( divide(1,n) , add( multiply(a,r), divide(x, power(r,a)) ) );
    }
    return r;
}
