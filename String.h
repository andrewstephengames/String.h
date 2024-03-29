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
STRDEF char *StringFormat (String s);
STRDEF String StringCat (String s1, String s2); // StringFree
STRDEF bool StringEquals (String s1, String s2);
STRDEF String CharToString (char c); // StringFree
STRDEF String StringTrim (String s, char c);
STRDEF String StringReplace (String s, char a, char b); // StringFree
STRDEF String StringUpper (String s); // StringFree
STRDEF String StringLower (String s); // StringFree
STRDEF String Substring (String s, size_t a, size_t b); // StringFree
STRDEF bool StringEmpty (String s);
STRDEF size_t StringLength (String s);
STRDEF bool StringStartsWith (String s, char *p);
STRDEF bool StringEndsWith (String s, char *t);
STRDEF int StringChar (String s, char c);
STRDEF String StringAtChar (String s, char c);

STRDEF String StringSet (char *data) {
     String s = {0};
     for (size_t i = 0; data[i] != 0; ++i) {
          s.size++;
     }
     s.data = data;
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

STRDEF char *StringFormat (String s) {
     char *data = s.data;
     if (data == NULL) {
          data = "";
     }
     return data;
}

STRDEF String StringCat (String s1, String s2) { // Must use StringFree after
     String s;
     size_t size = s1.size + s2.size;
     s.data = malloc (size);
     s.size = size;
     assert (s.data != NULL && "Buy more RAM lol");
     Overwrite (s.data, s1.data);
     Overwrite (s.data + s1.size, s2.data);
     return s;
}

STRDEF bool StringEquals (String s1, String s2) {
     if (s1.size != s2.size) return false;
     for (size_t i = 0; i < s1.size; ++i) {
          if (s1.data[i] != s2.data[i]) {
               return false;
          }
     }
     return true;
}

STRDEF String CharToString (char c) {
     String s;
     s.size = 1;
     s.data = malloc (sizeof(char));
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

// Must use StringFree after
STRDEF String StringReplace (String s, char a, char b) {
     String t;
     t.data = malloc (s.size);
     assert (t.data != NULL && "Buy more RAM lol");
     t.size = s.size;
     for (size_t i = 0; i < s.size; ++i) {
          if (s.data[i] == a) {
               t.data[i] = b;
          }
          else {
               t.data[i] = s.data[i];
          }
     }
     return t;
}

STRDEF String StringUpper (String s) { // Must use StringFree after
     String t;
     t.data = malloc (s.size);
     assert (t.data != NULL && "Buy more RAM lol");
     t.size = s.size;
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

STRDEF String StringLower (String s) { // Must use StringFree after
     String t;
     t.data = malloc (s.size + 1);
     assert (t.data != NULL && "Buy more RAM lol");
     t.size = s.size;
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
     if (a > b) {
          size_t tmp = a;
          a = b;
          b = tmp;
     }
     assert (b < s.size && "Invalid substring.");
     String t;
     t.data = malloc (b-a+1);
     assert (t.data != NULL && "Buy more RAM lol");
     t.size = b-a+1;
     size_t j = 0;
     for (size_t i = a; i <= b; ++i) {
          t.data[j++] = s.data[i];
     }
     return t;
}

STRDEF bool StringEmpty (String s) {
     return s.size == 0;
}

STRDEF size_t StringLength (String s) {
     return s.size;
}

STRDEF bool StringStartsWith (String s, char *p) {
     String prefix = StringSet (p);
     if (prefix.size <= s.size) {
          String pf = Substring (s, 0, prefix.size-1);
          return StringEquals (prefix, pf);
     }
     StringFree (s);
     return false;
}

STRDEF bool StringEndsWith (String s, char *t) {
     String suffix = StringSet (t);
     if (suffix.size <= s.size) {
          String sf = Substring (s, s.size-1, s.size-suffix.size);
          return StringEquals (suffix, sf);
     }
     StringFree (s);
     return false;
}

STRDEF int StringChar (String s, char c) {
     for (size_t i = 0; i < s.size; ++i) {
          if (s.data[i] == c)
               return (int) i;
     }
     return -1;
}

STRDEF String StringAtChar (String s, char c) {
     String t = {0};
     t.data = haystack.data + StringChar (haystack, needle);
     for (size_t i = 0; t.data[i] != 0; ++i) {
          t.size++;
     }
     return t;
}

#endif // STRING_H_
