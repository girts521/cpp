#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void testPoint(Point const &a, Point const &b, Point const &c,
                      Point const &p, std::string const &description, bool expected)
{
    bool result = bsp(a, b, c, p);
    std::cout << description << ": "
              << (result ? "inside" : "outside")
              << " (expected: " << (expected ? "inside" : "outside") << ")"
              << (result == expected ? " [OK]" : " [FAIL]")
              << std::endl;
}

int main(void)
{
    /* Triangle with vertices at (0,0), (5,0), (0,5) */
    Point const a(0.0f, 0.0f);
    Point const b(5.0f, 0.0f);
    Point const c(0.0f, 5.0f);

    std::cout << "Triangle: (0,0), (5,0), (0,5)" << std::endl;
    std::cout << "==============================" << std::endl;

    /* Inside */
    testPoint(a, b, c, Point(1.0f, 1.0f), "Point (1,1) inside", true);
    testPoint(a, b, c, Point(0.5f, 0.5f), "Point (0.5,0.5) inside", true);
    testPoint(a, b, c, Point(2.0f, 2.0f), "Point (2,2) inside", true);

    /* On vertices — should be false */
    testPoint(a, b, c, Point(0.0f, 0.0f), "Vertex (0,0) (on vertex)", false);
    testPoint(a, b, c, Point(5.0f, 0.0f), "Vertex (5,0) (on vertex)", false);
    testPoint(a, b, c, Point(0.0f, 5.0f), "Vertex (0,5) (on vertex)", false);

    /* On edges — should be false */
    testPoint(a, b, c, Point(2.5f, 0.0f), "Edge (2.5,0) on base", false);
    testPoint(a, b, c, Point(0.0f, 2.5f), "Edge (0,2.5) on left", false);
    testPoint(a, b, c, Point(1.0f, 4.0f), "Edge (1,4) on hypotenuse", false);

    /* Outside */
    testPoint(a, b, c, Point(5.0f, 5.0f), "Point (5,5) outside", false);
    testPoint(a, b, c, Point(-1.0f, -1.0f), "Point (-1,-1) outside", false);
    testPoint(a, b, c, Point(6.0f, 0.0f), "Point (6,0) outside", false);

    /* Different triangle: (1,1), (4,1), (1,4) */
    std::cout << std::endl;
    std::cout << "Triangle: (1,1), (4,1), (1,4)" << std::endl;
    std::cout << "==============================" << std::endl;

    Point const d(1.0f, 1.0f);
    Point const e(4.0f, 1.0f);
    Point const f(1.0f, 4.0f);

    testPoint(d, e, f, Point(2.0f, 2.0f), "Point (2,2) inside", true);
    testPoint(d, e, f, Point(1.5f, 1.5f), "Point (1.5,1.5) inside", true);
    testPoint(d, e, f, Point(1.0f, 1.0f), "Vertex (1,1) (on vertex)", false);
    testPoint(d, e, f, Point(4.0f, 1.0f), "Vertex (4,1) (on vertex)", false);
    testPoint(d, e, f, Point(2.0f, 1.0f), "Edge (2,1) on base", false);
    testPoint(d, e, f, Point(5.0f, 5.0f), "Point (5,5) outside", false);

    std::cout << std::endl << "All tests completed." << std::endl;
    return 0;
}