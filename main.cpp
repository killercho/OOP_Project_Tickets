#include "Show/Show.h"
#include "Vector/Vector.h"

#include <fstream>

using namespace std;

int main()
{

    Vector<int> arr;
    arr.push(3);
    arr.push(2);
    arr.push(3);

    Vector<int> arr2 = arr;
    arr2.pop();
    arr2[1] = 1;
    cout << arr2[1] << " " << arr[1];
    cout << "Success!";
}
