//
//  ABUAdapterRewardAdInfo.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/8/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 激励视频广告透传信息
@interface ABUAdapterRewardAdInfo : NSObject

/// adn 服务器定义的激励名称
@property (nonatomic, copy, nullable) NSString *rewardName;

/// 奖励用户的金额
@property (nonatomic, assign) NSInteger rewardAmount;

/// 交易ID
@property (nonatomic, copy, nullable) NSString *tradeId;

/// 是否验证
@property (nonatomic, assign) BOOL verify;

@end

NS_ASSUME_NONNULL_END
