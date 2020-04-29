//
// Created by nb3 on 26.4.2019 г..
//

#ifndef PROJECTOOP_GROUP_H
#define PROJECTOOP_GROUP_H

#include "shape.h"
#include <vector>

class Group : public Shape {
public:
    Group(int _x, int _y, const char *s);

    Group(const Group &);

    void draw();

    void translate(int vertical, int horizontal);

    Shape *clone();

    void serialize(std::ostream &);

    void withinFigure(Shape *shape);

    void addShape(Shape *);

    void removeShape(int index);

    Group &operator=(const Group &g);


    ~Group();

private:
    std::vector<Shape *> children;
};

#endif //PROJECTOOP_GROUP_H
