# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

int main() {
	Base* base = generate();
	std::cout << "Identifying using pointer:" << std::endl;
	identify(base);
	std::cout << "Identifying using reference:" << std::endl;
	identify(*base);

	delete base;
	return 0;
}