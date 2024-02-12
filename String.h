#ifndef STRING_H_
#define STRING_H_

#ifndef STRDEF
#define STRDEF
#endif // STRDEF

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define space (String) { .data = " ", .size = 1 }

typedef struct {
     char *data;
     size_t size; 
} String;

STRDEF String StringSet (char *data);
STRDEF void StringFree (String s);
STRDEF static char *Overwrite (char *d, char *s);
STRDEF char *StringToC (String s);
STRDEF String StringCat (String s1, String s2);
STRDEF bool StringEquals (String s1, String s2);
STRDEF String CharToString (char c);
STRDEF String StringTrim (String s, char c);
STRDEF String StringToUpper (String s);
STRDEF String StringToLower (String s);
STRDEF String Substring (String s, size_t a, size_t b);

STRDEF String StringSet (char *data) {
     String s;
     size_t size = 0;
     for (size_t i = 0; data[i] != 0; ++i) {
          size++;
     }
     s.data = data;
     s.size = size;
     return s;
}

STRDEF void StringFree (String s) {
     free (s.data);
     s.size = 0;
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

STRDEF String StringCat (String s1, String s2) { // Must use StringFree after
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
     String s;
     s.size = 1;
     s.data = malloc (2 * sizeof(char));
     assert (s.data != NULL && "Buy more RAM lol");
     s.data[0] = c;
     return s;
}

STRDEF String StringTrim (String s, char c) {
     for (size_t i = 0; i < s.size; ++i) {
          while (s.data[i] == c) {
               Overwrite (s.data + i, s.data + i+1);
               s.size--;
          }
     }
     return s;
}

STRDEF String StringToUpper (String s) { // Must use StringFree after
     String t;
     t.data = malloc (s.size + 1);
     t.size = s.size;
     if (t.data == NULL) {
          assert (t.data != NULL && "Buy more RAM lol");
          return s;
     }
     for (size_t i = 0; i < s.size; ++i) {
          if (s.data[i] >= 'a' && s.data[i] <= 'z') {
               t.data[i] = s.data[i] - 32;
          }
          else {
               t.data[i] = s.data[i];
          }
     }
     return t;
}

STRDEF String StringToLower (String s) { // Must use StringFree after
     String t;
     t.data = malloc (s.size + 1);
     t.size = s.size;
     if (t.data == NULL) {
          assert (t.data != NULL && "Buy more RAM lol");
          return s;
     }
     for (size_t i = 0; i < s.size; ++i) {
          if (s.data[i] >= 'A' && s.data[i] <= 'Z') {
               t.data[i] = s.data[i] + 32;
          }
          else {
               t.data[i] = s.data[i];
          }
     }
     return t;
}

STRDEF String Substring (String s, size_t a, size_t b) { // Must use StringFree after
     if (b == s.size) b = s.size-1;
     assert (a < b && b < s.size && "Invalid substring.");
     String t;
     t.data = malloc (b - a + 2);
     t.size = b-a+1;
     size_t j = 0;
     for (size_t i = a; i <= b; ++i) {
          t.data[j++] = s.data[i];
     }
     return t;
}

#endif // STRING_H_
