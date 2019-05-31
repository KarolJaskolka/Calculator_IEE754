#ifndef FLOATINGPOINT_H
#define FLOATINGPOINT_H


class FloatingPoint
{
public:

    FloatingPoint();

    static float root(float x, float n);
    static float power(float x, int y);
    static float add(float x, float y);
    static float subtract(float x, float y);
    static float multiply(float x, float y);
    static float divide(float x, float y);
    static float sqrt(float x);

};

#endif // FLOATINGPOINT_H
