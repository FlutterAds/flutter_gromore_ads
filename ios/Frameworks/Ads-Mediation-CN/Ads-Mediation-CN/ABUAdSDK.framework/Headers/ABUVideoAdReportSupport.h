//
// Created by bytedance on 2022/5/6.
//

#import <Foundation/Foundation.h>

/// 待上报的视频事件枚举类型
typedef NS_ENUM(NSInteger, ABUVideoAdEvent) {
    ABUVideoAdEventVideoDidPlay = 1, // 视频开始播放
    ABUVideoAdEventVideoDidFinish = 2, // 视频播放完成，无异常
    ABUVideoAdEventVideoDidPause = 3, // 视频暂停
    ABUVideoAdEventVideoDidResume = 4, // 视频恢复播放
    ABUVideoAdEventVideoDidBreak = 5, // 视频意外终止，如跳过、视频切出屏幕等
    ABUVideoAdEventVideoDidClick = 6, // 视频被点击
    ABUVideoAdEventVideoDidStartFailed = 7, // 视频开始播放时出现异常
    ABUVideoAdEventVideoDidPlayFailed = 8, // 视频播放中出现异常

};

typedef NSString * ABUVideoAdEventParameter;

/// 视频总时长，NSNumber类型，单位s
extern ABUVideoAdEventParameter const ABUVideoAdEventParameterVideoTotalDurationKey;
/// 视频播放时长，NSNumber类型，单位s
extern ABUVideoAdEventParameter const ABUVideoAdEventParameterVideoCurrentDurationKey;
/// 视频出现异常原因，NSError类型
extern ABUVideoAdEventParameter const ABUVideoAdEventParameterErrorKey;
