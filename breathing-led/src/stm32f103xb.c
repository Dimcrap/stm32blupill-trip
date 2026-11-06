#include "../include/stm32f103xb.h"


static void clock_init(void)
{
    RCC -> CR |= RCC_CR_HSEON ;
    while( !(RCC-> CR & RCC_CR_HSERDY)) ;

    FLASH -> ACR |= FLASH_ACR_LATENCY_2 ;

    RCC->CFGR |= RCC_CFGR_PLLSRC;
    RCC->CFGR |= RCC_CFGR_PLLMULL9;

    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));


    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

}

static void pwm_init(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    GPIOA->CRL &= ~(0xF << 0);
    GPIOA->CRL |= (0xB << 0);

    TIM2->PSC = 72 - 1;
    TIM2->ARR = 1000 - 1;
    TIM2->CCR1 = 0;

    TIM2->CCMR1 |= (0x6 << 4) | TIM_CCMR1_OC1PE;
    TIM2->CCER |= TIM_CCER_CC1E;
    TIM2->CR1 |= TIM_CR1_CEN;
}
