/*==================================================================================
    Copyright (c) 2008, binaryzebra
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    * Neither the name of the binaryzebra nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE binaryzebra AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL binaryzebra BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
=====================================================================================*/

#ifndef __DAVAENGINE_UI_TEXT_FIELD_IMPL_IOS_H__
#define __DAVAENGINE_UI_TEXT_FIELD_IMPL_IOS_H__

#include "Base/BaseTypes.h"
#include "Base/BaseMath.h"
#include "UI/UITextFieldImpl.h"

namespace DAVA 
{
class UITextFieldImpl_iOS: public UITextFieldImpl
{
public:
    UITextFieldImpl_iOS(UITextField *tf);
    virtual ~UITextFieldImpl_iOS();

    virtual void OpenKeyboard();
    virtual void CloseKeyboard();
    virtual const WideString &GetText() const;
    virtual void SetText(const WideString &string);
    virtual void UpdateRect(const Rect &rect, float32 timeElapsed);

    virtual const Color &GetTextColor() const;
    virtual void SetTextColor(const Color &color);
    virtual void SetFontSize(float32 size);
    
    virtual void SetTextAlign(int32 align);

    virtual void AddNativeControl();
    virtual void RemoveNativeControl();

    virtual void SetVisible(bool value);

    virtual void SetIsPassword(bool isPassword);

    virtual void SetInputEnabled(bool value);

    // Keyboard traits.
    virtual void SetAutoCapitalizationType(int32 value);
    virtual void SetAutoCorrectionType(int32 value);
    virtual void SetSpellCheckingType(int32 value);
    virtual void SetKeyboardAppearanceType(int32 value);
    virtual void SetKeyboardType(int32 value);
    virtual void SetReturnKeyType(int32 value);
    virtual void SetEnableReturnKeyAutomatically(bool value);

    // Cursor pos.
    virtual uint32 GetCursorPos() const;
    virtual void SetCursorPos(uint32 pos);
private:
    void * nativeClassPtr;
    mutable WideString text;
    mutable Color textColor;
};
};

#endif // __DAVAENGINE_UI_TEXT_FIELD_IMPL_IOS_H__