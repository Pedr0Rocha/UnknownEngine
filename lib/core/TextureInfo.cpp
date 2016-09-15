/* Unknown Engine Project */

#include "unk/core/TextureInfo.h"
#include "unk/core/Resources.h"

unk::TextureInfo::TextureInfo(std::string name) : Name(name) {
    Resources::registerTexture(*this);
}

std::string unk::TextureInfo::getName() const {
    return Name;
}

bool std::less<unk::TextureInfo>::operator()(const unk::TextureInfo &one, 
        const unk::TextureInfo &two) const {
    return one.getName() < two.getName();
}
