#include "stm32f103xb.h"
//#include <cstdint>
#include <stdint.h>




int main()
{
    clock_init() ;
    pwm_init() ;

    uint16_t brightness = 0 ;
    int8_t direction = 1 ;
    uint32_t step_delay = 200 ;

    while( 1 ){
            TIM2-> CCR1 = brightness ;

            brightness += direction ;
            if( brightness >= 999 )
                direction = -1 ;
            else if ( brightness == 0 )
                direction = 1 ;


            for( volatile uint32_t i = 0 ; i < step_delay ; i++ );
    }


}
