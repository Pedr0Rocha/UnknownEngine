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
        };

}

#endif
