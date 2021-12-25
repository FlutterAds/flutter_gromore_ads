//
//  ABUSigmobError.h
//  Pods
//
//  Created by Makaiwen on 2021/5/31.
//

#ifndef ABUSigmobError_h
#define ABUSigmobError_h
#import <Foundation/Foundation.h>

static inline
NSError *ABUSigmobError(int code, NSString *reason) {
    return [NSError errorWithDomain:@"com.bytedance.GroMore.sigmob.adapter" code:code userInfo:@{
        NSLocalizedDescriptionKey : reason ?: @"Unknow error",
        NSLocalizedFailureReasonErrorKey : reason ?: @"Unknow error"}];
}

static inline
NSError *ABUSigmobError_Setup_Failed() {
    return ABUSigmobError(-1, @"Failed to set up ad.");
}

#endif /* ABUSigmobError_h */
