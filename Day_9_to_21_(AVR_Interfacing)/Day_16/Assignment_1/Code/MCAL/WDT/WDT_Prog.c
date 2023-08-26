
void WDT_enable(u8 wait_time)
{
	SET_BIT(WDTCR, WDE);
	
	WDTCR &= 0b11111000;
	WDTCR |= wait_time;
}

void WDT_disable(void)
{
	// both WDTOE && WDE must be written 1 at the same time
	// write 0 to WDE
	mask = 0b 000 11 000
	WDTCR |= (1<<WDTOE) | (1<<WDR);
	WDTCR = 0x00;
	
}