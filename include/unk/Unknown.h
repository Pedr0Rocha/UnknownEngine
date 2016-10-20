/* Unknown Engine Project */

#ifndef UNKNOWN_H
#define UNKNOWN_H

namespace unk {

    /// @brief Returns wheather the @p base pointer points to an instance 
    /// of the @p Derived class.
    template <class Derived, class Base>
        bool isInstanceOf(const Base *base);

    /// @brief Gets the @p base casted to @p Derived class, if it points
    /// to an instance of that type.
    template <class Derived, class Base>
        Derived *getInstanceOf(Base *base);

}

template <class Derived, class Base>
bool isInstanceOf(const Base *base) {
    return Derived::isInstance(base);
}

template <class Derived, class Base>
Derived* unk::getInstanceOf(Base *base) {
    if (isInstanceOf<Derived>(base))
        return static_cast<Derived*>(base);
    return nullptr;
}

#endif
