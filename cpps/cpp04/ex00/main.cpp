#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongj = new WrongCat();

	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrongj->getType() << " " << std::endl;



	std::cout << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();
	wrongj -> makeSound();

	std::cout << std::endl;
	delete wrongj;
	delete i;
	delete j;
	delete meta;
}