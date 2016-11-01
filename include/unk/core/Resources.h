/* Unknown Engine Project */

#ifndef UNK_RESOURCES_H
#define UNK_RESOURCES_H

#include "unk/core/TextureInfo.h"

#include <map>

namespace unk {

    /**
     * @brief The base class for the template resources class.
     */
    class Resources {
        public:
            /**
             * @brief Enum with all kinds of @c Resources available.
             */
            enum class Kind {
                SDL
            };

        protected:
            Kind K;

            Resources(Kind kind);

        public:
            virtual ~Resources();

            /// @brief Returns the @c Kind of the resource. Is called by
            /// the function @p isInstanceOf.
            Kind getKind() const;
    };

    /**
     * @brief This template class should be specialized for each
     * resources manager implementation.
     */
    template <class Texture, class Key = TextureInfo, class CustomMap = std::map<Key, Texture> >
        class TResources : public Resources {
            protected:
                CustomMap Map;

                TResources<Texture, Key, CustomMap>(Kind kind);

            public:
                virtual ~TResources();
                
                /// @brief Returns true if the texture is loaded.
                virtual bool hasTexture(TextureInfo info) = 0;
                /// @brief Destroys all previously loaded textures.
                virtual void destroyAll() = 0;
                /// @brief Returns the @c Texture related to @c info.
                virtual Texture getTexture(TextureInfo info) = 0;

        };

}

template <class Texture, class Key, class CustomMap>
unk::TResources<Texture, Key, CustomMap>::TResources(Kind kind) : Resources(kind) {

}

template <class Texture, class Key, class CustomMap>
unk::TResources<Texture, Key, CustomMap>::~TResources() {

}


#endif
