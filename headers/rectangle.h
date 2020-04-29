//
// Created by nb3 on 26.4.2019 г..
//

#ifndef PROJECTOOP_RECTANGLE_H
#define PROJECTOOP_RECTANGLE_H


#include "shape.h"

class Rect : public Shape {
public:
    Rect(int _x, int _y, int _w, int _h, const char *_s);

    Rect();

    void draw();

    Shape *clone();

    void serialize(std::ostream &);

    void translate(int, int);

    void set_w(int _w);

    void set_h(int _h);

    int get_w();

    int get_h();

private:
    int w;
    int h;
};


#endif //PROJECTOOP_RECTANGLE_H
