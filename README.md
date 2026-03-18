# STM32F429i-Discovery Board Driver Library

A custom peripheral driver library for the STM32F429i-Discovery board featuring GPIO and SPI drivers with example applications.

---

## Project Overview

This project provides low-level peripheral drivers for the STM32F429ZI microcontroller, implemented in bare-metal embedded C programming. The drivers give direct access to hardware peripherals without using HAL libraries.

### Key Features

- **GPIO Driver**: Full-featured General Purpose Input/Output support including interrupt handling
- **SPI Driver**: Serial Peripheral Interface support with configurable modes and data formats
- **NVIC Support**: Nested Vector Interrupt Controller configuration for ARM Cortex-M4

---

## Hardware Details

### STM32F429i-Discovery Board

| Specification | Value |
|--------------|-------|
| MCU | STM32F429ZI |
| Core | ARM 32-bit Cortex-M4 with FPU |
| Frequency | Up to 180 MHz |
| Flash | 2 MB |
| SRAM | 256 KB |
| GPIO Pins | 140 I/O ports |

### On-Board Peripherals

- **User LEDs**: Green (PG13) and Red (PG14) LEDs
- **User Button**: Blue push button on PA0

### Bus Architecture

The STM32F429 uses a hierarchical bus system:

| Bus | Peripherals | Max Speed |
|-----|-------------|-----------|
| AHB1 | GPIO ports (A-K), RCC | 180 MHz |
| APB1 | SPI2, SPI3, I2C1-3, USART2-3, UART4-5 | 45 MHz |
| APB2 | SPI1, EXTI, SYSCFG, USART1, USART6 | 90 MHz |

---

## Software Architecture

### Drivers

| Driver | Description |
|--------|-------------|
| **Core (stm32f429xx.h)** | Base addresses, register maps, clock macros, NVIC configuration |
| **GPIO Driver** | Pin initialization, input/output operations, pull-up/pull-down, interrupt handling |
| **SPI Driver** | Master/slave mode, baud rate control, data frame format, polling and interrupt transfers |

### Memory Map

| Region | Address | Size |
|--------|---------|------|
| Flash | 0x0800_0000 | 2 MB |
| SRAM1 | 0x2000_0000 | 192 KB |
| SRAM2 | 0x2001_C000 | 64 KB |
| Peripherals | 0x4000_0000 | - |

### Example Applications

| Application | Description |
|-------------|-------------|
| **led_toggle** | Basic LED blinking demonstration |
| **button_led** | Button-controlled LED toggling |
| **led_interrupt** | External interrupt-driven LED control |

---

## Directory Structure

```
stm32f429i-discovery/
├── Docs/                           # Board documentation and reference manuals
│   ├── cortex_m4_generic_user_guide.pdf
│   ├── mb1075-f429i-e01_schematic.pdf
│   ├── rm0090-stm32f405415-...-reference_manual.pdf
│   └── um1670-discovery-kit-...-user_manual.pdf
│
└── stm32f429xx_driver/
    ├── drivers/
    │   ├── Inc/                    # Driver header files
    │   │   ├── stm32f429xx.h              # Core definitions, register maps
    │   │   ├── stm32f429xx_gpio_driver.h  # GPIO driver interface
    │   │   └── stm32f429xx_spi_driver.h   # SPI driver interface
    │   │
    │   └── src/                    # Driver implementations
    │       ├── stm32f429xx_gpio_driver.c   # GPIO driver source
    │       └── stm32f429xx_spi_driver.c    # SPI driver source
    │
    └── Src/                       # Example applications
        ├── led_toggle.c           # Basic LED blink
        ├── button_led.c           # Button input control
        ├── led_interrupt.c        # Interrupt-based control
        ├── syscalls.c             # System calls (semihosting)
        └── sysmem.c               # Memory functions
```

---

## Getting Started

### Requirements

- ARM GCC toolchain (arm-none-eabi-gcc)
- Make or CMake build system
- OpenOCD or ST-Link tools for flashing
- STM32F429i-Discovery board

### Build and Flash

1. Create a Makefile with your toolchain settings
2. Add linker script and startup code for STM32F429ZI
3. Build: `make`
4. Flash using OpenOCD or ST-Link debugger

### Quick Start with Example

To run the LED toggle example:

1. Configure your build system to compile `led_toggle.c` with the driver sources
2. Flash the resulting binary to the board
3. Observe the green LED (PG13) blinking

---

## Documentation

Reference documentation available in `Docs/`:

| Document | Description |
|----------|-------------|
| **UM1670** | Discovery kit with STM32F429ZI MCU - User manual |
| **RM0090** | STM32F405/415, STM32F407/417, STM32F427/437, STM32F429/439 - Reference manual |
| **MB1075** | STM32F429i-Discovery board schematics |
| **Cortex-M4 Generic User Guide** | ARM Cortex-M4 processor documentation |

---

## References

- [STM32F429ZI Product Page](https://www.st.com/en/microcontrollers-microprocessors/stm32f429zi.html)
- [STM32F429 Discovery Kit](https://www.st.com/en/evaluation-tools/32f429idiscovery.html)
- [ARM Cortex-M4 Documentation](https://developer.arm.com/documentation/dui0553/latest/)
- [STM32F4 HAL Documentation](https://www.st.com/resource/en/user_manual/dm00105879-description-of-stm32f4-hal-and-ll-drivers-stmicroelectronics.pdf)

---

## License

This project is provided as-is for educational purposes.
