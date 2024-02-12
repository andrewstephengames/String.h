#include <stdio.h>
#include "String.h"

int main (void) {
     String s1, s2;
     s1 = StringSet ("Hello World");
     s2 = Substring (s1, 0, s1.size);
     printf ("%s\n", s2);
     StringFree (s2);
     return 0;
}
