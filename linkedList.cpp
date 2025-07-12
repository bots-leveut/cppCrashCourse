#include <cstdio>
//using namespace std;

struct Element
{
	Element *prev{};
	Element *next{};
	void insert_before(Element* new_element){
		new_element->prev = this->prev;
		new_element->next = this;
		if (this->prev)
			this->prev->next = new_element;
		this->prev = new_element;
	}
	void insert_after(Element *new_element)
	{
		new_element->next = this->next;
		new_element->prev = this;
		if(this->next)
			this->next->prev = new_element;
		this->next = new_element;
	}
	char prefix[2];
	short operating_number;
};

int main(int argc, char *argv[])
{
	Element trooper0,  trooper1, trooper2, trooper3;
	trooper1.prefix[0] = 'U';
	trooper1.prefix[1] = 'K';
	trooper1.operating_number = 62;
	trooper1.insert_after(&trooper2);
	trooper2.prefix[0] = 'C';
	trooper2.prefix[1] = 'D';
	trooper2.operating_number = 243;
	trooper2.insert_after(&trooper3);
	trooper3.prefix[0] = 'U';
	trooper3.prefix[1] = 'S';
	trooper3.operating_number = 001;
	trooper1.insert_before(&trooper0);
	trooper0.prefix[0] = 'S';
	trooper0.prefix[1] = 'K';
	trooper0.operating_number = 007;
	
	for (Element *cursor = &trooper0; cursor; cursor = cursor->next)
	{
		printf("stormtrooper %c%c - %d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
	}
	
	printf("\nprinting in reverse order ...\n\n");

	for(Element *cursor = &trooper3; cursor; cursor = cursor->prev){
		printf("stormtrooper %c%c - %d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
	}
	return 0;
}