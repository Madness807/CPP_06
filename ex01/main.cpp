#include <iostream>
#include "Serializer.hpp"

int main(void)
{
////////////////////////////////////////////////////////////////////////////////
	std::cout << "" << std::endl;
	std::cout << "=== Test 1: Comparaison des pointeurs ===" << std::endl;
	Data* original = new Data;
	original->number = 42;
	original->character = 'A';
	original->text = "Bonjour";

	uintptr_t raw = Serializer::serialize(original);
	Data* deserialized = Serializer::deserialize(raw);

	std::cout << "Pointeur original   : " << original << std::endl;
	std::cout << "Pointeur déserialisé: " << deserialized << std::endl;
	std::cout << "Les pointeurs sont " << (original == deserialized ? "identiques" : "différents") << std::endl;

	delete original;

////////////////////////////////////////////////////////////////////////////////
	std::cout << "" << std::endl;
	std::cout << "\n=== Test 2: Accès aux données ===" << std::endl;
	Data* data = new Data;
	data->number = 21;
	data->character = 'B';
	data->text = "Test";

	std::cout << "Données originales  : " << data->number << ", " 
			  << data->character << ", " << data->text << std::endl;

	uintptr_t serialized = Serializer::serialize(data);
	Data* result = Serializer::deserialize(serialized);

	std::cout << "Données récupérées  : " << result->number << ", " 
			  << result->character << ", " << result->text << std::endl;

	delete data;

	return 0;
}