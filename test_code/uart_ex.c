#include "clocks_and_modes.h"


//Clock enable
#define PCC_BASE			(0x40065000)
#define PCC_PORTC			*((volatile unsigned*)(PCC_BASE + 0x12C))
#define PCC_LPUART1			*((volatile unsigned*)(PCC_BASE + 0x1AC))

#define PCS_BITS			24
#define CGC_BIT				30

//LPUART1 Reg
#define LPUART1_BASE		(0x4006B000)
#define LPUART1_BAUD		*((volatile unsigned*)(LPUART1_BASE + 0x10))
#define LPUART1_STAT		*((volatile unsigned*)(LPUART1_BASE + 0x14))
#define LPUART1_CTRL		*((volatile unsigned*)(LPUART1_BASE + 0x18))
#define LPUART1_DATA		*((volatile unsigned*)(LPUART1_BASE + 0x1C))

#define M10_BIT			29
#define OSR_BITS		24
#define SBNS_BIT		13
#define SBR_BITS		0
#define TDRE_BIT		23
#define RDRF_BIT		21
#define TE_BIT			19
#define RE_BIT			18
#define M7_BIT			11
#define M_BIT			4
#define PE_BIT			1

// Port Reg
#define PORTC_BASE			(0x4004B000)
#define PORTC_PCR6			*((volatile unsigned*)(PORTC_BASE + 0x18))
#define PORTC_PCR7			*((volatile unsigned*)(PORTC_BASE + 0x1C))

#define MUX_BITS		8





void SOSC_init_8MHz(void)
{
	/*!
	 * SOSC Initialization (8 MHz):
	 * ===================================================
	 */
	SCG->SOSCDIV = SCG_SOSCDIV_SOSCDIV1(1)|
				   SCG_SOSCDIV_SOSCDIV2(1);  	/* SOSCDIV1 & SOSCDIV2 =1: divide by 1 		*/
	SCG->SOSCCFG  =	SCG_SOSCCFG_RANGE(2)|		/* Range=2: Medium freq (SOSC betw 1MHz-8MHz) 	*/
					SCG_SOSCCFG_EREFS_MASK;		/* HGO=0:   Config xtal osc for low power 		*/
  	  	  	  	  	  	  	  	  	  	  	  	/* EREFS=1: Input is external XTAL 			*/

  while(SCG->SOSCCSR & SCG_SOSCCSR_LK_MASK); 	/* Ensure SOSCCSR unlocked 							*/
  SCG->SOSCCSR = SCG_SOSCCSR_SOSCEN_MASK; 		/* LK=0:          SOSCCSR can be written 				*/
												/* SOSCCMRE=0:    OSC CLK monitor IRQ if enabled 		*/
												/* SOSCCM=0:      OSC CLK monitor disabled 			*/
												/* SOSCERCLKEN=0: Sys OSC 3V ERCLK output clk disabled */
												/* SOSCLPEN=0:    Sys OSC disabled in VLP modes 		*/
												/* SOSCSTEN=0:    Sys OSC disabled in Stop modes 		*/
												/* SOSCEN=1:      Enable oscillator 					*/

while(!(SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK));	/* Wait for sys OSC clk valid */
}

void SPLL_init_160MHz(void)
{
	/*!
	 * SPLL Initialization (160 MHz):
	 * ===================================================
	 */
  while(SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK); 	/* Ensure SPLLCSR unlocked 				*/
  SCG->SPLLCSR &= ~SCG_SPLLCSR_SPLLEN_MASK;  	/* SPLLEN=0: SPLL is disabled (default) 	*/

  SCG->SPLLDIV |= 	SCG_SPLLDIV_SPLLDIV1(2)|	/* SPLLDIV1 divide by 2 */
					SCG_SPLLDIV_SPLLDIV2(3);  	/* SPLLDIV2 divide by 4 */

  SCG->SPLLCFG = SCG_SPLLCFG_MULT(24);			/* PREDIV=0: Divide SOSC_CLK by 0+1=1 		*/
  	  	  	  	  	  	  	  	  	  	  		/* MULT=24:  Multiply sys pll by 4+24=40 	*/
										  		/* SPLL_CLK = 8MHz / 1 * 40 / 2 = 160 MHz 	*/

  while(SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK); 	/* Ensure SPLLCSR unlocked 						*/
  SCG->SPLLCSR |= SCG_SPLLCSR_SPLLEN_MASK; 		/* LK=0:        SPLLCSR can be written 			*/
                             	 	 	 		/* SPLLCMRE=0:  SPLL CLK monitor IRQ if enabled 	*/
                             	 	 	 	 	/* SPLLCM=0:    SPLL CLK monitor disabled 			*/
                             	 	 	 	 	/* SPLLSTEN=0:  SPLL disabled in Stop modes 		*/
                             	 	 	 	 	/* SPLLEN=1:    Enable SPLL 						*/

  while(!(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK)); /* Wait for SPLL valid */
}

