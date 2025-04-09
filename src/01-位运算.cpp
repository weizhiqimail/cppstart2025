#include <iostream>
#include <string>
using namespace std;

int main() {
    float a = 100.9f;
    printf("%f\n", a);
    // 100.900002

    printf("«Î ‰»Î float: ");
    // «Î ‰»Î float:98.22
    scanf("%f", &a);
    printf("%f\n", a);
    // 98.220001
    return 0;
}
