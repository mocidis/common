#ifndef __LVCODE_H__
#define __LVCODE_H__
typedef struct lvc_s {
    char *data;
    int len;
    int pack_ptr;
    int unpack_ptr;
} lvc_t;

void lvc_init(lvc_t *lvc, char *buff, int len);
void lvc_pack(lvc_t *lvc, int len, char *val);
void lvc_pack_finish(lvc_t *lvc);
int lvc_unpack(lvc_t *lvc, int *len, char **val);
#endif
