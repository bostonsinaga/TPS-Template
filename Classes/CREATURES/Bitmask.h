#ifndef __BITMASK_H__
#define __BITMASK_H__

class Bitmask {
public:
    Bitmask() {

        /*
        *   AUTOMATICALLY set series of number for 'catMaskArr' with multiply by two
        *   eg. 1, 2, 4, 8, ...
        */
        for (int i = 0; i < count; i++) {
            if (i == 0) {
                catMaskArr[0] = 1;
            }
            else {
                catMaskArr[i] = catMaskArr[i-1] * 2;
            }
        }

        // MANUALLY set the 'colMaskArr'
        colMaskArr[PLAYER] = catMaskArr[ENEMY];
        colMaskArr[ENEMY] = catMaskArr[PLAYER];
    }

    // BITMASK REGISTRY //

    enum {
        PLAYER,
        ENEMY
    };

    const static int count = 2;
    unsigned short catMaskArr[count];
    unsigned short colMaskArr[count];
};

#endif // __BITMASK_H__