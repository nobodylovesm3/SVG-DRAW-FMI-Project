//
// Created by nb3 on 26.4.2019 г..
//

#ifndef PROJECTOOP_CIRCLE_H
#define PROJECTOOP_CIRCLE_H

#include "shape.h"

class Circle : public Shape {
public:
    Circle(int _x, int _y, int _r, const char *color);

    Circle();

    void draw();

    Shape *clone();

    void translate(int vertical, int horizontal) ;

    void serialize(std::ostream &);

    void set_r(int _r);

    int get_r();

private:
    int r;

};


#endif //PROJECTOOP_CIRCLE_H
