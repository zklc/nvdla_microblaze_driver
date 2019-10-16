#ifndef PLATFORM_DLA_H
#define PLATFORM_DLA_H



#define DLA_DEBUG
//microblaze platform print
//#define DEBUG_PRINT(fmt, agrs...) printf(fmt, ## args) 
#ifdef DLA_DEBUG
#define d_print(fmt, args...) printf(fmt, ## args)
#else
#define d_print(fmt, args...) 
#endif









#endif
