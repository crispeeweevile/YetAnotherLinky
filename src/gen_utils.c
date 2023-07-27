#include "gen_utils.h"
#include <stdio.h>

void *smalloc(size_t size) {
    void *nPtr = malloc(size);
    if (!nPtr) {
        fprintf(stderr, "Failed to allocate: %zu bytes\n", size);
        (*nPtr);
    }

    return nPtr;
}
