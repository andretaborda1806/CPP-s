#include "Point.hpp"

int main(void){
    Point a(0, 100);
    Point b(100, 0);
    Point c(0, 0);
    Point point(0, 0);

    switch (bsp(a, b, c, point))
    {
        case true:
            std::cout << "Inside the triangle" << std::endl;
            break;
        case false:
            std::cout << "Outside the triangle!" << std::endl;
            break;
    }
    return 0;
}