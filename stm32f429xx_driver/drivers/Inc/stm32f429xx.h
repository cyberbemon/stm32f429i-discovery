#include<stddef.h>
#include<stdint.h>

#ifndef INC_STM32F429XX_H_
#define INC_STM32F429XX_H_


/*
 * ARM Cortex M4 Processor NVIC ISERx register addresses
 */
#define NO_PR_BITS_IMPLEMENTED	4 //

#define NVIC_ISER_BASEADDR  	0xE000E100U

#define NVIC_PR_BASE_ADDR 	((volatile uint32_t*)0xE000E400)

typedef struct{
	volatile uint32_t ISER0;
	volatile uint32_t ISER1;
	volatile uint32_t ISER2;
	volatile uint32_t ISER3;
}NVIC_ISER_Type;

#define NVIC_ISER ((NVIC_ISER_Type *)NVIC_ISER_BASEADDR)

/*
 * ARM Cortex M4 Processor NVIC ICERx register addresses
 */

#define NVIC_ICER_BASEADDR	0XE000E180U

typedef struct{
	volatile uint32_t ICER0;
	volatile uint32_t ICER1;
	volatile uint32_t ICER2;
	volatile uint32_t ICER3;
}NVIC_ICER_Type;

#define NVIC_ICER ((NVIC_ICER_Type*)NVIC_ICER_BASEADDR)

/*
 *  Arm Cortex M4 Processor NVIC IPR register addresses
 */
#define NVIC_IPR_BASEADDR 			0xE000E400U

typedef struct{
	volatile uint32_t IP[60]; // Array of Interrupt Priority Registers (IPR0 to IPR59)
}NVIC_IP_Type;

#define NVIC_IP ((NVIC_IP_Type *)NVIC_IPR_BASEADDR)

/*
 * Base addresses of flash and SRAM memories
 * */

#define FLASH_BASEADDR				0x08000000U
#define SRAM1_BASEADDR				0x20000000U
#define SRARM2_BASERADDR			0x2001C000U
#define ROM_BASEADDR				0x1FFF0000U
#define SRAM  						SRAM1_BASEADDR

/*
 * AHBx and APBx bus peripheral base addresses
 */

#define PERIPH_BASEADDR				0x40000000U
#define APB1PERIPH_BASEADDR			PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR			0x40010000U
#define AHB1PERIPH_BASEADDR			0x40020000U
#define AHB2PERIPH_BASEADDR			0x50000000U

/*
 * Base addresses of peripherals on AHBI bus
 */

#define GPIOA_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR				(AHB1PERIPH_BASEADDR + 0x2000)
#define GPIOJ_BASEADDR				(AHB1PERIPH_BASEADDR + 0x2400)
#define GPIOK_BASEADDR				(AHB1PERIPH_BASEADDR + 0x2800)
#define RCC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x3800)
/*
 * Base addresses of peripherals on APB1 bus
 */

#define I2C1_BASEADDR				(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR				(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR				(APB1PERIPH_BASEADDR + 0x5C00)
#define SPI2_BASEADDR				(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR				(APB1PERIPH_BASEADDR + 0x3C00)
#define USART2_BASEADDR				(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR				(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR				(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR				(APB1PERIPH_BASEADDR + 0x5000)

/*
 * Base address of peripherals on APB2 bus
 */

#define SPI1_BASEADDR				(APB2PERIPH_BASEADDR + 0x3000)
#define USART1_BASEADDR				(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR				(APB2PERIPH_BASEADDR + 0x1400)
#define EXTI_BASEADDR				(APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR				(APB2PERIPH_BASEADDR + 0x3800)

/*
 *Peripheral register definition structures
 */

typedef struct {
	volatile uint32_t MODER; /* GPIO port mode register */
	volatile uint32_t OTYPER; /* GPIO port output type register */
	volatile uint32_t OSPEEDR; /* GPIO port output speed register */
	volatile uint32_t PUPDR; /* GPIO port pull-up/pull-down register */
	volatile uint32_t IDR; /* GPIO port input data register */
	volatile uint32_t ODR; /* GPIO port output data register */
	volatile uint32_t BSRR; /* GPIO port bit set/reset register */
	volatile uint32_t LCKR; /* GPIO port configuration lock register */
	volatile uint32_t AFR[2]; /* AFR[0]: GPIO alternate function low register, AF[1]: GPIO alternate function high register*/

} GPIO_RegDef_t;

