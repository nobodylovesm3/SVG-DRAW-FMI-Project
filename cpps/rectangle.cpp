#include <cstring>
#include "../headers/shape.h"
#include "../headers/rectangle.h"

Rect::Rect(int _x, int _y, int _w, int _h, const char *_s) : Shape(_x, _y, _s), w(_w), h(_h) {
}

Rect::Rect() {

}

void Rect::draw() {
    std::cout << "Drawing rect with: " << x
              << " "
              << y
              << " "
              << w
              << " "
              << h
              << " "
              << color
              << "\n";
}

void Rect::set_w(int _w) {
    w = _w;
}

void Rect::set_h(int _h) {
    h = _h;
}

int Rect::get_w() {
    return w;
}

int Rect::get_h() {
    return h;
}

void Rect::translate(int vertical, int horizontal) {
    set_x(x + vertical);
    set_y(y + horizontal);
}

Shape *Rect::clone() {
    return new Rect(*this);
}

void Rect::serialize(std::ostream &out) {
    out << "rect x=\""
        << x
        << "\" y=\""
        << y
        << "\" width=\""
        << w
        << "\" height=\""
        << h
        << "\" fill=\""
        << color
        << "\"\n";
}
