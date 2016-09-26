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
            std::string Name;
            int Width;
            int Height;

        public:
            /// @brief As soon as it is instantiated, it tries to register the texture
            /// by calling the @c Resources class function.
            TextureInfo(std::string name);

            std::string getName() const;

            /**
             * @brief Gets the @c width of the texture. 
             *
             * @details By the time this class is instantiated, both @c Width and @c Height
             * are initialized with zero. However, after the call of the loading operation
             * when this function is called, it retrieves both the dimension by calling the
             * function @c getMeasures from @c Resources class.
             */
            int getWidth();

            /**
             * @brief Gets the @c width of the texture. 
             *
             * @details By the time this class is instantiated, both @c Width and @c Height
             * are initialized with zero. However, after the call of the loading operation
             * when this function is called, it retrieves both the dimension by calling the
             * function @c getMeasures from @c Resources class.
             */
            int getHeight();

        private:
            void getMeasures();

    };
}

namespace std {
    template <>
        struct less<unk::TextureInfo> {
            bool operator()(const unk::TextureInfo &one, const unk::TextureInfo &two) const;
        };
}

#endif