void NormalRUNmode_80MHz (void)
{
/*! Slow IRC is enabled with high range (8 MHz) in reset.
 *	Enable SIRCDIV2_CLK and SIRCDIV1_CLK, divide by 1 = 8MHz
 *  asynchronous clock source.
 * ==========================================
*/
	SCG->SIRCDIV = SCG_SIRCDIV_SIRCDIV1(1)
				 | SCG_SIRCDIV_SIRCDIV2(1);

/*!
 *  Change to normal RUN mode with 8MHz SOSC, 80 MHz PLL:
 *  ====================================================
 */
  SCG->RCCR=SCG_RCCR_SCS(6)      /* Select PLL as clock source 								*/
    |SCG_RCCR_DIVCORE(0b01)      /* DIVCORE=1, div. by 2: Core clock = 160/2 MHz = 80 MHz 		*/
    |SCG_RCCR_DIVBUS(0b01)       /* DIVBUS=1, div. by 2: bus clock = 40 MHz 					*/
    |SCG_RCCR_DIVSLOW(0b10);     /* DIVSLOW=2, div. by 2: SCG slow, flash clock= 26 2/3 MHz	*/

  while (((SCG->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT ) != 6) {}	/* Wait for sys clk src = SPLL */
}


void PORT_init(void){

	PCC_PORTC |= (1<<CGC_BIT);

	PORTC_PCR6 &= ~((0b111)<<MUX_BITS);
	PORTC_PCR6 |= ((0b010)<<MUX_BITS);

	PORTC_PCR7 &= ~((0b111)<<MUX_BITS);
	PORTC_PCR7 |= ((0b010)<<MUX_BITS);


}

void LPUART1_init(void){

	PCC_LPUART1 &= ~(1<<CGC_BIT);				// Ensure clk disabled for config
	PCC_LPUART1 &= ~((0b111)<<PCS_BITS);		// SIRCDIV2_CLK Set
	PCC_LPUART1 |= ((0b010)<<PCS_BITS);
	PCC_LPUART1 |= (1<<CGC_BIT);				// LPUART1 clock enable

	/* Init for 9600 baud, 1 stop */
	LPUART1_BAUD &= ~(1<<M10_BIT);
	LPUART1_BAUD &= ~(1<<SBNS_BIT);

	LPUART1_BAUD &= ~((0b11111)<<OSR_BITS); ///////////15=0x1111
	LPUART1_BAUD |= (15<<OSR_BITS);
	LPUART1_BAUD &= ~(8191<<SBR_BITS);
	LPUART1_BAUD |= (52<<SBR_BITS);

	/* Enable transmitter & receiver, no parity, 8 bit char */
	LPUART1_CTRL &= ~(1<<M7_BIT);
	LPUART1_CTRL &= ~(1<<M_BIT);
	LPUART1_CTRL &= ~(1<<PE_BIT);

	LPUART1_CTRL |= (1<<TE_BIT);
	LPUART1_CTRL |= (1<<RE_BIT);
}

/* Transmit 1 char */
void LPUART1_transmit_char(char send){

	while((LPUART1_STAT & (1<<TDRE_BIT)) == 0);

	LPUART1_DATA = send;
}

/* Transmit whole string */
void LPUART1_transmit_string(char data_string[]){

	uint32_t i = 0;

	while(data_string[i] != '\0'){
		LPUART1_transmit_char(data_string[i]);
		i++;
	}
}

/* Receive 1 char */
char LPUART1_receive_char(void){

	char receive;

	while((LPUART1_STAT & (1<<RDRF_BIT)) == 0);

	receive = LPUART1_DATA;

	return receive;
}

#define STR_MAXLEN		100

int main(void){


	SOSC_init_8MHz();
	SPLL_init_160MHz();
	NormalRUNmode_80MHz();
	PORT_init();
	LPUART1_init();

	LPUART1_transmit_string("Running LPUART example\n\r");
	LPUART1_transmit_string("Input string to echo...\n\r");

	char str[STR_MAXLEN] = {0};
	int str_cur_len = 0;

	for(;;){

		char receive;

		receive = LPUART1_receive_char();

		if(receive != '\r'){
			str[str_cur_len] = receive;

			str_cur_len++;
		}
		else{

			str[str_cur_len] = '\0';

			LPUART1_transmit_char('>');
			LPUART1_transmit_string(str);
			LPUART1_transmit_char('\n');
			LPUART1_transmit_char('\r');

			str_cur_len = 0;

		}
	}

}
