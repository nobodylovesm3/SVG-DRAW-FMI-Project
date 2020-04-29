#include "../headers/group.h"

//
// Created by nb3 on 26.4.2019 г..
//

Group::Group(int _x, int _y, const char *s) : Shape(_x, _y, s) {}

void Group::draw() {
    for (Shape *shape : children) {
        shape->draw();
    }
}

void Group::translate(int vertical, int horizontal) {
    for (Shape *shape : children) {
        shape->translate(vertical, horizontal);
    }
}

void Group::addShape(Shape *shape) {

    children.push_back(shape->clone());
}

void Group::withinFigure(Shape *toCmp) {
    int index = 1;
    for (Shape *shape : children) {
        if (shape->get_x() <= toCmp->get_x() && shape->get_y() <= toCmp->get_y()) {
            std::cout << index << " ";
            shape->draw();
            index++;
        }
    }
}

void Group::removeShape(int index) {
    children.erase(children.begin() + index - 1);
}

Group::~Group() {
    for (Shape *shape : children) {
        delete shape;
    }
}

Shape *Group::clone() {
    Group *cloning = new Group(x, y, color);

    for (Shape *shape : children) {
        cloning->addShape(shape->clone());
    }

    return cloning;
}

Group &Group::operator=(const Group &g) {
    if (this != &g) {
        Shape::operator=(g);
        for (Shape *s : children) {
            delete s;
        }
        children.clear();
        for (Shape *s : g.children) {
            children.push_back(s->clone());
        }
    }
    return *this;
}

Group::Group(const Group &g) : Shape(g) {
    for (Shape *s : g.children) {
        children.push_back(s->clone());
    }
}

void Group::serialize(std::ostream &out) {
    out << R"(<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 1920 1080"> )";
    out << "<!-- Group "
        << children.size()
        << "-->\n";
    for (Shape *s : children) {
        out << "<";
        s->serialize(out);
        out << "/>";
    }
    out << "</svg>";
}
