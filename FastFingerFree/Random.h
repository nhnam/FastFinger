//
//  Random.h
//  FastFingerFree
//
//  Created by Nam Nguyen on 7/9/13.
//  Copyright (c) 2013 DreamersTeam. All rights reserved.
//

#ifndef __FastFingerFree__Random__
#define __FastFingerFree__Random__

#include <iostream>
class Random
{
public:
    Random(void);
    Random( long seed);
    static void setSeed(long _seed);
    static int next();
public:
    static long seed;
    static long multiplier;
    static long addend;
    static long mask;
};
#endif /* defined(__FastFingerFree__Random__) */
