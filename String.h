#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>
#include <stdio.h>

#ifndef STRDEF
#define STRDEF
#endif // STRDEF

typedef struct {
     char *data;
     size_t size; 
} String;

STRDEF String StringInit (char *data, size_t size);
STRDEF void StringFree (String *s);
STRDEF String StringToUpper (String *s);

STRDEF String StringInit (char *data) {
     String s;
     for (int i = 0; data[i] != 0; ++i)
     s.data = malloc (s.size * sizeof (char));
     return s;
}

STRDEF void StringFree (String *s) {
     free (s->data);
     s->data = NULL;
     s->size = 0;
}

STRDEF String StringToUpper (String *s) {
     if (s->size == 0) {
          fprintf (stderr, "Give me a workable String!");
          exit(1);
     }
     for (int i = 0; i < s->size; ++i) {
          if (s->data[i] >= 'a' && s->data[i] <= 'z')
               s->data[i] -= 32;
     }
     return *s;
}
STRDEF String StringToLower (String *s) {
     if (s->size == 0) {
          fprintf (stderr, "Give me a workable String!");
          exit(1);
     }
     for (int i = 0; i < s->size; ++i) {
          if (s->data[i] >= 'A' && s->data[i] <= 'Z')
               s->data[i] += 32;
     }
     return *s;
}

#endif // STRING_H_
