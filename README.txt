String.h

String operations in C similar to the Java String class.

String StringSet (char *data); // Set String from char* value
void StringFree (String s); // Free String that was allocated by another function (marked by !)
char *StringFormat (String s); // Format String as a char* for functions such as printf
!String StringCat (String s1, String s2); // Concatenates two String variables
bool StringEquals (String s1, String s2); // Checks if two String variables' contents are equal
!String CharToString (char c); Returns a String that contains only the char c
String StringTrim (String s, char c); // Trims all occurances of the char c in the String s
!String StringReplace (String s, char a, char b); // Replaces all occurances of the char a with the char b in the String s
!String StringUpper (String s); // Returns a String with the content of String s but uppercase
!String StringLower (String s); // Returns a String with the content of String s but lowercase
!String Substring (String s, size_t a, size_t b); // Returns a String with the content between index a and b in the String s
bool StringEmpty (String s); // Checks if the String s has the size of 0
size_t StringLength (String s); // Returns the size of the String s
bool StringStartsWith (String s, char *p); // Checks if the String s starts with the string literal p
bool StringEndsWith (String s, char *t); // Checks if the String s ends with the string literal p
int StringChar (String s, char c); // Returns the index of the first occurance of the char c in the String s
String StringAtChar (String haystack, char needle); // Returns the String that starts with the first occurance of the char needle in the String haystack
