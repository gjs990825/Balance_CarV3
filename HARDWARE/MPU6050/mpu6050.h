#ifndef _MPU6050_H_
#define _MPU6050_H_

#include "sys.h"


// 定义MPU6050内部地址
#define	SMPLRT_DIV		0x19	//陀螺仪采样率，典型值：0x07(125Hz)
#define	CONFIG			0x1A	//低通滤波频率，典型值：0x06(5Hz)
#define	GYRO_CONFIG		0x1B	//陀螺仪自检及测量范围，典型值：0x18(不自检，2000deg/s)
#define	ACCEL_CONFIG	0x1C	//加速计自检、测量范围及高通滤波频率，典型值：0x01(不自检，2G，5Hz)
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44	
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B	//电源管理，典型值：0x00(正常启用)
#define	WHO_AM_I		0x75	//IIC地址寄存器(默认数值0x68，只读)
//#define	SlaveAddress	0xD0	//IIC写入时的地址字节数据，+1为读取

// void MPU6050_Init(void);
// void MPU6050_WriteOneByte(uint8_t REG_Adress, uint8_t REG_Data);
// uint8_t MPU6050_ReadOneByte(u8 REG_Address);
// int16_t Out_Data(u8 REG_Address);


#define CALIBRATING_GYRO_CYCLES             1000
#define CALIBRATING_ACC_CYCLES              400


void MPU6050_Init(uint16_t sample_rate, uint16_t lpf);
int16_t MPU6050_Get_Data(uint8_t addr);
uint8_t MPU6050_Sequence_Read(void);
void MPU6050_Single_Read(void);
uint8_t MPU6050_Check(void);
void MPU6050_Compose_Data(void);


#endif
