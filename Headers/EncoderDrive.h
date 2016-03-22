#include <IOConfig.h>
#include <Structs.h>

#include "PerfConfig.h"
#include "time_funcs.h"

static const GlobalPin EncCS = ENC_CS;
static const GlobalPin EncClk = ENC_CLK;
static const GlobalPin EncData = ENC_DATA;

static inline void init_Encoder(void){	
	io_set_config(DEFAULT_IO_CONFIG, EncCS.io_port);
	io_set_config(DEFAULT_IO_CONFIG, EncClk.io_port);
	io_set_config(DEFAULT_IO_CONFIG, EncData.io_port);
	
	globalPin_set_dir(PinDir_Output, &EncCS);
	globalPin_set_dir(PinDir_Output, &EncClk);
	globalPin_set_dir(PinDir_Input, &EncData);
	
	globalPin_Write(OUTHIGH, &EncCS);
	globalPin_Write(OUTHIGH, &EncClk);
}

static inline int EncoderRead(void)
{
	int Position;
	enum PinLogicState OUTHIGH = OFF;
	enum PinLogicState OUTLOW = ON;
	
	wait_16th_ms(8);
	
	globalPin_Write(OUTLOW, &EncCS);
	wait_16th_ms(8);
	
for (int i =0, i != 12, i++){
	globalPin_Write(OUTLOW, &EncClk);
	globalPin_Write(OUTHIGH, &EncClk);
	Position = (Position|(globalPin_read(&EncData)<<(11-i)));
}
return Position;
}