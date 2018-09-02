#include <nds.h>
#include <stdio.h>

#ifndef __SOUNDCOMMON_H
#define __SOUNDCOMMON_H

#include <nds/fifocommon.h>

// FIFO channel used for MP3 control
#define CMDFIFO_MP3 FIFO_USER_01

// Commands the ARM7 can receive
typedef enum
{
	CMDFIFO7_MP3_PLAY,
	CMDFIFO7_MP3_SEEK,
	CMDFIFO7_MP3_PAUSE,
	CMDFIFO7_MP3_STOP,
    CMDFIFO7_MP3_VOLUME,
	CMDFIFO7_MP3_START,
	CMDFIFO7_BACKLIGHT_TOGGLE,
} CmdFifo7_e;

struct CmdFifo7_Mp3_Volume
{
	u32	volume;
};

struct CmdFifo7_Mp3_Start
{
	u8*	aviBuffer;
	int	aviBuffLen;
	int	aviBufPos;
	int	aviRemain;
};

typedef struct CmdFifo7
{
	CmdFifo7_e	command;
	union {
		struct CmdFifo7_Mp3_Volume volume;
		struct CmdFifo7_Mp3_Start start;
	} data;
} CmdFifo7;

// Commands the ARM9 can receive
typedef enum
{
	CMDFIFO9_MP3_AMOUNTUSED,
	CMDFIFO9_MP3_END,
	CMDFIFO9_MP3_READY,
	CMDFIFO9_MP3_SAMPLES,

	CMDFIFO9_ERROR,
} CmdFifo9_e;

struct CmdFifo9_Mp3_AmountUsed
{
	int amountUsed;
};

struct CmdFifo9_Mp3_Ready
{
	int	sampleRate;
};

struct CmdFifo9_Mp3_Samples
{
	int	samples;
};

struct CmdFifo9_Mp3_Error
{
	u32	error;
};

typedef struct CmdFifo9
{
	CmdFifo9_e command;
	union {
		struct CmdFifo9_Mp3_AmountUsed amountUsed;
		struct CmdFifo9_Mp3_Ready ready;
		struct CmdFifo9_Mp3_Samples samples;
		struct CmdFifo9_Mp3_Error error;
	} data;
} CmdFifo9;


// Sound mixer state
typedef enum
{
	SNDMIXER_IDLE,
	SNDMIXER_SETUPSTREAM,
	SNDMIXER_STREAMING,
	SNDMIXER_PAUSE,
	SNDMIXER_STOP,

	SNDMIXER_SIZE,

} sndMixerState;

typedef enum
{
	SNDSTATE_IDLE,
	SNDSTATE_PLAY,
	SNDSTATE_ENDOFDATA,
	SNDSTATE_ERROR,

	SNDSTATE_SIZE,

} sndState;

#endif