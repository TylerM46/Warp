/*
	Authored 2016-2018. Phillip Stanley-Marbell. Additional contributors,
	2018-onwards, see git log.

	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions
	are met:

	*	Redistributions of source code must retain the above
		copyright notice, this list of conditions and the following
		disclaimer.

	*	Redistributions in binary form must reproduce the above
		copyright notice, this list of conditions and the following
		disclaimer in the documentation and/or other materials
		provided with the distribution.

	*	Neither the name of the author nor the names of its
		contributors may be used to endorse or promote products
		derived from this software without specific prior written
		permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
	FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
	COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
	INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
	BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
	ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGE.
*/

void		initMMA8451Q(const uint8_t i2cAddress, uint16_t operatingVoltageMillivolts);
WarpStatus	readSensorRegisterMMA8451Q(uint8_t deviceRegister, int numberOfBytes);
WarpStatus	writeSensorRegisterMMA8451Q(uint8_t deviceRegister, uint8_t payloadBtye);
WarpStatus 	configureSensorMMA8451Q(uint8_t payloadF_SETUP, uint8_t payloadCTRL_REG1);
void		printSensorDataMMA8451Q(bool hexModeFlag);
void		MyOrientate(bool hexModeFlag);
void		myprintSensorDataMMA8451Q(bool hexModeFlag);
uint8_t		appendSensorDataMMA8451Q(uint8_t* buf);

const uint8_t bytesPerMeasurementMMA8451Q            = 6;
const uint8_t bytesPerReadingMMA8451Q                = 2;
const uint8_t numberOfReadingsPerMeasurementMMA8451Q = 3;
