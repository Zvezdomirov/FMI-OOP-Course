#include <iostream>
#include "Storage.h"
#include "OnlineStorage.h"
#include <assert.h>

int main() {

	/*Storage st1("123",
		"storage",
		20,
		10);
	std::cout << st1.getHashcode() << std::endl;
	std::cout << st1.getName() << std::endl;
	Storage st2 = st1;
	static_assert(&st2 != &st1, "copy constructor not working!");
	assert(strcmp(st1.getName(), st2.getName()) == 0);
	st2.setName("pesho");
	std::cout << st2.getName();

	Storage st3;
	st3 = st2;
	static_assert(&st3 != &st2, "operator= not working!");*/

	OnlineStorage on_st("3u487yyd12gad21efadf",
		"OOP-Exams-Dont-Steal",
		8, 5.5, 80, 3, 5, 3.5);
	on_st.uploadFile(1300);
	std::cout << on_st.calcPricePerMonth() << std::endl;

	return 0;
}