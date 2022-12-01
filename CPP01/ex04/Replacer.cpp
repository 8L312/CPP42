#include "Replacer.hpp"

 void   Replacer::getArg(char *filename, char *s1, char *s2)
{
    this->av1 = filename;
    this->av2 = s1;
    this->av3 = s2;

    return ;
}

void    Replacer::replace(void)
{
    this->s1size = 0;
    this->s2size = 0;

    while (this->av2[this->s1size] != '\0')
		this->s1size++;
	while (this->av3[this->s2size] != '\0')
		this->s2size++;

	this->name.insert(0, ".replace");
	this->name.insert(0, this->av1);
	this->outfile.open(this->name.c_str());

	this->infile.open(this->av1, std::ios::in);

	while (!this->infile.eof())
	{
		getline(this->infile, this->str);
		this->found = 0;
		while (this->found != std::string::npos)
		{
			this->found = this->str.find(this->av2, this->found);
			if (this->found != std::string::npos)
			{
				this->str.insert(this->found, this->av3);
				this->str.erase(this->found + this->s2size, this->s1size);
				this->found++;
			}
		}
		if (!this->infile.eof())
			this->outfile << this->str << std::endl;
	}
	this->infile.close();
	this->outfile.close();
	
	return ;
}
