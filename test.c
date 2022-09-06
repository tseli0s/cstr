/* Test unit for cstr */
#include "cstr.h"

int main(int argc, char **argv)
{
        char* hello_world = cstr_new_from_string("Hello, ");
        cstr_push(hello_world, "world !");
        puts(hello_world);
        cstr_delete(hello_world);
}