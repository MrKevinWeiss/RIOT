ifneq (,$(USE_HIL_BOARDS))

ifeq (samr21-xpro,$(BOARD))
  HOST = 10.28.48.11
  PI_PORT = /dev/ttyACM0
  PI_FLASHFILE = ${BINFILE}
  PI_BAUDRATE = 115200
endif

ifeq (nrf52dk,$(BOARD))
  HOST = 10.28.48.12
  PI_PORT = /dev/ttyACM0
  PI_FLASHFILE = ${HEXFILE}
  PI_BAUDRATE = 115200
endif

ifeq (nucleo-l073rz,$(BOARD))
  HOST = 10.28.48.13
  PI_PORT = /dev/ttyACM0
  PI_FLASHFILE = ${ELFFILE}
  PI_BAUDRATE = 115200
endif

ifeq (nucleo-f411re,$(BOARD))
  HOST = 10.28.48.14
  PI_PORT = /dev/ttyACM0
  PI_FLASHFILE = ${ELFFILE}
  PI_BAUDRATE = 115200
endif

ifeq (remote-revb,$(BOARD))
  HOST = 10.28.48.21
  PI_PORT = /dev/ttyUSB0
  PI_FLASHFILE = ${BINFILE}
  PI_BAUDRATE = 115200
endif

ifeq (arduino-mega2560,$(BOARD))
  HOST = 10.28.48.22
  PI_PORT = /dev/ttyACM0
  PI_FLASHFILE = ${HEXFILE}
  PI_BAUDRATE = 9600
endif

ifeq (nucleo-f103rb,$(BOARD))
  HOST = 10.28.48.23
  PI_PORT = /dev/ttyACM0
  PI_FLASHFILE = ${ELFFILE}
  PI_BAUDRATE = 115200
endif

ifeq (frdm-k22f,$(BOARD))
  HOST = 10.28.48.24
  PI_PORT = /dev/ttyACM0
  PI_FLASHFILE = ${ELFFILE}
  PI_BAUDRATE = 115200
endif


FLASHER = scp
FFLAGS = -oProxyCommand="ssh weiss@riot-ci.inet.haw-hamburg.de -W %h:%p" ${PI_FLASHFILE} pi@${HOST}:flash/fw$(suffix ${PI_FLASHFILE}) && ssh -oProxyCommand="ssh weiss@riot-ci.inet.haw-hamburg.de -W %h:%p" pi@${HOST} 'make -C flash flash-only'
RESET = ssh
RESET_FLAGS = -oProxyCommand="ssh weiss@riot-ci.inet.haw-hamburg.de -W %h:%p" pi@${HOST} 'make -C flash reset'

TERMPROG = ssh
TERMFLAGS = -oProxyCommand="ssh weiss@riot-ci.inet.haw-hamburg.de -W %h:%p" -t pi@${HOST} 'RIOT/dist/tools/pyterm/pyterm -p ${PI_PORT} -b ${PI_BAUDRATE}'

endif # (,$(USE_HIL_BOARDS))
