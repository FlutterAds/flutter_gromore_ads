//
// Created by bytedance on 2022/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 自渲染视频类广告事件上报类
@interface ABUVideoAdReporter : NSObject

/// 上报视频开始播放事件
- (void)didStartPlayVideo;
/// 上报视频播放完成事件
- (void)didFinishVideo;
/// 上报视频播放暂停事件
- (void)didPauseVideoWithCurrentDuration:(NSTimeInterval)duration;
/// 上报视频播放继续事件
- (void)didResumeVideoWithCurrentDuration:(NSTimeInterval)duration;
/// 上报视频播放中止事件
- (void)didBreakVideoWithCurrentDuration:(NSTimeInterval)duration;
/// 上报视频视图点击事件
- (void)didClickVideoViewWithCurrentDuration:(NSTimeInterval)duration;
/// 上报视频播放失败事件
- (void)didPlayFailedWithError:(NSError *)error;
/// 上报视频无法播放事件
- (void)didPlayStartFailedWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END