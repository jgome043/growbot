/*
* ----------------------------------------------------------------------------
* “THE COFFEEWARE LICENSE” (Revision 1):
* <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a coffee in return.
* -----------------------------------------------------------------------------
* Please define your platform spesific functions in this file ...
* -----------------------------------------------------------------------------
*/

#include <avr/io.h>

#define set_bit(reg,bit) reg |= (1<<bit)
#define clr_bit(reg,bit) reg &= ~(1<<bit)
#define check_bit(reg,bit) (reg&(1<<bit))

#define NRF_DDR   DDRB
#define NRF_PORT  PORTB
#define NRF_PIN   PINB
#define NRF_SCK   DDB7    // SPI Clock
#define NRF_MISO  DDB6    // SPI Master Input Slave Output
#define NRF_MOSI  DDB5    // SPI Master Output Slave Input
#define NRF_CSN   DDB4    // Chip Select Not  (same function as SS')
#define NRF_CE    DDB3    // Chip Enable

/* ------------------------------------------------------------------------- */
void nrf24_setupPins()
{
    set_bit(NRF_DDR,NRF_CE);    // CE output
    set_bit(NRF_DDR,NRF_CSN);   // CSN output
    set_bit(NRF_DDR,NRF_SCK);   // SCK output
    set_bit(NRF_DDR,NRF_MOSI);  // MOSI output
    clr_bit(NRF_DDR,NRF_MISO);  // MISO input
}
/* ------------------------------------------------------------------------- */
void nrf24_ce_digitalWrite(uint8_t state)
{
    if(state)
    {
        set_bit(NRF_PORT,NRF_CE);
    }
    else
    {
        clr_bit(NRF_PORT,NRF_CE);
    }
}
/* ------------------------------------------------------------------------- */
void nrf24_csn_digitalWrite(uint8_t state)
{
    if(state)
    {
        set_bit(NRF_PORT,NRF_CSN);
    }
    else
    {
        clr_bit(NRF_PORT,NRF_CSN);
    }
}
/* ------------------------------------------------------------------------- */
void nrf24_sck_digitalWrite(uint8_t state)
{
    if(state)
    {
        set_bit(NRF_PORT,NRF_SCK);
    }
    else
    {
        clr_bit(NRF_PORT,NRF_SCK);
    }
}
/* ------------------------------------------------------------------------- */
void nrf24_mosi_digitalWrite(uint8_t state)
{
    if(state)
    {
        set_bit(NRF_PORT,NRF_MOSI);
    }
    else
    {
        clr_bit(NRF_PORT,NRF_MOSI);
    }
}
/* ------------------------------------------------------------------------- */
uint8_t nrf24_miso_digitalRead()
{
    return check_bit(NRF_PIN,NRF_MISO);
}
/* ------------------------------------------------------------------------- */
