/* Copyright 2012 exMULTI, Inc.
 * Copyright 2022 bluezr
 * Copyright 2022 The Dogecoin Foundation
 * Distributed under the MIT/X11 software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 */

#include <dogecoin/buffer.h>
#include <dogecoin/mem.h>

int buffer_equal(const void* a_, const void* b_)
{
    const struct buffer* a = a_;
    const struct buffer* b = b_;

    if (a->len != b->len)
        return 0;
    return memcmp(a->p, b->p, a->len) == 0;
}

void buffer_free(void* struct_buffer)
{
    struct buffer* buf = struct_buffer;
    if (!buf) {
        return;
    }

    dogecoin_free(buf->p);
    dogecoin_free(buf);
}

struct buffer* buffer_copy(const void* data, size_t data_len)
{
    struct buffer* buf;
    buf = dogecoin_calloc(1, sizeof(*buf));
    if (!buf) {
        goto err_out;
    }

    buf->p = dogecoin_calloc(1, data_len);
    if (!buf->p) {
        goto err_out_free;
    }

    memcpy(buf->p, data, data_len);
    buf->len = data_len;

    return buf;

err_out_free:
    dogecoin_free(buf);
err_out:
    return NULL;
}
