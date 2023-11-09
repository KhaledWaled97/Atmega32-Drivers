/*
 * Seven_Segment.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Khaled Waled
 */

#ifndef SEVEV_SEG_INTERFACE_H_
#define SEVEV_SEG_INTERFACE_H_



void Sev_Seg_Intialize(void);
void Sev_Seg_Enable_1(void);
void Sev_Seg_Enable_2(void);
void Sev_Seg_Enable_3(void);
void Sev_Seg_Enable_4(void);
void Sev_Seg_Disable_1(void);
void Sev_Seg_Disable_2(void);
void Sev_Seg_Disable_3(void);
void Sev_Seg_Disable_4(void);
void Sev_Seg_WriteNumber(u8 Number);

#endif /* SEVEV_SEG_INTERFACE_H_ */
