#include <cstring>
#include <iostream>

#include "../headers/shape.h"
#include "../headers/circle.h"
#include "../headers/line.h"
#include "../headers/rectangle.h"

void Shape::set_x(int _x) {
    x = _x;
}

void Shape::set_y(int _y) {
    y = _y;
}

void Shape::set_text(const char *s) {

    if (color != nullptr) {
        delete color;
    }

    color = new char[strlen(s) + 1];
    strcpy(color, s);
}

int Shape::get_x() {
    return x;
}

int Shape::get_y() {
    return y;
}

char *Shape::get_text() {
    return color;
}

Shape::Shape() : x(0), y(0), color(nullptr) {

}

Shape::Shape(int _x, int _y, const char *s) {
    set_x(_x);
    set_y(_y);
    color = nullptr;
    set_text(s);
}

Shape::~Shape() {
    delete color;
}

Shape::Shape(const Shape &s) : x(s.x), y(s.y), color(nullptr) {
    set_text(s.color);
}

