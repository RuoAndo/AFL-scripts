#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "rb");
    if (!f) return 1;

    char buf[32];
    fread(buf, 1, sizeof(buf), f);
    fclose(f);

    if (memcmp(buf, "CRASH", 5) == 0) {
        char *p = NULL;
        *p = 1;  // 故意にセグメンテーションフォールト
    }

    return 0;
}

