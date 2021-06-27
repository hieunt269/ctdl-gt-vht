//
//  employee.h
//  DemoEmployees
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef employee_h
#define employee_h

#define ADD_EMPLOYEE    1
#define PRINT_EMPLOYEES 2

typedef struct
{
    int id;
    char *name;
    float salary;
} employee;

void print_menu()
{
    
}

int get_option()
{
    return 0;
}

void do_task(const int option,
             employee employee_list[],
             const int curr)
{
    switch (option)
    {
        case ADD_EMPLOYEE   : add_employee(employee_list, curr); break;
        case PRINT_EMPLOYEES: print_all(employee_list, curr);    break;
        default: print_error_msg("Invalid option!);
    }
}
            
            
#endif /* employee_h */
