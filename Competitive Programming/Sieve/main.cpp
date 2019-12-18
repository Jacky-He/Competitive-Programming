//
//  main.cpp
//  Sieve
//
//  Created by Jacky He on 2018-12-17.
//  Copyright © 2018 Jacky He. All rights reserved.
//

#include <iostream>
bool sieve [200001];
void init()
{
    sieve [0] = 1; sieve [1] = 1;
    for (int i = 2; i <= 200000; i++)
    {
        if (sieve [i])
        {
            continue;
        }
        for (int j = i*2; j <= 200000; j+= i)
        {
            sieve [j] = 1;
        }
    }
}
int main(int argc, const char * argv[])
{
    init();
    //insert my code here
    
    return 0;
}
