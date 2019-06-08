#include<cstdio>

int main()
{
    for(double i=10; i<100; i++)
        for(double j=1; j<10; j++)
            for(double k=10; k<100; k++)
            {
                double a=i*10+j, b=j*100+k;
                if(a/b==i/k && (a!=b || i!=k))
                    printf("%.0lf / %.0lf = %.0lf / %.0lf\n", a, b, i, k);
            }
}
