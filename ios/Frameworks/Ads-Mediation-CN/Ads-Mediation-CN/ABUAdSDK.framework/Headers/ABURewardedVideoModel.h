//
//  ABURewardedVideoModel.h
//  Ads-Mediation-CN
//
//  Created by CHAORS on 2021/11/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 开发者提供给GroMore和ADN的奖励信息，适用于ADN的服务端验证和GroMore的S2S验证
@interface ABURewardedVideoModel : NSObject
/// 可选，三方用户ID。主要用于奖励发放，是服务器到服务器的回调传递参数。在非服务器回调模式下，当视频播放结束时，它也将被透传。是否有效依赖于adapter和adn。
@property (nonatomic, copy) NSString *userId;

/// 可选，奖励名称。是否有效依赖于adapter和adn。
@property (nonatomic, copy) NSString *rewardName;

/// 可选，奖励金额。是否有效依赖于adapter和adn。
@property (nonatomic, assign) NSInteger rewardAmount;

/// 可选，可序列化字符串。是否有效依赖于adapter和adn。
@property (nonatomic, copy) NSString *extra;

@end

NS_ASSUME_NONNULL_END
