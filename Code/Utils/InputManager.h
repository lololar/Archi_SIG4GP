#ifndef _INPUT_H
#define _INPUT_H

#include "Game\Singleton.h"

class InputManager : public Singleton<InputManager>
{
public:
	bool charPress[256];
};

// list of keynumber for letters

#define key_a 97 
#define key_b 98 
#define key_c 99 
#define key_d 100
#define key_e 101
#define key_f 102
#define key_g 103
#define key_h 104
#define key_i 105
#define key_j 106
#define key_k 107
#define key_l 108
#define key_m 109
#define key_n 110
#define key_o 111
#define key_p 112
#define key_q 113
#define key_r 114
#define key_s 115
#define key_t 116
#define key_u 117
#define key_v 118
#define key_w 119
#define key_x 120
#define key_y 121
#define key_z 122

#endif