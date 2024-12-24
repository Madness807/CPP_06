#include "Serializer.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
Serializer::Serializer(void) {}

Serializer::Serializer(Serializer const &src) {
    *this = src;
}

Serializer::~Serializer(void) {}


//##################################################################
//	            	Operateur d'affectation		                   #
//##################################################################
Serializer &Serializer::operator=(Serializer const &rhs) {
    (void)rhs;
    return *this;
}

//##################################################################
//                          Methodes                               #
//##################################################################

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}














