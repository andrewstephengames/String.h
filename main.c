#include <stdio.h>
#include "String.h"

int main (void) {
     String s1, s2;
     s1 = StringSet ("Hello");
     printf ("%s: %d\n", s1.data, s1.size);
     s2 = StringSet ("World");
     printf ("%s: %d\n", s2.data, s2.size);
     s1 = StringCat (s1, space);
     s1 = StringCat (s1, s2);
     printf ("%s: %d\n", s1.data, s1.size);
     free (s1.data);
     return 0;
}
