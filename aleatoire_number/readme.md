# Simple Aleatoire Number

```C
#include<time.h>
#include<stdlib.h>

int generateRandomNumber(int min, int max){
    if (min > max) {
        min += max;
        max = min - max;
        min -= max;
    }
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min; 
}
```

