#include "lvcode.h"
#include "ansi-utils.h"

void lvc_init(lvc_t *lvc, char *buff, int len) {
    lvc->data = buff;
    lvc->len = len;
    lvc->pack_ptr = 0;
    lvc->unpack_ptr = 0;
}

void lvc_pack(lvc_t *lvc, int len, char *val) {
    EXIT_IF_TRUE((lvc->pack_ptr + len) > lvc->len, "lvc buffer is overflown\n");

    SHOW_LOG(1, "len:%d\n", len);
    memcpy((lvc->data + lvc->pack_ptr), &len, sizeof(int));
    lvc->pack_ptr += sizeof(int);

    memcpy(lvc->data + lvc->pack_ptr, val, len);
    lvc->pack_ptr += len;
}

void lvc_pack_finish(lvc_t *lvc) {
    lvc->len = lvc->pack_ptr;
    lvc->pack_ptr = 0;
}

int lvc_unpack(lvc_t *lvc, int *len, char **val) {
    int *temp;
    if (lvc->unpack_ptr >= lvc->len) return -1;
    temp = (int *)(lvc->data + lvc->unpack_ptr);
    *len = *temp;
    SHOW_LOG(1, "lllllen:%d\n", *len);
    lvc->unpack_ptr += sizeof(int);
    *val = lvc->data + lvc->unpack_ptr;
    lvc->unpack_ptr += *len;
    return 0;
}