/*RCC Register map
 * Section 6.3.26 in Datasheet*/
typedef struct {
	volatile uint32_t CR; /* RCC clock control register  */
	volatile uint32_t PLLCFGR; /* RCC PLL configuration register */
	volatile uint32_t CFGR; /* RCC clock configuration register */
	volatile uint32_t CIR; /* RCC clock interrupt register */
	volatile uint32_t AHB1RSTR; /* RCC AHB1 peripheral reset register */
	volatile uint32_t AHB2RSTR; /* RCC AHB2 peripheral reset register */
	volatile uint32_t AHB3RSTR; /* RCC AHB3 peripheral reset register */
	uint32_t RESERVED0; /* Reserved. 0x1C */
	volatile uint32_t APB1RSTR; /* RCC APB1 peripheral reset register */
	volatile uint32_t APB2RSTR; /* RCC APB2 peripheral reset register */
	uint32_t RESERVED1[2]; /* Reserved 1. 0x28, Reserved 2. 0x2C */
	volatile uint32_t AHB1ENR; /* RCC AHB1 peripheral clock register */
	volatile uint32_t AHB2ENR; /* RCC AHB2 peripheral clock enable register */
	volatile uint32_t AHB3ENR; /* RCC AHB3 peripheral clock enable register */
	uint32_t RESERVED2; /* Reserved. 0x3C */
	volatile uint32_t APB1ENR; /* RCC APB1 peripheral clock enable register */
	volatile uint32_t APB2ENR; /* RCC APB2 peripheral clock enable register */
	uint32_t RESERVED3[2]; /* Reserved 1. 0x48, Reserved 2. 0x4C */
	volatile uint32_t AHB1LPENR; /* RCC AHB1 peripheral clock enable in low power mode register */
	volatile uint32_t AHB2LPENR; /* RCC AHB2 peripheral clock enable in low power mode register */
	volatile uint32_t AHB3LPENR; /* RCC AHB3 peripheral clock enable in low power mode register */
	uint32_t RESERVED4; /* Reserved. 0x5C */
	volatile uint32_t APB1LPENR; /* RCC APB1 peripheral clock enable in low power mode register  */
	volatile uint32_t APB2LPENR; /* RCC APB2 peripheral clock enabled in low power mode register */
	uint32_t RESERVED5[2]; /* Reserved 1. 0x68, Reserved 2. 0x6C */
	volatile uint32_t BDCR; /* RCC Backup domain control register */
	volatile uint32_t CSR; /* RCC clock control & status register */
	uint32_t RESERVED6[2]; /* Reserved 1. 0x78, Reserved 2. 0x7C */
	volatile uint32_t SSCGR; /* RCC spread spectrum clock generation register */
	volatile uint32_t PLLI2SCFGR; /* RCC PLLI2S configuration register */
	volatile uint32_t PLLSAICFGR; /* RCC PLL configuration register */
	volatile uint32_t DCKCFGR; /* RCC Dedicated Clock Configuration Register */

} RCC_RegDef_t;


/*
 * peripheral register definition structure for EXTI
 */

typedef struct
{
	volatile uint32_t IMR;		/* Interrupt mask register */
	volatile uint32_t EMR;		/* Event mask register */
	volatile uint32_t RTSR;		/* Rising trigger selection register */
	volatile uint32_t FTSR;		/* Falling trigger selection register */
	volatile uint32_t SWIER;	/* Software interrupt event register */
	volatile uint32_t PR;		/* Pending register */

}EXTI_RegDef_t;


/*
 * SYSCFG register map
 */
typedef struct
{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
			 uint32_t RESERVED[2];
	volatile uint32_t CMPCR;

}SYSCFG_RegDef_t;


/*
 * peripheral definitions (Peripheral base addresses typecasted to xxx_RegDef_t)
 */

#define GPIOA						((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB						((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC						((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD						((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE						((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF						((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG						((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH						((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI						((GPIO_RegDef_t*)GPIOI_BASEADDR)
#define GPIOJ						((GPIO_RegDef_t*)GPIOJ_BASEADDR)
#define GPIOK						((GPIO_RegDef_t*)GPIOK_BASEADDR)

#define RCC							((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI						((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG						((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

/*
 * Clock enable macros for GPIOx peripherals.
 */

