//
// Created by nb3 on 26.4.2019 г..
//

#include <cstring>
#include "../headers/circle.h"

Circle::Circle(int _x, int _y, int _r, const char *color) : Shape(_x, _y, color), r(_r) {

}

Circle::Circle() {

}

void Circle::draw() {
    std::cout << "Drawing circle with: "
              << x
              << " "
              << y
              << " and radius "
              << r
              << " "
              << color
              << "\n";
}

void Circle::set_r(int _r) {
    r = _r;
}

void Circle::translate(int vertical, int horizontal) {
    set_x(x + vertical);
    set_y(y + horizontal);
}

int Circle::get_r() {
    return r;
}

Shape *Circle::clone() {
    return new Circle(*this);
}

void Circle::serialize(std::ostream &out) {
    out << "circle cx=\""
        << x
        << "\" cy=\""
        << y
        << "\" r=\""
        << r
        << "\" fill=\""
        << color
        << "\"\n";
}