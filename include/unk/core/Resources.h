/* Unknown Engine Project */

#ifndef UNK_RESOURCES_H
#define UNK_RESOURCES_H

#include "unk/core/TextureInfo.h"

namespace unk {

    /**
     * @brief The base class for the template resources class.
     */
    class Resources {
        public:
            virtual ~Resources();
    };

    /**
     * @brief This template class should be specialized for each
     * resources manager implementation.
     */
    template <class Texture, class Key = TextureInfo, class CustomMap = std::map<Key, Texture> >
        class TResources : public Resources {
        };
}

#endif
