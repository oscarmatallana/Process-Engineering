/* ========================================================= */
/*                                                           */
/*   File   : smart_kettle.c                                 */
/*   Author : Oscar Matallana                                */
/*   Profile: Process Engineering × Software Engineering     */
/*                                                           */
/*   Description:                                            */
/*   Educational simulation of a simple temperature control  */
/*   loop for a household electric kettle using C.           */
/*                                                           */
/*   Concepts practiced:                                     */
/*   - Control logic and automation basics                   */
/*   - Loops and conditional statements                      */
/*   - Input validation and safety limits                    */
/*   - Systems thinking and process-oriented programming     */
/*                                                           */
/* ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int	is_number(char *str)
{
	int	i;

	i = 0;

	if (str[0] == '\0')
		return (0);

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

int	main(int argc, char **argv)
{
	int	current_temp;
	int	target_temp;

	if (argc != 3)
	{
		printf("Usage: ./smart_kettle <current_temp> <target_temp>\n");
		return (1);
	}

	if (!is_number(argv[1]) || !is_number(argv[2]))
	{
		printf("Error: Temperatures must contain only numbers.\n");
		printf("Valid range: 0°C to 100°C.\n");
		return (1);
	}

	current_temp = atoi(argv[1]);
	target_temp = atoi(argv[2]);

	if (current_temp < 0 || current_temp > 100
		|| target_temp < 0 || target_temp > 100)
	{
		printf("Error: Temperature must be between 0°C and 100°C.\n");
		return (1);
	}

	if (current_temp > target_temp)
	{
		printf("Water is already hotter than the target temperature.\n");
		return (0);
	}

	printf("Heating from %d°C to %d°C...\n",
		current_temp, target_temp);

	while (current_temp < target_temp)
	{
		current_temp++;
		printf("Current temperature: %d°C\n", current_temp);
	}

	printf("Target temperature reached.\n");

	return (0);
}
