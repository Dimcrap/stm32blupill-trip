TARGET = breathing-led
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m3 -mthumb -Os -Wall -g
CFLAGS += -DSTM32F103xB
CFLAGS += -Iinclude

#LDFLAGS = -T STM32F103C8Tx_FLASH.ld -nostdlib -lc -lgcc

LDFLAGS = -T STM32F103XB_FLASH.ld -specs=nosys.specs -specs=nano.specs
#need some including path here  for stm32 headers and sources
SRCS = src/main.c src/system_stm32f1xx.c src/startup_stm32f103.s

all: $(TARGET).bin

$(TARGET).elf: $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

flash: $(TARGET).bin
	openocd -f openocd.cfg -c "program $< 0x08000000 verify reset exit"

clean:
	rm -f $(TARGET).elf $(TARGET).bin

.PHONY: all flash clean
