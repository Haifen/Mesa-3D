/*
 * Copyright 2013 Christoph Bumiller
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the Software),
 * to deal in the Software without restriction, including without limitation
 * on the rights to use, copy, modify, merge, publish, distribute, sub
 * license, and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHOR(S) AND/OR THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE. */

#include "object.h"

HRESULT
DXGIObject_ctor( struct DXGIObject *This,
                 struct D3D11UnknownParams *pParams )
{
    return D3D11Unknown_ctor(&This->base, pParams);
}

void
DXGIObject_dtor( struct DXGIObject *This )
{
    D3D11PrivateData_Destroy(&This->pdata);
    D3D11Unknown_dtor(&This->base);
}

HRESULT WINAPI
DXGIObject_SetPrivateData( struct DXGIObject *This,
                           REFGUID Name,
                           UINT DataSize,
                           void *pData )
{
    return D3D11PrivateData_Set(This, Name, DataSize, pData);
}

HRESULT WINAPI
DXGIObject_SetPrivateDataInterface( struct DXGIObject *This,
                                    REFGUID Name,
                                    IUnknown *pUnknown )
{
    return D3D11PrivateData_SetInterface(&This->pdata, Name, pUnknown);
}

HRESULT WINAPI
DXGIObject_GetPrivateData( struct DXGIObject *This,
                           REFGUID Name,
                           UINT *pDataSize,
                           void *pData )
{
    return D3D11PrivateData_Get(&This->pdata, Name, pDataSize, pData);
}

HRESULT WINAPI
DXGIObject_GetParent( struct DXGIObject *This,
                      REFIID riid,
                      void **ppParent )
{
    return D3D11Unknown_QueryInterface(This->base.container, riid, ppParent);
}
