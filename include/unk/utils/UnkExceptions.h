/* Unknown Engine Project */

#ifndef UNK_UNK_EXCEPTIONS_H
#define UNK_UNK_EXCEPTIONS_H

#include <exception>
#include <string>

namespace unk {

    extern std::string FunctionNotImplementedExceptionMessage;

    /**
     * @brief Exception raised if the function is not implemented.
     */
    class FunctionNotImplementedException : public std::exception {
        private:
            std::string function;

        public:
            /// @brief Constructs the object without the function name.
            FunctionNotImplementedException();
            /// @brief Constructs the object with the function name in the error message.
            FunctionNotImplementedException(std::string function);

            ~FunctionNotImplementedException() throw();

            /// @brief Returns the exception message given.
            virtual const char *what() const throw();
    };
}

#endif
