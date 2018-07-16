#include <stdio.h>

#include "derivative.h"
#include "CLK/CLK.h"
#include "DbgConsole/DbgConsole.h"
#include "FLASH/flash.h"

static int i = 0;

int main(void)
{
	/* Init clock for serial */
	Clk_Init();

	/* Init debgging console */
	DbgConsole_Init(UART2, 16000000, 9600);

	/* Init flash */
	printf("\nInitializaing flash memory...");
	uint16_t flash_init_result = FLASH_Init(16000000);
	if (flash_init_result != FLASH_ERR_SUCCESS)
	{
		printf("failed\n");
		printf("Fail code: %d\n", flash_init_result);
		while (1)
			;
	}
	printf("done\n");
	printf("Flash sector size\t: %d\n", FLASH_SECTOR_SIZE);
	printf("Flash start address\t: 0x%.8X\n", FLASH_START_ADDRESS);
	printf("EEPROM start address\t: 0x%.8X\n", EEPROM_START_ADDRESS);

	/* Begin test */
	uint32_t start_write_address = 0x2000;
	uint8_t *payload = "Hello world!";
	uint16_t size = 12;

	printf("\nWriting '%s' (%d bytes) at address 0x%.8X...", payload, size, start_write_address);
	uint16_t flash_write_result = FLASH_Program(start_write_address, payload, size);

	if (flash_write_result != FLASH_ERR_SUCCESS)
	{
		printf("failed\n");
		printf("Fail code: %d\n", flash_write_result);
		while(1);
	}
	printf("done\n");

	for (;;)
	{
		i++;
	}
	/* Never leave main */
	return 0;
}

