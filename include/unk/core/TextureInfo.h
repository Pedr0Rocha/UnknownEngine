/* Unknown Engine Project */

#ifndef UNK_TEXTURE_INFO_H
#define UNK_TEXTURE_INFO_H

#include <string>

namespace unk {
    class TextureInfo {
        private:
            std::string Name;

        public:
            TextureInfo(std::string name);

            std::string getName() const;

    };
}

namespace std {
    template <>
        struct less<unk::TextureInfo> {
            bool operator()(const unk::TextureInfo &one, const unk::TextureInfo &two) const;
        };
}

#endif
