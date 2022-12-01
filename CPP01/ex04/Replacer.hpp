#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>

class Replacer {

    public:
        void    getArg(char *filename, char *s1, char *s2);
        void    replace(void);

    private:
        char    *av1;
        char    *av2;
        char    *av3;

        std::ifstream   infile;
        std::ofstream   outfile;
        std::string     name;
        std::string     str;
        std::size_t     found;
        int             s1size;
        int             s2size;
};

#endif
