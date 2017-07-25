// Simple command-line kernel prompt useful for
// controlling the kernel and exploring the system interactively.

/*
KEY WORDS
==========
CONSTANTS:	WHITESPACE, NUM_OF_COMMANDS
VARIABLES:	Command, commands, name, description, function_to_execute, number_of_arguments, arguments, command_string, command_line, command_found
FUNCTIONS:	readline, cprintf, execute_command, run_command_prompt, command_kernel_info, command_help, strcmp, strsplit, start_of_kernel, start_of_uninitialized_data_section, end_of_kernel_code_section, end_of_kernel
=====================================================================================================================================================================================================
*/

#include <inc/stdio.h>
#include <inc/string.h>
#include <inc/memlayout.h>
#include <inc/assert.h>
#include <inc/x86.h>

#include <kern/console.h>
#include <kern/command_prompt.h>

//Structure for each command
struct Command 
{
	char *name;
	char *description;
	// return -1 to force command prompt to exit
	int (*function_to_execute)(int number_of_arguments, char** arguments);
	int arg;
};

//Array of commands. (initialized)
struct Command commands[] = 
{
	{ "help", "Display this list of commands", command_help, 1 },
	{ "kernel_info", "Display information about the kernel", command_kernel_info, 1 },
	{ "add", "Takes 2 integers n1, n2 and displays n1 + n2", command_add, 3 },
	{ "rep", "Echo the given string for N times", command_rep, 3 },
	{ "halt", "Halts the kernel", command_halt, 1 },
};

//Number of commands = size of the array / size of command structure
#define NUM_OF_COMMANDS (sizeof(commands)/sizeof(commands[0]))

//Functions Declaration
int execute_command(char *command_string);
//=====================

//invoke the command prompt
void run_command_prompt()
{
	char *command_line;

	cprintf("\nWelcome to the FOS kernel command prompt!\n");
	cprintf("Type 'help' for a list of commands.\n");
	
	while (1==1) 
	{
		//get command line
		command_line = readline("FOS> ");
		
		//parse and execute the command
		if (command_line != NULL)
			if (execute_command(command_line) < 0)
				break;
	}
}

/***** Kernel command prompt command interpreter *****/

//define the white-space symbols 
#define WHITESPACE " "

//Function to parse any command and execute it 
//(simply by calling its corresponding function)
int execute_command(char *command_string)
{
	int return_value=0;
	int number_of_arguments0;
	//allocate array of char* of size MAX_ARGUMENTS = 16 defined in "inc/string.h" 	
	char *arguments0[MAX_ARGUMENTS];
	strsplit(command_string, "&", arguments0, &number_of_arguments0) ;
	int v=0;
	while(arguments0[v] != NULL)
	{
		// Split the command string into whitespace-separated arguments
		int number_of_arguments;
	//allocate array of char* of size MAX_ARGUMENTS = 16 defined in "inc/string.h" 	
		char *arguments[MAX_ARGUMENTS];
		strsplit(arguments0[v], WHITESPACE, arguments, &number_of_arguments) ;
		if (number_of_arguments == 0)
		{
			v++;
			continue;
		}
	
	// Lookup in the commands array and execute the command
		int command_found = 0;
		int i ;
		for (i = 0; i < NUM_OF_COMMANDS; i++)
		{
			if (strcmp(arguments[0], commands[i].name) == 0)
			{
				command_found = 1;
				break;
			}
		}
	
		if(command_found)
		{
			if(commands[i].arg != number_of_arguments)
			{
				cprintf("Invalid number of arguments\n");
				v++;
				continue;
			}
			//int return_value;
			else
			return_value = commands[i].function_to_execute(number_of_arguments, arguments);			
			//return return_value;
			/*if(i==4)
			break;*/
		}
		else
		{
		//if not found, then it's unknown command
			cprintf("Unknown command '%s'\n", arguments[0]);
			v++;
			continue;
		}
		v++;
	}
	return return_value;
	
}

/***** Implementations of basic kernel command prompt commands *****/

//print name and description of each command
int command_help(int number_of_arguments, char **arguments)
{
	int i;
	int j;
	for (j=0;j< number_of_arguments;j++)
	{
		if (arguments[j]=="&")
			break;
	}
	
	for (i = 0; i < NUM_OF_COMMANDS; i++)
		cprintf("%s - %s\n", commands[i].name, commands[i].description);
	return 0;
}

//print information about kernel addresses and kernel size
int command_kernel_info(int number_of_arguments, char **arguments )
{
	extern char start_of_kernel[], end_of_kernel_code_section[], start_of_uninitialized_data_section[], end_of_kernel[];

	cprintf("Special kernel symbols:\n");
	cprintf("  Start Address of the kernel 			%08x (virt)  %08x (phys)\n", start_of_kernel, start_of_kernel - KERNEL_BASE);
	cprintf("  End address of kernel code  			%08x (virt)  %08x (phys)\n", end_of_kernel_code_section, end_of_kernel_code_section - KERNEL_BASE);
	cprintf("  Start addr. of uninitialized data section 	%08x (virt)  %08x (phys)\n", start_of_uninitialized_data_section, start_of_uninitialized_data_section - KERNEL_BASE);
	cprintf("  End address of the kernel   			%08x (virt)  %08x (phys)\n", end_of_kernel, end_of_kernel - KERNEL_BASE);
	cprintf("Kernel executable memory footprint: %d KB\n",
		(end_of_kernel-start_of_kernel+1023)/1024);
	return 0;
}

//adds two integers
int command_add(int number_of_arguments, char **arguments )
{
	int n1, n2, res;
	n1=strtol(arguments[1], NULL, 10);
	n2=strtol(arguments[2], NULL, 10);
	
	res = n1 + n2 ;
	
	cprintf("%d + %d = %d\n", n1, n2, res);
	return 0;
}

int command_rep(int number_of_arguments, char **arguments )
{
	int n;
	int i;
	n=strtol(arguments[2], NULL, 10);
	for( i = 0 ; i < n ; i++ )
	{
		cprintf(" %s \n",arguments[1]);
	}
	return 0;

}

int command_halt(int number_of_arguments, char **arguments )
{
	return(-1);
}