#define GPIOA_PCLK_EN()				(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()				(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()				(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()				(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()				(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()				(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()				(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()				(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()				(RCC->AHB1ENR |= (1 << 8))
#define GPIOJ_PCLK_EN()				(RCC->AHB1ENR |= (1 << 9))
#define GPIOK_PCLK_EN()				(RCC->AHB1ENR |= (1 << 10))

/*
 * Clock enable macros for I2Cx peripherals.
 */

#define I2C1_PCLK_EN() 				(RCC->APB1ENR |= (1 << 21)
#define I2C2_PCLK_EN() 				(RCC->APB1ENR |= (1 << 22)
#define I2C3_PCLK_EN() 				(RCC->APB1ENR |= (1 << 23)

/*
 * clock enable macros for SPIx peripherals.
 */

#define SPI1_PCLK_EN() 				(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() 				(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() 				(RCC->APB1ENR |= (1 << 15))

/*
 * Clock enable macros for USARTx peripherals
 */
#define USART1_PCLK_EN() 			(RCC->APB2ENR |= (1 << 4))
#define USART6_PCLK_EN() 			(RCC->APB2ENR |= (1 << 5))
#define USART2_PCLK_EN() 			(RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN() 			(RCC->APB1ENR |= (1 << 18))

/*
 * Clock enable macros for SYSCFG peripherals
 */

#define SYSCFG_PLCLK_EN() 			(RCC->APB2ENR |= (1 << 14))

/*
 * Clock disable macros for GPIOx peripherals.
 */

#define GPIOA_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOI_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 8))
#define GPIOH_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 7))
#define GPIOJ_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 9))
#define GPIOK_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 10))

/*
 * Clock disable macros for I2Cx peripherals.
 */

#define I2C1_PCLK_DI() 				(RCC->APB1ENR &= ~(1 << 21)
#define I2C2_PCLK_DI() 				(RCC->APB1ENR &= ~(1 << 22)
#define I2C3_PCLK_DI() 				(RCC->APB1ENR &= ~(1 << 23)

/*
 * Clock disable macros for SPIx peripherals.
 */

#define SPI1_PCLK_DI() 				(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI() 				(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI() 				(RCC->APB1ENR &= ~(1 << 15))
/*
 * Clock disable macros for USARTx peripherals.
 */

#define USART1_PCLK_DI() 			(RCC->APB2ENR &= ~(1 << 4))
#define USART6_PCLK_DI() 			(RCC->APB2ENR &= ~(1 << 5))
#define USART2_PCLK_DI() 			(RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI() 			(RCC->APB1ENR &= ~(1 << 18))

/*
 * Clock disable macros for SYSCFG peripherals.
 */

#define SYSCFG_PLCLK_DI() 			(RCC->APB2ENR &= ~(1 << 14))

/*
 * Macros to reset GPIOx peripherals
 */

#define GPIOA_REG_RESET()			do{(RCC->AHB1RSTR |= (1 <<0)); 	(RCC->AHB1RSTR &= ~(1 << 0)); } while(0)
#define GPIOB_REG_RESET()			do{(RCC->AHB1RSTR |= (1 <<1)); 	(RCC->AHB1RSTR &= ~(1 << 1)); } while(0)
#define GPIOC_REG_RESET()			do{(RCC->AHB1RSTR |= (1 <<2)); 	(RCC->AHB1RSTR &= ~(1 << 2)); } while(0)
#define GPIOD_REG_RESET()			do{(RCC->AHB1RSTR |= (1 <<3)); 	(RCC->AHB1RSTR &= ~(1 << 3)); } while(0)
#define GPIOE_REG_RESET()			do{(RCC->AHB1RSTR |= (1 <<4)); 	(RCC->AHB1RSTR &= ~(1 << 4)); } while(0)
#define GPIOF_REG_RESET()			do{(RCC->AHB1RSTR |= (1 <<5)); 	(RCC->AHB1RSTR &= ~(1 << 5)); } while(0)
#define GPIOG_REG_RESET()			do{(RCC->AHB1RSTR |= (1 <<6)); 	(RCC->AHB1RSTR &= ~(1 << 6)); } while(0)
#define GPIOH_REG_RESET()			do{(RCC->AHB1RSTR |= (1 <<7)); 	(RCC->AHB1RSTR &= ~(1 << 7)); } while(0)
#define GPIOI_REG_RESET()			do{(RCC->AHB1RSTR |= (1 <<8)); 	(RCC->AHB1RSTR &= ~(1 << 8)); } while(0)
#define GPIOJ_REG_RESET()			do{(RCC->AHB1RSTR |= (1 <<10)); (RCC->AHB1RSTR &= ~(1 << 10)); } while(0)
#define GPIOK_REG_RESET()			do{(RCC->AHB1RSTR |= (1 <<11)); (RCC->AHB1RSTR &= ~(1 << 011); } while(0)

