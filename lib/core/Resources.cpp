/* Unknown Engine Project */

#include "unk/core/Resources.h"
#include "unk/utils/UnkExceptions.h"

unk::Resources::Resources(Kind kind) : K(kind) {
}

unk::Resources::~Resources() {
}

unk::Resources::Kind unk::Resources::getKind() const {
    return K;
}
