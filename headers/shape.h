//
// Created by nb3 on 26.4.2019 г..
//

#ifndef PROJECTOOP_SHAPE_H
#define PROJECTOOP_SHAPE_H

#include <iostream>

class Shape {
public:

    Shape();

    Shape(int, int, const char *);

    Shape(const Shape &);

    virtual void draw() = 0;

    virtual Shape *clone() = 0;

    virtual void translate(int vertical, int horizontal)  = 0;

    virtual void serialize(std::ostream &) = 0;

    void set_x(int);

    void set_y(int);

    void set_text(const char *);

    int get_x();

    int get_y();

    char *get_text();

    virtual ~Shape();

protected:

    int x;
    int y;
    char *color;

};

#endif //PROJECTOOP_SHAPE_H
