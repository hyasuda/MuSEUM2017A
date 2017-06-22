#include<stdio.h>
#include<math.h>

int main(void)

{


  double a;

  a = 0.293;//μA

  double T;//℃

  T = 1/(1/295.4-log(a/0.1348)/6500)-273;

  printf("%f\n",T);

  return 0;
}
