/* Unknown Engine Project */

#include "unk/core/TextureInfo.h"

unk::TextureInfo::TextureInfo(std::string filename) : Filename(filename) {
    Width = 0;
    Height = 0;
}

std::string unk::TextureInfo::getFilename() const {
    return Filename;
}

bool std::less<unk::TextureInfo>::operator()(const unk::TextureInfo &one, 
        const unk::TextureInfo &two) const {
    return one.getFilename() < two.getFilename();
}
