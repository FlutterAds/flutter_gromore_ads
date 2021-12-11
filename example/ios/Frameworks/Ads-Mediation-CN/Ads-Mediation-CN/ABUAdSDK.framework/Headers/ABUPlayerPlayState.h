//
//  ABUPlayState.h
//  ABUAdSDK
//
//  Created by wangchao on 2020/3/31.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, ABUPlayerPlayState) {
    ABUPlayerStateFailed    = 0,
    ABUPlayerStateBuffering = 1,
    ABUPlayerStatePlaying   = 2,
    ABUPlayerStateStopped   = 3,
    ABUPlayerStatePause     = 4,
    ABUPlayerStateDefalt    = 5
};
