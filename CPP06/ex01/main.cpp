#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data		*data = new Data;
	uintptr_t	ptr;

	Serializer	convert;

	data->one = 'c';
	data->two = 42;
	data->three = 12.34f;

	std::cout << "data adress = " << data << std::endl;
	std::cout << "data contains :" << std::endl
		<< data->one << std::endl
		<< data->two << std::endl
		<< data->three << std::endl;
	
	ptr = convert.serialize(data);
	std::cout << "uintptr_t value = " << ptr << std::endl;

	Data		*data2 = convert.deserialize(ptr);
	std::cout << "data adress = " << data2 << std::endl;
	std::cout << "data2 contains :" << std::endl
		<< data2->one << std::endl
		<< data2->two << std::endl
		<< data2->three << std::endl;

	delete (data);
	return (0);
}
