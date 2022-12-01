#include "Array.hpp"
#define MAX_VAL 750

int	main()
{
{	
	Array<int>	empty;
	Array<int>	a(5);

	std::cout << "empty size = " << empty.size() << std::endl;
	std::cout << "a size = " << a.size() << std::endl;

	for (int i = 0; i < 4; i++)
		std::cout << "elem of a nº" << i << " = " << a[i] << std::endl;

	a[0] = 0;
	a[1] = 10;
	a[2] = 20;
	a[3] = 30;
	a[4] = 40;
//	a[5] = 50;

	for (int i = 0; i < 5; i++)
		std::cout << "elem of a nº" << i << " = " << a.getElem(i) << std::endl;

	std::cout << "\n\n";

	Array<int>	b(a);

	int i = 0;
	a[i] = 999;
	b[i] = 42;
	
	std::cout << "elem of a nº" << i << " = " << a[i] << std::endl;
	std::cout << "elem of b nº" << i << " = " << b[i] << std::endl;
}

	std::cout << "\n\n\n";
{
	Array<std::string>	empty;
	Array<std::string>	a(4);

	std::cout << "empty size = " << empty.size() << std::endl;
	std::cout << "a size = " << a.size() << std::endl;

	for (int i = 0; i < 4; i++)
		std::cout << "elem of a nº" << i << " = " << a[i] << std::endl;

	a[0] = "ein";
	a[1] = "zwei";
	a[2] = "drei";
	a[3] = "vier";
//	a[4] = "cinq";
	
	for (int i = 0; i < 4; i++)
		std::cout << "elem of a nº" << i << " = " << a[i] << std::endl;

	std::cout << "\n\n";

	Array<std::string>	b;
	b = a;

	int i = 2;
	a[i] = "coucou je suis un element de a";
	b[i] = "et moi un elephant de mer";

	std::cout << "elem of a nº" << i << " = " << a[i] << std::endl;
	std::cout << "elem of b nº" << i << " = " << b[i] << std::endl;
}

	std::cout << "\n\n";

{
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << "Tout va tres bien :)\n";
}
	return (0);
}


#include <iostream>
/*int	main()
{
	int *a = new int();
	std::cout << "*a = " << *a << std::endl;

	int n = 4;
	int	*tab = new int[n];

	std::cout << "*tab = " << *tab << std::endl;

	for (int i = 0; i < n; i++)
		std::cout << "tab [" << i << "] = " << tab[i] << std::endl;
	delete[] (tab);

	return (0);
}*/
