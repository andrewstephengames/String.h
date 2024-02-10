#include "String.h"

int main (void) {
     String s;
     s = StringInit ("test", 4);
     printf ("%c\n", s.data[0]);
     return 0;
}
