#include <iostream>
#include "headers/rectangle.h"
#include "headers/line.h"
#include "headers/circle.h"
#include "headers/group.h"
#include <fstream>
#include <assert.h>
#include <string>
#include <cstring>
#include "headers/pugixml.h"

using namespace std;


void readFromFile(std::vector<Shape *> &v, const char *fileName) {
    v.clear();
    using namespace pugi;

    std::ifstream xml_file(fileName);

    xml_document doc;
    xml_parse_result res = doc.load(xml_file);

    auto sources = doc.child("svg").children();
    for (auto &&s: sources) {
        string name = s.name();
        if (!name.compare("rect")) {
            int x = s.attribute("x").as_int();
            int y = s.attribute("y").as_int();
            int width = s.attribute("width").as_int();
            int height = s.attribute("height").as_int();
            const char *color = s.attribute("fill").as_string();

            Rect *rect = new Rect();

            rect->set_x(x);
            rect->set_y(y);
            rect->set_w(width);
            rect->set_h(height);
            rect->set_text(color);

            v.push_back(rect);
        }
        if (!name.compare("line")) {
            int x1 = s.attribute("x1").as_int();
            int y1 = s.attribute("y1").as_int();
            int x2 = s.attribute("x2").as_int();
            int y2 = s.attribute("y2").as_int();
            const char *color = s.attribute("fill").as_string();

            Line *line = new Line();
            line->set_x(x1);
            line->set_y(y1);
            line->set_x2(x2);
            line->set_y2(y2);
            line->set_text(color);

            v.push_back(line);
        }
        if (!name.compare("circle")) {
            int x = s.attribute("cx").as_int();
            int y = s.attribute("cy").as_int();
            int rad = s.attribute("r").as_int();
            const char *color = s.attribute("fill").as_string();

            Circle *circle = new Circle();
            circle->set_x(x);
            circle->set_y(y);
            circle->set_r(rad);
            circle->set_text(color);

            v.push_back(circle);
        }
    }
}

int main() {
//    Group group2(0, 0, "test");
//    std::vector<Shape *> v;
//    readFromFile(v);
//    std::cout << v.size();
//    for (int i = 0; i < v.size(); i++) {
//        group2.addShape(v.at(i));
//    }
//    group2.draw();
//    Rect rect(10, 10, 100, 120, "yellow");
//    Line line(10, 10, 203, 300, "blue");
////    rect.draw();
////    line.draw();
//    Circle circle(120, 10, 205, "green");
////    rect.draw();
//    Rect rect2(122, 12, 150, 100, "black");
//    Rect rect3(100, 122, 159, 199, "blue");
//
////    circle.draw();
//
//    Group group(0, 0, "text");
//    group.addShape(&circle);
//    group.addShape(&rect);
//    group.addShape(&rect2);
//    group.addShape(&line);
//
//
//    group.translate(100, 200);
//    group.draw();
//
//    ofstream file("figures.svg");
//
//    group.serialize(file);
//
//    group2.addShape(&rect3);
//
//    ofstream file2("figures2.svg");
//    group2.serialize(file2);
//
//    Rect rect(100, 150, 130, 110, "yellow");
//    Rect rect2(1000, 1009, 130, 110, "green");
//    Rect rect3(350, 190, 130, 110, "green");
//    Rect rect4(200, 150, 730, 110, "black");
//    Circle circle(100, 100, 50, "blue");
//    Rect rect5(100, 150, 130, 110, "green");
//    rect.draw();
//    std::cout << std::endl;
//
//    Line line(400, 500, 500, 600, "blue");
    Group group(0, 0, "testgroup");
//    group.addShape(&line);
//    group.addShape(&rect);
//
//    group.addShape(&rect2);
//    group.addShape(&rect3);
//    group.addShape(&rect4);
//    group.addShape(&rect5);
//    group.addShape(&circle);
//
//    group.draw();
//    group.removeShape(3);
//
//    cout << std::endl;
//
//    group.draw();
//
//    group.translate(5, 5);
//
//    cout << std::endl;
//
//    group.draw();
    vector<Shape *> v;
    readFromFile(v, "stoian.svg");

    for (int i = 0; i < v.size(); i++) {
        group.addShape(v.at(i));
    }

    group.draw();
    return 0;

}