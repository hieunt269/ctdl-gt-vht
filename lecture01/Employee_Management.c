#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int id;
	char name[50];
	float salary;
} employee;

void alloc_list_employee (employee **list);
int order_employee (employee *person, int id_employee);
void add_employee (employee *person);
void print_a_employee (employee *person);
void edit_employee (employee *person);
void print_list_employee (employee *person);

int number_employee = 0;

int main()
{
	employee *person = NULL;
	int user_choice;

//	printf("Current employee number: %d \n", number_employee);

	while(1) {
		printf("===================EMPLOYEE MANAGEMENT=================\n");
		printf("Enter your request: \n");
		printf("[1] ADD A NEW EMPLOYEE\n");
		printf("[2] SHOW INFO OF A EMPLOYEE\n");
		printf("[3] EDIT INFO OF A EMPLOYEE\n");
		printf("[4] SHOW LIST OF ALL EMPLOYEE\n");
		printf("[5] EXIT...\n");
		printf("Your choice: ");

		scanf("%d", &user_choice);

		switch (user_choice)
		{
			case 1:
				alloc_list_employee(&person);
				add_employee(person);
				break;
			case 2:
				print_a_employee(person);
				break;
			case 3:
				edit_employee(person);
				break;
			case 4:
				print_list_employee(person);
				break;
			case 5:
				return 0;
		}
	}

	free(person);

	return 0;
}

void alloc_list_employee (employee **list)
{
	if (number_employee == 0)
	{
		*list = (employee *) malloc(sizeof(employee));
	}
	else
	{
		*list == (employee *) realloc(*list, number_employee);
	}

	number_employee++;
}

int order_employee (employee *person, int id_employee)
{
	for (int i = 0; i <= (number_employee - 1); ++i)
	{
		if ((person + i)->id == id_employee)
		{
			return (i + 1);
		}
	}
	return 0;
}

void add_employee (employee *person)
{
	employee *cur_employee_order = person + number_employee - 1;

	printf("Enter new employee info: \n");

	printf("(1) Enter employee's ID: ");
	scanf("%d", &cur_employee_order->id);

    getchar();
	printf("(2) Enter employee's name: ");
	fgets(cur_employee_order->name, sizeof(cur_employee_order->name), stdin);

	printf("(3) Enter employee's salary: ");
	scanf("%f", &cur_employee_order->salary);
}

void print_a_employee (employee *person)
{
	int id_employee = 0;
	int index_person = 0;

	printf("Enter employee ID: ");
	scanf("%d", &id_employee);

	index_person = order_employee(person, id_employee);

	if (index_person == 0)
	{
		printf("No employee has id %d!\n", id_employee);
	}
	else
	{
		printf("Employee ID %d have name: ", (person + index_person - 1)->id);
		puts((person + index_person - 1)->name);
		printf("\tSalary: %f \n", (person + index_person - 1)->salary);
	}
}

void edit_employee (employee *person)
{
	int id_employee = 0;
	int index_person = 0;

	printf("Enter employee ID to edit info: ");
	scanf("%d", &id_employee);

	index_person = order_employee(person, id_employee);

	if (index_person == 0)
	{
		printf("No employee has id %d!\n", id_employee);
	}
	else
	{
		employee *cur_employee_order = person + number_employee - 1;

		printf("Employee ID %d have name: ", (person + index_person - 1)->id);
		puts((person + index_person - 1)->name);
		printf("Salary: %f \n", (person + index_person - 1)->salary);

		printf("Enter new info: \n");

		printf("(1) New employee's ID: ");
		scanf("%d", &cur_employee_order->id);

	    getchar();
		printf("(2) New employee's name: ");
		fgets(cur_employee_order->name, sizeof(cur_employee_order->name), stdin);

		printf("(3) New employee's salary: ");
		scanf("%f", &cur_employee_order->salary);
	}

}

void print_list_employee (employee *person)
{
	printf("LIST OF ALL EMPLOYEES: \n");
	for (int i = 0; i <= (number_employee - 1); ++i)
	{
		printf("Employee ID %d have name: ", (person + i)->id);
		puts((person + i)->name);
		printf("\tSalary: %f \n", (person + i)->salary);
	}
}
