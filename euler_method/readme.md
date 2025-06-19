# Algorithme d'Euler
Permet d'approcher les solutions du problème à valeur initial.

- `step1:` 

    - Set:    
        - $h= (b - a)/N$  
        - $t= a$  
        - $w= \alpha$     
    - $output(t,w)$

- `step2:` 

    For $i=1,...,N$ do `step 3-4`,

- `step 3:`
  
    - Set:
        - $w = w + hf(t,w)$
        - $t = a + ih$  
- `step4:` output(t,w) 


# Exemple

**donnée**:     

- $\frac{dy}{dt} = -ty + \frac{4t}{y}$   
- $a<=t<=1$       
- $y(0)= 1$   
- $h=0.25$

**Implementation en C**:

```C
#include<stdio.h>

float F(float t, float w);
float Y(float w,float h,float f);

int main(){
    float f,y,w,a,b,t,h;
    int n,i;

    printf(" h="); scanf("%f",&h);
    printf(" a="); scanf("%f",&a);
    printf(" b="); scanf("%f",&b);

    n = (int)((b - a) / h);
    t = a;
    w = 1;

    i = 1;
    while (i <= n){
        f = F(t,w);
        y = Y(w,h,f);
        printf("i= %d, t= %f, w= %f\n",i,t,y);
        t = a + (i * h);
        w = y;
        i++;    
    }
    return 0;
}


float F(float t, float w){
    return ((-t * w) + (4 * t / w));
}

float Y(float w,float h,float f){
    return (w + (h * f));
}
```

Thanks!!
  

  

