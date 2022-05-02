#include "utils/Date.h"
#include "utils/String.h"

using namespace std;

int main()
{
    Date d1(1, 1, 2001);
    Date d2 = d1;
    d2.setDay(2);
    cout << (d1 == d2) << '\n';
}
