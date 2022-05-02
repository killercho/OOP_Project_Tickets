#include "utils/String.h"

using namespace std;

int main()
{
    String str("blah");
    String str2(str);
    str2 = "idk";
    cout << str2.getStr() << " " << str2.getSize() << '\n';
}
