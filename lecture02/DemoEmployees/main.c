//
//  main.c
//  DemoEmployees
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include "employee.h"

#define MAX_EMPLOYEES 10
#define EXIT          0
int main()
{
    employee employee_list[MAX_EMPLOYEES];
    int curr = 0;
    int running = 1;
    
    while (running)
    {
        print_menu();
        int option = get_option();
        do_task(option, employee_list, curr);
        
        if (option == EXIT) running = 0;
    }
    return 0;
}
