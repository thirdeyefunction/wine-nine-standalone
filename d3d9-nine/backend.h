/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Wine D3D9 DRI backend interface
 *
 * Copyright 2019 Patrick Rudolph
 */

#ifndef __NINE_BACKEND_H
#define __NINE_BACKEND_H

#include <X11/Xlib.h>

struct DRIBackend;
struct PRESENTpriv;
struct DRI2priv;
typedef struct PRESENTPriv PRESENTpriv;

struct PRESENTPixmapPriv;
struct D3DWindowBuffer
{
    struct PRESENTPixmapPriv *present_pixmap_priv;
};

BOOL DRIBackendOpen(Display *dpy, int screen, struct DRIBackend **dri_backend);

void DRIBackendClose(struct DRIBackend *dri_backend);

int DRIBackendFd(struct DRIBackend *dri_backend);

BOOL DRIBackendCheckExtension(Display *dpy);

BOOL DRIBackendD3DWindowBufferFromDmaBuf(struct DRIBackend *dri_backend,
        PRESENTpriv *present_priv, struct DRI2priv *dri2_priv,
        int dmaBufFd, int width, int height, int stride, int depth,
        int bpp, struct D3DWindowBuffer **out);

#endif /* __NINE_BACKEND_H */
