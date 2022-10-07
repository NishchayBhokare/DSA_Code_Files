
#include<stdio.h>
#include<conio.h>
#include<math.h>


    
 double funct(int a, int b, int c)
{

    double r1, r2;
    double d = (b * b) - (4 * a * c);
    if (d > 0)
    {
        r1 = ((-b) + sqrt(d)) / (2 * a);
        r2 = ((-b) - sqrt(d)) / (2 * a);
        double num = (r1 + r2) / 2;
        num = (num * 10)/10;
        return num;
    }
    else if (d == 0)
    {
        r1 = -b / (2 * a);
        r2 = -b / (2 * a);
        double num = (r1 + r2) / 2;
        num = num/10;
        return num;
    }
    else
        return 0;
}
int main()
{
    int a = 1;
    int b = 5;
    int c = 6;
    double ans = funct(a, b, c);
    // setprecision(3);
    printf("%f",ans);
    return 0;
}