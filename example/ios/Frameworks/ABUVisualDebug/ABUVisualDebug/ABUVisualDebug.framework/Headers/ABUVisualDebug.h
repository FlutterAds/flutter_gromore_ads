//
//  ABUVisualDebug.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/3/25.
//

#import <Foundation/Foundation.h>

@interface ABUVisualDebug : NSObject

// start visual debug and show debug view, if success,return YES
+ (BOOL)startVisualDebug;
+ (void)stopVisualDebug;

@end
