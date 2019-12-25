#include <iostream>
#include <ctime>

using namespace std;

struct SingleLinkedList {
	int key;
	char char_data;
	double double_data;
	struct SingleLinkedList* next;
	struct SingleLinkedList* previous;
}*start, * last;

int counter = 0;

SingleLinkedList* create_node(int key)
{
	srand(time(NULL));
	counter++;

	struct SingleLinkedList* temp;
	temp = new(struct SingleLinkedList);

	temp->key = key;
	temp->char_data = 'T';
	temp->double_data = rand() % 5000 + 5;

	temp->next = NULL;
	temp->previous = NULL;

	return temp;
}

void insert_start()
{
	srand(time(NULL));
	int key = rand() % 10000;

	struct SingleLinkedList* temp;

	temp = create_node(key);

	if (start == last && start == NULL)
	{
		cout << "An item inserted into an empty list" << endl;

		start = last = temp;
		start->next = last->next = NULL;
		start->previous = last->previous = NULL;
	}
	else
	{
		temp->next = start;
		start->previous = temp;

		start = temp;

		start->previous = last;
		last->next = start;

		cout << "The item has been inserted" << endl;
	}
}
void insert_end()
{
	srand(time(NULL));
	int key = rand() % 99999 + 1;

	bool flag = false;

	struct SingleLinkedList* temp, * auxiliary_element;
	auxiliary_element = start;

	for (int i = 0; i < counter; i++) {

		if (auxiliary_element->key != key)
		{
			auxiliary_element = auxiliary_element->next;
		}
		else {
			cout << "Element already exists" << endl;

			flag = true;
			key = rand() % 99999 + 1;

			i = 0;
			auxiliary_element = start;
		}
	}

	temp = create_node(key);
	last->next = temp;
	temp->previous = last;

	last = temp;
	start->previous = last;
	last->next = start;
}
void search(int key)
{
	struct SingleLinkedList* auxiliary_element;
	bool flag = false;

	if (start == last && start == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}

	auxiliary_element = start;

	for (int i = 0; i < counter; i++)
	{
		if (auxiliary_element->key == key)
		{
			cout << "Element " << key << " Found. Data: \n" << auxiliary_element->double_data << endl;
			flag = true;
			cout << auxiliary_element->char_data << endl;
		}
	}
	if (flag == false)
		cout << "Item not found in the list" << endl;

}

void show_the_number_of_nodes() {

	cout << "The number of lists node is : " << counter << endl;

}

void Usuwanie_po_keyu(int key)
{
	SingleLinkedList* auxiliary_element;

	if (start == last && start == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}
	auxiliary_element = start;

	for (int i = 0; i < counter; i++) {
		if (auxiliary_element->key == key) {

			counter--;
			free(auxiliary_element);
			break;
		}
		else if (i == (counter - 1) && auxiliary_element->key != key) {
			cout << "There is no item with this key" << endl;
		}
		else {
			auxiliary_element = auxiliary_element->next;
		}
	}
}

void show_the_list_from_the_beginning(int N)
{
	struct SingleLinkedList* auxiliary_element;

	if (start == last && start == NULL)
	{
		cout << "The list is empty !" << endl;
		return;
	}

	if (counter < N) {
		N = counter;
	}
	auxiliary_element = start;

	for (int i = 0; i < N; i++)
	{
		auxiliary_element = auxiliary_element->next;
		cout << "node key : " << auxiliary_element->key << endl;
	}
}
void show_the_list_from_the_end(int N)
{
	struct SingleLinkedList* auxiliary_element;

	if (start == last && start == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}

	if (counter < N) {
		N = counter;
	}
	auxiliary_element = last;

	for (int i = N; i > 0; i--)
	{
		auxiliary_element = auxiliary_element->previous;
		cout << "node key : " << auxiliary_element->key << endl;
	}
}

void remove_all_nodes() {
	struct SingleLinkedList* auxiliary_element, * tmp;
	auxiliary_element = start;

	for (int i = 0; i < counter; i++) {
		tmp = auxiliary_element->next;
		free(auxiliary_element);
		auxiliary_element = tmp;
	}
}

int main()
{
	clock_t begin, end;
	double time_spent;
	begin = clock();
	insert_start();
	insert_end();
	insert_end();

	for (int i = 0; i < 6; i++) {
		insert_end();
	}

	show_the_list_from_the_beginning(53);

	search(34121);

	cout << endl;

	show_the_list_from_the_end(53);

	search(68);

	show_the_number_of_nodes();

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << time_spent << endl;

	remove_all_nodes();

	getchar();
	getchar();
	return 0;
}