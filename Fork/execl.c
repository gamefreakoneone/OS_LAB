#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

main () { if (fork () && fork ()) if (fork () || fork ()) fork (); printf ("hello\n"); }