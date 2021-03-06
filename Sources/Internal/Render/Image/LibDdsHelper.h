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



#ifndef __DAVAENGINE_DXT_HELPER_H__
#define __DAVAENGINE_DXT_HELPER_H__

#include "Base/BaseTypes.h"
#include "Render/RenderBase.h"
#include "FileSystem/FilePath.h"
#include "Render/Image/ImageFormatInterface.h"
#include "Render/Image/CRCAdditionInterface.h"

namespace DAVA 
{

class Image;
class File;

class LibDdsHelper: public ImageFormatInterface, public CRCAdditionInterface
{
public:
    
    LibDdsHelper();
    
    virtual bool IsImage(File *file) const;
    
    virtual eErrorCode ReadFile(File *infile, Vector<Image *> &imageSet, int32 baseMipMap = 0) const;

  	//input data only in RGBA8888
    virtual eErrorCode WriteFile(const FilePath & fileName, const Vector<Image *> &imageSet, PixelFormat compressionFormat) const;

    //input data only in RGBA8888
    virtual eErrorCode WriteFileAsCubeMap(const FilePath & fileName, const Vector<Vector<Image *> > &imageSet, PixelFormat compressionFormat) const;
    
    virtual uint32 GetDataSize(File * file) const;
	virtual Size2i GetImageSize(File *infile) const;



    static eErrorCode ReadFile(File * file, Vector<Image*> &imageSet, int32 baseMipMap = 0, bool forceSoftwareConvertation = false);
       
	static bool DecompressImageToRGBA(const DAVA::Image & image, Vector<DAVA::Image*> &imageSet, bool forceSoftwareConvertation = false);
    
    static uint32 GetMipMapLevelsCount(const FilePath & fileName);
	static uint32 GetMipMapLevelsCount(File * file);
    
	virtual bool AddCRCIntoMetaData(const FilePath &filePathname) const;
	virtual uint32 GetCRCFromFile(const FilePath &filePathname) const;
    
private:

	static PixelFormat GetPixelFormat(const FilePath & fileName);
	static PixelFormat GetPixelFormat(File * file);
	
	static bool GetTextureSize(const FilePath & fileName, uint32 & width, uint32 & height);
	static bool GetTextureSize(File * file, uint32 & width, uint32 & height);
    
	static bool GetCRCFromDDSHeader(const FilePath &filePathname, uint32* tag, uint32* outputCRC);
	
	//input data only in RGBA8888
	static bool WriteDxtFile(const FilePath & fileNameOriginal, const Vector<Image *> &imageSet, PixelFormat compressionFormat);
	static bool WriteAtcFile(const FilePath & fileNameOriginal, const Vector<Image *> &imageSet, PixelFormat compressionFormat);

    static bool WriteDxtFileAsCubemap(const FilePath & fileNameOriginal, const Vector<Vector<Image *> > &imageSet, PixelFormat compressionFormat);
    static bool WriteAtcFileAsCubemap(const FilePath & fileNameOriginal, const Vector<Vector<Image *> > &imageSet, PixelFormat compressionFormat);

};

};

#endif // __DAVAENGINE_DXT_HELPER_H__