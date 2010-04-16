/*
Copyright (c) 2007-, Miklós Fazekas
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the <organization>.
4. Neither the name of the <organization> nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY <COPYRIGHT HOLDER> ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
#include "PerfTestBase.h"
#include "PerfTestRegistry.h"
#include <sstream>

template <int size>
class MemCpyPerfTest : public PerfTestBase {
public:
    virtual int perform(int& rounds_,int fourtytwo_,int random_) {
        int32_t result;
        for (int i = 0; i < rounds_; ++i) {
            int idx = i*(fourtytwo_-42);
            memcpy(src+idx,dest+idx,size);
        }
        return result;
        
    }
    
    std::string name() const {
        std::ostringstream os;
        os << "MemCpyPerfTest<" << size << ">";
        return os.str();
    }
    
    char dest[42+size];
    char src[42+size];
};

PERFTEST_AUTOREGISTER(MemCpyPerfTest1,new MemCpyPerfTest<10>())
PERFTEST_AUTOREGISTER(MemCpyPerfTest2,new MemCpyPerfTest<100>())
PERFTEST_AUTOREGISTER(MemCpyPerfTest3,new MemCpyPerfTest<1024>())
PERFTEST_AUTOREGISTER(MemCpyPerfTest4,new MemCpyPerfTest<4096>())
PERFTEST_AUTOREGISTER(MemCpyPerfTest5,new MemCpyPerfTest<4*4096>())
