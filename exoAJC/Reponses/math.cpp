#include "math.hpp"

int main()
{
    Rectangle rect1(15, 10);
    Cercle cerc1(4);

    cout << "Aire rec1: " << rect1.aire() << endl;
    cout << "Aire cerc1: " << cerc1.aire() << endl;

    return 0;
}
