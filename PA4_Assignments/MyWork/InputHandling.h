//
//  InputHandling.h
//  PA4
//
//  Created by MazeRunner on 15-12-10.
//  Copyright (c) 2015 Reno Jackson. All rights reserved.
//

#ifndef PA4_InputHandling_h
#define PA4_InputHandling_h

class InvalidInput
{
public:
    InvalidInput (const char* in_ptr): msg_ptr (in_ptr) {}
    const char* const msg_ptr;
private:
    InvalidInput();
};



#endif
