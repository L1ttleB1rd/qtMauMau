#ifndef GAME_STATUS_H_
#define GAME_STATUS_H_

enum game_status {
	STATUS_NONE = 0,
	STATUS_DRAW_2 = 2,
	STATUS_DRAW_4 = 4,
	STATUS_DRAW_6 = 6,
	STATUS_DRAW_8 = 8,
	STATUS_MISS_TURN = 1,
	STATUS_WISHED_SUIT = 3
};

#endif /* GAME_STATUS_H_ */