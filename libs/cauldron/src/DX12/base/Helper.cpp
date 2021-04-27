// AMD Cauldron code
// 
// Copyright(c) 2020 Advanced Micro Devices, Inc.All rights reserved.
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "stdafx.h"
#include "Helper.h"

namespace CAULDRON_DX12
{
    void SetViewportAndScissor(ID3D12GraphicsCommandList* pCommandList, uint32_t topLeftX, uint32_t topLeftY, uint32_t width, uint32_t height)
    {
        // Set the viewport
        D3D12_VIEWPORT viewPort = { static_cast<float>(topLeftX), static_cast<float>(topLeftY), static_cast<float>(width), static_cast<float>(height), 0.0f, 1.0f };
        pCommandList->RSSetViewports(1, &viewPort);

        // Create scissor rectangle
        D3D12_RECT rectScissor = { (LONG)topLeftX, (LONG)topLeftY, (LONG)(topLeftX + width), (LONG)(topLeftY + height) };
        pCommandList->RSSetScissorRects(1, &rectScissor);
    }

    void SetName(ID3D12Object *pObj, const char * name)
    {
        if (name != NULL)
        {
            SetName(pObj, std::string(name));
        }
    }

    void SetName(ID3D12Object *pObj, const std::string &name)
    {
        assert(pObj != NULL);

        size_t size = name.size() + 1;
        wchar_t *uniName = (wchar_t*)malloc(size * sizeof(wchar_t));
        swprintf(uniName, size, L"%S", name.c_str());
        pObj->SetName(uniName);
        //Trace(format("Create: %p %S\n", pObj, uniName));
       free(uniName);
    }
}
