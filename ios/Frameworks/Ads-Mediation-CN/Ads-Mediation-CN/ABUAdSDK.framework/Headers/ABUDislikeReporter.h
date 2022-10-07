//
// Created by bytedance on 2022/4/26.
//

#import <Foundation/Foundation.h>
#import "ABUDislikeReason.h"

@class ABUNativeAdView;
@class ABUDrawAdView;

/// dislike的原因上报句柄
@interface ABUDislikeReporter : NSObject

/// 构建上报对象
/// @param nativeAdView 非模板Native广告对应的广告视图对象
- (instancetype)initWithNativeAd:(ABUNativeAdView *)nativeAdView;

/// 构建上报对象
/// @param nativeAdView 非模板Native广告对应的广告视图对象
- (instancetype)initWithDrawAd:(ABUDrawAdView *)drawAdView;

/// 原因，不喜欢该广告的原因，由adn通过adapter提供
@property (nonatomic, copy, readonly) NSArray<ABUDislikeReason *> *reasons;

/// 选中了某个原因
/// @param ID 原因的唯一标识
- (void)didSelectedReasonWithID:(NSString *)ID;

/// 取消选中了某个原因
/// @param ID 原因的唯一标识
- (void)didUnselectedReasonWithID:(NSString *)ID;

/// 提交最终结果
- (void)submit;

@end
