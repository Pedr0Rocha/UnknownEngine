/* Unknown Engine Project */

#ifndef UNK_TEXTURE_INFO_H
#define UNK_TEXTURE_INFO_H

#include <string>

namespace unk {
    /**
     * @brief Represents a texture with name @c Name.
     *
     * @details It has the information of a texture, such as its @ Name and
     * its dimension (@c Width and @c Height).
     */
    class TextureInfo {
        private:
            std::string Filename;

        public:
            int Width;
            int Height;

            TextureInfo(std::string filename);

            std::string getFilename() const;

    };
}

namespace std {
    template <>
        struct less<unk::TextureInfo> {
            bool operator()(const unk::TextureInfo &one, const unk::TextureInfo &two) const;
        };
}

#endif
