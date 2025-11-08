# pragma once

# include <string>
# include <iostream>
# include <cstdlib> // for rand()
# include <ctime>   // for time()

class Base {
    public:
        virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);