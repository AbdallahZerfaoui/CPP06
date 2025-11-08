#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
    std::cout << "Destructor called for Base" << std::endl;
}

Base* generate(void) {

    std::srand(std::time(0)); // Seed the random number generator to avoid same sequence each run

    int randNum = rand() % 3;
    if (randNum == 0) {
        return new A();
    } else if (randNum == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Identified type: A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Identified type: B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Identified type: C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void	identify(Base &p)
{
	try {
		(void) dynamic_cast <A&>(p);
		std::cout << "Identified type: A" << std::endl;
		
	} catch (std::bad_cast &)
	{
		try {
			(void) dynamic_cast <B&>(p);
			std::cout << "Identified type: B" << std::endl;
		} catch (std::bad_cast &)
		{
			try {
				(void) dynamic_cast <C&>(p);
				std::cout << "Identified type: C" << std::endl;
			}
			catch(std::bad_cast &)
			{
				std::cout << "Unknown type" << std::endl;
			}
			
		}
	}
}
