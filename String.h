#ifndef STRING_H_
#define STRING_H_

#ifndef STRDEF
#define STRDEF
#endif // STRDEF

#include <stdlib.h>
#include <assert.h>

#define bool int
#define true 1
#define false 0
#define space (String) { .data = " ", .size = 1 }

typedef struct {
     char *data;
     size_t size; 
} String;

STRDEF String StringSet (char *data);
STRDEF static char *Overwrite (char *d, char *s);
STRDEF char *StringToC (String s);
STRDEF String StringCat (String s1, String s2);
STRDEF bool StringEquals (String s1, String s2);
STRDEF String CharToString (char c);

STRDEF String StringSet (char *data) {
     String s;
     size_t size = 0;
     for (int i = 0; data[i] != 0; ++i) {
          size++;
     }
     s.data = data;
     s.size = size;
     return s;
}

STRDEF static char *Overwrite (char *d, char *s) {
     if (d == NULL) {
          d = "";
     }
     if (s == NULL) {
          s = "";
     }
     while ((*d = *s)) {
          ++s;
          ++d;
     }
     return d;
}

STRDEF char *StringToC (String s) {
     char *data = s.data;
     if (data == NULL) {
          data = "";
     }
     return data;
}

STRDEF String StringCat (String s1, String s2) {
     String s;
     size_t size = s1.size + s2.size;
     s.data = malloc (size * 2 + 1);
     s.size = size;
     assert (s.data != NULL && "Buy more RAM lol");
     Overwrite (s.data, s1.data);
     Overwrite (s.data + s1.size, s2.data);
     return s;
}

STRDEF bool StringEquals (String s1, String s2) {
     return s1.data == s2.data;
}

STRDEF String CharToString (char c) {
     String s, t;
     s.size = 1;
     s.data = malloc (2 * sizeof(char));
     s.data[0] = c;
     return s;
}

#endif // STRING_H_
