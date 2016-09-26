/* Unknown Engine Project */

#include "unk/core/TextureInfo.h"
#include "unk/core/Resources.h"

unk::TextureInfo::TextureInfo(std::string name) : Name(name) {
    Width = 0;
    Height = 0;

    Resources::getResources().registerTexture(*this);
}

std::string unk::TextureInfo::getName() const {
    return Name;
}

int unk::TextureInfo::getWidth() {
    getMeasures();
    return Width;
}

int unk::TextureInfo::getHeight() {
    getMeasures();
    return Height;
}

void unk::TextureInfo::getMeasures() {
    if (!Width && !Height)
        Resources::getResources().getTextureMeasures(*this, &Width, &Height);
}

bool std::less<unk::TextureInfo>::operator()(const unk::TextureInfo &one, 
        const unk::TextureInfo &two) const {
    return one.getName() < two.getName();
}
