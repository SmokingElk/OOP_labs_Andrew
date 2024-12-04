#include <iostream>
#include <memory>

#include "include/custom-concepts.h"
#include "include/point.h"
#include "include/triangle.h"
#include "include/hexagon.h"
#include "include/octagon.h"
#include "include/array.h"
#include "include/ppm.h"
#include "include/figure-renderer.h"

using FigureRendering::FigureRenderer;

int main () {
    // инициализация рендерера и выходного изображения
    const int WIDTH = 512;
    const int HEIGHT = 512;

    PPM image("../renders/render.ppm", WIDTH, HEIGHT);
    FigureRenderer renderer(-256, -256, WIDTH, HEIGHT);

    // создание фигур
    std::unique_ptr<Figure<double>> octagon(new Octagon<double>(
        Point(136.692435121, -59.262390493), Point(84.737609507, -7.307564879), Point(11.262390493, -7.307564879),
        Point(-40.692435121, -59.262390493), Point(-40.692435121, -132.737609507), Point(11.262390493, -184.692435121),
        Point(84.737609507, -184.692435121), Point(136.692435121, -132.737609507)
    ));

    std::unique_ptr<Figure<double>> hexagon(new Hexagon<double>(
        Point(113.384870242, 105.475219014), Point(-38.938971094, 222.357413384), Point(-216.323841336, 148.882194370),
        Point(-241.384870242, -41.475219014), Point(-89.061028906, -158.357413384), Point(88.323841336, -84.882194370)
    ));

    std::unique_ptr<Figure<double>> triangle(new Triangle<double>(
        Point(182.256580161, 112.983479343), Point(-37.549227557, 141.921462913), Point(47.292647396, -62.904942256)
    ));

    // рендеринг фигур
    renderer << RGB24(110, 110, 250) << octagon << RGB24(250, 90, 90) << hexagon << RGB24(250, 50, 50) << triangle;
    
    // сохранение изображения
    renderer >> image;

    return 0;
}
