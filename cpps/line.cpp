#include <cstring>
#include "../headers/shape.h"
#include "../headers/line.h"

Line::Line(int _x1, int _x2, int _y1, int _y2, const char *color) : Shape(_x1, _y1, color), x2(_x2), y2(_y2) {

}

Line::Line() {

}

void Line::draw() {
    std::cout << "Drawing line with: "
              << x
              << " "
              << y
              << "| to |"
              << x2
              << " "
              << y2
              << " "
              << color
              << "\n";
}

void Line::set_x2(int _x2) {
    x2 = _x2;
}

void Line::translate(int vertical, int horizontal) {
    set_x(x + vertical);
    set_y(y + horizontal);
    set_x2(x2 + vertical);
    set_y2(y2 + horizontal);
}

void Line::set_y2(int _y2) {
    y2 = _y2;
}

int Line::get_x2() {
    return x2;
}

int Line::get_y2() {
    return y2;
}

Shape *Line::clone() {
    return new Line(*this);
}

void Line::serialize(std::ostream &out) {
    out << "line x1=\""
        << x
        << "\" y1=\""
        << y
        << "\" x2=\""
        << x2
        << "\" y2=\""
        << y2
        << "\" stroke=\""
        << color
        << "\"\n";
}
