/* Unknown Engine Project */

#include "unk/utils/UnkExceptions.h"

std::string unk::FunctionNotImplementedExceptionMessage = "Function not implemented.";

unk::FunctionNotImplementedException::FunctionNotImplementedException() : function("") {
}

unk::FunctionNotImplementedException::FunctionNotImplementedException(std::string function) : 
    function(function){
}

unk::FunctionNotImplementedException::~FunctionNotImplementedException() throw() {
}

const char *unk::FunctionNotImplementedException::what() const throw() {
    std::string message = FunctionNotImplementedExceptionMessage + " (" + this->function + ")";
    return message.c_str();
}
