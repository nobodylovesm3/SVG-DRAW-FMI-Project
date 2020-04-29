//
// Created by nb3 on 26.4.2019 г..
//

#ifndef PROJECTOOP_LINE_H
#define PROJECTOOP_LINE_H


#include "shape.h"

class Line : public Shape {
public:
    Line(int _x1, int _y1, int _x2, int _y2, const char *color);

    Line();

    void draw();

    Shape *clone();

    void serialize(std::ostream &);

    void translate(int, int);

    void set_x2(int _x2);

    void set_y2(int _y2);

    int get_x2();

    int get_y2();

private:
    int x2;
    int y2;

};

#endif //PROJECTOOP_LINE_H
