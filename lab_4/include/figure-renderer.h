#pragma once
#include <memory>
#include <math.h>
#include "array.h"
#include "figure.h"
#include "ppm.h"
#include "rgb-24.h"
#include "ppm.h"
#include "custom-concepts.h"

namespace FigureRendering {

Point<double> minPointX (Point<double> a, Point<double> b) {
    return a.getX() < b.getX() ? a : b;
}

Point<double> minPointX (Point<double> a, Point<double> b, Point<double> c) {
    return minPointX(a, minPointX(b, c));
}

Point<double> maxPointX (Point<double> a, Point<double> b) {
    return a.getX() > b.getX() ? a : b;
}

Point<double> maxPointX (Point<double> a, Point<double> b, Point<double> c) {
    return maxPointX(a, maxPointX(b, c));
}

class PolygonAtom {
    private:
        Point<double> A, B, C;
        bool degenAB, degenBC, degenAC, BUpperAC;
        double AB_k, AB_b, BC_k, BC_b, AC_k, AC_b;

    public:
        PolygonAtom () = default;

        PolygonAtom (Point<double> a, Point<double> b, Point<double> c) {
            A = minPointX(a, b, c);
            C = maxPointX(a, b, c);
            B = a + b + c - A - C;

            degenAB = A.getX() == B.getX();
            degenBC = B.getX() == C.getX();
            degenAC = A.getX() == C.getX();

            AB_k = degenAB ? 0.0 : (B.getY() - A.getY()) / (B.getX() - A.getX());
            AB_b = A.getY() - AB_k * A.getX();

            BC_k = degenBC ? 0.0 : (C.getY() - B.getY()) / (C.getX() - B.getX());
            BC_b = B.getY() - BC_k * B.getX();

            AC_k = degenAC ? 0.0 : (C.getY() - A.getY()) / (C.getX() - A.getX());
            AC_b = A.getY() - AC_k * A.getX();
            
            BUpperAC = AC_k * B.getX() + AC_b < B.getY();
        }

        bool isCollide (double x, double y) {
            if (degenAC) return false;

            if (x <= B.getX()) {
                if (degenAB) return false;
                if (BUpperAC) return AC_k * x + AC_b <= y && y <= AB_k * x + AB_b;
                return AB_k * x + AB_b <= y && y <= AC_k * x + AC_b;
            }

            if (degenBC) return false;
            if (BUpperAC) return AC_k * x + AC_b <= y && y <= BC_k * x + BC_b;
            return BC_k * x + BC_b <= y && y <= AC_k * x + AC_b;
        }
};

class PolygonMesh {
    private:
        Array<PolygonAtom> atoms;

        int borderLeft;
        int borderRight;
        int borderBottom;
        int borderTop;

    public:
        PolygonMesh (std::unique_ptr<Array<Point<double>>> &points) {
            Point<double> vertexA, vertexB, vertexC;
            vertexA = (*points)[0];

            borderLeft = vertexA.getX();
            borderRight = vertexA.getX();
            borderBottom = vertexA.getY();
            borderTop = vertexA.getY();

            for (std::size_t i = 1; i < points->getSize() - 1; i++) {
                vertexB = (*points)[i];
                vertexC = (*points)[i + 1];
                atoms.append(PolygonAtom(vertexA, vertexB, vertexC));

                borderLeft = std::min(borderLeft, static_cast<int>(vertexB.getX()));
                borderRight = std::max(borderRight, static_cast<int>(vertexB.getX()));
                borderBottom = std::min(borderBottom, static_cast<int>(vertexB.getY()));
                borderTop = std::max(borderTop, static_cast<int>(vertexB.getY()));
            }

            borderLeft = std::min(borderLeft, static_cast<int>(vertexC.getX()));
            borderRight = std::max(borderRight, static_cast<int>(vertexC.getX()));
            borderBottom = std::min(borderBottom, static_cast<int>(vertexC.getY()));
            borderTop = std::max(borderTop, static_cast<int>(vertexC.getY()));
        }

        bool isCollide (int x, int y) {
            if (x < borderLeft || x > borderRight || y < borderBottom || y > borderTop) return false;

            for (std::size_t i = 0; i < atoms.getSize(); i++) {
                if (atoms[i].isCollide(static_cast<double>(x), static_cast<double>(y))) return true;
            }

            return false;
        }

        int getBorderLeft () { return borderLeft; }
        int getBorderRight () { return borderRight; }
        int getBorderBottom () { return borderBottom; }
        int getBorderTop () { return borderTop; }
};

class FigureRenderer {
    private:
        int viewLeft;
        int viewRight;
        int viewBottom;
        int viewTop;

        int viewWidth;
        int viewHeight;

        RGB24 fillColor;

        std::unique_ptr<RGB24[]> frameBuffer{nullptr};

        void fillPixel (int x, int y) {
            int pixelAddr = (viewHeight - y + viewBottom) * viewWidth + x - viewLeft;
            if (pixelAddr < 0 || pixelAddr >= viewWidth * viewHeight) return;
            frameBuffer[pixelAddr] = fillColor;
        }

    public:
        FigureRenderer (int x, int y, int width, int height) 
            : viewLeft{x}, viewRight{x + width - 1}, viewBottom{y}, viewTop{y + height - 1},
            viewWidth{width}, viewHeight{height} {

            frameBuffer = std::make_unique<RGB24[]>(width * height);
        }
        
        FigureRenderer& operator<< (RGB24 color) {
            fillColor = color;
            return *this;
        }

        template <class T>
        FigureRenderer& operator<< (std::unique_ptr<Figure<T>> &figure) {
            auto points{figure->getPointsArray()};

            PolygonMesh mesh(points);

            int renderBottom = std::max(viewBottom, mesh.getBorderBottom());
            int renderTop = std::min(viewTop, mesh.getBorderTop());
            int renderLeft = std::max(viewLeft, mesh.getBorderLeft());
            int renderRight = std::min(viewRight, mesh.getBorderRight());

            for (int y = renderBottom; y <= renderTop; y++) {
                for (int x = renderLeft; x <= renderRight; x++) {
                    if (mesh.isCollide(x, y)) fillPixel(x, y); 
                }
            }

            return *this;
        }

        template <PrintColor T>
        FigureRenderer& operator>> (T &stream) {
            for (int i = 0; i < viewWidth * viewHeight; i++) {
                stream << frameBuffer[i];
            }

            return *this;
        }
};

};