/*
 *  returns port code for given GPIOx base address
 */
#define GPIO_BASEADDR_TO_CODE(x)	 ( (x == GPIOA)?0:\
									   (x == GPIOB)?1:\
									   (x == GPIOC)?2:\
									   (x == GPIOD)?3:\
        							   (x == GPIOE)?4:\
        							   (x == GPIOF)?5:\
        							   (x == GPIOG)?6:\
        							   (x == GPIOH)?7:\
        							   (x == GPIOI)?8:0)


// Some generic macros
#define ENABLE 						1
#define DISABLE 					0
#define SET 						ENABLE
#define RESET 						DISABLE
#define GPIO_PIN_SET				SET
#define GPIO_PIN_RESET				RESET

// IRQ number of STM32429xx
#define IRQ_NO_EXTI0		6
#define IRQ_NO_EXTI1		7
#define IRQ_NO_EXTI2		8
#define IRQ_NO_EXTI3		9
#define IRQ_NO_EXTI4		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10	40


/*
 * 				SPI
 */

#define SPI1  				((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2  				((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3  				((SPI_RegDef_t*)SPI3_BASEADDR)

#define FLAG_RESET         RESET
#define FLAG_SET 			SET

/*
 * peripheral register definition structure for SPI
 */
typedef struct
{
	volatile uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
	volatile uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
	volatile uint32_t SR;         /*!< TODO,     										Address offset: 0x08 */
	volatile uint32_t DR;         /*!< TODO,     										Address offset: 0x0C */
	volatile uint32_t CRCPR;      /*!< TODO,     										Address offset: 0x10 */
	volatile uint32_t RXCRCR;     /*!< TODO,     										Address offset: 0x14 */
	volatile uint32_t TXCRCR;     /*!< TODO,     										Address offset: 0x18 */
	volatile uint32_t I2SCFGR;    /*!< TODO,     										Address offset: 0x1C */
	volatile uint32_t I2SPR;      /*!< TODO,     										Address offset: 0x20 */
} SPI_RegDef_t;



/*
* Clock Enable Macros for SPIx peripherals
*/
#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN() (RCC->APB2ENR |= (1 << 13))


/******************************************************************************************
 *Bit position definitions of SPI peripheral
 ******************************************************************************************/
/*
 * Bit position definitions SPI_CR1
 */
#define SPI_CR1_CPHA     				 0
#define SPI_CR1_CPOL      				 1
#define SPI_CR1_MSTR     				 2
#define SPI_CR1_BR   					 3
#define SPI_CR1_SPE     				 6
#define SPI_CR1_LSBFIRST   			 	 7
#define SPI_CR1_SSI     				 8
#define SPI_CR1_SSM      				 9
#define SPI_CR1_RXONLY      		 	10
#define SPI_CR1_DFF     			 	11
#define SPI_CR1_CRCNEXT   			 	12
#define SPI_CR1_CRCEN   			 	13
#define SPI_CR1_BIDIOE     			 	14
#define SPI_CR1_BIDIMODE      			15

/*
 * Bit position definitions SPI_CR2
 */
#define SPI_CR2_RXDMAEN		 			0
#define SPI_CR2_TXDMAEN				 	1
#define SPI_CR2_SSOE				 	2
#define SPI_CR2_FRF						4
#define SPI_CR2_ERRIE					5
#define SPI_CR2_RXNEIE				 	6
#define SPI_CR2_TXEIE					7


/*
 * Bit position definitions SPI_SR
 */
#define SPI_SR_RXNE						0
#define SPI_SR_TXE				 		1
#define SPI_SR_CHSIDE				 	2
#define SPI_SR_UDR					 	3
#define SPI_SR_CRCERR				 	4
#define SPI_SR_MODF					 	5
#define SPI_SR_OVR					 	6
#define SPI_SR_BSY					 	7
#define SPI_SR_FRE					 	8



#endif /* INC_STM32F429XX_H_ */
