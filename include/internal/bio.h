/*
 * Copyright 2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <openssl/bio.h>

struct bio_method_st {
    int type;
    const char *name;
    int (*bwrite) (BIO *, const char *, size_t, size_t *);
    int (*bwrite_old) (BIO *, const char *, int);
    int (*bread) (BIO *, char *, size_t, size_t *);
    int (*bread_old) (BIO *, char *, int);
    int (*bputs) (BIO *, const char *);
    int (*bgets) (BIO *, char *, int);
    long (*ctrl) (BIO *, int, long, void *);
    int (*create) (BIO *);
    int (*destroy) (BIO *);
    long (*callback_ctrl) (BIO *, int, BIO_info_cb *);
    int (*bwrite_direct) (BIO *, BIO_direct_write_cb, size_t, size_t *, void *);
    int (*bread_direct) (BIO *, BIO_direct_read_cb, size_t *, void *);
};

void bio_free_ex_data(BIO *bio);
void bio_cleanup(void);


/* Old style to new style BIO_METHOD conversion functions */
int bwrite_conv(BIO *bio, const char *data, size_t datal, size_t *written);
int bread_conv(BIO *bio, char *data, size_t datal, size_t *read);
