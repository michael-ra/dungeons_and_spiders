
using namespace std;
#include "world/worldutil.cpp"
#include "world/object/world.h"

// Driver program to test function
int main()
{
    world w;
    generateNewWorld(w, 200);
    w.printWorld();

    w.setFields('P', 25, 25);
    w.setFields('Z', 15, 25);

    int i = getDistance(w, {10,10}, {11,10});
    cout << i;

    return 0;
}