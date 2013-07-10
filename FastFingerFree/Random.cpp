//
//  Random.cpp
//  FastFingerFree
//
//  Created by Nam Nguyen on 7/9/13.
//  Copyright (c) 2013 DreamersTeam. All rights reserved.
//

#include "Random.h"
long Random::multiplier = 0x5DEECE6C;
long Random::addend = 0xB;
long Random::mask = (1L << 48) - 1;
long Random::seed= 0x2342dda;

Random::Random(void)
{
    setSeed(time(NULL));
}

Random::Random( long seed) {
    setSeed(seed);
}

void Random::setSeed(long _seed) {
    seed = (unsigned)(_seed & 0x7fffffffU);
}

int Random::next() {
    seed = (seed * 1103515245U + 12345U) & 0x7fffffffU;
    return (int)(seed);
}