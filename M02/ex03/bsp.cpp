#include "Point.hpp"

static Fixed abs(Fixed x)
{
    if (x < 0)
        return x * Fixed(-1);
    return x;
}

/* Calculate the area of triangle (a, b, c) using the shoelace formula */
static Fixed area(Point const &a, Point const &b, Point const &c)
{
    Fixed ax = a.getX();
    Fixed ay = a.getY();
    Fixed bx = b.getX();
    Fixed by = b.getY();
    Fixed cx = c.getX();
    Fixed cy = c.getY();

    Fixed result = (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / Fixed(2);
    return abs(result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed ABC = area(a, b, c);
    Fixed PAB = area(point, a, b);
    Fixed PBC = area(point, b, c);
    Fixed PCA = area(point, c, a);

    /* If point is on an edge or vertex, one of the sub-triangles will have zero area */
    if (PAB == 0 || PBC == 0 || PCA == 0)
        return false;

    /* Point is inside if the sum of the three sub-triangle areas equals the total area */
    return (PAB + PBC + PCA) == ABC;
}